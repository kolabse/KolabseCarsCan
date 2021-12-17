#ifndef ALL_CARS_H
#define ALL_CARS_H

#include <Arduino.h>

class AllCars {

    public:
        struct Lamps {
            bool reverse        {false};
            bool leftTurn       {false};
            bool rightTurn      {false};
            bool driverBelt     {false};
            bool doors          {false};
            bool sidelight      {false};
            bool beamLow        {false};
            bool beamHigh       {false};
            bool fogFront       {false};
            bool fogRear        {false};
            bool leftIndcator   {false};
            bool rightIndcator  {false};
            bool fuelLow        {false};
        };

        struct Doors {
            bool frontLeft  {false};
            bool frontRight {false};
            bool backLeft   {false};
            bool backRight  {false};
            bool trunk      {false};
        };

        void setBatteryVoltage(float batteryVoltage);
        void setInstFuelCons(float instFuelCons);
        void setCoolantTemp(int8_t coolantTemp);
        void setOutdoorTemp(int8_t outdoorTemp);
        void setClimateFanSpeed(int8_t climateFanSpeed);
        void setClimateLeftTemp(int8_t climateLeftTemperature);
        void setClimateRightTemp(int8_t climateRightTemperature);
        void setRecyclingAir(bool recyclingAir);
        void setBlowingWindshield(bool blowingWindshield);
        void setSecAfterStart(uint32_t secAfterStart);
        void setEngineRPM(int8_t engineRPM);
        void setCarSpeed(int8_t carSpeed);
        void setIgnitionMode(int8_t ignitionMode);
        void setDashboardLightningBrightnessLevel(int8_t dashboardLightningBrightnessLevel);
        void setEconomyModeIsEnabled(bool economyModeIsEnabled);
        void setDashboardLightningIsEnabled(bool dashboardLightningIsEnabled);
        void setOdometerValue(int8_t odometerValue);
        void setOdometerFromStartValue(int8_t odometerFromStartValue);
        void setLamps(Lamps lamps);
        void setDoors(Doors doors);

        float getBatteryVoltage();
        float getInstFuelCons();
        int8_t getCoolantTemp();
        int8_t getOutdoorTemp();
        int8_t getClimateFanSpeed();
        int8_t getClimateLeftTemp();
        int8_t getClimateRightTemp();
        bool getRecyclingAir();
        bool getBlowingWindshield();
        uint32_t getSecAfterStart();
        int8_t getEngineRPM();
        int8_t getCarSpeed();
        int8_t getIgnitionMode();
        int8_t getDashboardLightningBrightnessLevel();
        bool getEconomyModeIsEnabled();
        bool getDashboardLightningIsEnabled();
        int8_t getOdometerValue();
        int8_t getOdometerFromStartValue();
        Lamps getLamps();
        Doors getDoors();

    private:
        const int startValue    {-99};
        float _batteryVoltage {startValue};                               // Напряжение бортовой сети
        float _instFuelCons {startValue};                                 // Мгновенный расход топлива

        int8_t _coolantTemp {startValue};                                 // Температура охлаждающей жидкости
        int8_t _outdoorTemp {startValue};                                 // Наружная температура
        int8_t _climateFanSpeed {startValue};                             // Выбранная скорость воздушного потока климатичсеской установки
        int8_t _climateLeftTemperature {startValue};                      // Выбранная температура для левой зоны климатической установки
        int8_t _climateRightTemperature {startValue};                     // Выбранная температура для правой зоны климатической установки
        int8_t _engineRPM;                                                // Обороты двигателя
        int8_t _carSpeed;                                                 // Скорость автомобиля
        int8_t _ignitionMode;
        int8_t _dashboardLightningBrightnessLevel;
        int8_t _odometerValue;
        int8_t _odometerFromStartValue;

        uint32_t _secAfterStart;                                          // Секунд после запуска

        bool _recyclingAir {false};                                       // Актиен режим рециркуляции на климатической установке
        bool _blowingWindshield {false};                                  // Активен режим обдува ветрового стекла
        bool _economyModeIsEnabled {false};
        bool _dashboardLightningIsEnabled {false};

        Lamps _lamps;
        Doors _doors;
};

#endif
