/* 
 * File: adcATtiny167.c
 * Author(s):  Rubens Fernandes
 *             Samuel Torres  
 * Created on December, 2019 
 */

#include "adcATtiny167.h"

/**********ADC INITIALIZATION*********/
void adcInit(void)
{
  ADMUX = 0;
  ADMUX |= (0 << ADLAR)|(1 << MUX1)|(1 << MUX2);
  ADCSRA |= (1 << ADEN)|(1 << ADPS2)|(1 << ADPS0);
}
/*************************************/

/**************ADC READ***************/
int adcRead(void)
{
  uint16_t adcValue;
  uint8_t adclValue;
  
  ADCSRA |= (1 << ADSC);
  while (ADCSRA & (1 << ADSC));

  adclValue = ADCL;
  adcValue = (ADCH << 8)|adclValue;    

  return adcValue;
}
/*************************************/
