/* 
 * File:   Key.h
 * Author: ??????
 *
 * Created on 14 ?????, 2017, 06:33 ?
 */

#include "Key_p.h"

#ifndef KEY_H
#define	KEY_H

#define STATE_NOT_PRESSED                (unsigned char)0x00
#define STATE_SHORT_PRESS                (unsigned char)0x01
#define STATE_LONG_PRESS                 (unsigned char)0x02

#define CAPTURE_STATE_SHORT_PRESS          (unsigned char)0x40
#define CAPTURE_STATE_LONG_PRESS           (unsigned char)0x80
#define NEW_STATE_SHORT_PRESS                (unsigned char)0x81
#define NEW_STATE_LONG_PRESS                 (unsigned char)0x82

typedef struct
{
   unsigned char HWI_ID;
   unsigned char ActiveValue;
   unsigned short ReleaseTicks;
   unsigned short ShortPress;
   unsigned short LongPress;   
}strKeyConfig;

typedef struct
{
    unsigned char KeyState;
    unsigned short KeyCounter;
}strKeyData;

PUBLIC void KeyInitialize(void);

PUBLIC unsigned char GetKeyStatus(unsigned char KeyID);

PUBLIC void MangeKeys(unsigned char KeyID);

#endif	/* KEY_H */

