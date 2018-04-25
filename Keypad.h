/*
 * Keypad.h
 *
 *  Created on: Aug 5, 2017
 *      Author: hosam
 */
#include <avr/io.h>
#include "../Services layer/PLATFORM_TYPES.h"
#include "util/delay.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_
void keypad_init(void);
uint8_t key_pressed(void);


#endif /* KEYPAD_H_ */
