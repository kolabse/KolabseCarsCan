/**
 * KolabseCarsCan
 * Storing data about the state of the car and decoding this data from CAN bus messages
 * This library allows you to decode messages received from CAN-bus and store this info about car state.
 *
 * authors:
 * Kolabse [https://github.com/kolabse]
 * Sonc [https://github.com/Sonc-man]
 *
 * define CAR_TYPE in your code before include this library
 * CAR_TYPE posible values:
 *  0 - without can decode, only store data;
 *  1 - PSACars - see PSACars.h
 *
*/

#ifndef KOLABSE_CARS_CAN_H
#define KOLABSE_CARS_CAN_H

#ifndef CAR_TYPE
    #define CAR_TYPE 0
#endif

#include <Arduino.h>
#include "AllCars.h"

#if CAR_TYPE == 1
    #include "PSACar.h"
    #define CAR_CLASS  : public PSACar
// COPY and uncomment this part if you added new car decoder
//#elif CAR_TYPE == 2                           // replace "2" with yours
//    #include "TemplateCar.h"                  // replace "Template" with yours
//    #define CAR_CLASS  : public TemplateCar   // replace "Template" with yours
#else
    #define CAR_CLASS  : public AllCars
#endif

class KolabseCarsCan CAR_CLASS {

};

extern KolabseCarsCan car;
#endif
