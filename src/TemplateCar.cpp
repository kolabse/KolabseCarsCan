/**
 * COPY this file and rename before chage
 */

#include <Arduino.h>
#include "TemplateCar.h" // replace "Template" with yors

void TemplateCar::setCanFilters(MCP2515 &mcp2515) { // replace "Template" with yors

    // reset MCP2515
    mcp2515.reset();

    // Set can-bus speed and frequency
    mcp2515.setBitrate(CAN_125KBPS, MCP_16MHZ); // replace with yors

    // Set MCP2515 config mode on
    mcp2515.setConfigMode();

    // replace with yors or delete masks and filters for get all messages

    // Set masks
    mcp2515.setFilterMask(MCP2515::MASK0, false, 0x7FF); // replace with yors
    mcp2515.setFilterMask(MCP2515::MASK1, false, 0x7FF); // replace with yors

    // set filters
    mcp2515.setFilter(MCP2515::RXF0, false, 0x036); // replace with yors
    mcp2515.setFilter(MCP2515::RXF1, false, 0x0B6); // replace with yors
    mcp2515.setFilter(MCP2515::RXF2, false, 0x0E6); // replace with yors
    mcp2515.setFilter(MCP2515::RXF3, false, 0x0F6); // replace with yors
    mcp2515.setFilter(MCP2515::RXF4, false, 0x1D0); // replace with yors
    mcp2515.setFilter(MCP2515::RXF5, false, 0x221); // replace with yors

    // Set MCP2515 config mode off
    mcp2515.setNormalMode();
}

void TemplateCar::decodeCanMessage(can_frame canMsg) { // replace "Template" with yors

    switch (canMsg.can_id) {
        case 0x001: // replace with yors
            this->setCarSpeed(canMsg.data[0]); // replace with yors
        break;

        default:
        break;
    }

}