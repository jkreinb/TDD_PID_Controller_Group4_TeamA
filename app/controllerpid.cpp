/**
 * @file controllerpid.cpp
 * @author Jonathon Kreinbrink (Driver) Abhishek Nalawade (Observer) Team A
 * @brief Source code for PID controller class
 * @version 0.1
 * @date 2021-10-02
 * 
 * @copyright Copyright (c) 2021 Jonathon Kreinbrink, Abhishek Nalawade
 * 
 */

#include <iostream>
#include "../include/controllerpid.hpp"

/**
 * @brief Calculates velocity change for one time step using PID equation
 * 
 * @param setpoint Target setpoint for velocity
 * @param velocity Initial velocity for this time step
 * @return float Change in velocity calculated using PID equation
 */
float ControllerPID::ComputePID(float setpoint, float velocity) {
    float p_gain, i_gain, d_gain, deravative, answer;
    current_error = setpoint - velocity;
    p_gain = Kp * current_error;
    intergral += current_error * timeStep;
    i_gain = Ki * intergral;
    deravative = (current_error - past_error)/timeStep;
    d_gain = Kd * deravative;
    answer = p_gain + i_gain+ d_gain;
    past_error = current_error;
    return answer;
}

/**
 * @brief Set the K values for the PID controller
 * 
 * @param test_Kp Proportional gain value
 * @param test_Ki Integral gain value
 * @param test_Kd Derivative gain value
 */
void ControllerPID::set_Kvalues(float test_Kp, float test_Ki, float test_Kd) {
    Kp = test_Kp;
    Ki = test_Ki;
    Kd = test_Kd;
}

/**
 * @brief Getter for proportional gain Kp
 * 
 * @return float 
 */
float ControllerPID::get_Kp() {
    return Kp;
}

/**
 * @brief Getter for derivative gain Kd
 * 
 * @return float 
 */
float ControllerPID::get_Kd() {
    return Kd;
}

/**
 * @brief Getter for integral gain Ki
 * 
 * @return float 
 */
float ControllerPID::get_Ki() {
    return Ki;
}

/**
 * @brief Getter for velocity at each iteration
 * 
 * @return float 
 */
float ControllerPID::get_goal_velocity(){
    return goal_velocity;
}

/**
 * @brief Setter for initialising the velocity with initial velocity
 * 
 * @return nil
 */
void ControllerPID::set_goal_velocity(float _goal_velocity){
    goal_velocity = _goal_velocity;
}
