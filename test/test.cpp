#include <gtest/gtest.h>
#include <../include/controllerpid.hpp>

ControllerPID Test_PID_class;
/**
 * @brief Calls TEST case called Unit_Test to ensure expec
 * 
 */
TEST(compute_initialPID, should_pass) {

   EXPECT_NEAR((Test_PID_class.ComputePID(50, 20)), 10.650, .2); 
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
   for (int i = 0; i<1000; i++){
     float add = Test_PID_class.ComputePID(setpoint, test_speed);
     test_speed += add;
 }

  // Tests if current speed is within 1% of set point after 1000 time steps
  EXPECT_NEAR(test_speed, setpoint, .5);
}
