#define PWM_FREQUENCY 19531
#define PWM_BIT_WIDTH 12

const uint32_t PWM_MAX = (0b1 << PWM_BIT_WIDTH) - 1;
// duty比100％の時のタイヤの回転速度[rpm]
const float MAX_SPEED = 100.0f;


void motor_driver_setup(MotorDriver* MD){
  pinMode(MD->standby_pin, OUTPUT);
  pinMode(MD->mode_pin, OUTPUT);
  pinMode(MD->error_pin, INPUT);

  ledcSetup(MD->MA.pwm_plus_channel, PWM_FREQUENCY,PWM_BIT_WIDTH);
  ledcAttachPin(MD->MA.pwm_plus_pin, MD->MA.pwm_plus_channel);

  ledcSetup(MD->MA.pwm_minus_channel, PWM_FREQUENCY,PWM_BIT_WIDTH);
  ledcAttachPin(MD->MA.pwm_minus_pin, MD->MA.pwm_minus_channel);

  ledcSetup(MD->MB.pwm_plus_channel, PWM_FREQUENCY,PWM_BIT_WIDTH);
  ledcAttachPin(MD->MB.pwm_plus_pin, MD->MB.pwm_plus_channel);

  ledcSetup(MD->MB.pwm_minus_channel, PWM_FREQUENCY,PWM_BIT_WIDTH);
  ledcAttachPin(MD->MB.pwm_minus_pin, MD->MB.pwm_minus_channel);

  digitalWrite(MD->mode_pin, LOW);
}

void md_control_loop(MotorDriver* MD){
  if(digitalRead(MD->error_pin)){
    serial_println_str("motor_driver_error");
    MD->enable = false;
  }
  if(MD->enable){
    md_motor_control(&(MD->MA));
    md_motor_control(&(MD->MB));
  }
  else {
    md_control_stop(MD);
  }
}

void md_motor_control(Motor* motor){
  if(motor->speed > 0.0f){
    // モーターの回転数と電圧の変換（仮で線形とする）
    uint32_t diff = (motor->speed / MAX_SPEED) * PWM_MAX * motor->gain;
    ledcWrite(motor->pwm_plus_channel, PWM_MAX);
    ledcWrite(motor->pwm_minus_channel, PWM_MAX-diff);
  }
  else if(motor->speed < 0.0f){
    // モーターの回転数と電圧の変換（仮で線形とする）
    uint32_t diff = (-motor->speed / MAX_SPEED) * PWM_MAX * motor->gain;
    ledcWrite(motor->pwm_plus_channel, PWM_MAX);
    ledcWrite(motor->pwm_minus_channel, PWM_MAX-diff);
  }
  else{
    ledcWrite(motor->pwm_plus_channel, PWM_MAX);
    ledcWrite(motor->pwm_minus_channel, PWM_MAX);
  }
}

void md_control_start(MotorDriver* MD){
  digitalWrite(MD->standby_pin, HIGH);
  serial_println_str("control start");
}

void md_control_stop(MotorDriver* MD){
  ledcWrite(MD->MA.pwm_plus_channel, 0);
  ledcWrite(MD->MA.pwm_minus_channel, 0);
  MD->MA.speed = 0.0f;
  ledcWrite(MD->MB.pwm_plus_channel, 0);
  ledcWrite(MD->MB.pwm_minus_channel, 0);
  MD->MB.speed = 0.0f;
  digitalWrite(MD->standby_pin, LOW);
  serial_println_str("control stop");
}