/*!
 ******************************************************************************
 **  CarMaker - Version 9.0.2
 **  Vehicle Dynamics Simulation Toolkit
 **
 **  Copyright (C)   IPG Automotive GmbH
 **                  Bannwaldallee 60             Phone  +49.721.98520.0
 **                  76185 Karlsruhe              Fax    +49.721.98520.99
 **                  Germany                      WWW    www.ipg-automotive.com
 ******************************************************************************
 *
 * Description:
 * - Prototype/Proof of Concept
 * - Unsupported ROS Example with CarMaker
 * - Structure may change in future!
 * - Change general parameters in Infofile for CMRosIF ("Data/Config/CMRosIFParameters")
 * - Basic communication with or without parameterizable synchronization
 *
 *
 * ToDo:
 * - C++!!!
 * - ROS naming/way/namespaces
 * - parameter: CarMaker read, ROS set by service?
 *   -> ROS parameter mechanism seems better solution!
 * - node/topic/... destruction to allow dynamic load/unload
 *   when TestRun starts instead of initialization at CarMaker startup
 * - New Param_Get() function to read parameters from Infofile
 * - ...
 *
 */


/* CarMaker
 * - include other headers e.g. to access to vehicle data
 *   - e.g. "Vehicle.h" or "Vehicle/Sensor_*.h".
 * - additional headers can be found in "<CMInstallDir>/include/"
 * - see Reference Manual, chapter "User Accessible Quantities" to find some variables
 *   that are already defined in DataDictionary and their corresponding C-Code Name
 */
#include "Log.h"
#include "DataDict.h"
#include "SimCore.h"
#include "InfoUtils.h"

#include "apo.h"
#include "GuiCmd.h"


// 220205 TY add
// #include "Vehicle_Control_UDP.h"
// extern tUDP_PC UDP_PC;
// extern tUDP_Input UDP_Input;
#include "std_msgs/msg/float64_multi_array.hpp"
#include "Vehicle/Sensor_GNav.h"
#include "Vehicle/Sensor_TSign.h" //Speed_Limit
#include <sensor_msgs/point_cloud_conversion.hpp> //pointcloud2_example
#include "sensor_msgs/msg/point_cloud2.hpp" //pointcloud2_example
#include "Vehicle/Sensor_Inertial.h"
#include "TrafficLight.h"
#include "Environment.h"
#include "Vehicle.h"
#include <hellocm_msgs/msg/imu_out.hpp>
#include <hellocm_msgs/msg/vehicle_info_out.hpp>
#include <hellocm_msgs/msg/vehicle_control_in.hpp>
#include <hellocm_msgs/msg/signal_light_in.hpp>
#include <hellocm_msgs/msg/object_info_out.hpp>

#include "VehicleControl.h"
#include "DrivMan.h"
#include "Vehicle/VehicleControlApps.h"
#include <time.h>
#include <cstring>

#define VLP_16_POINTS_OF_PACKET 2880
#define VLP_16_NUMBER_OF_PACKET 10
#define OS1_64_POINTS_OF_PACKET 2900
#define OS1_64_POINTS_OF_LAST_PACKET 1736
#define OS1_64_NUMBER_OF_PACKET 23
#define Max_Intensity 65000


#include "Vehicle.h"
#include "Vehicle/Sensor_LidarRSI.h"
#include "Vehicle/Sensor_Object.h"
#include "Vehicle/Sensor_Line.h"
#include "Traffic.h"
#include "infoc.h"
#include "InfoUtils.h"
#include "Log.h"
#include <math.h>
#include "DataDict.h"
#include "SimCore.h"
#include "Car/Car.h"
#define VLP_16_NUMBER_OF_POINTS 28800
#define OS1_64_NUMBER_OF_POINTS 65536




int Lidar_CycleCount;

/* ROS */
#include "cmrosutils/CMRosUtils.h"    /* Node independent templates, ...*/

#include "cmrosutils/CMRosIF_Utils.h" /* Only for CarMaker ROS Node!!! Functions are located in library for CarMaker ROS Interface */
#include "cmrosutils/srv/cm_remote.hpp"      /* Basic service for CarMaker remote from ROS */

#include "sensor_msgs/msg/point_cloud.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "nav_msgs/msg/path.hpp"
#include <angles/angles.h>
#include <hellocm_msgs/msg/gps_out.hpp>


// #include "cmrosutils/CMRosIF_Utils.h" //OnlyTrafficLight
// #include "visualization_msgs/msg/marker_array.hpp"
// #include "tf2_geometry_msgs/tf2_geometry_msgs.h"
// #include "tf2_ros/transform_broadcaster.h"
// #include "tf2_ros/static_transform_broadcaster.h"
// #include "nav_msgs/msg/path.hpp"
// #include "nav_msgs/msg/odometry.hpp"
// #include <angles/angles.h>
// #include "std_msgs/msg/float64_multi_array.hpp"

// // Added by hongbeen
// // #include <hellocm_msgs/msg/control_command_stamped.hpp>
// #include "Vehicle/VehicleControlApps.h"
// #include "VehicleControl.h"
// #include "DrivMan.h"

/* Following header from external ROS node can be used to get topic/service/... names
 * Other mechanism:
 * 1. Put names manually independently for each node
 * 2. Using command line arguments or launch files and ROS remapping
 * - Doing so, only general message headers are necessary
 */
#if 1
#  include "hellocm/ROS1_HelloCM.h"  /* External ROS Node. Topic name, ... */
#else
#include <hellocm_msgs/msg/cm2_ext.hpp>
#include <hellocm_msgs/msg/ext2_cm.hpp>
#include <hellocm_msgs/msg/control_command.hpp>
#include <hellocm_msgs/srv/init.hpp>
#endif

/*! String and numerical version of this Node
 *  - String:    e.g. <Major>.<Minor>.<Patch>
 *  - Numerical: e.g. <nDigitsMajor><2DigitsMinor><2DigitsPatch>
 */
#define CMNODE_VERSION "0.8.0"
#define CMNODE_NUMVER  800


/* NDEBUG is set in CarMaker Makefile/MakeDefs in OPT_CFLAGS */
#if !defined NDEBUG
#  warning "Debug options are enabled!"
#  define DBLOG LOG
#else
#  define DBLOG(...)
#endif

/* Not beautiful but consistent with external ROS Node
 * where ROS_INFO is used (implicit newline)*/
# define LOG(frmt, ...)  Log(frmt "\n", ##__VA_ARGS__)


/* General switches for CarMaker ROS Node */
typedef enum tCMNode_Mode {
    CMNode_Mode_Disabled  = 0,  /*!< Node is disabled. e.g. don't publish. */
    CMNode_Mode_Default   = 1,  /*!< Node is enabled, spinOnce is used  */
    CMNode_Mode_Threaded  = 2   /*!< Node is enabled, spin in parallel thread
                                     - Messages are received all the time
                                     - Data is updated at defined position, e.g. *_In()
                                     - Currently not implemented! */
} tCMNode_Mode;



/* Managing synchronization between CarMaker Node and other ROS nodes */
typedef enum tCMNode_SyncMode {
    CMNode_SyncMode_Disabled  = 0, /*!< No synchronization on CarMaker side */
    CMNode_SyncMode_Tpc       = 1  /*!< Buffer messages or Spin until external Topics are received */
} tCMNode_SyncMode;


// temporary GPS, IMU, VehicleInfoOut Hz Control
static struct {
    long long BeforeTime;
    int Hz = 50;
    bool isOkay = false;
} HzControl;


/* Global struct for this Node */
static struct {
    unsigned long  CycleNoRel;  /*!< CarMaker relative cycle number, e.g. since start of TestRun */
    int            TY_Debugging;

    struct {
        double         Duration;      /*!< Time spent for synchronization task */
        int            nCycles;       /*!< Number of cycles in synchronization loop */
        int            CyclePrepDone; /*!< Last cycle when preparation was done */
        int            CycleJobDone;  /*!< Last cycle when job was done */
        double         SynthDelay;    /*!< Synthetic delay in seconds provided to external node to check sync */
    } Sync; /*!< Synchronization related information */

    struct {
        int CycleNo;      /*!< Cycle number of external ROS Node (only for information) */

        /* For debugging */
        int            CycleLastOut;   /*!< Cycle number when Topic was published */
        int            CycleLastIn;    /*!< Cycle number when Topic from external ROS Node was received */
        int            CycleLastFlush; /*!< Cycle number when data from external ROS Node was provided to model */
    } Model; /*!< Model related information. ROS side! */

    struct {
        struct {
            tRosIF_TpcSub<hellocm_msgs::msg::Ext2CM> Ext2CM; /* For this example also used for Synchronization */
            // tRosIF_TpcSub<hellocm_msgs::msg::ControlCommandStamped> VehicleControlIn; //autoware ctrl msg sub
            tRosIF_TpcSub<std_msgs::msg::Float64MultiArray> VehicleControlIn;  // From SAVE CM project
            tRosIF_TpcSub<std_msgs::msg::Float64MultiArray> SaveCustom;  // SaveCustom Msgs
            tRosIF_TpcSub<std_msgs::msg::Float64MultiArray> SignalLightIn;     // From SAVE CM project
        } Sub; /*!< Topics to be subscribed */

        struct {
            tRosIF_TpcPub<hellocm_msgs::msg::CM2Ext> CM2Ext;
                        tRosIF_TpcPub<sensor_msgs::msg::PointCloud> Lidar_VLP;
                        tRosIF_TpcPub<sensor_msgs::msg::PointCloud> Lidar_OS1;  // HB Edited: remove 2
                        
            tRosIF_TpcPub<hellocm_msgs::msg::GPSOut> GPSOut;
            tRosIF_TpcPub<hellocm_msgs::msg::IMUOut> IMUOut;
            tRosIF_TpcPub<hellocm_msgs::msg::VehicleInfoOut> VehicleInfoOut;
            tRosIF_TpcPub<hellocm_msgs::msg::ObjectInfoOut> ObjectInfoOut;
                tRosIF_TpcPub<std_msgs::msg::Float64MultiArray> GPSOut2;
                tRosIF_TpcPub<std_msgs::msg::Float64MultiArray> IMUOut2;
                tRosIF_TpcPub<std_msgs::msg::Float64MultiArray> VehicleInfoOut2;
                tRosIF_TpcPub<std_msgs::msg::Float64MultiArray> ObjectInfoOut2;


            tRosIF_TpcPub<sensor_msgs::msg::PointCloud2> Lidar_OS1_PC2; //pointcloud2_example
            tRosIF_TpcPub<nav_msgs::msg::Path> LeftLane[2];
            tRosIF_TpcPub<nav_msgs::msg::Path> RightLane[2];

                        // tRosIF_TpcPub<visualization_msgs::msg::MarkerArray> ObjectList;
            // tRosIF_TpcPub<nav_msgs::msg::Odometry> Odometry;
            // tRosIF_TpcPub<visualization_msgs::msg::MarkerArray> EgoVehicle;

            /*!< CarMaker can be working as ROS Time Server providing simulation time
             *   starting at 0 for each TestRun */
            tRosIF_TpcPub<rosgraph_msgs::msg::Clock> Clock;
        } Pub; /*!< Topics to be published */
    } Topics; /*!< ROS Topics used by this Node */

    struct {
        /*!< Initialization/Preparation of external ROS Node e.g. when simulation starts */
        tRosIF_Srv<hellocm_msgs::srv::Init>    Init;
        tRosIF_Srv<cmrosutils::srv::CMRemote>  CMRemote; // Trial
    } Services; /*!< ROS Services used by this Node (client and server)*/

        struct {
        std::shared_ptr<tf2_ros::TransformBroadcaster> br;
                std::shared_ptr<tf2_ros::StaticTransformBroadcaster> st_br;

        geometry_msgs::msg::TransformStamped Lidar_VLP;
                geometry_msgs::msg::TransformStamped Lidar_OS1;
        geometry_msgs::msg::TransformStamped Lidar_OS1_PC2; //pointcloud2_example
                // geometry_msgs::msg::TransformStamped Object;
        geometry_msgs::msg::TransformStamped Line;

    } TF;


    struct {
        int               QueuePub;     /*!< Queue size for Publishers */
        int               QueueSub;     /*!< Queue size for Subscribers */
        int               nCyclesClock; /*!< Number of cycles publishing /clock topic.
                                             CycleTime should be multiple of this value */
        tCMNode_Mode      Mode;
        tCMNode_SyncMode  SyncMode;
        double            SyncTimeMax;  /* Maximum Synchronization time */

        tRosIF_Cfg        Ros;
    } Cfg; /*!< General configuration for this Node */

        struct {
        double *BeamTable;
        int rows = 0;
    } LidarRSI_VLP, LidarRSI_OS1;

} CMNode;



/*!
 * Description:
 * - Callback for ROS Topic published by external ROS Node
 *
 */
static void
cmnode_HelloCM_CB_TpcIn (const hellocm_msgs::msg::Ext2CM::SharedPtr msg)
{
    /* Process message only if receive is expected */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
            return;

    int rv;
    auto in = &CMNode.Topics.Sub.Ext2CM;

    /* Update receive buffer
     * - No lock for spinOnce necessary?
     */
    in->Msg.header  = msg->header;
    in->Msg.time    = msg->time;
    in->Msg.cycleno = msg->cycleno;

    /* Stopping simulation is only necessary when synchronization is activated */
    if (CMNode.Cfg.SyncMode == CMNode_SyncMode_Tpc && (rv = CMCRJob_DoPrep_SetDone(in->Job, CMNode.CycleNoRel)) != CMCRJob_RV_Success) {
            LogErrF(EC_Sim, "CMNode: Error on DoPrep_SetDone for Job '%s'! rv=%s", CMCRJob_GetName(in->Job), CMCRJob_RVStr(rv));
    }

    /* Remember cycle for debugging */
    CMNode.Model.CycleLastIn = CMNode.CycleNoRel;


    LOG("%s (CMSimTime=%.3fs): External Node is in cycle %lu, Time=%ds, Stamp=%ds",
            CMNode.Cfg.Ros.Node->get_name(), SimCore.Time,
            in->Msg.cycleno, msg->time.sec, in->Msg.header.stamp.sec);

}

