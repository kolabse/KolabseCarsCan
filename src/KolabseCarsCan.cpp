#include <Arduino.h>
#include "KolabseCarsCan.h"

void KolabseCarsCan::setBatteryVoltage(float batteryVoltage) { _batteryVoltage = batteryVoltage; }
void KolabseCarsCan::setInstFuelCons(float instFuelCons) { _instFuelCons = instFuelCons; }
void KolabseCarsCan::setCoolantTemp(int8_t coolantTemp) { _coolantTemp = coolantTemp; }
void KolabseCarsCan::setOutdoorTemp(int8_t outdoorTemp) { _outdoorTemp = outdoorTemp; }
void KolabseCarsCan::setClimateFanSpeed(int8_t climateFanSpeed) { _climateFanSpeed = climateFanSpeed; }
void KolabseCarsCan::setClimateLeftTemp(int8_t climateLeftTemperature) { _climateLeftTemperature = climateLeftTemperature; }
void KolabseCarsCan::setClimateRightTemp(int8_t climateRightTemperature) { _climateRightTemperature = climateRightTemperature; }
void KolabseCarsCan::setRecyclingAir(bool recyclingAir) { _recyclingAir = recyclingAir; }
void KolabseCarsCan::setBlowingWindshield(bool blowingWindshield) { _blowingWindshield = blowingWindshield; }
void KolabseCarsCan::setSecAfterStart(uint32_t secAfterStart) { _secAfterStart = secAfterStart; }
void KolabseCarsCan::setEngineRPM(int8_t engineRPM) { _engineRPM = engineRPM; }

float KolabseCarsCan::getBatteryVoltage() { return _batteryVoltage; }
float KolabseCarsCan::getInstFuelCons() { return _instFuelCons; }
int8_t KolabseCarsCan::getCoolantTemp() { return _coolantTemp; }
int8_t KolabseCarsCan::getOutdoorTemp() { return _outdoorTemp; }
int8_t KolabseCarsCan::getClimateFanSpeed() { return _climateFanSpeed; }
int8_t KolabseCarsCan::getClimateLeftTemp() { return _climateLeftTemperature; }
int8_t KolabseCarsCan::getClimateRightTemp() { return _climateRightTemperature; }
bool KolabseCarsCan::getRecyclingAir() { return _recyclingAir; }
bool KolabseCarsCan::getBlowingWindshield() { return _blowingWindshield; }
uint32_t KolabseCarsCan::getSecAfterStart() { return _secAfterStart; }
int8_t KolabseCarsCan::getEngineRPM() {return _engineRPM; }
