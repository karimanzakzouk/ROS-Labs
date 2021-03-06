#include "ros/ros.h"
#include <std_msgs/Int8.h>

void chatterCallback(const std_msgs::Int8::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->data);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener3");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/sensor/ultrasonic", 10, chatterCallback);

  ros::spin();

  return 0;
}


