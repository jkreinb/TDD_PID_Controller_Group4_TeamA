/**
 * @file main.cpp
 * @author Jonathon Kreinbrink (Driver) Abhishek Nalawade (Observer) Team A
 * @brief Source code for main shell-app
 * @version 0.1
 * @date 2021-10-02
 * 
 * @copyright Copyright (c) 2021 Jonathon Kreinbrink, Abhishek Nalawade
 */

#include <iostream>
#include "../include/controllerpid.hpp"
// #include "../app/controllerpid.cpp"

int main() {
    ControllerPID pid;
    float new_kp, new_ki, new_kd, setpoint, velocity;
    char ans;
    std::cout<<"The default gain values are - "<<std::endl;
    std::cout<<"Kp : "<<pid.get_Kp()<<std::endl;
    std::cout<<"Ki : "<<pid.get_Ki()<<std::endl;
    std::cout<<"Kd : "<<pid.get_Kd()<<std::endl;
    std::cout<<"Do you want to change the gain value? (y/n)"<<std::endl;
    std::cin>>ans;
    if(ans == 'y'){
        std::cout<<"Enter the new gains for Kp, Ki and Kd : ";
        std::cin>>new_kp>>new_ki>>new_kd;
        std::cout<<""<<std::endl;
        pid.set_Kvalues(new_kp,new_ki,new_kd);
        std::cout<<"The new gains are - "<<std::endl;
        std::cout<<"Kp : "<<pid.get_Kp()<<std::endl;
        std::cout<<"Ki : "<<pid.get_Ki()<<std::endl;
        std::cout<<"Kd : "<<pid.get_Kd()<<std::endl;
    }
    
    std::cout<<"Enter the initial velocity : ";
    std::cin>>velocity;
    std::cout<<"Enter the target velocity : ";
    std::cin>>setpoint;
    double final_goal = 0;
    pid.set_goal_velocity(velocity);
    std::cout<<"Computing PID!!!!"<<std::endl;
    for (int i=0;i<1;i++){
        final_goal = pid.ComputePID(setpoint,pid.get_goal_velocity());
        pid.set_goal_velocity(final_goal+pid.get_goal_velocity());
    }
    std::cout<<"The new velocity is : "<<pid.get_goal_velocity()<<std::endl;

    return 0;
}
