// ロボットを制御するためのファイル
// DDRからの指令とＩＭＵの測定値を利用し、各モーターの指令値を生成する。

/*
M2     M1
    x
    ↑
  y←

M3     M4
*/
static MotorDriver MD1,MD2;

void control_setup(){
  // MD1の設定
  MD1.MA.speed = 0.0f;
  MD1.MA.gain = 1.0f;
  MD1.MA.pwm_plus_pin = 32;
  MD1.MA.pwm_plus_channel = 0;
  MD1.MA.pwm_minus_pin = 33;
  MD1.MA.pwm_minus_channel = 1;
  
  MD1.MB.speed = 0.0f;
  MD1.MB.gain = 1.0f;
  MD1.MB.pwm_plus_pin = 25;
  MD1.MB.pwm_plus_channel = 2;
  MD1.MB.pwm_minus_pin = 26;
  MD1.MB.pwm_minus_channel = 3;
  
  MD1.standby_pin = 12;
  MD1.mode_pin = 14;
  MD1.error_pin = 27;

  // MD2の設定
  MD2.MA.speed = 0.0f;
  MD2.MA.gain = 1.0f;
  MD2.MA.pwm_plus_pin = 17;
  MD2.MA.pwm_plus_channel = 4;
  MD2.MA.pwm_minus_pin = 16;
  MD2.MA.pwm_minus_channel = 5;

  MD2.MB.speed = 0.0f;
  MD2.MB.gain = 1.0f;
  MD2.MB.pwm_plus_pin = 13;
  MD2.MB.pwm_plus_channel = 6;
  MD2.MB.pwm_minus_pin = 5;
  MD2.MB.pwm_minus_channel = 7;

  MD2.standby_pin = 15;
  MD2.mode_pin = 2;
  MD2.error_pin = 4;
  
  // setup関数を呼び出す。
  motor_driver_setup(&MD1);
  motor_driver_setup(&MD2);
}

void control(Command* body_command, Imu* imu){
  // commandとimuのデータでいい感じに制御するコード
  
  md_control_loop(&MD1);
  md_control_loop(&MD2);
}