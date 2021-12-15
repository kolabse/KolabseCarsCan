#ifndef ALL_CARS_H
#define ALL_CARS_H

#include <Arduino.h>

class AllCars {

    public:
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

    private:
        const int startValue    {-99};
        float _batteryVoltage {startValue};                               // Напряжение бортовой сети
        float _instFuelCons {startValue};                                 // Мгновенный расход топлива

        int8_t _coolantTemp {startValue};                                 // Температура охлаждающей жидкости
        int8_t _outdoorTemp {startValue};                                 // Наружная температура
        int8_t _climateFanSpeed {startValue};                             // Выбранная скорость воздушного потока климатичсеской установки
        int8_t _climateLeftTemperature {startValue};                      // Выбранная температура для левой зоны климатической установки
        int8_t _climateRightTemperature {startValue};                     // Выбранная температура для правой зоны климатической установки
        uint32_t _secAfterStart;                                          // Секунд после запуска
        int8_t _engineRPM;                                                // Обороты двигателя
        int8_t _carSpeed;                                                 // Скорость автомобиля

        bool _recyclingAir = false;                                       // Актиен режим рециркуляции на климатической установке
        bool _blowingWindshield = false;                                  // Активен режим обдува ветрового стекла
};

#endif
