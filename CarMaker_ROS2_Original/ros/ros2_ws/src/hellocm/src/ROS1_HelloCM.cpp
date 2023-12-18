/*!
 ******************************************************************************
 **  External ROS Node for simple communication with CarMaker
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
 * - This ROS Node is independent from CarMaker libraries
 * - Basic communication without hard synchronization on CarMaker side
 *   -> For an example with synchronization see "desraccel"
 *
 * ToDo:
 * - C++!
 * - ROS naming/way/namespaces
 * - Synchronization in this example (currently only desraccel)
 * - ...
 *
 */
	
#include <cmrosutils/CMRosUtils.h>
#include <hellocm/ROS1_HelloCM.h>

#include <std_msgs/msg/string.hpp>


/* NDEBUG is set in CarMaker Makefile/MakeDefs in OPT_CFLAGS */
#if !defined NDEBUG
#  warning "Debug options are enabled!"
#  define DBLOG LOG
#else
#  define DBLOG(...)
#endif


#if 0
# define LOG(frmt, ...)  printf(frmt "\n", ##__VA_ARGS__)
#else
# define LOG RCLCPP_INFO
#endif


/*!< Global struct for this Node */
static struct {
    unsigned long CycleNo;     /*!< Current cycle number for algorithm */
    int           CycleTime;   /*!< Expected cycle time in milliseconds of external ROS Node.
                                    - Might be used for synchronization (under development)
                                    - e.g. usage in combination of published message */
    double        SynthDelay;  /*!< Synthetic delay in seconds to check Sync */

    struct {
	/*!< Cyclic log to terminal independent from simulation time */
	std::shared_ptr<rclcpp::TimerBase> WallTimer;
	
	/*!< Cyclic log to terminal dependent on simulation time ("/clock" topic) */
	std::shared_ptr<rclcpp::TimerBase> PubTimer;
	} Timer;
	
    struct {
	struct {
	    tRosIF_TpcSub<hellocm_msgs::msg::CM2Ext>  CM2Ext;
	} Sub; /*!< Topics to be subscribed */
	
	struct {
	    tRosIF_TpcPub<hellocm_msgs::msg::Ext2CM>  Ext2CM;
	} Pub; /*!< Topics to be published */
	} Topics; /*!< ROS Topics used by this Node */
	
    struct {
	/*!< Initialization/Preparation of this ROS Node e.g. when simulation starts */
		tRosIF_Srv<hellocm_msgs::srv::Init>      Init;
    } Services; /*!< ROS Services used by this Node */
	
    tRosIF_Cfg Cfg;
	
} RosIF;




/*!
 * Description:
 * - Called when service is triggered
 * - e.g. before CarMaker TestRun starts to re-init this node
 *
 */
static bool
ros_HelloCM_CB_SrvInit(
	const std::shared_ptr<rmw_request_id_t> request_header,
	std::shared_ptr<hellocm_msgs::srv::Init::Request> req,
	std::shared_ptr<hellocm_msgs::srv::Init::Response> resp)
{
    int rv;
    char sbuf[256];
    std::shared_ptr<rclcpp::Node> node = RosIF.Cfg.Node;
	
    LOG(node->get_logger(), "%s: Service 'Init' was triggered", node->get_name());

    /* Reset variables */
    RosIF.CycleNo    = 0;
    RosIF.SynthDelay = 0.0;

    
    /*
     * Check if parameter has changed!
     *  ToDo:
     * - http://wiki.ros.org/roscpp/Overview/Parameter%20Server
     *   - cached parameter?
     * - Create own function in ROS_Utils.h
     * - Changing parameter this way only experimental
     * - Update e.g. via CarMaker TestAutomation or "rosparam" in terminal
     */
    strcpy(sbuf, "hellocm/cycletime");

    if ((rv = node->has_parameter(sbuf)) == true) {
	node->get_parameter(sbuf, rv);
	
	if (RosIF.CycleTime != rv){
	    RosIF.CycleTime = rv;
	    LOG(node->get_logger(), "  -> Update param '%s' to '%d'", sbuf, RosIF.CycleTime);
	}
    }

    resp->success   = 1;
    resp->cycletime = RosIF.CycleTime; /* ToDo: remove this? only use ROS parameter mechanism? */
    return true;
}



