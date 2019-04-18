/* * timer.c
 *
 *  Created on: Sep 23, 2018
 *      Author: hosam
 */
#include "timer.h"

uint16_t time_from_first_wrong=0;

void Timer_Start_Count(void)
{
	TCNT0=0;
	TCCR0=0x05;		//normal mode,1024 prescaler.
	TIMSK=(1<<TOIE0);
	sei();
}

ISR(TIMER0_OVF_vect)
{

	time_from_first_wrong++;

	if(time_from_first_wrong==1800)
		{
			time_from_first_wrong=0;
		}
}

