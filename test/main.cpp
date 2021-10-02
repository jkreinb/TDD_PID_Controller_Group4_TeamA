/**
 * @file main.cpp
 * @author Jonathon Kreinbrink (Driver) Abhishek Nalawade (Observer) Team A
 * @brief Source code for main cpp-test app
 * @version 0.1
 * @date 2021-10-02
 * 
 * @copyright Copyright (c) 2021 Jonathon Kreinbrink, Abhishek Nalawade
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}