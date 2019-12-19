/* 
 * File: eepromATtiny167.h
 * Author(s):  Rubens Fernandes
 *             Samuel Torres  
 * Created on December, 2019 
 */

#include "eepromATtiny167.h"

unsigned char eeprom_read(unsigned int address) {
	while(EECR & (1 << EEPE));
	EEAR = address;
	EECR |= (1 << EERE);
	return EEDR;
}

void eeprom_write(unsigned int address, unsigned char data) {
	while(EECR & (1 << EEPE));
  EECR &= ~(1 << EEPM1);
  EECR &= ~(1 << EEPM0);	
	EEAR = address;	
	EEDR = data;
	EECR |= (1 << EEMPE);
	EECR |= (1 << EEPE);
}

void eeprom_erase(unsigned int address) {
	EECR &= ~(1 << EEPM1);
  EECR |= (1 << EEPM0);
	eeprom_write(address, 0x00);
}
