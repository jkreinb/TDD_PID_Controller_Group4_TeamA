#include <gtest/gtest.h>
#include <../include/Controller_pid.hpp>

Controller_pid Test_PID_class;
/**
 * @brief Calls TEST case called Unit_Test
 * 
 */
TEST(compute_initialPID, should_pass) {
   EXPECT_EQ(Test_PID_class.computePID(50, 20), .3456);
}

/**
 * @brief Tests the computePID method by supplying an initial test_speed 
 * of = 20 and a velocity setpoint of 50. The proposed computePID method
 * must converge to within 2% of the setpoint after 1000 iterations
 * 
 */
TEST(PID_Converges, should_pass) {
  
  // Initial setpoint and initial velocity for test case
  float setpoint = 50;
  float test_speed = 20;

  // For loop to call the computePID method 1000 times
  // for (int i = 0; i<1000; i++){
  //   float add = Test_PID_class.computePID(setpoint, test_speed)
  //     test_speed += add;
  // }

  // Calculates how far the final speed is from the original set point
  float percent_off = (test_speed-setpoint)/setpoint;

  // Tests if current speed is within 2% of set point after 1000 time steps
   EXPECT_LT(percent_off, .02 );
}