// SAVE_AN
int sw = 3;
int gear_no = 1;
double ax = 0;
double steer_ang = 0;
int SelectorCtrl = 1;
static void
cmnode_VehicleControlIn_TpcIn (const std_msgs::msg::Float64MultiArray::SharedPtr vc)
{
    /* Process message only if receive is expected */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
            return;

    int rv;
    auto in = &CMNode.Topics.Sub.VehicleControlIn;

    /* Update receive buffer
     * - No lock for spinOnce necessary?
     */
    sw        = int(vc->data[3]);
    ax        = double(vc->data[2]);
    steer_ang = double(vc->data[1]);
    gear_no   = int(vc->data[0]);
    SelectorCtrl = int(vc->data[4]);

    /* Stopping simulation is only necessary when synchronization is activated */
    if (CMNode.Cfg.SyncMode == CMNode_SyncMode_Tpc && (rv = CMCRJob_DoPrep_SetDone(in->Job, CMNode.CycleNoRel)) != CMCRJob_RV_Success) {
            LogErrF(EC_Sim, "CMNode: Error on DoPrep_SetDone for Job '%s'! rv=%s", CMCRJob_GetName(in->Job), CMCRJob_RVStr(rv));
    }

    /* Remember cycle for debugging */
    CMNode.Model.CycleLastIn = CMNode.CycleNoRel;
}

int obj_disappear_trig = 0;
int obj_disappear_id = 0;
static void cmnode_SaveCustomIn_TpcIn (const std_msgs::msg::Float64MultiArray::SharedPtr savecustom)
{
    /* Process message only if receive is expected */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
            return;

    int rv;
    auto in = &CMNode.Topics.Sub.SaveCustom;

    /* Update receive buffer
     * - No lock for spinOnce necessary?
     */
    obj_disappear_id          = int(savecustom->data[0]);
    obj_disappear_trig        = int(savecustom->data[1]);

    /* Stopping simulation is only necessary when synchronization is activated */
    if (CMNode.Cfg.SyncMode == CMNode_SyncMode_Tpc && (rv = CMCRJob_DoPrep_SetDone(in->Job, CMNode.CycleNoRel)) != CMCRJob_RV_Success) {
            LogErrF(EC_Sim, "CMNode: Error on DoPrep_SetDone for Job '%s'! rv=%s", CMCRJob_GetName(in->Job), CMCRJob_RVStr(rv));
    }

    /* Remember cycle for debugging */
    CMNode.Model.CycleLastIn = CMNode.CycleNoRel;
}



int signallight;
bool hazard;
static void
cmnode_SignalLightIn_TpcIn (const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    /* Process message only if receive is expected */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
            return;

    int rv;
    auto in = &CMNode.Topics.Sub.SignalLightIn;

    /* Update receive buffer
     * - No lock for spinOnce necessary?
     */
    signallight   = int(msg->data[0]);
    hazard         = bool(msg->data[1]);
    /* Stopping simulation is only necessary when synchronization is activated */
    if (CMNode.Cfg.SyncMode == CMNode_SyncMode_Tpc && (rv = CMCRJob_DoPrep_SetDone(in->Job, CMNode.CycleNoRel)) != CMCRJob_RV_Success) {
            LogErrF(EC_Sim, "CMNode: Error on DoPrep_SetDone for Job '%s'! rv=%s", CMCRJob_GetName(in->Job), CMCRJob_RVStr(rv));
    }

    /* Remember cycle for debugging */
    CMNode.Model.CycleLastIn = CMNode.CycleNoRel;

}


/*!
 * Description:
 * - Exemplary Service Callback for CarMaker Remote using ROS
 * - e.g. via rqt Service Caller or terminal "rosservice call ..."
 *
 *
 */
static bool
cmnode_HelloCM_CB_SrvCMRemote(cmrosutils::srv::CMRemote::Request req, cmrosutils::srv::CMRemote::Response resp)
        // const std::shared_ptr<rmw_request_id_t> request_header,
        // std::shared_ptr<cmrosutils::srv::CMRemote::Request> req,
        // std::shared_ptr<cmrosutils::CMRemote::Response> resp)
{

    int rv = -2;
    char sbuf[512];

    LOG("%s: Service '%s' was triggered with type='%s', msg='%s', data='%s'",
            CMNode.Cfg.Ros.Node->get_name(),
            CMNode.Services.CMRemote.Srv->get_service_name(),
                req.type.c_str(), req.msg.c_str(), req.data.c_str());


    /* Commands to CarMaker GUI
     * - Tcl commands!
     * - More information see "ProgrammersGuide"
     */
    if (strcasecmp("guicmd", req.type.c_str()) == 0) {
        /* Default: Evaluate command sent with message */
        if (strcasecmp("eval", req.msg.c_str()) == 0) {
            /* e.g. data = 'LoadTestRun CMRosIF/AdaptiveCruiseControl; StartSim' */
            rv = GuiCmd_Eval(req.data.c_str());
        } else {
            if (strcasecmp("start", req.msg.c_str()) == 0) {
                if (req.data.length() == 0)
                    rv = GuiCmd_Eval("LoadTestRun CMRosIF/AdaptiveCruiseControl; StartSim");
                else {
                    sprintf(sbuf, "%s; StartSim", req.data.c_str());
                    rv = GuiCmd_Eval(sbuf);
                }
            }
            if (strcasecmp("stop", req.msg.c_str()) == 0)
                rv = GuiCmd_Eval("StopSim");
        }


        /* Commands directly to CarMaker Executable
         * - Warning:
         *   - Information normally provided by CarMaker GUI might be missing
         */
    } else if (strcasecmp("cmd", req.type.c_str()) == 0) {
        if (strcasecmp("start", req.msg.c_str()) == 0) {
            if (req.data.length() == 0) {
                /* Most strings are normally provided by CarMaker GUI */
                SimStart(NULL, CMNode.Cfg.Ros.Node->get_name(),
                        "CMRosIF/AdaptiveCruiseControl", NULL, NULL);
            } else {
                /* Most strings are normally provided by CarMaker GUI */
                SimStart(NULL, CMNode.Cfg.Ros.Node->get_name(),
                        req.data.c_str(), NULL, NULL);
            }
        }
        if (strcasecmp("stop", req.msg.c_str()) == 0)
            SimStop2(0);
        rv = 0;
    }

    resp.res = rv;
    return true;
}



/*****************************************************************************/
/**********          C-Code for interfacing with CarMaker!          **********/
/*****************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Get versions from shared library
 * - Set the returned Version to 0 if there is no dependency!
 * - Compatibility check should be done by calling procedure
 *   as early as possible(e.g. before CMRosIF_CMNode_Init()
 *
 * Arguments:
 * - CMRosIFVer = CMRosIF shared library version (User defined)
 *                - Initially filled with version of CMRosIF management library
 * - CMNumVer   = CarMaker version used for shared library at compile time (normally CM_NUMVER)
 *                - Initially filled with version of CMRosIF management library
 * - RosVersion = ROS version used for shared library at compile time (normally ROS_VERSION)
 *                - Initially filled with version requested by CMRosIF management library (0 if no request)
 *
 */
