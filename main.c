#include <avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"

#define ones	0x02
#define tens	0x01


int main(void)
{
	u8 numbers[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

	DDRB = 0xff;
	DDRA = 0xff;

	PORTA = 0x03;

	while(1)
	{
		for(u8 i=0; i<10; i++)
		{
			u8 time = 50;
			while(time--)
			{
				PORTB = numbers[9-i];
				PORTA = tens;
				_delay_ms(10);
				PORTB = numbers[i];
				PORTA = ones;
				_delay_ms(10);
			}
		}
	}

	return 0;
}
