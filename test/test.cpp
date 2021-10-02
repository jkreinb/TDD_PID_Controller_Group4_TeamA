#include <gtest/gtest.h>
#include <../include/controllerpid.hpp>

ControllerPID Test_PID_class;
/**
 * @brief Tests to make sure the first iteration of ComputerPID is calculating
 * the PID output properly
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

/**
 * @brief Test to verify set_Kvalues and getters for K values are updated 
 * properly
 * 
 */
TEST(KValues_Updated, should_pass) {

  // Sets some K values to ensure set_Kvalues function works
  Test_PID_class.set_Kvalues(.25,.50,.35);

  // Checks to ensure Kvalues are updated within the class, using the 
  // getter functions
  float retrieved_Kp = Test_PID_class.get_Kp();
  float retrieved_Ki = Test_PID_class.get_Ki();
  float retrieved_Kd = Test_PID_class.get_Kd();

  EXPECT_FLOAT_EQ(retrieved_Kp,.25);
  EXPECT_FLOAT_EQ(retrieved_Ki,.50);
  EXPECT_FLOAT_EQ(retrieved_Kd,.35);
}
