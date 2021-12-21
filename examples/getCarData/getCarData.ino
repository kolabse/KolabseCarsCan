/**
 * @file getCarData.ino
 * @author kolabse (https://github.com/kolabse)
 * @brief KolabseCarsCan use example
 * CAR_TYPE:
 *  0 - without can decode, only store data;
 *  1 - PSACars - see PSACars.h
 * @version 0.1
 * @date 2021-12-20
 */

#define CAR_TYPE 1

#include <SPI.h>
#include <mcp2515.h>
#include <KolabseCarsCan.h>

// SC pin of CAN-BUS Shield
const int mcpScPin      {10};
// Default value for most car properties
const int startValue    {-99};

// CAN-BUS Shield object
MCP2515 mcp2515(mcpScPin);

// CAN-BUS Shield message
struct can_frame canMsg;

void setup() {
    // Setup filters for CAN-BUS messages by message ID (optional)
    car.setCanFilters(mcp2515);

    Serial.begin(115200);

}

void loop() {

    // if message is present
    if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
        // send it to library to decode and store data in car properties
        car.decodeCanMessage(canMsg);
    }

    // Print decoded car data to serial port
    if (car.getBatteryVoltage() != startValue) {
        Serial.print(car.getBatteryVoltage());
        Serial.print("v ");
    }

    if (car.getCoolantTemp() != startValue) {
        Serial.print(car.getCoolantTemp());
        Serial.print("°C ");
    }

    if (car.getOutdoorTemp() != startValue) {
        Serial.print(car.getOutdoorTemp());
        Serial.print("°C ");
    }

    if (car.getInstFuelCons() != startValue) {
        Serial.print(car.getInstFuelCons());
        Serial.print("L/100km ");
    }

    if (car.getClimateFanSpeed() != startValue) {
        Serial.print(car.getClimateFanSpeed());
        Serial.print("sp. ");
    }

    if (car.getClimateLeftTemp() != startValue) {
        Serial.print(car.getClimateLeftTemp());
        Serial.print("°C ");
    }

    if (car.getClimateRightTemp() != startValue) {
        Serial.print(car.getClimateRightTemp());
        Serial.print("°C ");
    }

    if (car.getRecyclingAir() != startValue) {
        Serial.print("is_rc: ");
        Serial.print(car.getRecyclingAir());
    }

    if (car.getBlowingWindshield() != startValue) {
        Serial.print(" is_bw: ");
        Serial.print(car.getBlowingWindshield());
    }

    Serial.println();
}