int
CMRosIF_CMNode_GetVersion (unsigned long *CMRosIFCMNodeNumVer,
                           unsigned long *CMNumVer,
                           unsigned long *RosNumVer)
{

    *CMRosIFCMNodeNumVer = CMNODE_NUMVER;
    *CMNumVer            = CM_NUMVER;
    *RosNumVer           = 2;

    return 0;
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Basic Initialization
 * - e.g. create ROS Node, subscriptions, ...
 * - Return values
 *   - "rv <  0" = Error at initialization, CarMaker executable will stop
 *   - "rv >= 0" = Everything OK, CarMaker executable will continue
 *
 * Arguments:
 * - Argc/Argv  = Arguments normally provided to ROS executable are not be provided
 *                to CM executable directly, but can be set in Infofile for CMRosIF
 *                with key "Node.Args" in "Data/Config/CMRosIFParameters"
 *
 * - CMNodeName = Default CarMaker Node name
 *                - Can be parameterized in Infofile for CMRosIF
 *                - Final node name might be different (argument remapping, ...)
 *
 * - Inf        = Handle to CarMaker Infofile with parameters for this interface
 *                - Please note that pointer may change, e.g. before TestRun begins
 *
 * ToDo:
 * - Possible to create/initialize node/... before each TestRun start instead of CM startup?
 * - New Param_Get() function to read parameters from Infofile
 */
int
CMRosIF_CMNode_Init (int Argc, char **Argv, char *CMNodeName, struct tInfos *Inf)
{

    int rv;
    bool rvb                = false;
    char sbuf[512]          = "";
    char keybuf[256]        = "";
    std::shared_ptr<rclcpp::Node> node = nullptr;

    HzControl.BeforeTime = 0;

    LOG("Initialize CarMaker ROS Node");
    LOG("  -> Node Version = %05d", CMNODE_NUMVER);
    LOG("  -> ROS Version  = %05d", 2);
    LOG("  -> CM Version   = %05d", CM_NUMVER);

    /* ROS initialization. Name of Node might be different after remapping! */
    rclcpp::init(Argc, Argv);

    /* Node specific */
    CMNode.Cfg.Ros.Node = std::make_shared<rclcpp::Node>(CMNodeName);
        node = CMNode.Cfg.Ros.Node;

        strcpy(sbuf, "hellocm/cycletime");
        CMNode.Cfg.Ros.Node->declare_parameter(sbuf);

    /* Publish specific */
    CMNode.Cfg.QueuePub  = iGetIntOpt(Inf, "Node.QueuePub", 1000); /* ToDo: Influence of queue length relevant? */

    /* Prepare the node to provide simulation time. CarMaker will be /clock server */
    strcpy(sbuf, "use_sim_time");

    if ((rv = node->has_parameter(sbuf)) == true) {
        node->get_parameter(sbuf, rvb);
        LOG("  -> Has param '%s' with value '%d'", sbuf, rvb);
    }

    /* Additional switch to provide simulation Time */
    strcpy(keybuf, "Node.UseSimTime");

    if ((rv = iGetIntOpt(Inf, keybuf, 1)) > 0) {
        /* Parameter must be set before other nodes start
        * - set parameter outside to be independent from execution order?
        */
        LOG("  -> Provide simulation time!");
        node->set_parameter(rclcpp::Parameter("use_sim_time", true));

        CMNode.Cfg.nCyclesClock  = iGetIntOpt(Inf, "Node.nCyclesClock", 1000);

        strcpy(sbuf, "/clock");
        LOG("    -> Publish '%s' every %dms", sbuf, CMNode.Cfg.nCyclesClock);
        CMNode.Topics.Pub.Clock.Pub = node->create_publisher<rosgraph_msgs::msg::Clock>(sbuf, CMNode.Cfg.QueuePub);

        /* ToDo: Necessary/Possible to ensure /clock is zeroed? */
        CMNode.Topics.Pub.Clock.Msg.clock = rclcpp::Clock().now();
        CMNode.Topics.Pub.Clock.Pub->publish(CMNode.Topics.Pub.Clock.Msg);
    } else {
        LOG("  -> Don't provide simulation time!");
        CMNode.Cfg.nCyclesClock  = 0;
    }

    strcpy(sbuf, hellocm::tpc_in_name.c_str() /*! Opposite in/out compared to external node */);
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.CM2Ext.Pub         = node->create_publisher<hellocm_msgs::msg::CM2Ext>(sbuf, CMNode.Cfg.QueuePub);
    CMNode.Topics.Pub.CM2Ext.Job         = CMCRJob_Create("CM2Ext");
    CMNode.Topics.Pub.CM2Ext.CycleTime   = 5000;
    CMNode.Topics.Pub.CM2Ext.CycleOffset = 0;
    /*
        strcpy(sbuf, "/pointcloud/vlp");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.Lidar_VLP.Pub          = node->create_publisher<sensor_msgs::msg::PointCloud>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
        CMNode.Topics.Pub.Lidar_VLP.Job          = CMCRJob_Create("pointcloud/vlp");
    */
        strcpy(sbuf, "/pointcloud/os1");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.Lidar_OS1.Pub          = node->create_publisher<sensor_msgs::msg::PointCloud>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
        CMNode.Topics.Pub.Lidar_OS1.Job          = CMCRJob_Create("pointcloud/os1");

    strcpy(sbuf, "/gps_out");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.GPSOut.Pub           = node->create_publisher<hellocm_msgs::msg::GPSOut>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.GPSOut.Job           = CMCRJob_Create("gps_out");
        CMNode.Topics.Pub.GPSOut2.Pub           = node->create_publisher<std_msgs::msg::Float64MultiArray>("/carmaker/gps_out2", static_cast<uint>(CMNode.Cfg.QueuePub));
        CMNode.Topics.Pub.GPSOut2.Job           = CMCRJob_Create("gps_out2");

    strcpy(sbuf, "/imu_out");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.IMUOut.Pub           = node->create_publisher<hellocm_msgs::msg::IMUOut>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.IMUOut.Job           = CMCRJob_Create("imu_out");
        CMNode.Topics.Pub.IMUOut2.Pub           = node->create_publisher<std_msgs::msg::Float64MultiArray>("/carmaker/imu_out2", static_cast<uint>(CMNode.Cfg.QueuePub));
        CMNode.Topics.Pub.IMUOut2.Job           = CMCRJob_Create("imu_out2");

    strcpy(sbuf, "/vehicle_info_out");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.VehicleInfoOut.Pub   = node->create_publisher<hellocm_msgs::msg::VehicleInfoOut>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.VehicleInfoOut.Job   = CMCRJob_Create("vehicle_info_out");
        CMNode.Topics.Pub.VehicleInfoOut2.Pub   = node->create_publisher<std_msgs::msg::Float64MultiArray>("/carmaker/vehicle_info_out2", static_cast<uint>(CMNode.Cfg.QueuePub));
        CMNode.Topics.Pub.VehicleInfoOut2.Job   = CMCRJob_Create("vehicle_info_out2");

    strcpy(sbuf, "/objectinfo_out");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.ObjectInfoOut.Pub       = node->create_publisher<hellocm_msgs::msg::ObjectInfoOut>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.ObjectInfoOut.Job       = CMCRJob_Create("objectinfo_out");
        CMNode.Topics.Pub.ObjectInfoOut2.Pub       = node->create_publisher<std_msgs::msg::Float64MultiArray>("/carmaker/object_info_out2", static_cast<uint>(CMNode.Cfg.QueuePub));
        CMNode.Topics.Pub.ObjectInfoOut2.Job       = CMCRJob_Create("objectinfo_out2");

    strcpy(sbuf, "/pointcloud/os1_pc2");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.Lidar_OS1_PC2.Pub     = node->create_publisher<sensor_msgs::msg::PointCloud2>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.Lidar_OS1_PC2.Job     = CMCRJob_Create("pointcloud/os1_pc2");

    strcpy(sbuf, "/Lane/Left0");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.LeftLane[0].Pub         = node->create_publisher<nav_msgs::msg::Path>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.LeftLane[0].Job         = CMCRJob_Create("Lane/Left0");

        strcpy(sbuf, "/Lane/Left1");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.LeftLane[1].Pub         = node->create_publisher<nav_msgs::msg::Path>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.LeftLane[1].Job         = CMCRJob_Create("Lane/Left1");

    strcpy(sbuf, "/Lane/Right0");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.RightLane[0].Pub         = node->create_publisher<nav_msgs::msg::Path>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.RightLane[0].Job         = CMCRJob_Create("Lane/Right0");

        strcpy(sbuf, "/Lane/Right1");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.RightLane[1].Pub         = node->create_publisher<nav_msgs::msg::Path>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.RightLane[1].Job         = CMCRJob_Create("Lane/Right1");


    /*
        strcpy(sbuf, "/ObjectList");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.ObjectList.Pub         = node->create_publisher<visualization_msgs::msg::MarkerArray>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.ObjectList.Job         = CMCRJob_Create("ObjectList");

    strcpy(sbuf, "/LeftLane");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.LeftLane.Pub           = node->create_publisher<nav_msgs::msg::Path>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.LeftLane.Job           = CMCRJob_Create("LeftLane");

    strcpy(sbuf, "/RightLane");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.RightLane.Pub          = node->create_publisher<nav_msgs::msg::Path>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.RightLane.Job          = CMCRJob_Create("RightLane");

    strcpy(sbuf, "/Odometry");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.Odometry.Pub           = node->create_publisher<nav_msgs::msg::Odometry>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.Odometry.Job           = CMCRJob_Create("Odometry");
    CMNode.Topics.Pub.Odometry.CycleTime     = 50;
    CMNode.Topics.Pub.Odometry.CycleOffset   = 0;

    strcpy(sbuf, "/EgoVehicle");
    LOG("  -> Publish '%s'", sbuf);
    CMNode.Topics.Pub.EgoVehicle.Pub         = node->create_publisher<visualization_msgs::msg::MarkerArray>(sbuf, static_cast<uint>(CMNode.Cfg.QueuePub));
    CMNode.Topics.Pub.EgoVehicle.Job         = CMCRJob_Create("EgoVehicle");
    CMNode.Topics.Pub.EgoVehicle.CycleTime   = 50;
    CMNode.Topics.Pub.EgoVehicle.CycleOffset = 0;
        */

        CMNode.TF.br = std::make_shared<tf2_ros::TransformBroadcaster>(node);
    CMNode.TF.st_br = std::make_shared<tf2_ros::StaticTransformBroadcaster>(node);


    /* Subscribe specific */
    CMNode.Cfg.QueueSub  = iGetIntOpt(Inf, "Node.QueueSub", 1); /* ToDo: Effect of queue length for subscriber? */


    strcpy(sbuf, hellocm::tpc_out_name.c_str() /*! Opposite in/out compared to external node */);
    LOG("  -> Subscribe '%s'", sbuf);
    CMNode.Topics.Sub.Ext2CM.Sub         = node->create_subscription<hellocm_msgs::msg::Ext2CM>(sbuf, CMNode.Cfg.QueueSub, cmnode_HelloCM_CB_TpcIn);
    CMNode.Topics.Sub.Ext2CM.Job         = CMCRJob_Create("Ext2CM_for_Sync");

    /* In this example cycle time might be updated with value of external ROS Node
     * - See CMRosIF_CMNode_TestRun_Start_atBegin() */
    CMNode.Topics.Sub.Ext2CM.CycleTime   = 15000;

    // LOG("  -> Subscribe '%s'", "ctrl_cmd");
    // CMNode.Topics.Sub.VehicleControlIn.Sub         = node->subscribe("ctrl_cmd", CMNode.Cfg.QueueSub, cmnode_VehicleControlIn_TpcIn);
    CMNode.Topics.Sub.VehicleControlIn.Sub         = node->create_subscription<std_msgs::msg::Float64MultiArray>("/control/vehicle_control", CMNode.Cfg.QueueSub, cmnode_VehicleControlIn_TpcIn);
    CMNode.Topics.Sub.VehicleControlIn.Job         = CMCRJob_Create("vehicle_control_for_Sync");

    CMNode.Topics.Sub.SaveCustom.Sub         = node->create_subscription<std_msgs::msg::Float64MultiArray>("/control/cm_save_custom", CMNode.Cfg.QueueSub, cmnode_SaveCustomIn_TpcIn);
    CMNode.Topics.Sub.SaveCustom.Job         = CMCRJob_Create("save_custom");
    CMNode.Topics.Sub.SaveCustom.CycleTime   = 50;

    // In this example cycle time might be updated with value of external ROS Node
    // * - See CMRosIF_CMNode_TestRun_Start_atBegin()
    CMNode.Topics.Sub.VehicleControlIn.CycleTime   = 50;

    CMNode.Topics.Sub.SignalLightIn.Sub = node->create_subscription<std_msgs::msg::Float64MultiArray>("signal_light", CMNode.Cfg.QueueSub, cmnode_SignalLightIn_TpcIn);

    /* Services */
    strcpy(sbuf, hellocm::srv_init_name.c_str());
    LOG("  -> Service Client '%s'", sbuf);
    CMNode.Services.Init.Clnt = node->create_client<hellocm_msgs::srv::Init>(sbuf);


    strcpy(sbuf, "CMRemote");
    LOG("  -> Create Service '%s'", sbuf);
    // TODO
    // CMNode.Services.CMRemote.Srv = node->advertiseService(
    //         sbuf, cmnode_HelloCM_CB_SrvCMRemote);


    /* Print general information after everything is done */
    LOG("Initialization of ROS Node finished!");
    LOG("  -> Node Name = '%s'", CMNode.Cfg.Ros.Node->get_name());
    LOG("  -> Namespace = '%s'", CMNode.Cfg.Ros.Node->get_namespace());


        std::map<std::string, std::vector<std::string>> names;
        names = node->get_topic_names_and_types();

        LOG("    -> Connected Topics (%lu)", names.size());
        auto it = names.begin();
        for (; it != names.end(); ++it)
        LOG("    -> %s", it->first.c_str());
        names.clear();

    return 1;
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Add user specific Quantities for data storage
 *   and visualization to DataDictionary
 * - Called once at program start
 * - no realtime conditions
 *
 */
void
CMRosIF_CMNode_DeclQuants (void)
{

    tDDefault *df = DDefaultCreate("CMRosIF.");

    DDefULong   (df, "CycleNoRel",         "ms", &CMNode.CycleNoRel,               DVA_None);
    DDefInt     (df, "Sync.Cycles",        "-",  &CMNode.Sync.nCycles,             DVA_None);
    DDefDouble  (df, "Sync.Time",          "s",  &CMNode.Sync.Duration,            DVA_None);
    DDefInt     (df, "Sync.CyclePrepDone", "-",  &CMNode.Sync.CyclePrepDone,       DVA_None);
    DDefInt     (df, "Sync.CycleJobDone" , "-",  &CMNode.Sync.CycleJobDone,        DVA_None);
    DDefDouble4 (df, "Sync.SynthDelay",     "s", &CMNode.Sync.SynthDelay,          DVA_IO_In);

    DDefUChar   (df, "Cfg.Mode",           "-",  (unsigned char*)&CMNode.Cfg.Mode, DVA_None);
    DDefInt     (df, "Cfg.nCyclesClock",   "ms", &CMNode.Cfg.nCyclesClock,         DVA_None);
    DDefChar    (df, "Cfg.SyncMode",       "-",  (char*)&CMNode.Cfg.SyncMode,      DVA_None);
    DDefDouble4 (df, "Cfg.SyncTimeMax",    "s",  &CMNode.Cfg.SyncTimeMax,          DVA_IO_In);

    DDefInt     (df, "Mdl.CycleNo",        "-",  &CMNode.Model.CycleNo,            DVA_None);
    DDefInt     (df, "Mdl.CycleLastOut",   "ms", &CMNode.Model.CycleLastOut,       DVA_None);
    DDefInt     (df, "Mdl.CycleLastIn",    "ms", &CMNode.Model.CycleLastIn,        DVA_None);
    DDefInt     (df, "Mdl.CycleLastFlush", "ms", &CMNode.Model.CycleLastFlush,     DVA_None);

    DDefInt     (df, "TY.Debugging",       "ms", &CMNode.TY_Debugging,             DVA_None);

    DDefaultDelete(df);
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called when starting a new TestRun
 * - In separate Thread (no realtime conditions)
 * - After standard Infofiles are read in
 * - Return values
 *   - "rv <  0" = Error, TestRun start will be aborted
 *   - "rv >= 0" = Everything OK
 *
 * Arguments:
 * - Inf = CarMaker Infofile for CMRosIF with content after TestRun start
 *         - Please note that the Infofile provided at initialization might have been updated!
 *
 * ToDo:
 * - New Param_Get() function to read parameters from Infofile
 *
 */
int
CMRosIF_CMNode_TestRun_Start_atBegin (struct tInfos *Inf)
{
        srand(time(NULL));

        Lidar_CycleCount = 0;

        tInfos *Inf_Sensor = nullptr;
    tErrorMsg *err = nullptr;

    /*
    //Create infofile handle
    Inf_Sensor = InfoNew();
    iRead2(&err, Inf_Sensor, "Data/Sensor/LidarRSI_VLP_16", "");
    CMNode.LidarRSI_VLP.BeamTable = (double*) malloc(VLP_16_NUMBER_OF_POINTS * 6 * sizeof(double));
    //Read infofile parameters
    iGetTableOpt(Inf_Sensor, "Beams", CMNode.LidarRSI_VLP.BeamTable, VLP_16_NUMBER_OF_POINTS * 6, 6, &CMNode.LidarRSI_VLP.rows);
        InfoDelete(Inf_Sensor);
        */

        //Create infofile handle
    Inf_Sensor = InfoNew();
    iRead2(&err, Inf_Sensor, "Data/Sensor/LidarRSI_OS1_64", "");
    CMNode.LidarRSI_OS1.BeamTable = (double*) malloc(OS1_64_NUMBER_OF_POINTS * 6 * sizeof(double));
        //Read infofile parameters
    iGetTableOpt(Inf_Sensor, "Beams", CMNode.LidarRSI_OS1.BeamTable, OS1_64_NUMBER_OF_POINTS * 6, 6, &CMNode.LidarRSI_OS1.rows);
        InfoDelete(Inf_Sensor);

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //Read sensor info from Vehicle InfoFile
    tInfos *Inf_Vehicle = nullptr;
    Inf_Vehicle = InfoNew();

    const char *FName;
    FName = InfoGetFilename(SimCore.Vhcl.Inf);

    Log("FName = %s\n", FName);

    int VehicleInfo_Err = iRead2(&err, Inf_Vehicle, FName, "SensorReadCode");

    if (VehicleInfo_Err == 0) {

        tf2::Quaternion q;
        double* position;
        double* rotation;
                double tmp[3] = {0, 0, 0};

        /*
                //Lidar Sensor
                position = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.LidarRSI.0.pos", tmp, 3, 1);
                rotation = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.LidarRSI.0.rot", tmp, 3, 1);
                q.setRPY(rotation[0], rotation[1], rotation[2]);
        CMNode.TF.Lidar_VLP.transform.rotation = tf2::toMsg(q);
                CMNode.TF.Lidar_VLP.transform.translation.x = position[0];
                CMNode.TF.Lidar_VLP.transform.translation.y = position[1];
                CMNode.TF.Lidar_VLP.transform.translation.z = position[2];
                CMNode.TF.Lidar_VLP.child_frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.LidarRSI.0.name", "LIR00");
        CMNode.TF.Lidar_VLP.header.frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.LidarRSI.0.Mounting", "Fr1A");
        CMNode.Topics.Pub.Lidar_VLP.CycleTime = iGetIntOpt(Inf_Vehicle, "Sensor.LidarRSI.0.CycleTime", 100);
        CMNode.Topics.Pub.Lidar_VLP.CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.LidarRSI.0.nCycleOffset", 0);

                //Lidar Sensor
        position = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.LidarRSI.1.pos", tmp, 3, 1);
                rotation = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.LidarRSI.1.rot", tmp, 3, 1);
                q.setRPY(rotation[0], rotation[1], rotation[2]);
        CMNode.TF.Lidar_OS1.transform.rotation = tf2::toMsg(q);
                CMNode.TF.Lidar_OS1.transform.translation.x = position[0];
                CMNode.TF.Lidar_OS1.transform.translation.y = position[1];
                CMNode.TF.Lidar_OS1.transform.translation.z = position[2];
                CMNode.TF.Lidar_OS1.child_frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.LidarRSI.1.name", "LIR01");
        CMNode.TF.Lidar_OS1.header.frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.LidarRSI.1.Mounting", "Fr1A");
        CMNode.Topics.Pub.Lidar_OS1.CycleTime = iGetIntOpt(Inf_Vehicle, "Sensor.LidarRSI.1.CycleTime", 100);
        CMNode.Topics.Pub.Lidar_OS1.CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.LidarRSI.1.nCycleOffset", 0);

                //Object Sensor
        position = iGetFixedTable2(Inf_Vehicle, "Sensor.Object.0.pos", 3, 1);
        rotation = iGetFixedTable2(Inf_Vehicle, "Sensor.Object.0.rot", 3, 1);
        q.setRPY(rotation[0], rotation[1], rotation[2]);
        CMNode.TF.Object.transform.rotation = tf2::toMsg(q);
        CMNode.TF.Object.transform.translation.x = position[0];
                CMNode.TF.Object.transform.translation.y = position[1];
                CMNode.TF.Object.transform.translation.z = position[2];
        CMNode.TF.Object.child_frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.Object.0.name", "OB00");
        CMNode.TF.Object.header.frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.Object.0.Mounting", "Fr1A");
        CMNode.Topics.Pub.ObjectList.CycleTime = 1000 / iGetIntOpt(Inf_Vehicle, "Sensor.Object.0.UpdRate", 100);
        CMNode.Topics.Pub.ObjectList.CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.Object.0.nCycleOffset", 0);

                //Line Sensor
        position = iGetFixedTable2(Inf_Vehicle, "Sensor.Line.0.pos", 3, 1);
        rotation = iGetFixedTable2(Inf_Vehicle, "Sensor.Line.0.rot", 3, 1);
        q.setRPY(rotation[0], rotation[1], rotation[2]);
        CMNode.TF.Line.transform.rotation = tf2::toMsg(q);
        CMNode.TF.Line.transform.translation.x = position[0];
                CMNode.TF.Line.transform.translation.y = position[1];
                CMNode.TF.Line.transform.translation.z = position[2];
        CMNode.TF.Line.child_frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.Line.0.name", "LIN00");
        CMNode.TF.Line.header.frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.Line.0.Mounting", "Fr1A");
        CMNode.Topics.Pub.LeftLane.CycleTime = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.Line.0.UpdRate", 100);
        CMNode.Topics.Pub.LeftLane.CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.Line.0.nCycleOffset", 0);
        CMNode.Topics.Pub.RightLane.CycleTime = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.Line.0.UpdRate", 100);
        CMNode.Topics.Pub.RightLane.CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.Line.0.nCycleOffset", 0);
                */

        //Lidar Sensor
        position = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.LidarRSI.0.pos", tmp, 3, 1);
                rotation = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.LidarRSI.0.rot", tmp, 3, 1);
                q.setRPY(rotation[0], rotation[1], rotation[2]);
        CMNode.TF.Lidar_OS1.transform.rotation = tf2::toMsg(q);
        CMNode.TF.Lidar_OS1.transform.translation.x = position[0];
                CMNode.TF.Lidar_OS1.transform.translation.y = position[1];
                CMNode.TF.Lidar_OS1.transform.translation.z = position[2];
        // CMNode.TF.Lidar_OS1.transform.translation = tf2::toMsg(tf2::Vector3(position[0], position[1], position[2]));
        CMNode.TF.Lidar_OS1.child_frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.LidarRSI.0.name", "LIR01");
        CMNode.TF.Lidar_OS1.header.frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.LidarRSI.0.Mounting", "Fr1A");
        CMNode.Topics.Pub.Lidar_OS1.CycleTime = iGetIntOpt(Inf_Vehicle, "Sensor.LidarRSI.0.CycleTime", 100);
        CMNode.Topics.Pub.Lidar_OS1.CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.LidarRSI.0.nCycleOffset", 0);

        position = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.LidarRSI.0.pos", tmp, 3, 1);
                rotation = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.LidarRSI.0.rot", tmp, 3, 1);
                q.setRPY(rotation[0], rotation[1], rotation[2]);
        CMNode.TF.Lidar_OS1_PC2.transform.rotation = tf2::toMsg(q);
        CMNode.TF.Lidar_OS1_PC2.transform.translation.x = position[0];
                CMNode.TF.Lidar_OS1_PC2.transform.translation.y = position[1];
                CMNode.TF.Lidar_OS1_PC2.transform.translation.z = position[2];
        // CMNode.TF.Lidar_OS1_PC2.transform.translation = tf2::toMsg(tf2::Vector3(position[0], position[1], position[2]));
        CMNode.TF.Lidar_OS1_PC2.child_frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.LidarRSI.0.name", "LIR01");
        CMNode.TF.Lidar_OS1_PC2.header.frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.LidarRSI.0.Mounting", "Fr1A");
        CMNode.Topics.Pub.Lidar_OS1_PC2.CycleTime = iGetIntOpt(Inf_Vehicle, "Sensor.LidarRSI.0.CycleTime", 100);
        CMNode.Topics.Pub.Lidar_OS1_PC2.CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.LidarRSI.0.nCycleOffset", 0);

                //Line Sensor
        position = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.Line.0.pos", tmp, 3, 1);
        rotation = iGetFixedTableOpt2(Inf_Vehicle, "Sensor.Line.0.rot", tmp, 3, 1);
        q.setRPY(rotation[0], rotation[1], rotation[2]);
        CMNode.TF.Line.transform.rotation = tf2::toMsg(q);
        CMNode.TF.Line.transform.translation.x = position[0];
        CMNode.TF.Line.transform.translation.y = position[1];
        CMNode.TF.Line.transform.translation.z = position[2];
        CMNode.TF.Line.child_frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.Line.0.name", "LIN00");
        CMNode.TF.Line.header.frame_id = iGetStrOpt(Inf_Vehicle, "Sensor.Line.0.Mounting", "Fr1A");
        CMNode.Topics.Pub.LeftLane[0].CycleTime = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.Line.0.UpdRate", 25);
        CMNode.Topics.Pub.LeftLane[0].CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.Line.0.nCycleOffset", 0);
        CMNode.Topics.Pub.LeftLane[1].CycleTime = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.Line.0.UpdRate", 25);
        CMNode.Topics.Pub.LeftLane[1].CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.Line.0.nCycleOffset", 0);
        CMNode.Topics.Pub.RightLane[0].CycleTime = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.Line.0.UpdRate", 25);
        CMNode.Topics.Pub.RightLane[0].CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.Line.0.nCycleOffset", 0);
                CMNode.Topics.Pub.RightLane[1].CycleTime = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.Line.0.UpdRate", 25);
        CMNode.Topics.Pub.RightLane[1].CycleOffset = iGetIntOpt(Inf_Vehicle, "Sensor.Line.0.nCycleOffset", 0);

        //GNSS
        CMNode.Topics.Pub.GPSOut.CycleTime     = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.GNav.UpdRate", 30);
        CMNode.Topics.Pub.GPSOut.CycleOffset   = iGetIntOpt(Inf_Vehicle, "Sensor.GNav.nCycleOffset", 0);

        // Object (thk)
        CMNode.Topics.Pub.ObjectInfoOut.CycleTime     = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.Object.UpdRate", 30);
        CMNode.Topics.Pub.ObjectInfoOut.CycleOffset   = iGetIntOpt(Inf_Vehicle, "Sensor.Object.nCycleOffset", 0);

        // SAVE_AN
        CMNode.Topics.Pub.IMUOut.CycleTime     = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.Inertial.UpdRate", 30);
        CMNode.Topics.Pub.IMUOut.CycleOffset   = iGetIntOpt(Inf_Vehicle, "Sensor.Inertial.nCycleOffset", 0);

        CMNode.Topics.Pub.VehicleInfoOut.CycleTime     = 1000 / iGetDblOpt(Inf_Vehicle, "Sensor.Inertial.UpdRate", 30);
        CMNode.Topics.Pub.VehicleInfoOut.CycleOffset   = iGetIntOpt(Inf_Vehicle, "Sensor.Inertial.nCycleOffset", 0);
    }

    int errCode = InfoDelete(Inf_Vehicle);
    Log("errCode = %d\n", errCode);


    /* Node can be disabled via Infofile */
    tCMNode_Mode     *pmode     = &CMNode.Cfg.Mode;
    tCMNode_SyncMode *psyncmode = &CMNode.Cfg.SyncMode;

    if (Inf != NULL) {
        *pmode     =     (tCMNode_Mode)iGetIntOpt(Inf, "Node.Mode",      CMNode_Mode_Disabled);
        *psyncmode = (tCMNode_SyncMode)iGetIntOpt(Inf, "Node.Sync.Mode", CMNode_SyncMode_Disabled);
    }

    if (SimCore.CycleNo == 0 || Inf == NULL || *pmode == CMNode_Mode_Disabled) {
        *pmode = CMNode_Mode_Disabled;
        LOG("CarMaker ROS Node is disabled!");
        return 0;
    }

    char sbuf[512];
    char key[256];
    char *str        = NULL;
    int rv           = 0;
    bool rvb                = false;

    int cycletime           = 0;
    int *pcycletime         = NULL;
    int cycleoff            = 0;
    tCMCRJob *job           = NULL;
    auto srv         = &CMNode.Services.Init;

    LOG("CarMaker ROS Node is enabled! Mode=%d, SyncMode=%d", *pmode, *psyncmode);
    LOG("  -> Node Name = %s", CMNode.Cfg.Ros.Node->get_name());


    /* Update synchronization */
    if (*psyncmode != CMNode_SyncMode_Disabled && *psyncmode != CMNode_SyncMode_Tpc) {
        LogErrF(EC_Sim, "CMNode: Invalid synchronization mode '%d'!",*psyncmode);
        *pmode = CMNode_Mode_Disabled;
        return -1;
    }

    CMNode.Cfg.SyncTimeMax = iGetDblOpt(Inf, "Node.Sync.TimeMax", 1.0);


    /* Reset for next cycle */
    CMNode.CycleNoRel           =  0;
    CMNode.Sync.Duration        =  0.0;
    CMNode.Sync.nCycles         = -1;
    CMNode.Sync.CycleJobDone    = -1;
    CMNode.Sync.CyclePrepDone   = -1;
    CMNode.Model.CycleNo        = -1;
    CMNode.Model.CycleLastIn    = -1;
    CMNode.Model.CycleLastOut   = -1;
    CMNode.Model.CycleLastFlush = -1;


    /* Allow an update of the clock only if it was enabled before! */
    if (CMNode.Cfg.nCyclesClock > 0) {
        if ((rv = iGetIntOpt(Inf, "Node.nCyclesClock", 1000)) > 0)
            CMNode.Cfg.nCyclesClock = rv;
    }

    /* Necessary to ensure /clock is zeroed here?
     * ToDo: Create function? */
    if (CMNode.Cfg.nCyclesClock > 0) {
        LOG("  -> Publish /clock every %dms", CMNode.Cfg.nCyclesClock);
        CMNode.Topics.Pub.Clock.Msg.clock = rclcpp::Time(0.0);
        CMNode.Topics.Pub.Clock.Pub->publish(CMNode.Topics.Pub.Clock.Msg);
    }


        ///* Prepare external node for next simulation */
    if (!srv->Clnt->service_is_ready()) {
        // ToDo: possible to get update if external ROS Node name changes?
        LogErrF(EC_Sim, "ROS Service is not ready! Please start external ROS Node providing Service '%s'!",
            srv->Clnt->get_service_name());
        *pmode = CMNode_Mode_Disabled;
        return -1;
    }

    LOG("  -> Send Service Request");

    ///* ToDo: Async?*/
    auto request = std::make_shared<hellocm_msgs::srv::Init::Request>();

        auto future_result = srv->Clnt->async_send_request(request);
        if(!srv->Clnt->wait_for_service(std::chrono::seconds(1))) {
        LogErrF(EC_Sim, "ROS Service error!");
        *pmode = CMNode_Mode_Disabled;
        return -1;
        }

    /* Update cycle time with information of external node */
#if 1
    /* Variant 1:
     * - Receiving parameters via ROS Parameter Server
     * - Parameter may be set externally e.g. by other node or arguments to command
     * - ROS parameters are more flexible than ROS services!
     */
    strcpy(sbuf, "hellocm/cycletime");
        CMNode.Cfg.Ros.Node->set_parameter(rclcpp::Parameter(sbuf, future_result.get()->cycletime));
        if ((rv = CMNode.Cfg.Ros.Node->has_parameter(sbuf)) == true)
        CMNode.Cfg.Ros.Node->get_parameter(sbuf, rv);

#else
    /* Variant 2:
     * - Receiving parameters from external Node via Service
     * - Services might be too "static"
     * - Not recommended!
     */
    rv = srv->Msg.response.cycletime;
#endif

    pcycletime = &CMNode.Topics.Sub.Ext2CM.CycleTime;

    if (*pcycletime != rv) {
        LOG("  -> Cycle time of external node changed from %dms to %dms", *pcycletime, rv);
        *pcycletime = rv;
    }

    /* Plausibility check for Cycle Time */
    if (CMNode.Cfg.nCyclesClock > 0 && (*pcycletime < CMNode.Cfg.nCyclesClock
            || *pcycletime%CMNode.Cfg.nCyclesClock != 0)) {

        LogErrF(EC_Sim, "Ext. ROS Node has invalid cycle time! Expected multiple of %dms but got %dms",
            CMNode.Cfg.nCyclesClock, *pcycletime);

        *pmode = CMNode_Mode_Disabled;
        return -1;
    }



    /* Prepare Jobs for publish and subscribe
     * - Special use case:
     *   - Topic in and Topic out use same cycle time with relative shift!
     */

    /* Start to publish when simulation starts */
    job       = CMNode.Topics.Pub.CM2Ext.Job;
    cycletime = CMNode.Topics.Pub.CM2Ext.CycleTime;
    cycleoff  = CMNode.Topics.Pub.CM2Ext.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Default);
    /*
        job       = CMNode.Topics.Pub.Lidar_VLP.Job;
    cycletime = CMNode.Topics.Pub.Lidar_VLP.CycleTime;
    cycleoff  = CMNode.Topics.Pub.Lidar_VLP.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);
        */

        job       = CMNode.Topics.Pub.Lidar_OS1.Job;
    cycletime = CMNode.Topics.Pub.Lidar_OS1.CycleTime;
    cycleoff  = CMNode.Topics.Pub.Lidar_OS1.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);


    job       = CMNode.Topics.Pub.Lidar_OS1_PC2.Job;
    cycletime = CMNode.Topics.Pub.Lidar_OS1_PC2.CycleTime;
    cycleoff  = CMNode.Topics.Pub.Lidar_OS1_PC2.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);


    job       = CMNode.Topics.Pub.GPSOut.Job;
    cycletime = CMNode.Topics.Pub.GPSOut.CycleTime;
    cycleoff  = CMNode.Topics.Pub.GPSOut.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

    /*
        job       = CMNode.Topics.Pub.ObjectList.Job;
    cycletime = CMNode.Topics.Pub.ObjectList.CycleTime;
    cycleoff  = CMNode.Topics.Pub.ObjectList.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

    job       = CMNode.Topics.Pub.LeftLane.Job;
    cycletime = CMNode.Topics.Pub.LeftLane.CycleTime;
    cycleoff  = CMNode.Topics.Pub.LeftLane.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

    job       = CMNode.Topics.Pub.RightLane.Job;
    cycletime = CMNode.Topics.Pub.RightLane.CycleTime;
    cycleoff  = CMNode.Topics.Pub.RightLane.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

    job       = CMNode.Topics.Pub.Odometry.Job;
    cycletime = CMNode.Topics.Pub.Odometry.CycleTime;
    cycleoff  = CMNode.Topics.Pub.Odometry.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

    job       = CMNode.Topics.Pub.EgoVehicle.Job;
    cycletime = CMNode.Topics.Pub.EgoVehicle.CycleTime;
    cycleoff  = CMNode.Topics.Pub.EgoVehicle.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);
        */

    // SAVE_AN
        job       = CMNode.Topics.Pub.IMUOut.Job;
        cycletime = CMNode.Topics.Pub.IMUOut.CycleTime;
        cycleoff  = CMNode.Topics.Pub.IMUOut.CycleOffset;

        CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

        job       = CMNode.Topics.Pub.VehicleInfoOut.Job;
        cycletime = CMNode.Topics.Pub.VehicleInfoOut.CycleTime;
        cycleoff  = CMNode.Topics.Pub.VehicleInfoOut.CycleOffset;

        CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);


        job       = CMNode.Topics.Pub.LeftLane[0].Job;
    cycletime = CMNode.Topics.Pub.LeftLane[0].CycleTime;
    cycleoff  = CMNode.Topics.Pub.LeftLane[0].CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

        job       = CMNode.Topics.Pub.LeftLane[1].Job;
    cycletime = CMNode.Topics.Pub.LeftLane[1].CycleTime;
    cycleoff  = CMNode.Topics.Pub.LeftLane[1].CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

    job       = CMNode.Topics.Pub.RightLane[0].Job;
    cycletime = CMNode.Topics.Pub.RightLane[0].CycleTime;
    cycleoff  = CMNode.Topics.Pub.RightLane[0].CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

    job       = CMNode.Topics.Pub.RightLane[1].Job;
    cycletime = CMNode.Topics.Pub.RightLane[1].CycleTime;
    cycleoff  = CMNode.Topics.Pub.RightLane[1].CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

    job       = CMNode.Topics.Pub.ObjectInfoOut.Job;
    cycletime = CMNode.Topics.Pub.ObjectInfoOut.CycleTime;
    cycleoff  = CMNode.Topics.Pub.ObjectInfoOut.CycleOffset;

    CMCRJob_Init(job, cycleoff, cycletime, CMCRJob_Mode_Ext);

    /* Synchronization with external node
     * - external node provides cycle time (see service above)
     * - other parameterization methods (e.g. ROS parameter, ...) are possible!
     * - Expect sync Topic are delayed (communication time, ...)
     * - This example shows sync via ROS Timer in external node
     *   - Therefore "/clock" topic needs to be published by CarMaker!
     *   - Other mechanism, e.g. data triggered on external node side
     *     via publishing Topic directly inside subscription callback is also possible!
     * - time=0.0 can't be detected by external node, therefore
     *   first receive needs to start after expected cycle time
     *   of external ROS node
     */

    job       = CMNode.Topics.Sub.Ext2CM.Job;
    cycletime = CMNode.Topics.Sub.Ext2CM.CycleTime;
    cycleoff  = CMNode.Topics.Sub.Ext2CM.CycleOffset = 0; /* No offset allowed if ROS Timer is used for sync!*/


    /* Create the synchronization jobs */
    if (*psyncmode == CMNode_SyncMode_Tpc) {
        CMCRJob_Init(job, cycletime+1 , cycletime, CMCRJob_Mode_Ext);

        LOG("  -> Synchronize on Topic '%s' (cycletime=%d, cycleoff=%d)",
            CMNode.Topics.Sub.Ext2CM.Sub->get_topic_name(), cycletime, cycleoff);

    } else
            CMCRJob_Init(job, cycletime + 1 , cycletime, CMCRJob_Mode_Default);

        std::vector<geometry_msgs::msg::TransformStamped> transforms;
        transforms.push_back(CMNode.TF.Lidar_VLP);
        transforms.push_back(CMNode.TF.Lidar_OS1);
    transforms.push_back(CMNode.TF.Line);
    CMNode.TF.st_br->sendTransform(transforms);


    LOG("External ROS Node is ready to simulate");

    return 1;
}



