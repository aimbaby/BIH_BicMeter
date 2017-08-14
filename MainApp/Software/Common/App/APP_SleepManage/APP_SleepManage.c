#include "Extern.h"
	#include "HWI_func.h"
	#include "Led.h"
	#include "Eeprom.h"
#include "Alloc.h"
    #include "APP_SleepManage.h"


#define SLEEP_TIME_STAMP            (unsigned short)600 // 30 seconds

static unsigned short SleepTimer = (unsigned short)0;

static void SleepAfterSave(void);

PUBLIC void APP_SLEEPmanage(APP_INFOR_BYTE * StatusByte , APP_NVM_DATA * APP_DATA)
{
	if((unsigned char)1 == StatusByte->SleepFlag)
	{
		SleepTimer++;
		if( SLEEP_TIME_STAMP == SleepTimer )
		{
			SleepTimer = (unsigned short)0;
			/* save and sleep */
			Eeprom_Write_Block(1,APP_DATA,(unsigned char)sizeof(APP_NVM_DATA),SleepAfterSave);
		}
	}
	else
	{
		SleepTimer = (unsigned short)0;
	}
	
}

static void SleepAfterSave(void)
{
	HWI_DIGITAL_SLEEP();
	SendMCUtoSleep();
	/* wake up from sleep here */
	HWI_DIGITAL_INITIALIZE();
}