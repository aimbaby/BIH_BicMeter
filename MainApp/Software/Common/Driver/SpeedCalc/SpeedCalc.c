#include "TargetFile.h"

#include <string.h>

#include "Alloc.h"
    #include "SpeedCalc.h"

#define TimeSaturation (unsigned char)10


static unsigned char LapCounterBuffer[SpeedCalFilterBufferSize];
static unsigned char NotifyFlag = (unsigned char)0;
static unsigned char LapCounter = (unsigned char)0;
static unsigned short KMfactor = (unsigned char)200;
static unsigned long DistTravelCntr = (unsigned long)0;
static unsigned short LapCounterAvg = (unsigned short)0;


PUBLIC void SpeedCalcNotifyInitialize(void)
{
    memset(LapCounterBuffer , 0 , sizeof(LapCounterBuffer));
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
    static unsigned char LapTime = (unsigned char)0;
    static unsigned char LapSampleIndex = (unsigned char)0;
   
    LapTime ++; 

       
    if(TimeSaturation == LapTime)
    {   
        LapTime = (unsigned char)0;
        LapCounterAvg += (unsigned short)LapCounter;
        LapCounterAvg -= (unsigned short)LapCounterBuffer[LapSampleIndex];
        
        LapCounterBuffer[LapSampleIndex] = LapCounter;
        LapCounter = (unsigned char)0;
        DistTravelCntr ++;
        
       
        LapSampleIndex ++;    
       
        if( (unsigned char)SpeedCalFilterBufferSize == LapSampleIndex )  
        {
            LapSampleIndex = (unsigned char)0;
        }
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
PUBLIC void SetCircumfirunce(unsigned char Circum)
{
    KMfactor = (unsigned short)(
            ((unsigned long)36 * (unsigned long)Circum)
              /((unsigned long)SpeedCalFilterBufferSize)
            );
}

// Time Ms 
PUBLIC unsigned short GetAvgSpeed(void)
{
    unsigned short AvgSpeedKph;
    
    AvgSpeedKph = (unsigned short)(
            ((unsigned long)KMfactor * (unsigned long)LapCounterAvg)
            /((unsigned long)SpeedCalcTaskRate)
            );
    return AvgSpeedKph;
}

