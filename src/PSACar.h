#ifndef PSACAR_DATA
#define PSACAR_DATA

#include <Arduino.h>
#include <mcp2515.h>
#include "AllCars.h"

class PSACar : public AllCars {

    public:
        void setCanFilters(MCP2515 &mcp2515);
        void decodeCanMessage(can_frame canMsg);
    private:
        float roundToTenths(float value);
};

#endif
