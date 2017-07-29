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

static unsigned short BCDAlpha[NUMBER_LINES][NUMBER_DIGITS];
static unsigned char bIsAnodeUsed = (unsigned char)0;
static unsigned char BlinkIndex = (unsigned char)0;
static unsigned char BlinkDuration = (unsigned char)0;
static unsigned char LineBlinkIndex = (unsigned char)0;
static unsigned char BlinkFlag = (unsigned char)0;

PUBLIC void BCDInitialize( unsigned char bIsCommonAnode)
{
	bIsAnodeUsed = bIsCommonAnode;
}

PUBLIC void BCDsendNumber
(
    unsigned long Number , 
    unsigned char Line ,       
    unsigned char DecimalPlace,
    unsigned char EnableTranc
)
{
    unsigned long Link,Output,Buffer;
    unsigned char LoopIndex;
 
    Buffer = Number;
    for( LoopIndex = (unsigned char)0; LoopIndex < NUMBER_DIGITS ; LoopIndex++)
    {
        if((Buffer != (unsigned long)0)|| (LoopIndex <= DecimalPlace) )
        { 
            Link = Buffer;
            Buffer = (unsigned long)(Buffer/(unsigned long)10);
            Output = Link - (unsigned long)(Buffer * (unsigned long)10);
         
            BCDAlpha[Line][LoopIndex] = SevenSegmentMAP[Output];
        }
        else if ((LoopIndex <= DecimalPlace)
                                  ||( (unsigned char)0) == EnableTranc)
        {
            BCDAlpha[Line][LoopIndex] = SevenSegmentMAP[0];            
        }
        else
        {
           BCDAlpha[Line][LoopIndex] = 0x0;    
        }
    }    
    if(DecimalPlace != (unsigned char)0)
    {
        BCDAlpha[Line][DecimalPlace] |= SevenSegmentMAP[10];
    }
}

PUBLIC void BCDManage7segment(void)
{
    static unsigned char DigitIndex = (unsigned char)0;
    static unsigned char BlinkCounter = (unsigned char)0;
	static unsigned char LineIndex = (unsigned char)0;
    
    unsigned char Index;
	unsigned char BCD;    

    
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
        
    if( ((unsigned char)1 == BlinkFlag)&& (DigitIndex == BlinkIndex)
            && (LineBlinkIndex == LineIndex))
    {
        BCD = (unsigned char)0;
    }
    else
    {
        BCD = BCDAlpha[LineIndex][DigitIndex];   
    }

    if( (unsigned char)1 == bIsAnodeUsed)
    {
        //Index = (unsigned char)~Index;
        BCD = (unsigned char)~BCD;
    }
   
    
    Index = (unsigned char)(LineIndex * (unsigned char)NUMBER_DIGITS )
                                                                  + DigitIndex;
    //Index = ((NUMBER_DIGITS - DigitIndex)- (unsigned char)1);	
    HWI_4Digit_WRITE(0,Index);
    HWI_8Digit_WRITE(1,BCD);
    
    //PORTD = BCDAlpha[DigitIndex];
    //PORTC =  0xF & (~((unsigned char) 0x8 >> DigitIndex));

    
    
    DigitIndex ++;
    if(DigitIndex == (unsigned char)NUMBER_DIGITS)
    {
        DigitIndex = (unsigned char)0;
        LineIndex++;
        if(LineIndex == (unsigned char)NUMBER_LINES)
        {
            LineIndex = (unsigned char)0;
        }
    }
    
}


PUBLIC void BlinkDigit
(
    unsigned char Index , 
    unsigned char Line, 
    unsigned char duration
)
{
    BlinkIndex = Index;
    BlinkDuration = duration;
    LineBlinkIndex = Line;
}

/* Maximum is number of digits */
PUBLIC void Segment7SendString
(
    unsigned char Position, 
    unsigned char Line,
    unsigned char * Data,
    unsigned char Length
)
{
    unsigned char LoopIndex;
    if((Position + Length ) <= NUMBER_DIGITS)
    {
       for(LoopIndex = Position ; LoopIndex < (Position+Length) ;LoopIndex++)
       {
           BCDAlpha[Line][LoopIndex] = Data[LoopIndex];
       }    
    } 
}