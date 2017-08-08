#include "Extern.h"
	#include "HWI_func.h"


#include "Alloc.h"
	#include "Led.h"

const unsigned char LEDS_CONFIG_ARRAY[NUMBER_LEDS] = LEDS_CONFIG;

PUBLIC void SwitchLedOnOff
(
	unsigned char bIsSwitchOn,
	unsigned char LedId
)
{
	HWI_DIGI_WRITE(LEDS_CONFIG_ARRAY[LedId] , bIsSwitchOn);
}

PUBLIC void ExclusiveSwitchLedOnOff
(
	unsigned char bIsSwitchOn,
	unsigned char LedId
)
{
	unsigned char LedLoopIndex;
	unsigned char OthersOnOff = (unsigned char)0x1 & ((unsigned char)(~bIsSwitchOn));
	HWI_DIGI_WRITE(LEDS_CONFIG_ARRAY[LedId] , bIsSwitchOn);
	for(LedLoopIndex = (unsigned char)0 ; LedLoopIndex < NUMBER_LEDS ; LedLoopIndex++)
	{
		if( LedLoopIndex != LedId)
		{
			HWI_DIGI_WRITE(LEDS_CONFIG_ARRAY[LedLoopIndex] , OthersOnOff);
		}
		else
		{
			
		}
	}
}