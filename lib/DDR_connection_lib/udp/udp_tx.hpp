#pragma once 

#include "WiFi.h"
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include "../connection_data.hpp"

class udp_tx{
private: 
    static constexpr char * ssid = "XXXXXX";
    static constexpr char * password = "YYYYYY";
    static constexpr int Remote_Port = 9000;        // Destination port
    static constexpr int Org_Port = 9000;           // Source port
    WiFiUDP &udp;
public:
    udp_tx(WiFiUDP &_udp):udp(_udp){}

    void init(void);
    void write(const ConnectionData&);
};