#pragma once 
#pragma once 

#include "WiFi.h"
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include "../connection_data.hpp"

class udp_rx{
private: 
    static constexpr char * ssid = "XXXXXX";
    static constexpr char * password = "YYYYYY";
    static constexpr int Remote_Port = 9000;        // Destination port
    static constexpr int Org_Port = 9000;           // Source port
    WiFiUDP &udp;
    bool updated_;
    ConnectionData data_;
public:
    udp_rx(WiFiUDP &_udp):udp(_udp){}

    void init(void);
    void update(void);
    bool is_updated(void);
    ConnectionData read(void);
};