 #include "TargetFile.h"


#include "Alloc.h"
  #include "HWI_func.h"
  

PUBLIC void HWI_DIGITAL_INITIALIZE(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = (1<<PIND0) | (1<<PIND1) | (1<<PIND7);
	PORTD = (unsigned char)~((1<<PIND0) | (1<<PIND1) | (1<<PIND7));
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
PUBLIC void HWI_DIGI_WRITE(unsigned char pin,unsigned char val)
{
	switch(pin)
	{
		case 0:
			PORTD = (PORTD & ((unsigned char)~(1<<PIND0))) | ((val & (unsigned char)0x1)<<PIND0);
			break;
		case 1:
			PORTD = (PORTD & ((unsigned char)~(1<<PIND1))) | ((val & (unsigned char)0x1)<<PIND1);
			break;
		case 2:
			PORTD = (PORTD & ((unsigned char)~(1<<PIND7))) | ((val & (unsigned char)0x1)<<PIND7);
			break;
		case 3:
			PORTC = (PORTC & ((unsigned char)~(1<<PINC5))) | ((val & (unsigned char)0x1)<<PINC5);
			break;
		case 4:
			break;
		case 5:
			PORTC = (PORTC & ((unsigned char)~(1<<PINC4))) | ((val & (unsigned char)0x1)<<PINC4);
			break;
		case 6:
			PORTC = (PORTC & ((unsigned char)~(1<<PINC3))) | ((val & (unsigned char)0x1)<<PINC3);
			break;
		default:
			break;
	}
}

PUBLIC void HWI_4Digit_WRITE(unsigned char port,unsigned char val)
{
	switch (port)
	{
		case 0:
			PORTC = (PORTC & 0xF8) | val;
			break;
		case 1:
			PORTB = (PORTB & 0xF0) | val;
			break;
		default:
			PORTB = (PORTB & 0xF0) | val;
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

PUBLIC void HWI_8Digit_WRITE(unsigned char port,unsigned char val)
{
	switch (port)
	{
		case 0:
			PORTC = val;
			break;
		case 1:
			PORTB = val;
			break;
		default:
			PORTB = val;
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
