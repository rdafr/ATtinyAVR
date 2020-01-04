/* 
 * File: adcATtiny167.h
 * Author(s):  Rubens Fernandes
 *             Samuel Torres  
 * Created on December, 2019 
 */

#ifndef ADCATTINY167_H
#define ADCATTINY167_H

/***************INCLUDES****************/
#include <avr/io.h>
#include <stdint.h>
/***************************************/

/***************FUNCTIONS***************/
  void adcInit(void); //EXAMPLE OF HOW TO INITIALIZE ADC
  int adcRead(void);
/***************************************/

#endif /*ADCATTINY167_H*/
