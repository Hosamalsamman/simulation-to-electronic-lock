/*
 * EEPROM.c
 *
 *  Created on: Aug 5, 2017
 *      Author: hosam
 */
#include "EEPROM.h"
void eeprom_write(uint8_t memoryLocation,uint8_t data)
{
	i2c_init();
	i2c_start();
	i2c_write(slaveAddress);
	i2c_write(memoryLocation);
	i2c_write(data);
	i2c_stop();
	_delay_ms(15);
}


uint8_t eeprom_read(uint8_t memoryLocation)
{
	uint8_t i;
	i2c_init();
	i2c_start();
	i2c_write(slaveAddress);
	i2c_write(memoryLocation);
	i2c_start();
	i2c_write(slaveAddress|(1<<0));
	i=i2c_read(1);
	i2c_stop();
	return i;
}