/*!
 * ToDo:
 * - Put everything to TestRun_Start_atBegin?
 *
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Repeating call for several CarMaker cycles until return value is 1
 * - May be called even previous return value was 1
 * - See "User.c:User_TestRun_RampUp()"
 *
 */
int
CMRosIF_CMNode_TestRun_RampUp (void)
{

    /* Return immediately if node is disabled */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled)
        return 1;

    /* Put your code here */
    //if (NotReady) return 0;


    return 1;
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called when TestRun ends (no realtime conditions)
 * - See "User.c:User_TestRun_End()"
 *
 */
int
CMRosIF_CMNode_TestRun_End (void)
{


    /* Put your code here */

    /* Disable after simulation has finished */
    CMNode.Cfg.Mode = CMNode_Mode_Disabled;

    return 1;
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called at very beginning of CarMaker cycle
 * - Process all topics/services using different modes or synchronization modes
 * - See "User.c:User_In()"
 *
 * ToDo:
 * - Additional spin mechanism
 *   - e.g. for HIL
 *   - e.g. spinning in new thread, copying incoming data here, ...
 *
 */
int
CMRosIF_CMNode_In (void)
{

    int rv                   = 0;
    int rx_done              = 0;
    const char *job_name     = NULL;
    tCMCRJob *job            = NULL;
    auto tStart = rclcpp::Clock().now();
    rclcpp::Duration tDelta = rclcpp::Duration(0.0);
    CMNode.Sync.nCycles      = 0;
    CMNode.Sync.Duration     = 0.0;

    switch (CMNode.Cfg.Mode) {
        case CMNode_Mode_Disabled:
            /* Comment next line if no messages/services
             * shall be processed in disabled Node state
             */
            rclcpp::spin_some(CMNode.Cfg.Ros.Node);
                break;

        case CMNode_Mode_Default:

            if (CMNode.Cfg.SyncMode != CMNode_SyncMode_Tpc) {
            /* Process messages in queue, but do not block */
                    rclcpp::spin_some(CMNode.Cfg.Ros.Node);
            } else {
            /* Synchronization based on expected Topics
            * - Blocking call (process publish and wait for answer)
            * - Stop simulation if maximum time is exceeded
            */
            do {
                rclcpp::spin_some(CMNode.Cfg.Ros.Node);

                /* Only do anything if simulation is running */
                if (SimCore.State != SCState_Simulate) {
                    rx_done = 1;
                    break;
                }

                rx_done = 0;

                /* Check all jobs if preparation is done */
                job      = CMNode.Topics.Sub.Ext2CM.Job;

                if ((rv = CMCRJob_DoPrep(job, CMNode.CycleNoRel, 0, NULL, NULL)) < CMCRJob_RV_OK) {
                    LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s",CMCRJob_GetName(job), CMCRJob_RVStr(rv));
                    rx_done = 0;
                    break;
                }

                /* If job is not done, remember name and prevent loop to finish */
                job_name = (rv != CMCRJob_RV_DoSomething ? NULL : CMCRJob_GetName(job));
                rx_done  = rv == CMCRJob_RV_DoNothing ? 1 : 0;

                if (rx_done == 1)
                    break;

                /* Wait a little that data can arrive. WallTime, NOT ROS time!!!*/
                rclcpp::WallRate(0.0).sleep();
                tDelta = rclcpp::Clock().now() - tStart;
                CMNode.Sync.nCycles++;

            } while (rclcpp::ok() && rx_done == 0 && tDelta.nanoseconds()*1000000000 < CMNode.Cfg.SyncTimeMax);
            /* Final calculation to get duration including last cycle before receive */
            tDelta = rclcpp::Clock().now() - tStart;

            CMNode.Sync.Duration = (double)tDelta.nanoseconds()*1000000000;

            if (rx_done != 1 && CMNode.Cfg.SyncTimeMax > 0.0 && tDelta.nanoseconds()*1000000000 >= CMNode.Cfg.SyncTimeMax)
                LogErrF(EC_Sim, "CMNode: Synchronization error! tDelta=%.3f, Last invalid Job='%s'\n", tDelta.nanoseconds()*1000000000, job_name);
            }

            break;

        case CMNode_Mode_Threaded:
            /* ToDo
             * - Spinning in parallel thread started before
             * - Lock variables!
             * - e.g. for HIL
             */
            break;

        default:
            /* Invalid!!! */;
    }
    return 1;
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called after driving maneuver calculation
 * - before CMRosIF_CMNode_VehicleControl_Calc()
 * - See "User.c:User_DrivManCalc()"
 */
int
CMRosIF_CMNode_DrivMan_Calc (double dt)
{
    /* Only do anything if simulation is running */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled
            || SimCore.State != SCState_Simulate)
            return 0;

    /* Put your code here */
    DrivMan.Lights.Indicator = signallight;
    DrivMan.Lights.Hazard = hazard;

    return 1;
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called after CMRosIF_CMNode_DrivManCalc
 * - before CMRosIF_CMNode_VehicleControl_Calc()
 * - See "User.c:User_VehicleControl_Calc()"
 */
int
CMRosIF_CMNode_VehicleControl_Calc (double dt)
{
    /* Only do anything if simulation is running */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled
            || SimCore.State != SCState_Simulate)
        return 0;

    // SAVE_AN
    int Switch = sw;

    if (Switch == 0) {
    } else if (Switch == 1){
        AccelCtrl.DesrAx = ax;
        VehicleControl.SelectorCtrl = SelectorCtrl;
    } else if (Switch == 2){
        VehicleControl.Steering.Ang = steer_ang;
    } else {
        AccelCtrl.DesrAx = ax;
        VehicleControl.Steering.Ang = steer_ang;
        VehicleControl.GearNo = gear_no;
        VehicleControl.SelectorCtrl = SelectorCtrl;
    }

    if (obj_disappear_trig == 1){
        tTrafficObj *pObj = Traffic_GetByTrfId(obj_disappear_id);   
        pObj->t_0[0] = 0;
        pObj->t_0[1] = 0;
        pObj->t_0[2] = 0;
    }

    return 1;
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called after vehicle model has been calculated
 * - See "User.c:User_Calc()"
 */
int
CMRosIF_CMNode_Calc (double dt)
{

    /* Only do anything if simulation is running */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled
            || SimCore.State != SCState_Simulate)
        return 0;

    /* Put your code here
     * - Update model parameters here?
     * - Do some calculation...
     */

    /* Update model with values from external node only in specific cycle?
     * - This data handling is optionl, but necessary for deterministic behaviour
     * - if synchronization is active, incoming data remains in msg buffer until correct cycle
     */
    int rv;
    auto sync = &CMNode.Topics.Sub.Ext2CM;

    if ((rv = CMCRJob_DoJob(sync->Job, CMNode.CycleNoRel, 1, NULL, NULL)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
            LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s", CMCRJob_GetName(sync->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {
        /* Something to do in sync cycle? */
        //CMCRJob_Info(in->Job, CMNode.CycleNoRel, "CMNode: Do Something for Sync: ");

            /* Update model parameters here? */
        CMNode.Model.CycleNo = CMNode.Topics.Sub.Ext2CM.Msg.cycleno;

        /* Remember cycle for debugging */
        CMNode.Sync.CycleJobDone    = CMNode.CycleNoRel;
        CMNode.Model.CycleLastFlush = CMNode.CycleNoRel;
    }

    /* Do some calculation... */

        if (SimCore.State == SCState_Simulate) {
        //Lidar RSI --> PointCloud
        /*
        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.Lidar_VLP.Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
            LogErrF(EC_Sim, "cycleTime: %d, cycleoffset: %d, cycle: %lu", CMNode.Topics.Pub.Lidar_VLP.CycleTime, CMNode.Topics.Pub.Lidar_VLP.CycleOffset, CMNode.CycleNoRel);
            LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.Lidar_VLP.Job), CMCRJob_RVStr(rv));
        } else if (Lidar_CycleCount % (int)CMNode.Topics.Pub.Lidar_VLP.CycleTime == 0) {
                    geometry_msgs::msg::Point32 points;
            sensor_msgs::msg::ChannelFloat32 channels;
            channels.name = "intensity";

            //clearing vector data to avoid overflows
            CMNode.Topics.Pub.Lidar_VLP.Msg.points.clear();
            CMNode.Topics.Pub.Lidar_VLP.Msg.channels.clear();
            channels.values.clear();

                        for (int i = 0; i < LidarRSI[0].nScanPoints; i++) {

                                const int beam_id = LidarRSI[0].ScanPoint[i].BeamID;
                                const double azimuth = angles::from_degrees(CMNode.LidarRSI_VLP.BeamTable[4*CMNode.LidarRSI_VLP.rows + beam_id]);
                                const double elevation = angles::from_degrees(CMNode.LidarRSI_VLP.BeamTable[5*CMNode.LidarRSI_VLP.rows + beam_id]);
                                const double ray_length = 0.5 * LidarRSI[0].ScanPoint[i].LengthOF; // length of flight is back and forth

                                //XYZ-coordinates of scan point
                                points.x = ray_length * cos(elevation) * cos(azimuth);
                                points.y = ray_length * cos(elevation) * sin(azimuth);
                                points.z = ray_length * sin(elevation);

                                CMNode.Topics.Pub.Lidar_VLP.Msg.points.push_back(points);
                                channels.values.push_back(LidarRSI[0].ScanPoint[i].Intensity);

                        }
                        CMNode.Topics.Pub.Lidar_VLP.Msg.channels.push_back(channels);
                        CMNode.Topics.Pub.Lidar_VLP.Msg.header.frame_id = CMNode.TF.Lidar_VLP.child_frame_id;
                        CMNode.Topics.Pub.Lidar_VLP.Msg.header.stamp = rclcpp::Time(LidarRSI[0].ScanTime);

        }
                */

        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.Lidar_OS1.Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
            LogErrF(EC_Sim, "cycleTime: %d, cycleoffset: %d, cycle: %lu", CMNode.Topics.Pub.Lidar_OS1.CycleTime, CMNode.Topics.Pub.Lidar_OS1.CycleOffset, CMNode.CycleNoRel);
            LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.Lidar_OS1.Job), CMCRJob_RVStr(rv));
        } else if (Lidar_CycleCount % (int)CMNode.Topics.Pub.Lidar_OS1.CycleTime == 0) {
                    geometry_msgs::msg::Point32 points;
            sensor_msgs::msg::ChannelFloat32 channels;
            channels.name = "intensity";
                        // sensor_msgs::msg::PointCloud pointcloud;

            //clearing vector data to avoid overflows
            CMNode.Topics.Pub.Lidar_OS1.Msg.points.clear();
            CMNode.Topics.Pub.Lidar_OS1.Msg.channels.clear();
            channels.values.clear();

            //Lidar Quantity processing
                        for (int i = 0; i < LidarRSI[0].nScanPoints; i++) {

                                const int beam_id = LidarRSI[0].ScanPoint[i].BeamID;
                                const double azimuth = angles::from_degrees(CMNode.LidarRSI_OS1.BeamTable[4*CMNode.LidarRSI_OS1.rows + beam_id]);
                                const double elevation = angles::from_degrees(CMNode.LidarRSI_OS1.BeamTable[5*CMNode.LidarRSI_OS1.rows + beam_id]);
                                const double ray_length = 0.5 * LidarRSI[0].ScanPoint[i].LengthOF; // length of flight is back and forth

                                //XYZ-coordinates of scan point
                                points.x = ray_length * cos(elevation) * cos(azimuth);
                                points.y = ray_length * cos(elevation) * sin(azimuth);
                                points.z = ray_length * sin(elevation);

                                // pointcloud.points.push_back(points);
                                CMNode.Topics.Pub.Lidar_OS1.Msg.points.push_back(points);
                                channels.values.push_back(LidarRSI[0].ScanPoint[i].Intensity);

                        }

                        // pointcloud.channels.push_back(channels);

                        // sensor_msgs::convertPointCloudToPointCloud2(pointcloud, CMNode.Topics.Pub.Lidar_OS1.Msg);
                        CMNode.Topics.Pub.Lidar_OS1.Msg.channels.push_back(channels);
                        CMNode.Topics.Pub.Lidar_OS1.Msg.header.frame_id = CMNode.TF.Lidar_OS1.child_frame_id;
                        CMNode.Topics.Pub.Lidar_OS1.Msg.header.stamp = rclcpp::Time(LidarRSI[1].ScanTime);

        }

        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.Lidar_OS1_PC2.Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
            LogErrF(EC_Sim, "cycleTime: %d, cycleoffset: %d, cycle: %lu", CMNode.Topics.Pub.Lidar_OS1_PC2.CycleTime, CMNode.Topics.Pub.Lidar_OS1_PC2.CycleOffset, CMNode.CycleNoRel);
            LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.Lidar_OS1_PC2.Job), CMCRJob_RVStr(rv));
        } else if (Lidar_CycleCount % (int)CMNode.Topics.Pub.Lidar_OS1_PC2.CycleTime == 0) {
            Log("cycleTime: %d, cycleoffset: %d, cycle: %lu", CMNode.Topics.Pub.Lidar_OS1_PC2.CycleTime, CMNode.Topics.Pub.Lidar_OS1_PC2.CycleOffset, CMNode.CycleNoRel);
            Log("CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.Lidar_OS1_PC2.Job), CMCRJob_RVStr(rv));
            geometry_msgs::msg::Point32 points;
            sensor_msgs::msg::ChannelFloat32 channels;
            channels.name = "intensity";
                        sensor_msgs::msg::PointCloud pointcloud;

            ////clearing vector data to avoid overflows
            pointcloud.points.clear();
            pointcloud.channels.clear();
            channels.values.clear();

                        for (int i = 0; i < LidarRSI[0].nScanPoints; i++) {

                                const int beam_id = LidarRSI[0].ScanPoint[i].BeamID;
                                const double azimuth = angles::from_degrees(CMNode.LidarRSI_OS1.BeamTable[4*CMNode.LidarRSI_OS1.rows + beam_id]);
                                const double elevation = angles::from_degrees(CMNode.LidarRSI_OS1.BeamTable[5*CMNode.LidarRSI_OS1.rows + beam_id]);
                                const double ray_length = 0.5 * LidarRSI[0].ScanPoint[i].LengthOF; // length of flight is back and forth

                                //XYZ-coordinates of scan point
                                points.x = ray_length * cos(elevation) * cos(azimuth);
                                points.y = ray_length * cos(elevation) * sin(azimuth);
                                points.z = ray_length * sin(elevation);

                                pointcloud.points.push_back(points);
                                channels.values.push_back(LidarRSI[0].ScanPoint[i].Intensity);

                        }

                        pointcloud.channels.push_back(channels);

                        sensor_msgs::convertPointCloudToPointCloud2(pointcloud, CMNode.Topics.Pub.Lidar_OS1_PC2.Msg);

                        CMNode.Topics.Pub.Lidar_OS1_PC2.Msg.header.frame_id = CMNode.TF.Lidar_OS1_PC2.child_frame_id;
                        CMNode.Topics.Pub.Lidar_OS1_PC2.Msg.header.stamp = rclcpp::Time(LidarRSI[0].ScanTime);

        }

// SAVE_AN
// #if 1
        // CMNode.TY_Debugging = (int)CMNode.Topics.Pub.GPSOut.CycleTime;
        // Log("TAEYUN %s \n", CMCRJob_DoPrep(CMNode.Topics.Pub.GPSOut.Job, 0, 1, nullptr, nullptr));
        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.GPSOut.Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
                LogErrF(EC_Sim, "cycleTime: %d, cycleoffset: %d, cycle: %lu", CMNode.Topics.Pub.GPSOut.CycleTime, CMNode.Topics.Pub.GPSOut.CycleOffset, CMNode.CycleNoRel);
                LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.GPSOut.Job), CMCRJob_RVStr(rv));
        } else if (Lidar_CycleCount % (int)CMNode.Topics.Pub.GPSOut.CycleTime == 0) {
                CMNode.TY_Debugging = 1;
                CMNode.Topics.Pub.GPSOut.Msg.cycleno      = CMNode.CycleNoRel;
                CMNode.Topics.Pub.GPSOut.Msg.time         = rclcpp::Clock().now(); // ros::Time(SimCore.Time);
                CMNode.Topics.Pub.GPSOut.Msg.synthdelay   = CMNode.Sync.SynthDelay;

                CMNode.Topics.Pub.GPSOut.Msg.header.stamp = rclcpp::Clock().now();

                unsigned int noise_deg = 150;
                double pi = 3.1415926536897932384626433832795028841971;
            CMNode.Topics.Pub.GPSOut.Msg.latitude          = GNavSensor.Receiver.UserPosLlhTsa[0]; //* 180 / pi + ((double)(rand() % (noise_deg * 2 + 1)) - noise_deg) / 10000000;
            CMNode.Topics.Pub.GPSOut.Msg.longitude         = GNavSensor.Receiver.UserPosLlhTsa[1]; //* 180 / pi + ((double)(rand() % (noise_deg * 2 + 1)) - noise_deg) / 10000000;
            CMNode.Topics.Pub.GPSOut.Msg.altitude          = GNavSensor.Receiver.UserPosLlhTsa[2];
        }

        // SAVE_AN
        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.IMUOut.Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
                LogErrF(EC_Sim, "cycleTime: %d, cycleoffset: %d, cycle: %lu", CMNode.Topics.Pub.IMUOut.CycleTime, CMNode.Topics.Pub.IMUOut.CycleOffset, CMNode.CycleNoRel);
                LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.IMUOut.Job), CMCRJob_RVStr(rv));
        } else if (Lidar_CycleCount % (int)CMNode.Topics.Pub.IMUOut.CycleTime == 0) {
                CMNode.TY_Debugging = 2;
                CMNode.Topics.Pub.IMUOut.Msg.cycleno      = CMNode.CycleNoRel;
                CMNode.Topics.Pub.IMUOut.Msg.time         = rclcpp::Clock().now(); //ros::Time(SimCore.Time);
                CMNode.Topics.Pub.IMUOut.Msg.synthdelay   = CMNode.Sync.SynthDelay;

                CMNode.Topics.Pub.IMUOut.Msg.header.stamp = rclcpp::Clock().now();

                CMNode.Topics.Pub.IMUOut.Msg.vx              = InertialSensor[0].Vel_B[0];
                CMNode.Topics.Pub.IMUOut.Msg.vy              = InertialSensor[0].Vel_B[1];
                CMNode.Topics.Pub.IMUOut.Msg.vz              = InertialSensor[0].Vel_B[2];
                CMNode.Topics.Pub.IMUOut.Msg.roll_rate       = InertialSensor[0].Omega_B[0];
                CMNode.Topics.Pub.IMUOut.Msg.pitch_rate      = InertialSensor[0].Omega_B[1];
                CMNode.Topics.Pub.IMUOut.Msg.yaw_rate        = InertialSensor[0].Omega_B[2];

                CMNode.Topics.Pub.IMUOut.Msg.ax              = InertialSensor[0].Acc_B[0];
                CMNode.Topics.Pub.IMUOut.Msg.ay              = InertialSensor[0].Acc_B[1];
                CMNode.Topics.Pub.IMUOut.Msg.az              = InertialSensor[0].Acc_B[2];
                CMNode.Topics.Pub.IMUOut.Msg.roll_acc        = InertialSensor[0].Alpha_B[0];
                CMNode.Topics.Pub.IMUOut.Msg.pitch_acc       = InertialSensor[0].Alpha_B[1];
                CMNode.Topics.Pub.IMUOut.Msg.yaw_acc         = InertialSensor[0].Alpha_B[2];
        }


        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.VehicleInfoOut.Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
                LogErrF(EC_Sim, "cycleTime: %d, cycleoffset: %d, cycle: %lu", CMNode.Topics.Pub.VehicleInfoOut.CycleTime, CMNode.Topics.Pub.VehicleInfoOut.CycleOffset, CMNode.CycleNoRel);
                LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.VehicleInfoOut.Job), CMCRJob_RVStr(rv));
        } else if (Lidar_CycleCount % (int)CMNode.Topics.Pub.VehicleInfoOut.CycleTime == 0) {
                CMNode.TY_Debugging = 2;
                CMNode.Topics.Pub.VehicleInfoOut.Msg.cycleno      = CMNode.CycleNoRel;
                CMNode.Topics.Pub.VehicleInfoOut.Msg.time         = rclcpp::Clock().now();// ros::Time(SimCore.Time);
                CMNode.Topics.Pub.VehicleInfoOut.Msg.synthdelay   = CMNode.Sync.SynthDelay;

                // ros::WallTime wtime = ros::WallTime::now();
                // CMNode.Topics.Pub.VehicleInfoOut.Msg.header.stamp.sec  = wtime.sec;
                // CMNode.Topics.Pub.VehicleInfoOut.Msg.header.stamp.nsec = wtime.nsec;


                CMNode.Topics.Pub.VehicleInfoOut.Msg.roll         = Car.Roll;
                CMNode.Topics.Pub.VehicleInfoOut.Msg.pitch        = Car.Pitch;
                CMNode.Topics.Pub.VehicleInfoOut.Msg.yaw          = Car.Yaw;

                CMNode.Topics.Pub.VehicleInfoOut.Msg.vx           = Car.ConBdy1.v_1[0];
                CMNode.Topics.Pub.VehicleInfoOut.Msg.vy           = Car.ConBdy1.v_1[1];
                CMNode.Topics.Pub.VehicleInfoOut.Msg.vz           = Car.ConBdy1.v_1[2];
                CMNode.Topics.Pub.VehicleInfoOut.Msg.roll_vel     = Car.RollVel;
                CMNode.Topics.Pub.VehicleInfoOut.Msg.pitch_vel    = Car.PitchVel;
                CMNode.Topics.Pub.VehicleInfoOut.Msg.yaw_vel      = Car.YawRate;

                CMNode.Topics.Pub.VehicleInfoOut.Msg.ax           = Car.ConBdy1.a_1[0];
                CMNode.Topics.Pub.VehicleInfoOut.Msg.ay           = Car.ConBdy1.a_1[1];
                CMNode.Topics.Pub.VehicleInfoOut.Msg.az           = Car.ConBdy1.a_1[2];
                CMNode.Topics.Pub.VehicleInfoOut.Msg.roll_acc     = Car.RollAcc;
                CMNode.Topics.Pub.VehicleInfoOut.Msg.pitch_acc    = Car.PitchAcc;
                CMNode.Topics.Pub.VehicleInfoOut.Msg.yaw_acc      = Car.YawAcc;

        }