/*!
 * Description:
 * - Do something when external message arrives
 * - Called when external message is processed
 *
 */
static void
ros_HelloCM_CB_TpcIn(const hellocm_msgs::msg::CM2Ext::SharedPtr msg)
{
    /* Update variables
     * - ToDo: mutex?
     */
    RosIF.SynthDelay = msg->synthdelay;

    LOG(RosIF.Cfg.Node->get_logger(), "%s - TpcIn (ROS Time=%.3fs): CarMaker Node is in cycle %lu, Time=%ds, Stamp=%ds", 
		RosIF.Cfg.Node->get_name(), rclcpp::Clock().now().seconds(), 
		msg->cycleno, msg->time.sec, msg->header.stamp.sec);
	
}



/*!
 * Description:
 * - This callback is expected to be called by a default ROS Timer
 * - The callback depends on ROS Time (system time or "simulation" time)
 * - Dependent on "use_sim_time" parameter and /clock Topic
 * - e.g. initialized via "<Node Handle>->createTimer"
 *
 */
static void
ros_HelloCM_CB_PubTimer() {

    std::shared_ptr<rclcpp::TimerBase> wtime;
	auto out = &RosIF.Topics.Pub.Ext2CM;
    double delay;

    out->Msg.cycleno = ++RosIF.CycleNo;
    out->Msg.time    = rclcpp::Clock().now();
	
    /* Header stamp and frame needs to be set manually! */
    /* provide system time close to data is sent */
    out->Msg.header.stamp = rclcpp::Clock().now();
	
    /* Synthetic delay to demonstrate effect of synchronization
     * - ToDo: mutex?
     */
    delay = RosIF.SynthDelay;

    if (delay > 1e-9)
            rclcpp::WallRate(delay).sleep();

    /* Publish the message */
    out->Pub->publish(out->Msg);
	
	LOG(RosIF.Cfg.Node->get_logger(), "%s - PubTimer (ROS Time=%.3fs): This Node is in cycle %lu, Time=%ds, Stamp=%ds", 
		RosIF.Cfg.Node->get_name(), rclcpp::Clock().now().seconds(), 
		out->Msg.cycleno, out->Msg.time.sec, out->Msg.header.stamp.sec);
	
}



/*!
 * Description:
 * - This callback is expected to be called by a WallTimer
 * - The callback depends on system time
 * - e.g. initialized via "<Node Handle>->createWallTimer"
 *
 */
static void
ros_HelloCM_CB_WallTimer() {

    LOG(RosIF.Cfg.Node->get_logger(), "%s: I am Alive!", RosIF.Cfg.Node->get_name());
}



/*!
 * Description:
 * - Basic initialization of this ROS Node
 * - Initialize Services, Topics, Timers, ...
 *
 */
