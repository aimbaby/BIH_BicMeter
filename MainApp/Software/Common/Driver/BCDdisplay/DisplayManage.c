#include "Extern.h"
      #include "BCDdisplay.h"
#include "Alloc.h"
      #include "DisplayManage.h"

#define NUMBER_ASCII    26

const unsigned char Segment7ASCIItable[NUMBER_ASCII]=
{
    0b11101110, //A
    0b00111110, //b
    0b10011100, //C
    0b01111010, //d
    0b10011110, //E
    0b10001110, //F
    0b11110110, //g
    0b00101110, //h
    0b00001000, //I
    0b01111000, //J
    0b00000000, //K
    0b00000000, //L
    0b00000000, //M
    0b00000000, //N
    0b00000000, //O
    0b00000000, //P
    0b00000000, //Q
    0b00001010, //r
    0b10110110, //S
    0b00000000, //T
    0b00000000, //U
    0b01111100, //V
    0b00000000, //W
    0b00000000, //X
    0b00000000, //Y
    0b00000000  //Z
};

PUBLIC void DisplaySendString
( 
    unsigned char Position, 
    unsigned char Line,
    char * Data, 
    unsigned char Length
)
{
    unsigned char ConvertedData[NUMBER_DIGITS];
    unsigned char LoopIndex;
    unsigned char TempStore;
   
    for(LoopIndex = (unsigned char)0 ;LoopIndex < Length ; LoopIndex++)
    {
        if((Data[LoopIndex] >= (unsigned char) 0x41)
                &&(Data[LoopIndex] <= (unsigned char)0x66))
        {
            TempStore = (unsigned char)Data[LoopIndex] - (unsigned char)0x41;
            ConvertedData[(Length - (unsigned char)1)- LoopIndex] 
                                               = Segment7ASCIItable[TempStore];
        }     
		else
		{
			ConvertedData[(Length - (unsigned char)1)- LoopIndex] 
			                                   = (unsigned char)Data[LoopIndex];
		}			   
    }
    Segment7SendString(Position , Line , &ConvertedData[0] , Length);
}