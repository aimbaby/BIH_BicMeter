 #include "TargetFile.h"


#include "Alloc.h"
  #include "HWI_func.h"
  

PUBLIC void HWI_DIGITAL_INITIALIZE(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
}
  
PUBLIC unsigned char HWI_DIGI_READ(unsigned char pin)
{
 return (0);
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
	  }
	
}
PUBLIC unsigned char HWI_4Digit_READ(unsigned char port)
{
	unsigned char PortValue;
	switch (port)
	{
		case 0:
		PortValue = PORTC & 0x0f;
		break;
		case 1:
		PortValue = PORTB & 0x0f;
		break;
		default:
		PortValue = PORTB & 0x0f;
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
	}
	
}
PUBLIC unsigned char HWI8Digit_READ(unsigned char port)
{
	unsigned char PortValue;
	switch (port)
	{
		case 0:
		PortValue = PORTC;
		break;
		case 1:
		PortValue = PORTB;
		break;
		default:
		PortValue = PORTB;
		break;
	}
	return PortValue;
	
}
