#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <std_srvs/Empty.h>

double pose_x = 0.0;
double pose_y = 0.0;

void subfuncPose(const turtlesim::Pose &pose){
    pose_x = pose.x;
    pose_y = pose.y;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "turtle_publish");
    ros::NodeHandle nh;

    // Resistration publisher
    ros::Publisher pub_cmd = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // Resistration subscriber
    ros::Subscriber sub_pos = nh.subscribe("/turtle1/pose", 10,subfuncPose);

    // Resistration cliant
    ros::ServiceClient cli_reset = nh.serviceClient<std_srvs::Empty>("/reset");

    // Load parameter
    double K_pose = nh.param<double>("/turtle/K_pose", 0.1);
    double ref_x = nh.param<double>("/turtle/ref_x", 3.0);
    double ref_y = nh.param<double>("/turtle/ref_y", 3.0);

    ros::Rate loop_rate(10);

    geometry_msgs::Twist cmd;
    cmd.linear.x = 0.0;
    cmd.linear.y = 0.0;
    cmd.linear.z = 0.0;
    cmd.angular.x = 0.0;
    cmd.angular.y = 0.0;
    cmd.angular.z = 0.0;

    // reset turtlesim
    std_srvs::Empty args;
    bool ret = cli_reset.call(args);

    while(ros::ok()){
        // Check Callback
        ros::spinOnce();

        // Publish
        pub_cmd.publish(cmd);

        // controller
        cmd.linear.x = K_pose * (ref_x  - pose_x);
        cmd.linear.y = K_pose * (ref_y  - pose_y);

        // sleep
        loop_rate.sleep();
    }

    return 0;
}