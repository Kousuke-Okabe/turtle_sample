#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv){
    // ROSノードの初期化
    ros::init(argc, argv, "turtle_publish");
    // ROSノードハンドルの取得
    ros::NodeHandle nh;

    // 送信するTopic通信(Publisher)の登録
    ros::Publisher pub_cmd = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // ROSループ周期の設定
    ros::Rate loop_rate(0.2);   // [Hz]

    // cmd_velのデータ型に対応した変数の宣言
    // https://docs.ros.org/en/noetic/api/geometry_msgs/html/msg/Twist.html
    geometry_msgs::Twist cmd;
    cmd.linear.x = 1.0;
    cmd.linear.y = 0.0;
    cmd.linear.z = 0.0;
    cmd.angular.x = 0.0;
    cmd.angular.y = 0.0;
    cmd.angular.z = 1.0;

    // ループ処理　ros::ok()は処理中断信号が来ていないかの確認
    while(ros::ok()){
        // Topic通信送信
        pub_cmd.publish(cmd);

        // 設定したループ周期までスリープ
        loop_rate.sleep();
    }

    return 0;
}