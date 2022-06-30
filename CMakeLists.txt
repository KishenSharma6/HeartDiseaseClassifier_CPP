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


find_package(Boost 1.36.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(Deploy ${sourcefiles})
    #target_link_libraries(progname ${Boost_LIBRARIES})
endif()

