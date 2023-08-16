#include "define.h"

void setup() {
  serial_setup(true);
  wifi_setup();
  imu_setup();
  delay(300);
}

void loop() {
  Command command;
  wifi_get_command(&command);
  Imu imu;
  imu_get_result(&imu);
  control(&command,&imu);
}
