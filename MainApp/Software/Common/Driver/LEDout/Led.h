

#include "Led_p.h"

#ifndef LED_H
#define LED_H

PUBLIC void SwitchLedOnOff
(
	unsigned char bIsSwitchOn,
	unsigned char LedId
);

PUBLIC void ExclusiveSwitchLedOnOff
(
	unsigned char bIsSwitchOn,
	unsigned char LedId
);

PUBLIC void BlinkLedOnOff
(
	unsigned char LedId , 
	unsigned char BlinkRate ,
	unsigned char bIsBlink
);

PUBLIC void InitializeLed(void);

PUBLIC void ManageLeds(unsigned char LedId);

#endif /* LED_H */