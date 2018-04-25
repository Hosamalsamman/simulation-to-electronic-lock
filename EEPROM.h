/*
 * EEPROM.h
 *
 *  Created on: Aug 5, 2017
 *      Author: hosam
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "../Mcal/I2c.h"
#include "util/delay.h"
#define slaveAddress 0b10100100



void eeprom_write(uint8_t memoryLocation,uint8_t data);
uint8_t eeprom_read(uint8_t memoryLocation);


#endif /* EEPROM_H_ */
