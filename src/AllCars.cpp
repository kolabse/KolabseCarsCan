#include <Arduino.h>
#include "AllCars.h"

void AllCars::setBatteryVoltage(float batteryVoltage) { _batteryVoltage = batteryVoltage; }
void AllCars::setInstFuelCons(float instFuelCons) { _instFuelCons = instFuelCons; }
void AllCars::setCoolantTemp(int8_t coolantTemp) { _coolantTemp = coolantTemp; }
void AllCars::setOutdoorTemp(int8_t outdoorTemp) { _outdoorTemp = outdoorTemp; }
void AllCars::setClimateFanSpeed(int8_t climateFanSpeed) { _climateFanSpeed = climateFanSpeed; }
void AllCars::setClimateLeftTemp(int8_t climateLeftTemperature) { _climateLeftTemperature = climateLeftTemperature; }
void AllCars::setClimateRightTemp(int8_t climateRightTemperature) { _climateRightTemperature = climateRightTemperature; }
void AllCars::setRecyclingAir(bool recyclingAir) { _recyclingAir = recyclingAir; }
void AllCars::setBlowingWindshield(bool blowingWindshield) { _blowingWindshield = blowingWindshield; }
void AllCars::setSecAfterStart(uint32_t secAfterStart) { _secAfterStart = secAfterStart; }
void AllCars::setEngineRPM(int8_t engineRPM) { _engineRPM = engineRPM; }
void AllCars::setCarSpeed(int8_t carSpeed) { _carSpeed = carSpeed; }
void AllCars::setIgnitionMode(int8_t ignitionMode) { _ignitionMode = ignitionMode; }
void AllCars::setDashboardLightningBrightnessLevel(int8_t dashboardLightningBrightnessLevel) { _dashboardLightningBrightnessLevel = dashboardLightningBrightnessLevel; }
void AllCars::setEconomyModeIsEnabled(bool economyModeIsEnabled) { _economyModeIsEnabled = economyModeIsEnabled; }
void AllCars::setDashboardLightningIsEnabled(bool dashboardLightningIsEnabled) { _dashboardLightningIsEnabled = dashboardLightningIsEnabled; }

float AllCars::getBatteryVoltage() { return _batteryVoltage; }
float AllCars::getInstFuelCons() { return _instFuelCons; }
int8_t AllCars::getCoolantTemp() { return _coolantTemp; }
int8_t AllCars::getOutdoorTemp() { return _outdoorTemp; }
int8_t AllCars::getClimateFanSpeed() { return _climateFanSpeed; }
int8_t AllCars::getClimateLeftTemp() { return _climateLeftTemperature; }
int8_t AllCars::getClimateRightTemp() { return _climateRightTemperature; }
bool AllCars::getRecyclingAir() { return _recyclingAir; }
bool AllCars::getBlowingWindshield() { return _blowingWindshield; }
uint32_t AllCars::getSecAfterStart() { return _secAfterStart; }
int8_t AllCars::getEngineRPM() {return _engineRPM; }
int8_t AllCars::getCarSpeed() {return _carSpeed; }
int8_t AllCars::getIgnitionMode() { return _ignitionMode; }
int8_t AllCars::getDashboardLightningBrightnessLevel() { return _dashboardLightningBrightnessLevel; }
bool AllCars::getEconomyModeIsEnabled() { return _economyModeIsEnabled; }
bool AllCars::getDashboardLightningIsEnabled() { return _dashboardLightningIsEnabled; }
