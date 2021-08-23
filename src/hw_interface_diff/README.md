# diff_drive_parameters explained

reference :http://wiki.ros.org/diff_drive_controller


##left_wheel (string | string[...])
Left wheel joint name or list of joint names

##right_wheel (string | string[...])
Right wheel joint name or list of joint names

##pose_covariance_diagonal (double[6])
Diagonal of the covariance matrix for odometry pose publishing

##twist_covariance_diagonal (double[6])
Diagonal of the covariance matrix for odometry twist publishing

##publish_rate (double, default: 50.0)
Frequency (in Hz) at which the odometry is published. Used for both tf and odom

##wheel_separation_multiplier (double, default: 1.0)
Multiplier applied to the wheel separation parameter. This is used to account for a difference between the robot model and a real robot.

##wheel_radius_multiplier (double, default: 1.0)
Multiplier applied to the wheel radius parameter. This is used to account for a difference between the robot model and a real robot.

##cmd_vel_timeout (double, default: 0.5)
Allowed period (in s) allowed between two successive velocity commands. After this delay, a zero speed command will be sent to the wheels.

##base_frame_id (string, default: base_link)
Base frame_id, which is used to fill in the child_frame_id of the Odometry messages and TF.

##linear/x/has_velocity_limits (bool, default: false)
Whether the controller should limit linear speed or not.

##linear/x/max_velocity (double)
Maximum linear velocity (in m/s)

##linear/x/min_velocity (double)
Minimum linear velocity (in m/s). Setting this to 0.0 will disable backwards motion. When unspecified, -max_velocity is used.

##linear/x/has_acceleration_limits (bool, default: false)
Whether the controller should limit linear acceleration or not.

##linear/x/max_acceleration (double)
Maximum linear acceleration (in m/s^2)

##linear/x/min_acceleration (double)
Minimum linear acceleration (in m/s^2). When unspecified, -max_acceleration is used.

##linear/x/has_jerk_limits (bool, default: false)
Whether the controller should limit linear jerk or not.

##linear/x/max_jerk (double)
Maximum linear jerk (in m/s^3).

##angular/z/has_velocity_limits (bool, default: false)
Whether the controller should limit angular velocity or not.

##angular/z/max_velocity (double)
Maximum angular velocity (in rad/s)

##angular/z/min_velocity (double)
Minimum angular velocity (in rad/s). Setting this to 0.0 will disable counter-clockwise rotation. When unspecified, -max_velocity is used.

##angular/z/has_acceleration_limits (bool, default: false)
Whether the controller should limit angular acceleration or not.

##angular/z/max_acceleration (double)
Maximum angular acceleration (in rad/s^2)

##angular/z/min_acceleration (double)
Minimum angular acceleration (in rad/s^2). When unspecified, -max_acceleration is used.

##angular/z/has_jerk_limits (bool, default: false)
Whether the controller should limit angular jerk or not.

##angular/z/max_jerk (double)
Maximum angular jerk (in m/s^3).

##enable_odom_tf (bool, default: true)
Publish to TF directly or not

##wheel_separation (double)
The distance of the left and right wheel(s). The diff_drive_controller will attempt to read the value from the URDF if this parameter is not specified

##wheel_radius (double)
Radius of the wheels. It is expected they all have the same size. The diff_drive_controller will attempt to read the value from the URDF if this parameter is not specified.

##odom_frame_id (string, default: "/odom")
Name of frame to publish odometry in.

##publish_cmd (bool, default: False)
Publish the velocity command to be executed. It is to monitor the effect of limiters on the controller input.
allow_multiple_cmd_vel_publishers (bool, default: False)
Setting this to true will allow more than one publisher on the input topic, ~/cmd_vel. Setting this to false will cause the controller to brake if there is more than one publisher on ~/cmd_vel.

##velocity_rolling_window_size (int, default: 10)
The number of velocity samples to average together to compute the odometry twist.linear.x and twist.angular.z velocities
