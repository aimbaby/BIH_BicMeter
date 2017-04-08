#include <xc.h>

#include <string.h>

#include "Alloc.h"
    #include "SpeedCalc.h"

#define TimeSaturation (unsigned char)0xFF


static unsigned char LapTimeBuffer[SpeedCalFilterBufferSize];
static unsigned char LapFlag = (unsigned char)0;
static unsigned char NotifyFlag = (unsigned char)0;
static unsigned long DistTravelCntr = (unsigned long)0;
static unsigned short SpeedMps = (unsigned short)0;
static unsigned short CircFactor = (unsigned short)7200;
static unsigned short AvgSpeedKph = (unsigned short)0;


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
    unsigned short LapTimeAvg = (unsigned short)0;
    unsigned char LoopIndex;
   
    if(LapTime != TimeSaturation)
    {
       LapTime ++; 
    }
    
    if(((unsigned char)1 == LapFlag) || (TimeSaturation == LapTime))
    {   
        LapTimeBuffer[LapSampleIndex] = LapTime; 
        LapTime = (unsigned char)0; 
        LapFlag = (unsigned char)0;
        DistTravelCntr ++;
        
       if( (unsigned char)SpeedCalFilterBufferSize > LapSampleIndex )
       {
           LapSampleIndex ++;    
       }
       else
       {
           LapSampleIndex = (unsigned char)0;
       }
    }
    else 
    {
        
    }   
    
    for(LoopIndex = (unsigned char)0 ; 
             LoopIndex < (unsigned char)SpeedCalFilterBufferSize ; LoopIndex ++)
    {
        LapTimeAvg += (unsigned short)LapTimeBuffer[LoopIndex];
    }
    
    LapTimeAvg /= ((unsigned short)SpeedCalFilterBufferSize);
     
    AvgSpeedKph = (unsigned short)10 * (CircFactor/(unsigned short)SpeedCalcTaskRate);
    AvgSpeedKph /= LapTimeAvg;
      
    if(AvgSpeedKph == (unsigned short)10)
    {
        AvgSpeedKph = (unsigned short)0;
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


// Speed tenth 
PUBLIC unsigned short GetSpeedKph(void)
{

    return AvgSpeedKph;
}

PUBLIC void SetSpeedCircum(unsigned short CircumByKm)
{
    CircFactor = CircumByKm ;
}