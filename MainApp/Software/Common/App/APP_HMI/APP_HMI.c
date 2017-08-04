#include <string.h>
#include "Extern.h"
    #include "Key.h"

#include "Alloc.h"
    #include "APP_HMI.h"
	
#define LEFT_KEY_ID                        (unsigned char)0
#define RIGHT_KEY_ID                       (unsigned char)1

#define NORMAL_STATE                       (unsigned char)0x0
#define APPLY_STATE                        (unsigned char)0x1
#define TRANSITION_TO_NORMAL_STATE         (unsigned char)0x2
#define TRANSITION_TO_APPLY_STATE          (unsigned char)0x3

#define HMI_1BIT_MASK                      (unsigned char)0x01

PUBLIC void APP_HMImanage(APP_INFOR_BYTE * StatusByte )
{
	unsigned char KeyStatusLeft;
	unsigned char KeyStatusRight;
	unsigned char TempVar;
	static unsigned char DisplayState = NORMAL_STATE;
	
	
	KeyStatusLeft = GetKeyStatus(LEFT_KEY_ID);
	KeyStatusRight = GetKeyStatus(RIGHT_KEY_ID);
	
	switch(DisplayState)
	{
		case NORMAL_STATE:
		if(
		   (KeyStatusLeft == STATE_SHORT_PRESS)
		   &&(KeyStatusRight == STATE_SHORT_PRESS)
		   )
		{
			DisplayState = TRANSITION_TO_APPLY_STATE;
		}
		else if(KeyStatusLeft == CAPTURE_STATE_SHORT_PRESS)
		{
			StatusByte->CurrentState--;
		}
		else if(KeyStatusRight == CAPTURE_STATE_SHORT_PRESS)
		{
			StatusByte->CurrentState++;
		}
		else if(KeyStatusLeft == NEW_STATE_LONG_PRESS)
		{
			StatusByte->KphFlag ^= (unsigned char)1;
		}
		else
		{
					
		}
		break;
		
		case APPLY_STATE:
		TempVar = StatusByte->CurrentState;
		memset(StatusByte,0,sizeof(APP_INFOR_BYTE));
		if(
			(KeyStatusLeft == STATE_SHORT_PRESS)
			&&(KeyStatusRight == STATE_SHORT_PRESS)
		  )
		{
			DisplayState = TRANSITION_TO_NORMAL_STATE;
			StatusByte->EEPsaveFlag = (unsigned char)1;
		}
		else if(KeyStatusLeft == CAPTURE_STATE_SHORT_PRESS)
		{
			StatusByte->DecrementFlag = (unsigned char)1;
		}
		else if(KeyStatusRight == CAPTURE_STATE_SHORT_PRESS)
		{
			StatusByte->IncrementFlag = (unsigned char)1;
		}
		else if(KeyStatusLeft == NEW_STATE_LONG_PRESS)
		{
			StatusByte->ExtraDecrementFlag = (unsigned char)1;
		}
		else if(KeyStatusRight == NEW_STATE_LONG_PRESS)
		{
			StatusByte->ExtraIncrementFlag = (unsigned char)1;
		}
		else
		{
		    /* do nothing */
		}
		StatusByte->CurrentState = TempVar;
		break;
		
		case TRANSITION_TO_NORMAL_STATE:
		if(
		   ( KeyStatusLeft == STATE_NOT_PRESSED )
		   &&( KeyStatusRight == STATE_NOT_PRESSED )
		   )
		{
			DisplayState = NORMAL_STATE;		
		}
		break;
		
		case TRANSITION_TO_APPLY_STATE:
		if(
		( KeyStatusLeft == STATE_NOT_PRESSED )
		&&( KeyStatusRight == STATE_NOT_PRESSED )
		)
		{
			DisplayState = APPLY_STATE;
		}
		break;
				
		default:
		DisplayState = NORMAL_STATE;
		break;
	}	
	StatusByte->DisplayState = DisplayState & HMI_1BIT_MASK;
}
