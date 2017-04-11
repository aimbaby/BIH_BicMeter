#include <xc.h>

#include <string.h>

#include "Alloc.h"
    #include "SpeedCalc.h"

#define TimeSaturation (unsigned char)0xFF


static unsigned char LapTimeBuffer[SpeedCalFilterBufferSize];
static unsigned char LapFlag = (unsigned char)0;
static unsigned char NotifyFlag = (unsigned char)0;
static unsigned long DistTravelCntr = (unsigned long)0;
static unsigned short LapTimeAvg = (unsigned short)0;


PUBLIC void SpeedCalcNotifyInitialize(void)
{
    memset(LapTimeBuffer , 0 , sizeof(LapTimeBuffer));
}

PUBLIC void SensorOneNotify(void)
{
    if( (unsigned char)1 == NotifyFlag )
    {
        NotifyFlag = (unsigned char)0;
    }
    else
    {
        //LapFlag = (unsigned char)0;
    }
}

PUBLIC void SensorTwoNotify(void)
{
    if( (unsigned char)0 == NotifyFlag )
    {
        LapFlag = (unsigned char)1;
        NotifyFlag = (unsigned char)1;    
    }
    else
    {
        //LapFlag = (unsigned char)0;
    }
}

PUBLIC void SpeedCalcManage(void)
{
    static unsigned char LapTime = (unsigned char)0;
    static unsigned char LapSampleIndex = (unsigned char)0;
   
    if(LapTime != TimeSaturation)
    {
       LapTime ++; 
    }
    
     
       
    if(((unsigned char)1 == LapFlag) || (TimeSaturation == LapTime))
    {   
        LapTimeAvg += (unsigned short)LapTime;
        LapTimeAvg -= (unsigned short)LapTimeBuffer[LapSampleIndex];
        
        LapTimeBuffer[LapSampleIndex] = LapTime; 
        LapTime = (unsigned char)0; 
        LapFlag = (unsigned char)0;
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


// Time Ms 
PUBLIC unsigned short GetAvgLapTime(void)
{
    return LapTimeAvg;
}

