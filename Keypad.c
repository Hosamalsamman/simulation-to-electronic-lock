/*
 * Keypad.c
 *
 *  Created on: Aug 5, 2017
 *      Author: hosam
 */
#include "Keypad.h"

/* * * *c1  c2 c3
 * row1  1  2  3    PA4
 * row2  4  5  6    PA3
 * row3  7  8  9    PA2
 *     PA7 PA6 PA5
 */

void keypad_init(void)
{

	DDRA=0xE0;//0b11100000;             //(11100000  binary)..........(rows input).........(columns output)

	PORTA=0b00011100;     //  active internal pull up resistor for rows...... output high for columns

}



uint8_t key_pressed (void)
{
	uint8_t key=0;

	while (key==0)
	{
	_delay_ms(5);
	PORTA&=~(1<<PA7);
	PORTA|=(1<<PA5);
	PORTA|=(1<<PA6);
	_delay_ms(5);

		if((PINA&(1<<PA4))==0)
		{
			key=1;
		}
		else if((PINA&(1<<PA3))==0)
			{
			key=4;
			}
		else if((PINA&(1<<PA2))==0)
			{
			key=7;
			}

//////////////////////////////////////////////////////////////////////////////////////
	PORTA&=~(1<<PA6);
	PORTA|=(1<<PA5);
	PORTA|=(1<<PA7);
	_delay_ms(5);


		if((PINA&(1<<PA4))==0)
			{
			key=2;
			}
		else if((PINA&(1<<PA3))==0)
			{
			key=5;
			}
		else if((PINA&(1<<PA2))==0)
			{
			key=8;
			}

//////////////////////////////////////////////////////////////////////////////////////////
	PORTA&=~(1<<PA5);
	PORTA|=(1<<PA6);
	PORTA|=(1<<PA7);
	_delay_ms(5);


		if((PINA&(1<<PA4))==0)
			{
			key=3;
			}
		else if((PINA&(1<<PA3))==0)
			{
			key=6;
			}
		else if((PINA&(1<<PA2))==0)
			{
			key=9;
			}
	}

return key;
}
