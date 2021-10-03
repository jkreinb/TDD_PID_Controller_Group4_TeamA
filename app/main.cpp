/**
 * @file main.cpp
 * @author Jonathon Kreinbrink (Driver) Abhishek Nalawade (Observer) Team A
 * @copyright [2021] <Jonathon Kreinbrink, Abhishek Nalawade>
 * @section DESCRIPTION
 * Source code to obtain target velocity using PID controller.
 *
 * The default gain values are Kp=0.15, Ki=0.05, Kd=0.02.
 * The user has option of changing these gain values if needed.
 * The code takes in initial and target velocities from the user and for time
 * step of 0.1 sec the program calculates the error and uses the PID controller
 * to increase its velocity until the target velocity is reached.
 * @version 0.1
 * @date 2021-10-02
 */

#include <iostream>

#include "../include/controllerpid.hpp"
// #include "../app/controllerpid.cpp"

int main() {
  ControllerPID pid;
  float setpoint, velocity;
  char ans;
  // Displaying the default gain values.
  std::cout << "The default gain values are - " << std::endl;
  std::cout << "Kp : " << pid.get_Kp() << std::endl;
  std::cout << "Ki : " << pid.get_Ki() << std::endl;
  std::cout << "Kd : " << pid.get_Kd() << std::endl;
  // Option for user to keep or change the gain values.
  std::cout << "Do you want to change the gain value? (y/n)" << std::endl;
  std::cin >> ans;
  if (ans == 'y') {
    float new_kp, new_ki, new_kd;
    std::cout << "Enter the new gains for Kp, Ki and Kd : ";
    std::cin >> new_kp >> new_ki >> new_kd;
    std::cout << "" << std::endl;
    pid.set_Kvalues(new_kp, new_ki, new_kd);
    std::cout << "The new gains are :- " << std::endl;
    std::cout << "Kp : " << pid.get_Kp() << std::endl;
    std::cout << "Ki : " << pid.get_Ki() << std::endl;
    std::cout << "Kd : " << pid.get_Kd() << std::endl;
  }
  // Taking initial and target velocities from the user.
  std::cout << "Enter the initial velocity : ";
  std::cin >> velocity;
  std::cout << "Enter the target velocity : ";
  std::cin >> setpoint;
  pid.set_goal_velocity(velocity);
  // Using PID controller to reach the target velocity.
  std::cout << "Computing Velocity using PID controller!!!!" << std::endl;
  for (int i = 0; i < 1000; i++) {
    pid.final_goal = pid.ComputePID(setpoint, pid.get_goal_velocity());
    pid.set_goal_velocity(pid.final_goal + pid.get_goal_velocity());
  }
  std::cout << "The new velocity is : " << pid.get_goal_velocity() << std::endl;

  return 0;
}
