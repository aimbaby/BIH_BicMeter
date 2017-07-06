#include "TargetFile.h"

#include "Extern.h"
    #include "Scheduler.h"
    #include "HWI_func.h"
    #include "APP.h"
    #include "SpeedCalc.h"
    #include "BCDdisplay.h"
    #include "Key.h"    
    #include "Alloc.h"
    #include "BCDdisplay.h"
    #include "Eeprom.h"
#include "Alloc.h" 
    #include "OS_manage.h"

void DisplayAlphaNumeric (void);
void ManageApplication (void);
void ManageSpeedCalc(void);
void ManageDrivers(void);

PUBLIC void Start_App(void)
{
    HWI_INTERRUPTS_INTITALIZE();
    HWI_DIGITAL_INITIALIZE();
    SpeedCalcNotifyInitialize();
    APP_INITIALIZE();
	BCDInitialize(1);
   
    CreateTask( ManageSpeedCalc, (unsigned char)0  , (unsigned char) 20);
    
    CreateTask( ManageApplication, (unsigned char)2  , (unsigned char) 100);
    
    CreateTask( DisplayAlphaNumeric, (unsigned char)1  , (unsigned char) 2);
    
    CreateTask( ManageDrivers , (unsigned char)3 , (unsigned char) 10);

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

void ManageDrivers(void)
{
    unsigned char LoopIndex;
    for(LoopIndex = (unsigned char)0 ; LoopIndex < NUMBER_KEYS ; LoopIndex++)
    {
        MangeKeys(LoopIndex);
    }
    EepromManage();
    
}
