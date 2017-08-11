#include <string.h>

#include "Extern.h"
	#include "HWI_func.h"


#include "Alloc.h"
	#include "Led.h"

const unsigned char LEDS_CONFIG_ARRAY[NUMBER_LEDS] = LEDS_CONFIG;
static unsigned char BlinkDuration[NUMBER_LEDS];
static unsigned char bIsBlinkLed[NUMBER_LEDS];
static unsigned char bIsLedOn[NUMBER_LEDS];
static unsigned char BlinkLedCntr[NUMBER_LEDS];
static unsigned char LedturnOnOffFlag[NUMBER_LEDS];


PUBLIC void SwitchLedOnOff
(
	unsigned char bIsSwitchOn,
	unsigned char LedId
)
{
	bIsLedOn[LedId] = bIsSwitchOn;
}

PUBLIC void ExclusiveSwitchLedOnOff
(
	unsigned char bIsSwitchOn,
	unsigned char LedId
)
{
	unsigned char LedLoopIndex;
	unsigned char OthersOnOff = (unsigned char)0x1 & ((unsigned char)(~bIsSwitchOn));
	bIsLedOn[LedId] = bIsSwitchOn;
	for(LedLoopIndex = (unsigned char)0 ; LedLoopIndex < NUMBER_LEDS ; LedLoopIndex++)
	{
		if( LedLoopIndex != LedId)
		{
			bIsLedOn[LedLoopIndex] = OthersOnOff;
		}
		else
		{
			
		}
	}
}

PUBLIC void BlinkLedOnOff
(
	unsigned char LedId , 
	unsigned char BlinkRate ,
	unsigned char bIsBlink
)
{
	BlinkDuration[LedId] = BlinkRate;
	bIsBlinkLed[LedId] = bIsBlink;
}

PUBLIC void InitializeLed(void)
{
	memset(&BlinkDuration , 0 , sizeof(BlinkDuration));
	memset(&bIsBlinkLed , 0 , sizeof(bIsBlinkLed));
	memset(&bIsLedOn , 0 , sizeof(bIsLedOn));
	memset(&BlinkLedCntr , 0 ,sizeof(BlinkLedCntr));
	memset(&LedturnOnOffFlag , 0 , sizeof(LedturnOnOffFlag));
}

PUBLIC void ManageLeds(unsigned char LedId)
{	
	if((unsigned char)1 == bIsLedOn[LedId])
	{
		if( (unsigned char)1 == bIsBlinkLed[LedId])
		{
			if(BlinkLedCntr[LedId] >= BlinkDuration[LedId])
			{
				BlinkLedCntr[LedId] = (unsigned char)0;
				LedturnOnOffFlag[LedId] ^= (unsigned char)1;
			}
			else
			{
				BlinkLedCntr[LedId]++;
			}
		}
		else
		{
			LedturnOnOffFlag[LedId] = (unsigned char)1;
			BlinkLedCntr[LedId] = (unsigned char)0;	
		}
	}
	else
	{
		LedturnOnOffFlag[LedId] = (unsigned char)0;
		BlinkLedCntr[LedId] = (unsigned char)0;	
	}
	HWI_DIGI_WRITE(LEDS_CONFIG_ARRAY[LedId] , LedturnOnOffFlag[LedId]);
}

