 #include "TargetFile.h"


#include "Alloc.h"
  #include "HWI_func.h"
  

PUBLIC void HWI_DIGITAL_INITIALIZE(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x0;
	PORTD = 0xFF;
}
  
PUBLIC unsigned char HWI_DIGI_READ(unsigned char pin)
{
	unsigned char HWIread;
	    
	switch (pin)
	{
		case 15:
			HWIread = PIND & (1 << PIND4);
			break;
		case 16:
			HWIread = PIND & (1 << PIND5);
			break;
		case 17:
			HWIread = PIND & (1 << PIND6);
			break;
		default:
		    HWIread = (unsigned char)0;
			break;
	}
	return HWIread;
}
PUBLIC void HWI_DIGI_WRITE(unsigned char pin,unsigned char value)
{
}

PUBLIC void HWI_4Digit_WRITE(unsigned char port,unsigned char value)
{
	switch (port)
	{
		case 0:
			PORTC = (PORTC & 0xF0) | value;
			break;
		case 1:
			PORTB = (PORTB & 0xF0) | value;
			break;
		default:
			PORTB = (PORTB & 0xF0) | value;
			break;
	}
	
}
PUBLIC unsigned char HWI_4Digit_READ(unsigned char port)
{
	unsigned char PortValue;
	switch (port)
	{
		case 0:
			PortValue = PINC & 0x0f;
			break;
		case 1:
			PortValue = PINB & 0x0f;
			break;
		default:
			PortValue = PINB & 0x0f;
			break;
	}
	return PortValue;
}

PUBLIC void HWI_8Digit_WRITE(unsigned char port,unsigned char value)
{
	switch (port)
	{
		case 0:
			PORTC = value;
			break;
		case 1:
			PORTB = value;
			break;
		default:
			PORTB = value;
			break;
	}
	
}
PUBLIC unsigned char HWI8Digit_READ(unsigned char port)
{
	unsigned char PortValue;
	switch (port)
	{
		case 0:
			PortValue = PINC;
			break;
		case 1:
			PortValue = PINB;
			break;
		default:
			PortValue = PINB;
			break;
	}
	return PortValue;
	
}
