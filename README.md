# URP_example


## 코드 실행 방법 정리
$ git clone https://github.com/jungjjang44/URP_example.git
$ cd URP_example/CarMaker_ROS2_Original
$ ./build_cmrosif.sh
$ ./CMStart.sh
-> CarMaker UI창에서 위 Extras-> CMRosIF -> Launch & Start Application -> ok -> ok
-> 위 menu 창 File -> Open -> example 더블 클릭 -> File -> IPGMovie

다른 터미널 창 열고
$ cd URP_example/CarMaker_ROS2_Original/ros/ros2_ws
$ . /opt/ros/galactic/setup.bash && . install/setup.bash
$ ros2 run cm_control_example cm_control_example

CarMaker Start(초록색 버튼 클릭)


