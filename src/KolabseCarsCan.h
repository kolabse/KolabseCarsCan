/**
 * KolabseCarsCan. Library for storing data about the state of the car and decoding this data from CAN bus messages.
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
#else
    #define CAR_CLASS  : public AllCars
#endif

class KolabseCarsCan CAR_CLASS {

};

#endif
