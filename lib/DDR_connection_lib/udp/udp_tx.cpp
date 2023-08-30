#include "udp_tx.hpp"

void UdpTx::init(void){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
    MDNS.begin("UDP_Client01");
    udp.begin(Org_Port);
}

void UdpTx::write(const ConnectionData& data){
    udp.beginPacket(MDNS.queryHost("UDP_Client00"), Remote_Port);
    udp.write(data.serialize(),sizeof(data.data));
    udp.endPacket();
}