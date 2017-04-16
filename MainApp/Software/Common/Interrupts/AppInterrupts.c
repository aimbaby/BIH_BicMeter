#include "TargetFile.h"
#include "Extern.h"
 #include "SpeedCalc.h"

#include "Alloc.h"
 #include "AppInterrupts.h"

PUBLIC void APP_ISR1(void)
{
    SensorOneNotify();
}

PUBLIC void APP_ISR2(void)
{
    SensorTwoNotify();  
}