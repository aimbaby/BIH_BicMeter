#include "Extern.h"

#include "Alloc.h"
    #include "APP_Calculations.h"
	

#define ConvMeterMinuteRatio                (unsigned long)60

static unsigned short CalcMaxSpeed = (unsigned short)0;

PUBLIC unsigned short APP_CALC_AVGSPDmanage
(
	APP_INFOR_BYTE * StatusByte ,
	unsigned long TravelTime ,
	unsigned long Distance
)
{
	unsigned short AverageSpeed;
	
	if(TravelTime != (unsigned long)0)
	{
		AverageSpeed = (unsigned short)((unsigned long)
		        (Distance * ConvMeterMinuteRatio)/TravelTime);
	}
	else
	{
		AverageSpeed = (unsigned short)0;
	}
	
	return AverageSpeed;
	
}

PUBLIC void APP_CALC_MAXSPDmanage_Set(unsigned short MaxSpeed)
{
	CalcMaxSpeed = MaxSpeed;
}

PUBLIC unsigned short APP_CALC_MAXSPDmanage
(
	APP_INFOR_BYTE * StatusByte, 
	unsigned short CurrentSpeed
)
{
	if((unsigned char)0 == StatusByte->StopMeasureFlag)
	{
		if(CalcMaxSpeed < CurrentSpeed)
		{
			CalcMaxSpeed = CurrentSpeed;
		}
	}
	else
	{
		
	}

	return CalcMaxSpeed;	
}
