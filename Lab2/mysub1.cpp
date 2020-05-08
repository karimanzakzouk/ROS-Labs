#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

void twistCallback(const geometry_msgs::Twist& msg)
{
    ROS_INFO("angular {x = %d, y = %d, z = %d}\n", (int)msg.angular.x, (int)msg.angular.y, (int)msg.angular.z);
    ROS_INFO("linear {x = %d, y = %d, z = %d}\n", (int)msg.linear.x, (int)msg.linear.y, (int)msg.linear.z);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sub_ros_102_task2");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("vel_msg_1", 1000, twistCallback);

    ros::spin();

    return 0;
}
