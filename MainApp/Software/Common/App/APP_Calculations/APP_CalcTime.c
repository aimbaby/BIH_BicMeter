#include "Extern.h"

#include "Alloc.h"
  #include "APP_Calculations.h"

#define COUNTER_PERIOD_MS            (unsigned short)50  /* 50 ms */
#define MINUTE_STAMP                 (unsigned short)((unsigned short)60000/COUNTER_PERIOD_MS)

static unsigned long ElapsedTimeMinutes = (unsigned long)0;
static unsigned short ElapsedTimePeriod = (unsigned short)0;


PUBLIC void APP_CALC_TIMEsetTravelTime(unsigned long TravelTime)
{
	ElapsedTimeMinutes = TravelTime;
	ElapsedTimePeriod = (unsigned short)0;
}


PUBLIC unsigned long APP_CALC_TIMEmanage(APP_INFOR_BYTE * StatusByte)
{
	
	if((unsigned char)1 == StatusByte->ClearFlag)
	{
		ElapsedTimePeriod = (unsigned short)0;
		ElapsedTimeMinutes = (unsigned long)0;
	}	
	else if(ElapsedTimePeriod >= MINUTE_STAMP)
	{
		ElapsedTimePeriod = (unsigned short)0;
		ElapsedTimeMinutes++;
		StatusByte->EEPsaveFlag = (unsigned char)1;
	}
	else if(StatusByte->StopMeasureFlag != (unsigned char)1)
	{
		ElapsedTimePeriod++;						
	}	
	else
	{
		
	}
	
	return ElapsedTimeMinutes;
}