#include "TargetFile.h"

#include <string.h>

#include "Alloc.h"
    #include "SpeedCalc.h"

#define TimeSaturation (unsigned char)10
#define HundredMetersFactor (unsigned long)100000


static unsigned char LapCounterBuffer[SpeedCalFilterBufferSize];
static unsigned char NotifyFlag = (unsigned char)0;
static unsigned char LapCounter = (unsigned char)0;
static unsigned short CircumFactor = (unsigned char)200;
static unsigned long DistTravelCntr = (unsigned long)0;
static unsigned short LapCounterAvg = (unsigned short)0;
static unsigned short LapDistanceCounter = (unsigned short)0;
 

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
   
    unsigned short HundredMeterReference; 
    
    LapTime ++; 

       
    if(TimeSaturation == LapTime)
    {   
        LapTime = (unsigned char)0;
        LapCounterAvg += (unsigned short)LapCounter;
        LapCounterAvg -= (unsigned short)LapCounterBuffer[LapSampleIndex];
        
        LapCounterBuffer[LapSampleIndex] = LapCounter;
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
    
    AvgSpeedKphMph = (unsigned short)(
            (KphMphFactor * CircumFactor * (unsigned long)LapCounterAvg)
            /((unsigned long)SpeedCalcTaskRate * 
                                    (unsigned long)100 
                                      * (unsigned long)SpeedCalFilterBufferSize)
            );
    return AvgSpeedKphMph;
}

