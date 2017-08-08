

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

#endif /* LED_H */