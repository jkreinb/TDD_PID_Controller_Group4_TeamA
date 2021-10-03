/**
 * @file controllerpid.hpp
 * @author Jonathon Kreinbrink (Driver) Abhishek Nalawade (Observer) Team A
 * @brief Header file for the controllerpid class
 * @version 0.1
 * @date 2021-10-02
 *
 * @copyright Copyright (c) 2021 Jonathon Kreinbrink, Abhishek Nalawade
 */

#pragma once

#include <iostream>

class ControllerPID {
 public:
  float intergral = 0;
  double final_goal = 0;
  // Default Constructor
  ControllerPID() {
    Kp = .15;
    Ki = .05;
    Kd = .02;
    timeStep = .1;      // Default time step in seconds
    past_error = 0;     // Initializes with past error of 0
    current_error = 0; // Variable to store error in each iteration
    goal_velocity = 0; // Variable to store the final velocity
  }

  /**
   * @brief Calculates velocity change for one time step using PID equation
   *
   * @param setpoint Target setpoint for velocity
   * @param velocity Initial velocity for this time step
   * @return float Change in velocity calculated using PID equation
   */
  float ComputePID(float setpoint, float velocity);

  /**
   * @brief Set the K values for the PID controller
   *
   * @param test_Kp Proportional gain value
   * @param test_Ki Integral gain value
   * @param test_Kd Derivative gain value
   */
  void set_Kvalues(float test_Kp, float test_Ki, float test_Kd);

  /**
   * @brief Getter for proportional gain Kp
   *
   * @return float
   */
  float get_Kp();

  /**
   * @brief Getter for derivative gain Kd
   *
   * @return float
   */
  float get_Kd();

  /**
   * @brief Getter for integral gain Ki
   *
   * @return float
   */
  float get_Ki();

  /**
   * @brief Getter for velocity at each iteration
   *
   * @return float
   */
  float get_goal_velocity();

  /**
   * @brief Setter for initialising the velocity with initial velocity
   *
   * @return nil
   */
  void set_goal_velocity(float _goal_velocity);

 private:
  float Kp;             // Proportional gain value
  float Ki;             // Integral gain value
  float Kd;             // Derivative gain value
  float past_error;     // Error for the previous timestep
  float current_error;  // Current error
  float timeStep;       // Time step
  float goal_velocity;  // Goal velocity
};
