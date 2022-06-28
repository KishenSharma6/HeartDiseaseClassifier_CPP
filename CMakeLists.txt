#Set min cmake version and cpp version
cmake_minimum_required (VERSION 3.21)

set (CMAKE_CXX_STANDARD 17)

#Project name
project(HeartModel)

#Capture source files
file(GLOB sourcefiles
          "headers/*.h"
          "src/*.cpp"
          main.cpp)

#Create executable
add_executable(Deploy ${sourcefiles})