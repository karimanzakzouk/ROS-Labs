#include <ros/ros.h>
#include <std_msgs/Int8.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher1");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::Int8>("test_topic_1", 10);
    ros::Rate rate(2);

    while (ros::ok())
    {
        std_msgs::Int8 msg;
        for (int i=0; i<=10; i++)
        {
           msg.data = i ;
           pub.publish(msg);
           rate.sleep();
        }        

    }
}


