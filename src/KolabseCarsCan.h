/*
* KolabseCarsCan. Library for storing data about the state of the car and decoding this data from CAN bus messages.
*/
#ifndef CAR_DATA
#define CAR_DATA

#include <Arduino.h>

class KolabseCarsCan {
    #define START_VALUE  -99

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

    private:
        float _batteryVoltage = START_VALUE;                               // Напряжение бортовой сети
        float _instFuelCons = START_VALUE;                                 // Мгновенный расход топлива

        int8_t _coolantTemp = START_VALUE;                                 // Температура охлаждающей жидкости
        int8_t _outdoorTemp = START_VALUE;                                 // Наружная температура
        int8_t _climateFanSpeed = START_VALUE;                             // Выбранная скорость воздушного потока климатичсеской установки
        int8_t _climateLeftTemperature = START_VALUE;                      // Выбранная температура для левой зоны климатической установки
        int8_t _climateRightTemperature = START_VALUE;                     // Выбранная температура для правой зоны климатической установки
        uint32_t _secAfterStart;                                           // Секунд после запуска
        int8_t _engineRPM;                                                 // Обороты двигателя

        bool _recyclingAir = false;                                        // Актиен режим рециркуляции на климатической установке
        bool _blowingWindshield = false;                                   // Активен режим обдува ветрового стекла
};

#endif
