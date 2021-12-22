/**
 * COPY this file and rename before chage
 */


// replace "TEMPLATE" with yours
#ifndef TEMPLATE_CAR_DATA
// replace "TEMPLATE" with yours
#define TEMPLATE_CAR_DATA

#include <Arduino.h>
#include <mcp2515.h>
#include "AllCars.h"

class TemplateCar : public AllCars { // replace "Template" with yours

    public:
        void setCanFilters(MCP2515 &mcp2515);
        void decodeCanMessage(can_frame canMsg);
    private:
        // Your private methods
};

#endif