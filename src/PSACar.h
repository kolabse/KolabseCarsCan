#ifndef PSACAR_DATA
#define PSACAR_DATA

#include <Arduino.h>
#include <mcp2515.h>
#include "cars.h"

class PSACar : public Cars {

    public:
        void setCanFilters(MCP2515 &mcp2515);
    private:

};

#endif