// #endif
                unsigned int lane_noise = 50;

                //LineSensor LeftLine --> nav_msgs/Path
        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.LeftLane[0].Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
            LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.LeftLane[0].Job), CMCRJob_RVStr(rv));
        } else {
            geometry_msgs::msg::PoseStamped lines;
            CMNode.Topics.Pub.LeftLane[0].Msg.poses.clear(); //Need to clear...? No data in topic if cleared...why?
            CMNode.Topics.Pub.LeftLane[0].Msg.header.stamp = rclcpp::Time(LineSensor[0].TimeStamp);
            CMNode.Topics.Pub.LeftLane[0].Msg.header.frame_id = CMNode.TF.Line.child_frame_id;

            if (SimCore.State == SCState_Simulate && LineSensor[0].LLines.nLine > 0) {
                if (LineSensor[0].LLines.L[0].ds[0][0] < LineSensor[0].LLines.L[0].ds[1][0]) {
                                        for (int n = 0; n < LineSensor[0].LLines.L[0].nP && n < 100; n++) {

                                                lines.header.stamp = CMNode.Topics.Pub.LeftLane[0].Msg.header.stamp;

                                                lines.pose.position.x = LineSensor[0].LLines.L[0].ds[n][0] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;
                                                lines.pose.position.y = LineSensor[0].LLines.L[0].ds[n][1] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;
                                                lines.pose.position.z = LineSensor[0].LLines.L[0].ds[n][2] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;

                                                lines.pose.orientation.x = 0;
                                                lines.pose.orientation.y = 0;
                                                lines.pose.orientation.z = 0;
                                                lines.pose.orientation.w = 0;

                                                CMNode.Topics.Pub.LeftLane[0].Msg.poses.push_back(lines);
                                        }

                } else {
                                        for (int n = 0; n < LineSensor[0].LLines.L[0].nP && n < 100; n++) {
                                                int m = (LineSensor[0].LLines.L[0].nP - 1) - n;
                                                lines.header.stamp = CMNode.Topics.Pub.LeftLane[0].Msg.header.stamp;

                                                lines.pose.position.x = LineSensor[0].LLines.L[0].ds[m][0] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;
                                                lines.pose.position.y = LineSensor[0].LLines.L[0].ds[m][1] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;
                                                lines.pose.position.z = LineSensor[0].LLines.L[0].ds[m][2] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;

                                                lines.pose.orientation.x = 0;
                                                lines.pose.orientation.y = 0;
                                                lines.pose.orientation.z = 0;
                                                lines.pose.orientation.w = 0;

                                                CMNode.Topics.Pub.LeftLane[0].Msg.poses.push_back(lines);
                                        }
                                }
            }
        }

                //LineSensor LeftLine --> nav_msgs/Path
        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.LeftLane[1].Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
            LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.LeftLane[1].Job), CMCRJob_RVStr(rv));
        } else {
            geometry_msgs::msg::PoseStamped lines;
            CMNode.Topics.Pub.LeftLane[1].Msg.poses.clear(); //Need to clear...? No data in topic if cleared...why?
            CMNode.Topics.Pub.LeftLane[1].Msg.header.stamp = rclcpp::Time(LineSensor[0].TimeStamp);
            CMNode.Topics.Pub.LeftLane[1].Msg.header.frame_id = CMNode.TF.Line.child_frame_id;

            if (SimCore.State == SCState_Simulate && LineSensor[0].LLines.nLine > 1) {
                if (LineSensor[0].LLines.L[1].ds[0][0] < LineSensor[0].LLines.L[1].ds[1][0]) {
                                        for (int n = 0; n < LineSensor[0].LLines.L[1].nP && n < 100; n++) {

                                                lines.header.stamp = CMNode.Topics.Pub.LeftLane[1].Msg.header.stamp;

                                                lines.pose.position.x = LineSensor[0].LLines.L[1].ds[n][0] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;
                                                lines.pose.position.y = LineSensor[0].LLines.L[1].ds[n][1] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;
                                                lines.pose.position.z = LineSensor[0].LLines.L[1].ds[n][2] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;

                                                lines.pose.orientation.x = 0;
                                                lines.pose.orientation.y = 0;
                                                lines.pose.orientation.z = 0;
                                                lines.pose.orientation.w = 0;

                                                CMNode.Topics.Pub.LeftLane[1].Msg.poses.push_back(lines);
                                        }

                } else {
                                        for (int n = 0; n < LineSensor[0].LLines.L[1].nP && n < 100; n++) {
                                                int m = (LineSensor[0].LLines.L[1].nP - 1) - n;
                                                lines.header.stamp = CMNode.Topics.Pub.LeftLane[1].Msg.header.stamp;

                                                lines.pose.position.x = LineSensor[0].LLines.L[1].ds[m][0] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;
                                                lines.pose.position.y = LineSensor[0].LLines.L[1].ds[m][1] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;
                                                lines.pose.position.z = LineSensor[0].LLines.L[1].ds[m][2] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;

                                                lines.pose.orientation.x = 0;
                                                lines.pose.orientation.y = 0;
                                                lines.pose.orientation.z = 0;
                                                lines.pose.orientation.w = 0;

                                                CMNode.Topics.Pub.LeftLane[1].Msg.poses.push_back(lines);
                                        }
                                }
            }
        }

        //LineSensor RightLine--> nav_msgs/Path
        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.RightLane[0].Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
            LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.RightLane[0].Job), CMCRJob_RVStr(rv));
        } else {
            geometry_msgs::msg::PoseStamped lines;
            CMNode.Topics.Pub.RightLane[0].Msg.poses.clear(); //Need to clear...? No data in topic if cleared...why?
            CMNode.Topics.Pub.RightLane[0].Msg.header.stamp = CMNode.Topics.Pub.LeftLane[0].Msg.header.stamp;
            CMNode.Topics.Pub.RightLane[0].Msg.header.frame_id = CMNode.TF.Line.child_frame_id;

            if (LineSensor[0].RLines.nLine > 0) {
                                if (LineSensor[0].RLines.L[0].ds[0][0] < LineSensor[0].RLines.L[0].ds[1][0]) {
                                        for (int n = 0; n < LineSensor[0].RLines.L[0].nP && n < 100; n++) {

                                                lines.header.stamp = CMNode.Topics.Pub.RightLane[0].Msg.header.stamp;

                                                lines.pose.position.x = LineSensor[0].RLines.L[0].ds[n][0] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;
                                                lines.pose.position.y = LineSensor[0].RLines.L[0].ds[n][1] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;
                                                lines.pose.position.z = LineSensor[0].RLines.L[0].ds[n][2] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;

                                                lines.pose.orientation.x = 0;
                                                lines.pose.orientation.y = 0;
                                                lines.pose.orientation.z = 0;
                                                lines.pose.orientation.w = 0;

                                                CMNode.Topics.Pub.RightLane[0].Msg.poses.push_back(lines);
                                        }

                                } else {
                                        for (int n = 0; n < LineSensor[0].RLines.L[0].nP && n < 100; n++) {
                                                int m = (LineSensor[0].RLines.L[0].nP - 1) - n;
                                                lines.header.stamp = CMNode.Topics.Pub.RightLane[0].Msg.header.stamp;

                                                lines.pose.position.x = LineSensor[0].RLines.L[0].ds[m][0] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;
                                                lines.pose.position.y = LineSensor[0].RLines.L[0].ds[m][1] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;
                                                lines.pose.position.z = LineSensor[0].RLines.L[0].ds[m][2] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;

                                                lines.pose.orientation.x = 0;
                                                lines.pose.orientation.y = 0;
                                                lines.pose.orientation.z = 0;
                                                lines.pose.orientation.w = 0;

                                                CMNode.Topics.Pub.RightLane[0].Msg.poses.push_back(lines);
                                        }
                                }
            }
        }

                //LineSensor RightLine--> nav_msgs/Path
        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.RightLane[1].Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
            LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.RightLane[1].Job), CMCRJob_RVStr(rv));
        } else {
            geometry_msgs::msg::PoseStamped lines;
            CMNode.Topics.Pub.RightLane[1].Msg.poses.clear(); //Need to clear...? No data in topic if cleared...why?
            CMNode.Topics.Pub.RightLane[1].Msg.header.stamp = CMNode.Topics.Pub.LeftLane[0].Msg.header.stamp;
            CMNode.Topics.Pub.RightLane[1].Msg.header.frame_id = CMNode.TF.Line.child_frame_id;

            if (LineSensor[0].RLines.nLine > 1) {
                if (LineSensor[0].RLines.L[1].ds[0][0] < LineSensor[0].RLines.L[1].ds[1][0]) {
                                        for (int n = 0; n < LineSensor[0].RLines.L[1].nP && n < 100; n++) {

                                                lines.header.stamp = CMNode.Topics.Pub.RightLane[1].Msg.header.stamp;

                                                lines.pose.position.x = LineSensor[0].RLines.L[1].ds[n][0] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;
                                                lines.pose.position.y = LineSensor[0].RLines.L[1].ds[n][1] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;
                                                lines.pose.position.z = LineSensor[0].RLines.L[1].ds[n][2] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;;

                                                lines.pose.orientation.x = 0;
                                                lines.pose.orientation.y = 0;
                                                lines.pose.orientation.z = 0;
                                                lines.pose.orientation.w = 0;

                                                CMNode.Topics.Pub.RightLane[1].Msg.poses.push_back(lines);
                                        }

                                } else {
                                        for (int n = 0; n < LineSensor[0].RLines.L[1].nP && n < 100; n++) {
                                                int m = (LineSensor[0].RLines.L[1].nP - 1) - n;
                                                lines.header.stamp = CMNode.Topics.Pub.RightLane[0].Msg.header.stamp;

                                                lines.pose.position.x = LineSensor[0].RLines.L[1].ds[m][0] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;
                                                lines.pose.position.y = LineSensor[0].RLines.L[1].ds[m][1] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;
                                                lines.pose.position.z = LineSensor[0].RLines.L[1].ds[m][2] + ((double)(rand() % (lane_noise * 2 + 1)) - lane_noise) / 1000;

                                                lines.pose.orientation.x = 0;
                                                lines.pose.orientation.y = 0;
                                                lines.pose.orientation.z = 0;
                                                lines.pose.orientation.w = 0;

                                                CMNode.Topics.Pub.RightLane[1].Msg.poses.push_back(lines);
                                        }
                                }
            }
        }

