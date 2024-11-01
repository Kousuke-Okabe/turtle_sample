#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv){
    ros::init(argc, argv, "turtle_publish");
    ros::NodeHandle nh;

    ros::Publisher pub_cmd = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate loop_rate(0.2);

    // auto cmd = geometry_msgs::Twist();
    geometry_msgs::Twist cmd;
    cmd.linear.x = 1.0;
    cmd.linear.y = 0.0;
    cmd.linear.z = 0.0;
    cmd.angular.x = 0.0;
    cmd.angular.y = 0.0;
    cmd.angular.z = 1.0;

    while(ros::ok()){
        pub_cmd.publish(cmd);

        loop_rate.sleep();
    }

    return 0;
}