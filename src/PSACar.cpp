#include <Arduino.h>
#include "PSACar.h"

void PSACar::setCanFilters(MCP2515 &mcp2515) {

    // Сбрасываем настройки платы MCP2515
    mcp2515.reset();

    // Устанавливаем скорость шины с которой будем работать и частоту кварца распаянного на плате
    mcp2515.setBitrate(CAN_125KBPS, MCP_16MHZ);

    // Переходим в режим конфигурации аппаратной части
    mcp2515.setConfigMode();
    // Добавляем маски фильтрации сообщений
    mcp2515.setFilterMask(MCP2515::MASK0, false, 0x7FF);
    mcp2515.setFilterMask(MCP2515::MASK1, false, 0x7FF);

    // Добавляем фильтры по id сообщений

    // Зажигание, яркость подсветки, режим энергосбережения http://autowp.github.io/#036
    mcp2515.setFilter(MCP2515::RXF0, false, 0x036);

    // Тахометр, текущая скорость, одометр, расход топлива http://autowp.github.io/#0B6
    mcp2515.setFilter(MCP2515::RXF1, false, 0x0B6);

    // Скорость вращения колес, напряжение аккумулятора http://autowp.github.io/#0E6
    mcp2515.setFilter(MCP2515::RXF2, false, 0x0E6);

    // Зажигание, Температура ОЖ, Одометр, Температура ОС, Задний ход, Правый поворотник, Левый поворотник http://autowp.github.io/#0F6
    mcp2515.setFilter(MCP2515::RXF3, false, 0x0F6);

    // Информация климатческой установки http://autowp.github.io/#1D0
    mcp2515.setFilter(MCP2515::RXF4, false, 0x1D0);
    // http://autowp.github.io/#221
    mcp2515.setFilter(MCP2515::RXF5, false, 0x221);



    // Переходим в режим нормальной работы
    mcp2515.setNormalMode();
}

void PSACar::decodeCanMessage(can_frame canMsg) {

  switch (canMsg.can_id) {

    case 0x036: // BSI Ignition, Dashboard lightning
      this->setEconomyModeIsEnabled(canMsg.data[2] & 0x080);
      this->setDashboardLightningIsEnabled(canMsg.data[3] & 0x020);
      this->setDashboardLightningBrightnessLevel(canMsg.data[3] & 0x00f);
      this->setIgnitionMode(canMsg.data[4] & 0x007);
      break;

    case 0x0A4: // Current track name, radiotext

      break;

    case 0x0B6: // Tachometer, Actual speed, Odometer from start, Fuel consumtion
      this->setEngineRPM(canMsg.data[0] * 0x100 + (canMsg.data[1] >> 3));
      this->setCarSpeed(canMsg.data[2] * 0x100 + canMsg.data[3]);
      break;

    case 0x0DF: // Display menu

      break;

    case 0x0E1: // Parktronic

      break;

    case 0x0E2: // CD-changer, Yatour

      break;

    case 0x0E6: // Wheels rotation, voltage
      this->setBatteryVoltage(roundToTenths((canMsg.data[5] + 144) / 20));
      break;

    case 0x0F6: // Ignition, Coolant temperature, Odometer, Outdoor temperature, Reverse gear light, Turn right light, Turn left light
      this->setCoolantTemp(round(canMsg.data[1] - 39));
      this->setOdometerValue(canMsg.data[2] * 0x010000 + canMsg.data[3] * 0x0100 + canMsg.data[4]);
      this->setOutdoorTemp(round(canMsg.data[6] / 2 - 39.5));

      AllCars::Lamps lamps;
      lamps = this->getLamps();
      lamps.reverse = canMsg.data[7] & 0x080;
      lamps.leftTurn = canMsg.data[7] & 0x002;
      lamps.rightTurn = canMsg.data[7] & 0x001;
      this->setLamps(lamps);
      break;

    case 0x122: // Universal multiplexed panel (Multimedia control)

      break;

    case 0x125: // CD track list, radio list

      break;

    case 0x128: // Dashboard lights

      AllCars::Lamps lamps;
      lamps = this->getLamps();
      lamps.driverBelt = canMsg.data[0] & 0x040;
      lamps.doors = canMsg.data[1] & 0x010;
      lamps.sidelight = canMsg.data[4] & 0x080;
      lamps.beamLow = canMsg.data[4] & 0x040;
      lamps.beamHigh = canMsg.data[4] & 0x020;
      lamps.fogFront = canMsg.data[4] & 0x010;
      lamps.fogRear = canMsg.data[4] & 0x008;
      lamps.leftIndcator = canMsg.data[4] & 0x004;
      lamps.rightIndcator = canMsg.data[4] & 0x002;
      lamps.fuelLow = canMsg.data[5] >> 7;
      this->setLamps(lamps);
      break;

    case 0x131: // CD changer command

      break;

    case 0x162: // Current disk

      break;

    case 0x165: // Radio status

      break;

    case 0x167: // Display status

      break;

    case 0x1A0: // CD changer status

      break;

    case 0x1A1: // Informational message

      break;

    case 0x1A2: // Current disk tracks count

      break;

    case 0x1A5: // Current sound volume level

      break;

    case 0x1D0: // Climate control information
      this->setClimateFanSpeed((getClimateFanSpeed() == 16) ? 0 : canMsg.data[2] + 1);
      this->setClimateLeftTemp(canMsg.data[5]);
      this->setClimateRightTemp(canMsg.data[6]);
      this->setRecyclingAir((canMsg.data[4] & 0x020) >> 5);
      this->setBlowingWindshield((canMsg.data[4] & 0x010) >> 4);
      break;

    case 0x1E0:

      break;

    case 0x1E2: // Current CD changer track

      break;

    case 0x1E5:

      break;

    case 0x1ED: // Display conditioning commands

      break;

    case 0x21F: // Radio remote control under the steering wheel

      break;

    case 0x220: // Doors status

      break;

    case 0x221: // Trip computer info
      this->setInstFuelCons(roundToTenths(((int)canMsg.data[1] << 8 | canMsg.data[2]) / 10));
      break;

    case 0x225: // Radio frequency
      if (canMsg.can_dlc == 5) {
        // if C4 (B3/B5)
      }

      if (canMsg.can_dlc == 6) {
        // if C4 (B3/B5)
      }

      break;

    case 0x261: // Average speed, Vehicle mileage after reset, Liters per 100km

      break;

    case 0x265: // RDS

      break;

    case 0x276: // Date and time

      break;

    case 0x2A1: // Average speed, Vehicle mileage after reset, Liters per 100km

      break;

    case 0x2A5:

      break;

    case 0x2B6: // ASCII coded last 8 VIN digits

      break;

    case 0x2E1:

      break;

    case 0x30D: // Wheels rotation speed

      break;

    case 0x325: // CD tray info

      break;

    case 0x336: // First 3 letters of VIN

      break;

    case 0x365: // CD disk info

      break;

    case 0x39B: // Setup the system time

      break;

    case 0x3A5: // Current playing CD track info

      break;

    case 0x3B6: // 4-9 letters of VIN

      break;

    case 0x3E5: // Buttons Menu, Clim & Trip switches display to that modes

      break;

    case 0x3F6: // Date (possible) and time

      break;

    case 0x51D: // Parktronic

      break;


    case 0x5E0: // Info about radio HW/SW

      break;

    case 0x5E5: // Info about display HW/SW

      break;

    default:
      break;
  }
}

float PSACar::roundToTenths(float value) {
  return round(value * 10) / 10;
}
