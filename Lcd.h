/*
 * Lcd.h
 *
 *  Created on: Aug 5, 2017
 *      Author: hosam
 */

#ifndef LCD_H_
#define LCD_H_

#define RS PC6
#define E  PC7

#define LCD_CTRL_PORT PORTC
#define LCD_CTRL_PORT_DIR DDRC
#define LCD_DATA_PORT PORTB
#define LCD_DATA_PORT_DIR DDRB


#define clear_display (0x01)
#define return_home (0x02)
#define display_on_cursor_blinking (0xF0)
#define two_lines5x7matrix_D4_D7 (0x28)

#include <avr/io.h>
#include "../Services layer/PLATFORM_TYPES.h"
#include "util/delay.h"

void clear_returnhome(uint8_t command);
void Lcd_send_command(uint8_t command);
void Lcd_init(void);
void Lcd_send_data(uint8_t data);
void Lcd_send_string(uint8_t*string);
void Lcd_go_to(uint8_t row,uint8_t column);

#endif /* LCD_H_ */
