#include "udp_rx.hpp"

void udp_rx::init(void){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
    MDNS.begin("UDP_Client00");
    udp.begin(Org_Port);
}

void udp_rx::update(void){
    uint8_t read_data[10];
    if (udp.parsePacket() > 0){
        udp.read(read_data , 10);
        udp.flush();
        updated_ = true;
    }
    data_ = {0};
}

bool udp_rx::is_updated(void){
    return updated_;
}

ConnectionData udp_rx::read(void){
    updated_ = false;
    return data_;
}

