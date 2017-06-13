/*
 * BicMeter.c
 *
 * Created: 15/04/2017 11:28:59 ص
 *  Author: ahmed Imbaby
 */ 


#include "TargetFile.h"

#include "Extern.h"
#include "Scheduler.h"
#include "HWI_func.h"
#include "APP.h"
#include "SpeedCalc.h"
#include "BCDdisplay.h"

void DisplayAlphaNumeric (void);
void ManageApplication (void);
void ManageSpeedCalc(void);

int main(void)
{
 HWI_INTERRUPTS_INTITALIZE();
 HWI_DIGITAL_INITIALIZE();
 SpeedCalcNotifyInitialize();
 BCDInitialize(1);
 APP_INITIALIZE();
 
 CreateTask( ManageSpeedCalc, (unsigned char)0  , (unsigned char) 20);
 
 CreateTask( ManageApplication, (unsigned char)2  , (unsigned char) 100);
 
 CreateTask( DisplayAlphaNumeric, (unsigned char)1  , (unsigned char) 4);


 RunScheduler();
}


void DisplayAlphaNumeric (void)
{
	BCDManage7segment();
}
void ManageApplication (void)
{
	APP_MANAGE();
}
void ManageSpeedCalc(void)
{
	SpeedCalcManage();
}