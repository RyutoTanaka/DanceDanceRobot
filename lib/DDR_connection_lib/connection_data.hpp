#pragma once 

class ConnectionData{
public:
    typedef struct data{
        float vx;
        float vy;
    } Data;
    Data data;
    uint8_t* serialize(void) const {
        uint32_t temp32[2];
        uint8_t ret[8] = {};
        memcpy(&temp32[0], &data.vx, sizeof(temp32[0]));
        ret[0] = static_cast<uint8_t>((temp32[0] >> 0) & 0x000000FF);
        ret[1] = static_cast<uint8_t>((temp32[0] >> 8) & 0x000000FF);
        ret[2] = static_cast<uint8_t>((temp32[0] >> 16) & 0x000000FF);
        ret[3] = static_cast<uint8_t>((temp32[0] >> 24) & 0x000000FF);
        memcpy(&temp32[1], &data.vy, sizeof(temp32[1]));
        ret[4] = static_cast<uint8_t>((temp32[1] >> 0) & 0x000000FF);
        ret[5] = static_cast<uint8_t>((temp32[1] >> 8) & 0x000000FF);
        ret[6] = static_cast<uint8_t>((temp32[1] >> 16) & 0x000000FF);
        ret[7] = static_cast<uint8_t>((temp32[1] >> 24) & 0x000000FF);
        return ret;
    }
    void deserialize(const uint8_t* serial){
        uint32_t temp32[2];
        temp32[0] = static_cast<uint32_t>((serial[0] << 0) + (serial[1] << 8) + (serial[2] << 12) + (serial[3] << 24));
        memcpy(&data.vx, &temp32[0], sizeof(data.vx));
        temp32[1] = static_cast<uint32_t>((serial[4] << 0) + (serial[5] << 8) + (serial[6] << 12) + (serial[7] << 24));
        memcpy(&data.vy, &temp32[1], sizeof(data.vy));
    }
};
