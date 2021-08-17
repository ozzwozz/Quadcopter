#include "ros.hpp"

class hover()
{
    private:
      pParam=2;
      iParam=0;
      dParam=0;
      vParam=-2;

      cumul=0;
      lastE=0;
      pAlphaE=0;
      pBetaE=0;
      psp2=0;
      psp1=0;

      prevEuler=0;

      propellerHandles={}
      jointHandles={}


    protected:
      int hover_height = {0, 0, 0.5}; // starting hover height in meters, x, y, z

      // callback functions for movement control
      void hover::Rotational_Control();
      void hover::HorizontalControl();
      void hover::VerticalControl();
    public:
      hover() : Node("drone_movement_control")
      {
        odom_sub_ = this->create_subscription<std_msgs::msg::String>("/odom", 10, std::bind(&hover::topic_callback, this, _1));
        publisher_ = this->create_publisher<std_msgs::msg::String>("/cmd_vel", 10);
      }
};
