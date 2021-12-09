#ifndef PSACAR_DATA
#define PSACAR_DATA

#include <Arduino.h>
#include <mcp2515.h>
#include "KolabseCarsCan.h"

class PSACar : public KolabseCarsCan {

    public:
        void setCanFilters(MCP2515 &mcp2515);
        void decodeCanMessage(can_frame canMsg);
    private:
        float roundToTenths(float value);
};

#endif