static int
ros_HelloCM_Init(int Argc, char **Argv) {
	char sbuf[256];
    int  rv  = 0;    
    bool rvb = false;
	/* ROS initialization. Name of Node might be different after remapping! */
    rclcpp::init(Argc, Argv);

    /* Node specific */
    RosIF.Cfg.Node = std::make_shared<rclcpp::Node>(hellocm::node_name);
	std::shared_ptr<rclcpp::Node> node = RosIF.Cfg.Node;
	
    /* Publish specific */
    LOG(RosIF.Cfg.Node->get_logger(), "  -> Publish '%s'", hellocm::tpc_out_name.c_str());
    RosIF.Topics.Pub.Ext2CM.Pub = node->create_publisher<hellocm_msgs::msg::Ext2CM>(hellocm::tpc_out_name, 10);
	
    /* Subscribe specific */
    LOG(RosIF.Cfg.Node->get_logger(), "  -> Subscribe '%s'", hellocm::tpc_in_name.c_str());
    RosIF.Topics.Sub.CM2Ext.Sub = node->create_subscription<hellocm_msgs::msg::CM2Ext>(hellocm::tpc_in_name, 10, ros_HelloCM_CB_TpcIn); //?????????????????????????????????????????????????
	
    /* Services */
    LOG(RosIF.Cfg.Node->get_logger(), "  -> Create Service '%s'", hellocm::srv_init_name.c_str());
    RosIF.Services.Init.Srv = node->create_service<hellocm_msgs::srv::Init>(hellocm::srv_init_name, ros_HelloCM_CB_SrvInit);

	/* Parameter specific */
    /* ToDo:
     * - Parameter must be set in all external nodes?
     *   -> currently setting in CM seems to be sufficient! */
    strcpy(sbuf, "use_sim_time");
	
    /* ToDo:
       - getParam seems to return 0 even the value was received
     */
    if ((rv = node->has_parameter(sbuf)) == true && node->get_parameter(sbuf, rvb) == true) {
	
	node->get_parameter(sbuf, rvb);
	LOG(RosIF.Cfg.Node->get_logger(), "  -> Has param '%s' with value '%d'", sbuf, rvb);
    } else {
	LOG(RosIF.Cfg.Node->get_logger(), "  -> No param '%s' is set", sbuf);
	rvb = false;
    }

    if (rvb == true)
	LOG(RosIF.Cfg.Node->get_logger(), "  -> Use time provided by Clock Server!");
    else
	LOG(RosIF.Cfg.Node->get_logger(), "  -> Use system time!");

    /*
     * Use cached parameters?
     * - http://wiki.ros.org/roscpp/Overview/Parameter%20Server
     * - should be used rarely to avoid overloading the master
     */
    strcpy(sbuf, "hellocm/cycletime");
	if ((rv = node->has_parameter(sbuf)) == true) {

	/* May be set by other node or exe arguments */
	node->get_parameter(sbuf, rv);
	LOG(RosIF.Cfg.Node->get_logger(), "  -> Has param '%s' with value '%d'", sbuf, rv);
	RosIF.CycleTime = rv;
    } else {

	/* Create parameter available for other nodes */
	RosIF.CycleTime = 10000;
	LOG(RosIF.Cfg.Node->get_logger(), "  -> No param '%s' was set! Use default cycle time!", sbuf);
	node->declare_parameter(sbuf);
	node->set_parameter(rclcpp::Parameter(sbuf, RosIF.CycleTime));
	}

    LOG(RosIF.Cfg.Node->get_logger(), "  -> Cycle time = %dms", RosIF.CycleTime);


    /* Timer specific */
    RosIF.Timer.WallTimer = node->create_wall_timer(std::chrono::seconds(10), ros_HelloCM_CB_WallTimer);
	RosIF.Timer.PubTimer  = node->create_wall_timer(std::chrono::milliseconds(RosIF.CycleTime), ros_HelloCM_CB_PubTimer);


    /* Print general information after everything is done */
    LOG(RosIF.Cfg.Node->get_logger(), "Initialization of ROS Node finished!");
    LOG(RosIF.Cfg.Node->get_logger(), "  -> Node Name = '%s'", node->get_name());
    LOG(RosIF.Cfg.Node->get_logger(), "  -> Namespace = '%s'", node->get_namespace());


    /* Advertised Topics */
	std::map<std::string, std::vector<std::string>> names;
	names = node->get_topic_names_and_types();
    
	LOG(RosIF.Cfg.Node->get_logger(), "  -> Connected Topics (%lu)", names.size());
	auto it = names.begin();
	for (; it != names.end(); ++it)
	LOG(RosIF.Cfg.Node->get_logger(), "    -> %s", it->first.c_str());
	names.clear();
	
    return 0;
}


/*!
 * Description:
 * -This ROS Node is a standalone executable!
 *
 */
int main(int argc, char *argv[])
{
	
	ros_HelloCM_Init(argc, argv);
	
	LOG(RosIF.Cfg.Node->get_logger(), "%s -> Start spinning...", RosIF.Cfg.Node->get_name());
    
	rclcpp::spin(RosIF.Cfg.Node);
	
	LOG(RosIF.Cfg.Node->get_logger(), "%s -> Shutdown", RosIF.Cfg.Node->get_name());
	
	return 0;
}