#if 1
        //Object thk
        if ((rv = CMCRJob_DoPrep(CMNode.Topics.Pub.ObjectInfoOut.Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) < CMCRJob_RV_OK) {
                LogErrF(EC_Sim, "cycleTime: %d, cycleoffset: %d, cycle: %lu", CMNode.Topics.Pub.ObjectInfoOut.CycleTime, CMNode.Topics.Pub.ObjectInfoOut.CycleOffset, CMNode.CycleNoRel);
                LogErrF(EC_Sim, "CMNode: Error on DoPrep for Job '%s'! rv=%s", CMCRJob_GetName(CMNode.Topics.Pub.ObjectInfoOut.Job), CMCRJob_RVStr(rv));
        } else if (Lidar_CycleCount % (int)CMNode.Topics.Pub.ObjectInfoOut.CycleTime == 0) {
                CMNode.Topics.Pub.ObjectInfoOut.Msg.cycleno      = CMNode.CycleNoRel;
                CMNode.Topics.Pub.ObjectInfoOut.Msg.time         = rclcpp::Clock().now(); // ros::Time(SimCore.Time);
                CMNode.Topics.Pub.ObjectInfoOut.Msg.synthdelay   = CMNode.Sync.SynthDelay;

            // ros::WallTime wtime = ros::WallTime::now();
            // CMNode.Topics.Pub.ObjectInfoOut.Msg.header.stamp.sec  = wtime.sec;
            // CMNode.Topics.Pub.ObjectInfoOut.Msg.header.stamp.nsec = wtime.nsec;

            CMNode.Topics.Pub.ObjectInfoOut.Msg.num         = ObjectSensor->nObsvObjects;

            for (int i = 0; i < ObjectSensor->nObsvObjects; i++) {
                tObjectSensorObj *pOSO = ObjectSensor_GetObject(0, i);
                CMNode.Topics.Pub.ObjectInfoOut.Msg.id[i]         = i;
                CMNode.Topics.Pub.ObjectInfoOut.Msg.x[i]          = pOSO->RefPnt.ds[0];
                CMNode.Topics.Pub.ObjectInfoOut.Msg.y[i]          = pOSO->RefPnt.ds[1];
                CMNode.Topics.Pub.ObjectInfoOut.Msg.w[i]          = pOSO->w;
                CMNode.Topics.Pub.ObjectInfoOut.Msg.h[i]          = pOSO->h;
                CMNode.Topics.Pub.ObjectInfoOut.Msg.vx[i]         = pOSO->RefPnt.dv[0];
                CMNode.Topics.Pub.ObjectInfoOut.Msg.vy[i]         = pOSO->RefPnt.dv[1];
                // CMNode.Topics.Pub.ObjectInfoOut.Msg.alpha[i]      = pOSO->RefPnt.alpha_p;
                tTrafficObj *pObj = Traffic_GetByTrfId(i);
                CMNode.Topics.Pub.ObjectInfoOut.Msg.alpha[i]      = pObj->r_zyx[2];   // carmaker traffic ref heading
                CMNode.Topics.Pub.ObjectInfoOut.Msg.global_vx[i]      = pObj->v_0[0];   // carmaker traffic ref heading
                CMNode.Topics.Pub.ObjectInfoOut.Msg.global_vy[i]      = pObj->v_0[1];   // carmaker traffic ref heading
                
            }
        }
#endif
                Lidar_CycleCount++;
        }
    return 1;
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called close to end of CarMaker cycle
 * - See "User.c:User_Out()"
 */
