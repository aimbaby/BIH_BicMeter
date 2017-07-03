#include "TargetFile.h"

#include "Extern.h"
      #include "HWI_func.h"
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

static unsigned short BCDAlpha[NUMBER_DIGITS];
static unsigned char bIsAnodeUsed = (unsigned char)0;
static unsigned char BlinkIndex = (unsigned char)0;
static unsigned char BlinkDuration = (unsigned char)0;
static unsigned char BlinkFlag = (unsigned char)0;

PUBLIC void BCDInitialize( unsigned char bIsCommonAnode)
{
	bIsAnodeUsed = bIsCommonAnode;
}

PUBLIC void BCDsendNumber
(
    unsigned short Number , 
    unsigned char DecimalPlace,
    unsigned char EnableTranc
)
{
    unsigned short Link,Output,Buffer;
    unsigned char LoopIndex;
 
    Buffer = Number;
    for( LoopIndex = (unsigned char)0; LoopIndex < NUMBER_DIGITS ; LoopIndex++)
    {
        if((Buffer != (unsigned short)0)|| (LoopIndex <= DecimalPlace) )
        { 
            Link = Buffer;
            Buffer = (unsigned short)(Buffer/(unsigned short)10);
            Output = Link - (unsigned short)(Buffer * (unsigned short)10);
         
            BCDAlpha[LoopIndex] = SevenSegmentMAP[Output];
        }
        else if ((LoopIndex <= DecimalPlace)
                                  ||( (unsigned char)0) == EnableTranc)
        {
            BCDAlpha[LoopIndex] = SevenSegmentMAP[0];            
        }
        else
        {
           BCDAlpha[LoopIndex] = 0x0;    
        }
    }    
    if(DecimalPlace != (unsigned char)0)
    {
        BCDAlpha[DecimalPlace] |= SevenSegmentMAP[10];
    }
}

PUBLIC void BCDManage7segment(void)
{
    static unsigned char DigitIndex = (unsigned char)0;
    static unsigned char BlinkCounter = (unsigned char)0;
	unsigned char Index;
	unsigned char BCD = (unsigned char)0;    
    //PORTD = BCDAlpha/10;
    
    if( BlinkDuration != (unsigned char)0)
    {
       BlinkCounter++;
       if(BlinkCounter == BlinkDuration)
       {
           BlinkFlag ^= (unsigned char)1;
           BlinkCounter = (unsigned char)0;
       }
    }
    else
    {
       BlinkFlag = (unsigned char)0;    
    }
        
    if( ((unsigned char)1 == BlinkFlag)&& (DigitIndex == BlinkIndex))
    {
        Index = (unsigned char)0xF;
    }
    else
    {
        Index = (~(((unsigned char) 0x1 << ((NUMBER_DIGITS - DigitIndex) 
                                        - (unsigned char)1))));
        BCD = BCDAlpha[DigitIndex];   
    }

    if( (unsigned char)1 == bIsAnodeUsed)
    {
        Index = (unsigned char)~Index;
        BCD = (unsigned char)~BCD;
    }
    			
    HWI_4Digit_WRITE(0,Index);
    HWI_8Digit_WRITE(1,BCD);
    
    //PORTD = BCDAlpha[DigitIndex];
    //PORTC =  0xF & (~((unsigned char) 0x8 >> DigitIndex));

    
    
    DigitIndex ++;
    if(DigitIndex == NUMBER_DIGITS)
    {
        DigitIndex = (unsigned char)0;
    }
    
}


PUBLIC void BlinkDigit(unsigned char Index , unsigned char duration)
{
    BlinkIndex = Index;
    BlinkDuration = duration;
}

/* Maximum is number of digits */
PUBLIC void Segment7SendString
(
    unsigned char Position, 
    unsigned char * Data,
    unsigned char Length
)
{
    unsigned char LoopIndex;
    if((Position + Length ) <= NUMBER_DIGITS)
    {
       for(LoopIndex = Position ; LoopIndex < (Position+Length) ;LoopIndex++)
       {
           BCDAlpha[LoopIndex] = Data[LoopIndex];
       }    
    } 
}