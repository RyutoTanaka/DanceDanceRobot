#include "define.hpp"

void setup() {
  serial_setup(true);
  wifi_setup();
  imu_setup();
  delay(300);
  control_setup();
}

void loop() {
  // DDRコマンドを取得
  Command command;
  wifi_get_command(&command);
  // imuから測定値を取得
  Imu imu;
  imu_get_result(&imu);
  // 取得したデータでロボットを制御
  control(&command,&imu);
}
