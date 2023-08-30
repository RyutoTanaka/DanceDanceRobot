## UdpTxクラス  

UDP通信の送信を行うためのクラス  

### サンプルコード

```c
//インスタンス生成
UdpTx udp_tx();

//Udp初期設定　wifiに繋げる
//setup関数内におくといいと思われ
udp_tx.init();

//送信
//ConnectionData classに送信データを書き込んで
//write関数で送信
ConnectionData data(1.0f,0.0f);
udp_tx.write(&data);
```

## UdpRxクラス  

UDP通信の受信を行うためのクラス 

```c
//インスタンス生成
UdpRx udp_rx();

//Udp初期設定　wifiに繋げる
//setup関数内におくといいと思われ
udp_rx.init();

//受信
//update関数を送信と同じ周期で呼び出す
//timer割り込みなどを使うべきかも
udp_rx.update();

//データが更新されているか確認
//戻り値がtrueだったら更新されている
if(udp_rx.is_updated()){
    // 受信した後の処理
};

//データ取得
ConnectionData data();
data = udp_rx.read();
```

## ConnectionDataクラス

送受信するデータを管理するクラス

```c
//インスタンス生成
ConnectionData data();
ConnectionData data(1.0f,-1.0f);

//ConnectionDataクラスをuint8_tの配列に変換する。
uint8_t* write_data;
write_data = data.serialize();

// uint8_tの配列をConnectionDataクラスに変換する。
uint8_t read_data[8];
data.deserialize(read_data);
```