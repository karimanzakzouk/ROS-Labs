#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char**argv)
{

    ros::init(argc, argv, "pub_ros_102_task2");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("vel_msg_1", 1000);

    ros::Rate rate(1);

    geometry_msgs::Twist msg;
    
    msg.linear.x = 1;
    msg.linear.y = 0;
    msg.linear.z = 0;
    
    msg.angular.x = 0;
    msg.angular.y = 0;
    msg.angular.z = 0;


    while(ros::ok())
    {
        pub.publish(msg);

        rate.sleep();
    }
}
