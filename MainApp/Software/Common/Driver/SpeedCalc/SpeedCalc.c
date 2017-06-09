#include "TargetFile.h"

#include <string.h>

#include "Extern.h"
    #include "HWI_func.h"

#include "Alloc.h"
    #include "SpeedCalc.h"

#define HundredMetersFactor (unsigned long)100000
#define HW_TIMER_ID  (unsigned char)1

static unsigned char NotifyFlag = (unsigned char)0;
static unsigned char LapCounter = (unsigned char)0;
static unsigned short CircumFactor = (unsigned char)200;
static unsigned long DistTravelCntr = (unsigned long)0;
static unsigned short LapDistanceCounter = (unsigned short)0;
static unsigned short LapTimeTenthMilli = (unsigned short)0;
static unsigned char TimerOVFLcount = (unsigned char)0;
 
PUBLIC void SpeedCalcNotifyInitialize(void)
{
   
}

PUBLIC void SensorOneNotify(void)
{
    if( (unsigned char)1 == NotifyFlag )
    {
        NotifyFlag = (unsigned char)0;
    }
    else
    {
        if(LapCounter != (unsigned char)0)
        {
            LapCounter--;
        }   
    }
}

PUBLIC void SensorTwoNotify(void)
{
    if( (unsigned char)0 == NotifyFlag )
    {
        NotifyFlag = (unsigned char)1;
        LapCounter++; 
        LapTimeTenthMilli = ReloadHWtimer(HW_TIMER_ID);
        LapTimeTenthMilli /= 100;
        LapTimeTenthMilli += 
                        ((unsigned short)TimerOVFLcount * (unsigned short)655);         
        TimerOVFLcount = (unsigned char)0;
    }
    else
    {
        if(LapCounter != (unsigned char)0)
        {
            LapCounter--;
        }      
    }
}

PUBLIC void SpeedCalcManage(void)
{  
    unsigned short HundredMeterReference; 
    
    LapDistanceCounter += LapCounter;  
    
    LapCounter = (unsigned char)0;
        
    HundredMeterReference = (unsigned short)(HundredMetersFactor / 
                                             (unsigned long)CircumFactor);

    if(LapDistanceCounter >= HundredMeterReference)
    {      
      DistTravelCntr ++;
      LapDistanceCounter -= HundredMeterReference;
    }
    else
    {

    } 
}

PUBLIC void SetDistance(unsigned long Distance)
{
    DistTravelCntr = Distance;
}

PUBLIC unsigned long GetDistance(void)
{
    return DistTravelCntr;
}

// in cm
PUBLIC void SetCircumfirunce(unsigned short Circum)
{
    CircumFactor = (unsigned short)Circum;
}

// Time Ms 
PUBLIC unsigned short GetAvgSpeed(unsigned char bIsKph)
{
    unsigned short AvgSpeedKphMph;
    unsigned long KphMphFactor;
    
    if( (unsigned char)1 == bIsKph )
    {
        KphMphFactor = (unsigned long)360;
    }
    else
    {
        KphMphFactor = (unsigned long)225;
    }
 
    AvgSpeedKphMph = (unsigned short)
                     ((KphMphFactor * (unsigned long)CircumFactor )
                        /  (unsigned long)LapTimeTenthMilli);
            
    
    return AvgSpeedKphMph;
}

PUBLIC void HWtimerCallback (void)
{
    if(TimerOVFLcount < 64)
    {
        TimerOVFLcount++;
    }
}

