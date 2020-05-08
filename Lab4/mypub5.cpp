#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <geometry_msgs/Twist.h>


int dis;

void chatterCallback(const std_msgs::Int8::ConstPtr& msg)
{
  ROS_INFO("Distance  =  [%d]", msg->data);
  dis=  msg->data;
}

int main(int argc, char**argv)
{
    float i=0.0; 

    ros::init(argc, argv, "pub5_ros_005");
   
    ros::NodeHandle nh; 
   
    ros::Subscriber sub = nh.subscribe("/sensor/ultrasonic", 10, chatterCallback );

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/motor/vel_msg", 1000);

    ros::Rate rate(2);

    geometry_msgs::Twist msg;
   
    while(ros::ok())
    {
	    //speed is decided based on distance 
            if( dis <= 30 )
	    { 
                    //stop 
		    msg.linear.x = 0;
		    msg.linear.y = 0;
		    msg.linear.z = 0;
		    
		    msg.angular.x = 0;
		    msg.angular.y = 0;
		    msg.angular.z = 0;

	    }
            else if ( dis >= 70)
            {
			//forward 
		    msg.linear.x = 1;
		    msg.linear.y = 0;
		    msg.linear.z = 0;
		    
		    msg.angular.x = 0;
		    msg.angular.y = 0;
		    msg.angular.z = 0;

            }
	    else
	    {
			//forward 
                    i= ((float)dis/(float)100) + 0.3;

		    msg.linear.x = i;
		    msg.linear.y = 0;
		    msg.linear.z = 0;
		    
		    msg.angular.x = 0;
		    msg.angular.y = 0;
		    msg.angular.z = 0;
	    }

        pub.publish(msg);
        ros::spinOnce();
        //rate.sleep();
    }


}
