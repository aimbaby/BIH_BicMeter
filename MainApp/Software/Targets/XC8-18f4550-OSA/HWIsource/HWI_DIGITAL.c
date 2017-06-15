 #include <xc.h>


#include "Alloc.h"
  #include "HWI_func.h"
  

PUBLIC void HWI_4Digit_WRITE(unsigned char port,unsigned char value)
{
    switch (port)
    {
        case 0:
            PORTC = (LATC & 0xF0) | value;
            break;
        case 1:
            PORTD = (LATD & 0xF0) | value;
            break;
        default:
            PORTD = (LATD & 0xF0) | value;
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
            PortValue = PORTD & 0x0f;
            break;
        default:
            PortValue = PORTD & 0x0f;
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
            PORTD = value;
            break;
        default:
            PORTD = value;
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
            PortValue = PORTD;
            break;
        default:
            PortValue = PORTD;
            break;
    }
    return PortValue;
}


PUBLIC void HWI_DIGITAL_INITIALIZE(void)
{

    TRISD = 0x0;
    PORTD = 0x0;
    
    TRISC = 0x0;
    TRISBbits.RB2 = 1;
    TRISBbits.RB3 = 1;
    
    TRISBbits.RB6 =0;
    TRISBbits.RB7 =0;
}
  
PUBLIC unsigned char HWI_DIGI_READ(unsigned char pin)
{
    unsigned char HWIread;
    
    switch (pin)
    {
        case 15:
            HWIread = PORTBbits.RB2;
            break;
        case 16:
            HWIread = PORTBbits.RB3;
            break;
        default:
            break;
    }
 return HWIread;
}
PUBLIC void HWI_DIGI_WRITE(unsigned char pin,unsigned char value)
{
}