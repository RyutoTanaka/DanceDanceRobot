#ifndef DEFINE_H
#define DEFINE_H

struct robot_command{
  float vel_x; // [m/s]
  float vel_y; // [m/s]
  float angle; // pi ~ -pi [rad]
};
typedef struct robot_command Command;

struct imu_result{
  float acc_x; // [m^2/s]
  float acc_y; // [m^2/s]
  float acc_z; // [m^2/s]
  float gyro_x;
  float gyro_y;
  float gyro_z;
  int mag_x;
  int mag_y;
  int mag_z;
};
typedef struct imu_result Imu;

struct motor_data{
  float speed; // [rpm]
  float gain;
  int pwm_plus_pin;
  int pwm_minus_pin;
};
typedef struct motor_data Motor;

struct motor_driver_data{
  Motor MA;
  Motor MB;
  int standby_pin;
  int mode_pin;
  int error_pin;
};
typedef struct motor_driver_data MotorDriver;


#endif