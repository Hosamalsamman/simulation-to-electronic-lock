/*
 * I2c.h
 *
 *  Created on: Aug 5, 2017
 *      Author: hosam
 */

#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
void i2c_init(void);
void i2c_start(void);
void i2c_write(uint8_t data);
uint8_t i2c_read(uint8_t byteNum);
void i2c_stop(void);

#endif /* I2C_H_ */
