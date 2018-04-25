/* main.c
 *
 *  Created on: Jan 4, 2018
 *      Author: hosam
 */
#include <avr/io.h>
#include "Hal/Keypad.h"
#include "Hal/Lcd.h"
#include "Hal/EEPROM.h"
#include "Mcal/I2c.h"

int main(void)
{
	uint8_t typed_password[4];
	uint8_t key_state=0;
	uint8_t check=0;

	keypad_init();
	i2c_init();
	Lcd_init();
	if((eeprom_read(8)))
	{
		Lcd_send_string("creat password");
		for(uint8_t j=0;j<4;j++)
		{
			eeprom_write((j),key_pressed());
			_delay_ms(500);
		}
		eeprom_write(8,0);
	}

_delay_ms(2000);

	while(1)
	{
		clear_returnhome(clear_display);
		clear_returnhome(return_home);
		Lcd_send_string("1open2close3edit");
		key_state=key_pressed();
		_delay_ms(200);
		clear_returnhome(clear_display);
		clear_returnhome(return_home);
		Lcd_send_string("enter password");
		for(uint8_t n=0;n<4;n++)
		{
			typed_password[n]=key_pressed();
			_delay_ms(500);
		}
		clear_returnhome(clear_display);
		clear_returnhome(return_home);

		for(uint8_t x=0;x<4;x++)
		{
			if((typed_password[x])!=(eeprom_read(x)))
				check++;
		}

		if (check)                                                 //not equal
			{
				Lcd_send_string("wrong password");
				_delay_ms(2000);
				continue;									//(return to the first line of while)
			}
		if(key_state==1)
			Lcd_send_string("locker opened");
		else if(key_state==2)
			Lcd_send_string("locker closed");
		else if(key_state==3)
		{
			Lcd_send_string("enter new password");

			for(uint8_t i=0;i<4;i++)
			{
				eeprom_write(i,key_pressed());
				_delay_ms(500);
			}
			clear_returnhome(clear_display);
			clear_returnhome(return_home);

			Lcd_send_string("password saved");
		}
		_delay_ms(3000);
	}

	return 0;
}



