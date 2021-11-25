#include <Arduino.h>
#include "cars.h"

void Cars::setBatteryVoltage(float batteryVoltage) { _batteryVoltage = batteryVoltage; }
void Cars::setInstFuelCons(float instFuelCons) { _instFuelCons = instFuelCons; }
void Cars::setCoolantTemp(int8_t coolantTemp) { _coolantTemp = coolantTemp; }
void Cars::setOutdoorTemp(int8_t outdoorTemp) { _outdoorTemp = outdoorTemp; }
void Cars::setClimateFanSpeed(int8_t climateFanSpeed) { _climateFanSpeed = climateFanSpeed; }
void Cars::setClimateLeftTemp(int8_t climateLeftTemperature) { _climateLeftTemperature = climateLeftTemperature; }
void Cars::setClimateRightTemp(int8_t climateRightTemperature) { _climateRightTemperature = climateRightTemperature; }
void Cars::setRecyclingAir(bool recyclingAir) { _recyclingAir = recyclingAir; }
void Cars::setBlowingWindshield(bool blowingWindshield) { _blowingWindshield = blowingWindshield; }

float Cars::getBatteryVoltage() { return _batteryVoltage; }
float Cars::getInstFuelCons() { return _instFuelCons; }
int8_t Cars::getCoolantTemp() { return _coolantTemp; }
int8_t Cars::getOutdoorTemp() { return _outdoorTemp; }
int8_t Cars::getClimateFanSpeed() { return _climateFanSpeed; }
int8_t Cars::getClimateLeftTemp() { return _climateLeftTemperature; }
int8_t Cars::getClimateRightTemp() { return _climateRightTemperature; }
bool Cars::getRecyclingAir() { return _recyclingAir; }
bool Cars::getBlowingWindshield() { return _blowingWindshield; }
uint32_t Cars::getSecAfterStart() { return millis() / 1000ul; }