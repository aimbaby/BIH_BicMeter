#include "Extern.h"
    #include "Key.h"

#include "Alloc.h"
    #include "APP_HMI.h"
	
#define LEFT_KEY_ID                        (unsigned char)0
#define RIGHT_KEY_ID                       (unsigned char)1

#define NORMAL_STATE                       (unsigned char)0x0
#define APPLY_STATE                        (unsigned char)0x1

PUBLIC void APP_HMImanage(APP_INFOR_BYTE * StatusByte )
{
	unsigned char KeyStatusLeft;
	unsigned char KeyStatusRight;
	static unsigned char DisplayState = NORMAL_STATE;
	
	
	KeyStatusLeft = GetKeyStatus(LEFT_KEY_ID);
	KeyStatusRight = GetKeyStatus(RIGHT_KEY_ID);
	
	switch(DisplayState)
	{
		case NORMAL_STATE:
		if(
		   (KeyStatusLeft == STATE_LONG_PRESS)
		   &&(KeyStatusRight == STATE_LONG_PRESS)
		   )
		{
			DisplayState = APPLY_STATE;
		}
		else if(KeyStatusLeft == CAPTURE_STATE_SHORT_PRESS)
		{
			StatusByte->CurrentState--;
		}
		else if(KeyStatusRight == CAPTURE_STATE_SHORT_PRESS)
		{
			StatusByte->CurrentState++;
		}
		break;
		
		case APPLY_STATE:
		if(
		(KeyStatusLeft == STATE_LONG_PRESS)
		&&(KeyStatusRight == STATE_LONG_PRESS)
		)
		{
			DisplayState = NORMAL_STATE;
			StatusByte->EEPsaveFlag = (unsigned char)1;
		}
		else if(KeyStatusLeft == CAPTURE_STATE_SHORT_PRESS)
		{
			StatusByte->DecrementFlag = (unsigned char)1;
			StatusByte->IncrementFlag = (unsigned char)0;

		}
		else if(KeyStatusRight == CAPTURE_STATE_SHORT_PRESS)
		{
			StatusByte->IncrementFlag = (unsigned char)1;
			StatusByte->DecrementFlag = (unsigned char)0;
		}
		else
		{
		    StatusByte->DecrementFlag = (unsigned char)0;
			StatusByte->IncrementFlag = (unsigned char)0;
		}
		break;
		
		default:
		DisplayState = NORMAL_STATE;
		break;
	}	
}
