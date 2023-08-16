#include <WiFi.h>;

static WiFiServer server(80);

void wifi_setup(){
  WiFi.begin("ESSID", "PASSWD");          //アクセスポイント接続のためのIDとパスワードの設定
  while (WiFi.status() != WL_CONNECTED) { //接続状態の確認
    delay(300);
  }
  serial_println_str("");                     //シリアルモニタ改行
  serial_println_str("WiFi Connected");       //接続したらシリアルモニタに「WiFi Connected」と表示
  serial_print_str("IP Address : ");          //シリアルモニタに表示
  serial_println_num_int(WiFi.localIP());   
}

void wifi_get_command(Command* command){
  //
}