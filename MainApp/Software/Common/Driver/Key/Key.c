#include "TargetFile.h"
#include <string.h>

#include "Extern.h"
      #include "HWI_func.h"
#include "Alloc.h"  
      #include "Key.h"

#define STATE_MASK             (unsigned char)0x3F

const strKeyConfig KeyArrayConfig[NUMBER_KEYS] =  KEYS_CONFIG;
static strKeyData KeyInternalData[NUMBER_KEYS];

PUBLIC void KeyInitialize(void)
{
    memset(KeyInternalData , 0 ,sizeof(KeyInternalData));
}

PUBLIC unsigned char GetKeyStatus(unsigned char KeyID)
{
    unsigned char KeyStatus;
    
    KeyStatus = KeyInternalData[KeyID].KeyState;
    KeyInternalData[KeyID].KeyState &= STATE_MASK;
    
    return KeyStatus;
}

PUBLIC void MangeKeys(unsigned char KeyID)
{
    unsigned char HWIreading;
    unsigned char KeyState;
    
    KeyState = KeyInternalData[KeyID].KeyState & STATE_MASK;
    HWIreading = HWI_DIGI_READ(KeyArrayConfig[KeyID].HWI_ID);
    
    switch(KeyState)
    {
        case STATE_NOT_PRESSED:
            if( KeyArrayConfig[KeyID].ActiveValue == HWIreading)
            {
                KeyInternalData[KeyID].KeyCounter++;
                if(KeyArrayConfig[KeyID].ShortPress == 
                                              KeyInternalData[KeyID].KeyCounter)
                {
                    KeyInternalData[KeyID].KeyState = NEW_STATE_SHORT_PRESS;
                    KeyInternalData[KeyID].KeyCounter = 
                                          KeyArrayConfig[KeyID].ReleaseTicks;
                }
            }
            else
            {
                KeyInternalData[KeyID].KeyCounter = (unsigned short)0;
            }
            break;
        case STATE_SHORT_PRESS:
            if( KeyArrayConfig[KeyID].ActiveValue == HWIreading)
            {
                if ( KeyInternalData[KeyID].KeyCounter >= 
                                             KeyArrayConfig[KeyID].ReleaseTicks)
                {
                    KeyInternalData[KeyID].KeyCounter++;
                    if(KeyArrayConfig[KeyID].LongPress == 
                                              KeyInternalData[KeyID].KeyCounter)
                    {
                        KeyInternalData[KeyID].KeyState = NEW_STATE_LONG_PRESS;
                        KeyInternalData[KeyID].KeyCounter = 
                                             KeyArrayConfig[KeyID].ReleaseTicks;
                    }
                }
                else
                {
                        KeyInternalData[KeyID].KeyCounter = 
                                            KeyArrayConfig[KeyID].ReleaseTicks;
                }
            }
            else
            {
                if ( KeyInternalData[KeyID].KeyCounter > 
                                             KeyArrayConfig[KeyID].ReleaseTicks)
                {
                    KeyInternalData[KeyID].KeyCounter = 
                                            KeyArrayConfig[KeyID].ReleaseTicks;
                }
                else
                {
                    KeyInternalData[KeyID].KeyCounter--;
                    if(KeyInternalData[KeyID].KeyCounter == (unsigned short)0)
                    {
                        KeyInternalData[KeyID].KeyState = CAPTURE_STATE_SHORT_PRESSED;
                    }
                }
            }
            break;
        case STATE_LONG_PRESS:
            if( KeyArrayConfig[KeyID].ActiveValue == HWIreading)
            {
                        KeyInternalData[KeyID].KeyCounter = 
                                            KeyArrayConfig[KeyID].ReleaseTicks;
            }
            else
            {
                KeyInternalData[KeyID].KeyCounter--;
                if(KeyInternalData[KeyID].KeyCounter == (unsigned short)0)
                {
                    KeyInternalData[KeyID].KeyState = CAPTURE_STATE_LONG_PRESSED;
                }
            }
            break;
        default:
            KeyInternalData[KeyID].KeyState = STATE_NOT_PRESSED;
            break;    
    }   
}