int
CMRosIF_CMNode_Out (void)
{
    /* Only do anything if simulation is running */
    if (CMNode.Cfg.Mode == CMNode_Mode_Disabled
            || SimCore.State != SCState_Simulate)
        return 0;

    int rv;
    auto out = &CMNode.Topics.Pub.CM2Ext;

    /* Communicate to External ROS Node in this cycle?
     * - The job mechanism is optional and can be e.g. replaced by simple modulo on current cycle
     */
    if ((rv = CMCRJob_DoJob(out->Job, CMNode.CycleNoRel, 1, NULL, NULL)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
            LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {
        out->Msg.cycleno      = CMNode.CycleNoRel;
        out->Msg.time         = rclcpp::Time(SimCore.Time*1000000000);
        out->Msg.synthdelay   = CMNode.Sync.SynthDelay;

        /* Header stamp and frame needs to be set manually! */

        /* provide system time close to data is sent */
        out->Msg.header.stamp = rclcpp::Clock().now();
        out->Pub->publish(out->Msg);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }

#if 0
        auto out_lidar_vlp = &CMNode.Topics.Pub.Lidar_VLP;

    /* Communicate to External ROS Node in this cycle?
     * - The job mechanism is optional and can be e.g. replaced by simple modulo on current cycle
     */
    if ((rv = CMCRJob_DoJob(out_lidar_vlp->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_lidar_vlp->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {

        out_lidar_vlp->Pub->publish(out_lidar_vlp->Msg);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }
#endif

        auto out_lidar_os1 = &CMNode.Topics.Pub.Lidar_OS1;

    /* Communicate to External ROS Node in this cycle?
     * - The job mechanism is optional and can be e.g. replaced by simple modulo on current cycle
     */
    if ((rv = CMCRJob_DoJob(out_lidar_os1->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_lidar_os1->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {
            out_lidar_os1->Pub->publish(out_lidar_os1->Msg);
        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }



        auto out_lidar_os1_pc2 = &CMNode.Topics.Pub.Lidar_OS1_PC2;

    /* Communicate to External ROS Node in this cycle?
     * - The job mechanism is optional and can be e.g. replaced by simple modulo on current cycle
     */
    if ((rv = CMCRJob_DoJob(out_lidar_os1_pc2->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_lidar_os1_pc2->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {
        out_lidar_os1_pc2->Pub->publish(out_lidar_os1_pc2->Msg);
        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }

#if 1
    auto out_GPSOut = &CMNode.Topics.Pub.GPSOut;
    auto out_GPSOut2 = &CMNode.Topics.Pub.GPSOut2;

    /* Communicate to External ROS Node in this cycle?
     * - The job mechanism is optional and can be e.g. replaced by simple modulo on current cycle
     */
    // if (0){//((rv = CMCRJob_DoJob(out_GPSOut2->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
    //         // && rv != CMCRJob_RV_DoSomething) {
    //     LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_GPSOut2->Job), CMCRJob_RVStr(rv));
    // } 
    auto time = std::chrono::system_clock().now();
    auto mill = std::chrono::duration_cast<std::chrono::milliseconds>(time.time_since_epoch());

    long long currentTimeMillis = mill.count();
    if ((currentTimeMillis - HzControl.BeforeTime) < 1000/HzControl.Hz)
    {
        HzControl.isOkay = false;
    }
    
    if ((rv = CMCRJob_DoJob(out_GPSOut->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_GPSOut->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {
        std_msgs::msg::Float64MultiArray msg;
        // hellocm_msgs::msg::GPSOut msg;
        // out_GPSOut2->Msg.latitude
        msg.data.push_back(out_GPSOut->Msg.latitude);
        msg.data.push_back(out_GPSOut->Msg.longitude);
        msg.data.push_back(out_GPSOut->Msg.altitude);

        // out_GPSOut2->Pub->publish(out_GPSOut2->Msg);
        out_GPSOut2->Pub->publish(msg);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
        HzControl.isOkay = true;
        HzControl.BeforeTime = currentTimeMillis;
    }


    // SAVE_AN
    auto out_IMU_out = &CMNode.Topics.Pub.IMUOut;
    auto out_IMU_out2 = &CMNode.Topics.Pub.IMUOut2;

    if ((rv = CMCRJob_DoJob(out_IMU_out->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_IMU_out->Job), CMCRJob_RVStr(rv));
    } 
    else if (rv == CMCRJob_RV_DoSomething) { // (HzControl.isOkay){
        std_msgs::msg::Float64MultiArray msg1;

        msg1.data.push_back(out_IMU_out->Msg.vx);
        msg1.data.push_back(out_IMU_out->Msg.vy);
        msg1.data.push_back(out_IMU_out->Msg.vz);
        msg1.data.push_back(out_IMU_out->Msg.roll_rate);
        msg1.data.push_back(out_IMU_out->Msg.pitch_rate);
        msg1.data.push_back(out_IMU_out->Msg.yaw_rate);
        msg1.data.push_back(out_IMU_out->Msg.ax);
        msg1.data.push_back(out_IMU_out->Msg.ay);
        msg1.data.push_back(out_IMU_out->Msg.az);
        msg1.data.push_back(out_IMU_out->Msg.roll_acc);
        msg1.data.push_back(out_IMU_out->Msg.pitch_acc);
        msg1.data.push_back(out_IMU_out->Msg.yaw_acc);

        out_IMU_out2->Pub->publish(msg1);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }

    auto out_VehicleInfoOut = &CMNode.Topics.Pub.VehicleInfoOut;
    auto out_VehicleInfoOut2 = &CMNode.Topics.Pub.VehicleInfoOut2;

    if ((rv = CMCRJob_DoJob(out_VehicleInfoOut->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_VehicleInfoOut->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) { //(HzControl.isOkay){
        std_msgs::msg::Float64MultiArray msg2;

        msg2.data.push_back(out_VehicleInfoOut->Msg.roll);
        msg2.data.push_back(out_VehicleInfoOut->Msg.pitch);
        msg2.data.push_back(out_VehicleInfoOut->Msg.yaw);
        msg2.data.push_back(out_VehicleInfoOut->Msg.vx);
        msg2.data.push_back(out_VehicleInfoOut->Msg.vy);
        msg2.data.push_back(out_VehicleInfoOut->Msg.vz);
        msg2.data.push_back(out_VehicleInfoOut->Msg.roll_vel);
        msg2.data.push_back(out_VehicleInfoOut->Msg.pitch_vel);
        msg2.data.push_back(out_VehicleInfoOut->Msg.yaw_vel);
        msg2.data.push_back(out_VehicleInfoOut->Msg.ax);
        msg2.data.push_back(out_VehicleInfoOut->Msg.ay);
        msg2.data.push_back(out_VehicleInfoOut->Msg.az);
        msg2.data.push_back(out_VehicleInfoOut->Msg.roll_acc);
        msg2.data.push_back(out_VehicleInfoOut->Msg.pitch_acc);
        msg2.data.push_back(out_VehicleInfoOut->Msg.yaw_acc);

        out_VehicleInfoOut2->Pub->publish(msg2);

        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }
#endif

        //Send out Left Lane Detections
    auto out_LeftLane_0 = &CMNode.Topics.Pub.LeftLane[0];

    if ((rv = CMCRJob_DoJob(out_LeftLane_0->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_LeftLane_0->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {

        out_LeftLane_0->Pub->publish(out_LeftLane_0->Msg);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }

        //Send out Left Lane Detections
    auto out_LeftLane_1 = &CMNode.Topics.Pub.LeftLane[1];

    if ((rv = CMCRJob_DoJob(out_LeftLane_1->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_LeftLane_1->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {

        out_LeftLane_1->Pub->publish(out_LeftLane_1->Msg);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }

    //Send out Right Lane Detections
    auto out_RightLane_0 = &CMNode.Topics.Pub.RightLane[0];

    if ((rv = CMCRJob_DoJob(out_RightLane_0->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_RightLane_0->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {

        out_RightLane_0->Pub->publish(out_RightLane_0->Msg);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }

        //Send out Right Lane Detections
    auto out_RightLane_1 = &CMNode.Topics.Pub.RightLane[1];

    if ((rv = CMCRJob_DoJob(out_RightLane_1->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_RightLane_1->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {

        out_RightLane_1->Pub->publish(out_RightLane_1->Msg);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }
#if 1
        //Object thk
    auto out_ObjectInfoOut = &CMNode.Topics.Pub.ObjectInfoOut;
    auto out_ObjectInfoOut2 = &CMNode.Topics.Pub.ObjectInfoOut2;

    if ((rv = CMCRJob_DoJob(out_ObjectInfoOut->Job, CMNode.CycleNoRel, 1, nullptr, nullptr)) != CMCRJob_RV_DoNothing
            && rv != CMCRJob_RV_DoSomething) {
        LogErrF(EC_Sim, "CMNode: Error on DoJob for Job '%s'! rv=%s",CMCRJob_GetName(out_ObjectInfoOut->Job), CMCRJob_RVStr(rv));
    } else if (rv == CMCRJob_RV_DoSomething) {
        std_msgs::msg::Float64MultiArray msg3;

        int num = out_ObjectInfoOut->Msg.num;

        msg3.data.push_back(out_ObjectInfoOut->Msg.num);
        for (int i = 0; i < num; i++){
            msg3.data.push_back(out_ObjectInfoOut->Msg.id[i]);
            msg3.data.push_back(out_ObjectInfoOut->Msg.x[i]);
            msg3.data.push_back(out_ObjectInfoOut->Msg.y[i]);
            msg3.data.push_back(out_ObjectInfoOut->Msg.w[i]);
            msg3.data.push_back(out_ObjectInfoOut->Msg.h[i]);
            msg3.data.push_back(out_ObjectInfoOut->Msg.vx[i]);
            msg3.data.push_back(out_ObjectInfoOut->Msg.vy[i]);
            msg3.data.push_back(out_ObjectInfoOut->Msg.alpha[i]);
            msg3.data.push_back(out_ObjectInfoOut->Msg.global_vx[i]);
            msg3.data.push_back(out_ObjectInfoOut->Msg.global_vy[i]);
        }

        out_ObjectInfoOut2->Pub->publish(msg3);

        /* Remember cycle for debugging */
        CMNode.Model.CycleLastOut = CMNode.CycleNoRel;
    }
#endif
    /* Publish "/clock" topic after all other other topics are published
     * - Is the order of arrival in other node identical? */
    if (CMNode.Cfg.nCyclesClock > 0 && CMNode.CycleNoRel%CMNode.Cfg.nCyclesClock == 0) {
        CMNode.Topics.Pub.Clock.Msg.clock = rclcpp::Time(SimCore.Time*1000000000);
        CMNode.Topics.Pub.Clock.Pub->publish(CMNode.Topics.Pub.Clock.Msg);
    }

    /* ToDo: When increase? */
    CMNode.CycleNoRel++;

    return 1;
}



/*!
 * Important:
 * - DO NOT CHANGE FUNCTION NAME !!!
 * - Automatically called by CMRosIF extension
 *
 * Description:
 * - Called one Time when CarMaker ends
 * - See "User.c:User_End()"
 */
int
CMRosIF_CMNode_End (void)
{
        CMNode.Topics.Pub.Lidar_VLP.Msg.points.clear();
    CMNode.Topics.Pub.Lidar_VLP.Msg.channels.clear();

        CMNode.Topics.Pub.Lidar_OS1.Msg.points.clear();
    CMNode.Topics.Pub.Lidar_OS1.Msg.channels.clear();

        free(CMNode.LidarRSI_VLP.BeamTable);
        free(CMNode.LidarRSI_OS1.BeamTable);

    LOG("%s: End", __func__);

    return 1;
}



/*!
 * Important:
 * - NOT automatically called by CMRosIF extension
 *
 * Description:
 * - Example of user generated function
 * - Can be accessed in other sources, e.g. User.c
 * - Use "CMRosIF_GetSymbol()" to get symbol (see "lib/CMRosIF.h")
 *
 */
int
CMRosIF_CMNode_MyFunc (char *LogMsg)
{

    LOG("%s: %s",  __func__, LogMsg);
    return 1;
}

#ifdef __cplusplus
}
#endif

