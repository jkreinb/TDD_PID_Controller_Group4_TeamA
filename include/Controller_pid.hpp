/**
 * @file Controller_pid.hpp
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
#include <utility>

class Controller_pid
{

public:
    Controller_pid(){
        Kp = .35;
        Ki = .25;
        Kd = .15;
        timeStep = .1; // Time step in seconds
        past_error = 0; // Initializes with past error of 0
        }

    /**
     * @brief Computes PID value using private gain values
     * 
     * @return float value_PID, the PID control variable output until reaches set point
     */
    float computePID(float setpoint, float velocity){
        float value_PID = 9;

        // // Calculates proportional gain portion of PID
        // float proportional_gain = Kp*(velocity - setpoint);

        // // Calculates derivative gain portion of PID
        // float derivative_gain = Kd*((current_error - past_error)/timeStep);

        // // Calculates integral gain portion of PID
        // float integral_gain = integral_gain + Ki*timeStep*(current_error-past_error);

        return value_PID;
    } 

    /**
     * @brief Set the K values for the object
     * 
     * @param test_Kp 
     * @param test_Ki 
     * @param test_Kd 
     */
    void setK_values(float test_Kp, float test_Ki, float test_Kd){ //
        Kp = test_Kp;
        Ki = test_Ki;
        Kd = test_Kd;
    }


private:
    float Kp; // Proportional gain value
    float Ki; // Integral gain value
    float Kd; // Derivative gain value
    float past_error; // Error for the previous timestep
    float current_error; // Current error
    float timeStep; // Time step
    float set_velocity; // Goal velocity
    
};

