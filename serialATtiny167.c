/* 
 * File: serialATtiny167.c
 * Author(s):  Rubens Fernandes
 *             Samuel Torres  
 * Created on December, 2019 
 */

#include "serialATtiny167.h"

/**********UART INITIALIZATION*********/
void initSerial()
{
  DDRA = 0;
  DDRA |= (1 << DDA1);
  PORTA |= (1 << PA0);
  
  DDRB |= (1 << DDB1);
  
  LINCR = 0;
  LINBTR = 0;
  LINENIR = 0;
  
  LINCR |= (1 << LCMD2)|(1 << LCMD1)|(1 << LCMD0);
  
  LINBTR = (1 << LDISR) | SAMPLES_PER_BIT; 
  LINBRR = (((F_CPU * 10L / 16L / BAUD) + 5L) / 10L) - 1;

  LINENIR =(1<<LENRXOK);
   
  LINCR |= (1 << LENA);
  
}
/***************************************/

/*************STORAGE CHAR**************/
void store_char(unsigned char c, char stringBuffer[], uint8_t i)
{
  if (stringBuffer[i] != 100) {
    stringBuffer[i] = c;
    //i++;
  }
}
/***************************************/

/**********WRITE STRING*****************/
void writeStringSerial(char string[])
{
   int i = 0;
    while (string[i] != 0x00)
    {
      while ((LINSIR & (1 << LBUSY)));
      LINDAT = string[i];
      while (!(LINSIR & (1 << LTXOK)));
      i++;
    }      
    _delay_ms(1000);
}
/***************************************/
