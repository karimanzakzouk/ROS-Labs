#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <sstream>

int dir;
float speed; 

void twistCallback(const geometry_msgs::Twist& msg)
{
    ROS_INFO("angular {x = %f, y = %f, z = %f}\n", (float)msg.angular.x, (float)msg.angular.y, (float)msg.angular.z);
    ROS_INFO("linear {x = %d, y = %d, z = %d}\n", (int)msg.linear.x, (int)msg.linear.y, (int)msg.linear.z);
   
    speed =(float)msg.linear.x ;
   
    if (speed > 0) 
    {
           dir =1;
    }
    else
    {
           dir=0;
    }
   
}

int main(int argc, char**argv)
{
    ros::init(argc, argv, "pub6_ros_006");
   
    ros::NodeHandle nh; 
   
    ros::Subscriber sub = nh.subscribe("/motor/vel_msg", 10, twistCallback );

    ros::Publisher pub = nh.advertise<std_msgs::String>("/motor/dir/speed", 1000);

    ros::Rate rate(2);

    std_msgs::String msg;
    std::stringstream ss;
   
    while(ros::ok())
    {

            if( dir == 1 )
	    { 
		    ss << "Robot is moving forward with speed = " << (float)speed <<"\n";
		    msg.data = ss.str();	   
            }
	    else
	    {
		    ss << "Robot stoped "<<"\n";
		    msg.data = ss.str();

	    }

        pub.publish(msg);
        ros::spinOnce();
        
    }


}
