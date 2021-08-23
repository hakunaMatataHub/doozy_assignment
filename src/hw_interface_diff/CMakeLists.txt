cmake_minimum_required(VERSION 2.8.3)
project(hw_interface_diff)
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
find_package(catkin REQUIRED COMPONENTS std_msgs geometry_msgs controller_manager hardware_interface diff_drive_controller roscpp)




catkin_package(INCLUDE_DIRS include CATKIN_DEPENDS roscpp std_msgs geometry_msgs controller_manager diff_drive_controller hardware_interface)

include_directories(include  ${catkin_INCLUDE_DIRS})



add_executable(controlNode src/control_core.cpp)
target_link_libraries(controlNode ${catkin_LIBRARIES})

