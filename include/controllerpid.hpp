/**
 * @file controllerpid.hpp
 * @author Jon Kreinbrink, Abhishek Nalawade
 * @brief Declares a PID controller class that computes velocity given a target
 * setpoint and actual velocity
 * @version 0.1
 * @date 2021-10-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>

class ControllerPID
{
public:
    // Default Constructor
    ControllerPID(){
        Kp = .15;
        Ki = .05;
        Kd = .02;
        timeStep = .1; // Default time step in seconds
        past_error = 0; // Initializes with past error of 0
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

private:
    float Kp; // Proportional gain value
    float Ki; // Integral gain value
    float Kd; // Derivative gain value
    float past_error; // Error for the previous timestep
    float current_error; // Current error
    float timeStep; // Time step
    float set_velocity; // Goal velocity
    
};

