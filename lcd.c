/*
 * lcd.c
 *
 *  Created on: Aug 5, 2017
 *      Author: hosam
 */
#include "Lcd.h"

void clear_returnhome(uint8_t command)
{
	LCD_CTRL_PORT&=~(1<<RS);
	LCD_DATA_PORT=(command&(0xF0));
	LCD_CTRL_PORT|=(1<<E);
	_delay_ms(2);
	LCD_CTRL_PORT&=~(1<<E);
	_delay_ms(2);
//////////////////////////////////////////////////
	LCD_CTRL_PORT&=~(1<<RS);
	LCD_DATA_PORT=(command<<4);
	LCD_CTRL_PORT|=(1<<E);
	_delay_ms(2);
	LCD_CTRL_PORT&=~(1<<E);
	_delay_ms(2);
}

void Lcd_send_command(uint8_t command)
{
	LCD_CTRL_PORT&=~(1<<RS);
	LCD_DATA_PORT=(command&(0xF0));
	LCD_CTRL_PORT|=(1<<E);
	_delay_us(100);
	LCD_CTRL_PORT&=~(1<<E);
	_delay_us(100);
//////////////////////////////////////////////////
	LCD_CTRL_PORT&=~(1<<RS);
	LCD_DATA_PORT=(command<<4);
	LCD_CTRL_PORT|=(1<<E);
	_delay_us(100);
	LCD_CTRL_PORT&=~(1<<E);
	_delay_us(100);
}

void Lcd_init(void)
{
	LCD_CTRL_PORT_DIR=0xFF;
	LCD_DATA_PORT_DIR=0xFF;
	LCD_CTRL_PORT&=~(1<<E);
	Lcd_send_command(0x33);
	Lcd_send_command(0x32);
	clear_returnhome(clear_display);
	clear_returnhome(return_home);
	Lcd_send_command(display_on_cursor_blinking);
	Lcd_send_command(two_lines5x7matrix_D4_D7);
	Lcd_send_command(0x06);                             //shift cursor right
}

void Lcd_send_data(uint8_t data)
{
	LCD_CTRL_PORT|=(1<<RS);
	LCD_DATA_PORT=data&(0xF0);
	LCD_CTRL_PORT|=(1<<E);
	_delay_us(100);
	LCD_CTRL_PORT&=~(1<<E);
	_delay_us(100);
	////////////////////////////////////////////
	LCD_DATA_PORT=(data<<4);
	LCD_CTRL_PORT|=(1<<E);
	_delay_us(100);
	LCD_CTRL_PORT&=~(1<<E);
	_delay_us(100);
}

void Lcd_send_string(uint8_t*string)
{
	uint8_t i=0;
	while(string[i]!=0)
	{
		Lcd_send_data(string[i]);
		i++;
	}
}

void Lcd_go_to(uint8_t row,uint8_t column)
{
	uint8_t position;

	switch (column)
	{
		case 1:position=(0x80)+row;
			break;
		case 2:position=(0xC0)+row;
			break;
		default:position=(0x80);
			break;
	}

	Lcd_send_command(position);
}

