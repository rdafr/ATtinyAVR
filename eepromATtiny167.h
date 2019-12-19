/* 
 * File: eepromATtiny167.h
 * Author(s):  Rubens Fernandes
 *             Samuel Torres  
 * Created on December, 2019 
 */

#ifndef __EEPROMATTINY167_H__
#define __EEPROMATTINY167_H__

#include <avr/io.h>

  unsigned char eeprom_read(unsigned int address);
  void eeprom_write(unsigned int address, unsigned char data);
  void eeprom_erase(unsigned int address);

#endif /* __EEPROMATTINY167_H__ */
