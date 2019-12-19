/* 
 * File: serialATtiny167.h
 * Author(s):  Rubens Fernandes
 *             Samuel Torres  
 * Created on December, 2019 
 */

#ifndef SERIALATTINY167_H
#define SERIALATTINY167_H

/****************DEFINES****************/
#define SAMPLES_PER_BIT 16
#define BAUD 9600
/***************************************/

/***************INCLUDES****************/
#include <avr/io.h>
#include <stdint.h>
/***************************************/

/***************FUNCTIONS***************/
  void initSerial();
  void writeStringSerial(char string[]);
  void store_char(unsigned char c, char stringBuffer[], uint8_t i);
/***************************************/

#endif /*WAKEUPGUARDIAN_H*/
