#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <stdio.h>
 
class MyRobot : public hardware_interface::RobotHW
{
public:
 /* MyRobot() 
  { 
    // Initialization of the robot's resources (joints, sensors, actuators) and
    // interfaces can be done here or inside init().
    // E.g. parse the URDF for joint names & interfaces, then initialize them
    // robot description specific params are uplaoded into diff_drive ns directly
  }*/
 
  bool init(ros::NodeHandle &root_nh, ros::NodeHandle &robot_hw_nh)
  {
    // Create a JointStateHandle for each joint and register them with the 
    // JointStateInterface.

    //std::cout<<"I am here!!"<<std::endl;
    hardware_interface::JointStateHandle state_handle_L("L", &pos[0], &vel[0], &eff[0]);
    jnt_state_interface.registerHandle(state_handle_L);
 
    hardware_interface::JointStateHandle state_handle_R("R", &pos[1], &vel[1], &eff[1]);
    jnt_state_interface.registerHandle(state_handle_R);
 
    // Register the JointStateInterface containing the read only joints
    // with this robot's hardware_interface::RobotHW.
    registerInterface(&jnt_state_interface);
 
    // Create a JointHandle (read and write) for each controllable joint
    // using the read-only joint handles within the JointStateInterface and 
    // register them with the JointPositionInterface.
    hardware_interface::JointHandle vel_handle_L(jnt_state_interface.getHandle("L"), &cmd[0]);
    jnt_vel_interface.registerHandle(vel_handle_L);
 
    hardware_interface::JointHandle vel_handle_R(jnt_state_interface.getHandle("R"), &cmd[1]);
    jnt_vel_interface.registerHandle(vel_handle_R);
 
    // Register the JointPositionInterface containing the read/write joints
    // with this robot's hardware_interface::RobotHW.
    registerInterface(&jnt_vel_interface);
 
    return true;
  }

   void read()
  {
      //interfface with hardware using serial connection to read sensor data
  }

  /**
  * Get latest velocity commands from ros_control via joint structure, and send to MCU
  */
  void write()
  {
    // send command velocity to serial to write on motors/actuators
  }

 
public:
  // hardware_interface::JointStateInterface gives read access to all joint values 
  // without conflicting with other controllers.
  hardware_interface::JointStateInterface jnt_state_interface;
  // hardware_interface::PositionJointInterface inherits from 
  // hardware_interface::JointCommandInterface and is used for reading and writing
  // joint positions. Because this interface reserves the joints for write access,
  // conflicts with other controllers writing to the same joints might occure.
  // To only read joint positions, avoid conflicts using 
  // hardware_interface::JointStateInterface.
  hardware_interface::VelocityJointInterface jnt_vel_interface;
 
  // Data member array to store the controller commands which are sent to the 
  // robot's resources (joints, actuators)
  double cmd[2];
 
  // Data member arrays to store the state of the robot's resources (joints, sensors)
  double pos[2];
  double vel[2];
  double eff[2];
};
