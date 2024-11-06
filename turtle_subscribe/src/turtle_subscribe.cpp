#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>

#define K_pose  0.1
#define ref_x   3.0
#define ref_y   3.0

double pose_x = 0.0;
double pose_y = 0.0;

// Subscribe時に実行する関数(Callback関数)
void subfuncPose(const turtlesim::Pose &pose){
    pose_x = pose.x;
    pose_y = pose.y;
}

int main(int argc, char **argv){
    // ROSノードの初期化
    ros::init(argc, argv, "turtle_publish");
    // ROSノードハンドルの取得
    ros::NodeHandle nh;

    // 送信するTopic通信(Publisher)の登録
    ros::Publisher pub_cmd = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // 受信するTopic通信(Subscriber)の登録
    ros::Subscriber sub_pos = nh.subscribe("/turtle1/pose", 10,subfuncPose);

    // ROSループ周期の設定
    ros::Rate loop_rate(10);    // [Hz]

    // cmd_velのデータ型に対応した変数の宣言
    // https://docs.ros.org/en/noetic/api/geometry_msgs/html/msg/Twist.html
    geometry_msgs::Twist cmd;
    cmd.linear.x = 0.0;
    cmd.linear.y = 0.0;
    cmd.linear.z = 0.0;
    cmd.angular.x = 0.0;
    cmd.angular.y = 0.0;
    cmd.angular.z = 0.0;

    // ループ処理　ros::ok()は処理中断信号が来ていないかの確認
    while(ros::ok()){
        // Topic通信の受信（Callback）の確認
        ros::spinOnce();

        // Topic通信送信
        pub_cmd.publish(cmd);

        // 比例制御
        cmd.linear.x = K_pose * (ref_x  - pose_x);
        cmd.linear.y = K_pose * (ref_y  - pose_y);

        // 設定したループ周期までスリープ
        loop_rate.sleep();
    }

    return 0;
}