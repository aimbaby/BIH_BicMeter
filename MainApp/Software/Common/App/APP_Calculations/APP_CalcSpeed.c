#include "Extern.h"

#include "Alloc.h"
    #include "APP_Calculations.h"

static unsigned short CalcMaxSpeed = (unsigned short)0;

PUBLIC unsigned short APP_CALC_AVGSPDmanage
(
	APP_INFOR_BYTE * StatusByte ,
	unsigned long TravelTime ,
	unsigned long Distance
)
{
	return 4321;
	
}

PUBLIC void APP_CALC_MAXSPDmanage_Set(unsigned short MaxSpeed)
{
	CalcMaxSpeed = MaxSpeed;
}

PUBLIC unsigned short APP_CALC_MAXSPDmanage(unsigned short CurrentSpeed)
{
	if(CalcMaxSpeed < CurrentSpeed)
	{
		CalcMaxSpeed = CurrentSpeed;
	}
	return CalcMaxSpeed;	
}
