/* This library is suitable for DYP R01 IIC*/
#ifndef DYPR01_H
#define DYPR01_H
#include "Arduino.h"
class DYPR01
{
private:
    byte Address;
public:
    int Search();  //retrieve an address of a device;
    uint16_t Distance(byte Address);//return distance value;
};

#endif