/*
* timer.cpp
*
* Created: 8/18/2020 1:45:46 PM
* Author : Mosiur Rahman Sweet
*/

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h> //instruction 1

void init_timer0(void);

int main(void)
{
	DDRD=0xff;
	
	init_timer0();
	while(1)
	{
	}
}
void init_timer0(void) //instruction 2(a)
{
	TCCR0 |=(0<< CS00) | (1<< CS02); //instruction 3(d)
	TIMSK |=(1<<TOIE0); //instruction 3(c)
	TCNT0 = 255; //instruction 3(b)
	sei();
}

ISR(TIMER0_OVF_vect) //instruction 2(b)
{
	PORTD = PORTD ^ (1<<PD1);
}
