#include <xc.h>
#include "Alloc.h"
      #include "BCDdisplay.h"

const unsigned char SevenSegmentMAP[11] =
{
    0b11111100, //0
    0b01100000, //1
    0b11011010, //2
    0b11110010, //3
    0b01100110, //4
    0b10110110, //5
    0b10111110, //6
    0b11100000, //7
    0b11111110, //8
    0b11110110, //9
    0b00000001  //.
};

static unsigned short BCDNumber[NUMBER_DIGITS];

PUBLIC void BCDsendNumber( unsigned short Number)
{
    unsigned short Link,Output,Buffer;
    unsigned char LoopIndex;
    
 
    Buffer = Number;
    for( LoopIndex = (unsigned char)0; LoopIndex < NUMBER_DIGITS ; LoopIndex++)
    {
        if((Buffer != (unsigned short)0)|| (LoopIndex <= (unsigned short)1)) 
        { 
            Link = Buffer;
            Buffer /= (unsigned short)10;
            Output = Link - (unsigned short)(Buffer * (unsigned short)10);
         
            BCDNumber[LoopIndex] = SevenSegmentMAP[Output];
        }
        else if (LoopIndex <= (unsigned short)1)
        {
            BCDNumber[LoopIndex] = SevenSegmentMAP[0];            
        }
        else
        {
           BCDNumber[LoopIndex] = 0x0;    
        }
    }    
    BCDNumber[1] |= SevenSegmentMAP[10];
}

PUBLIC void BCDManage7segment(void)
{
    static unsigned char DigitIndex = (unsigned char)0;    
    //PORTD = BCDNumber/10;

    PORTD = BCDNumber[DigitIndex];
    PORTC =  0xF & (~((unsigned char) 0x8 >> DigitIndex));

    DigitIndex ++;
    if(DigitIndex == NUMBER_DIGITS)
    {
        DigitIndex = (unsigned char)0;
    }
    
}
