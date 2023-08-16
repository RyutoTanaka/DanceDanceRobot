// デバッグ用のserialを管理するファイル

// false:出力しない　true:出力する
static bool serial_valid = false;

void serial_setup(bool valid) {
  if(valid){
    Serial.begin(115200);
    serial_valid = valid;
  }
}

void serial_print_num_int(int num){
  if(serial_valid) Serial.print(num);
}

void serial_println_num_int(int num){
  if(serial_valid) Serial.println(num);
}

void serial_print_num_float(float num){
  if(serial_valid) Serial.print(num);
}

void serial_println_num_float(float num){
  if(serial_valid) Serial.println(num);
}
void serial_print_str(char* str){
  if(serial_valid) Serial.print(str);
}

void serial_println_str(char* str){
  if(serial_valid) Serial.print(str);
}