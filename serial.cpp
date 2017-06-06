/*
 * serial.cpp
 *
 *  Created on: 2015. 5. 19.
 *      Author: RTSV
 */
#include "Arduino.h"
#include "serial.h"


void printSerial(char *str)
{
	Serial.println(str);
}

void printInteger(int num)
{
	Serial.println(num);
}



void printByte(byte re)
{
	Serial.println(re);
}

void printFloat(float f)
{
	Serial.println(f);
}
