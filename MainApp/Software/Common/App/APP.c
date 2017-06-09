#include "TargetFile.h"

#include   "Extern.h"
  #include "HWI_func.h"
  #include "SpeedCalc.h"
  #include "BCDdisplay.h"
#include "Alloc.h"
  #include "APP.h"
  
  PUBLIC void APP_INITIALIZE(void)
  {
 
  }
  
  PUBLIC void APP_MANAGE(void)
  {
      unsigned short AvgSpeedKph;
      unsigned short TravelledDistance;
      //unsigned short LapTimeAvg;    
     // const unsigned short CircFactor = (unsigned short)7200;
      
      SetCircumfirunce(2000);
 
      AvgSpeedKph =  GetAvgSpeed(1);
      TravelledDistance = GetDistance();
      TravelledDistance *= (unsigned short)10;
      TravelledDistance /= (unsigned short)16;
      //AvgSpeedKph = (AvgSpeedKph + (unsigned short)5)/(unsigned short)10;
      
   /*   LapTimeAvg /= ((unsigned short)SpeedCalFilterBufferSize);

      AvgSpeedKph = (unsigned short)10 * (CircFactor/(unsigned short)SpeedCalcTaskRate);
      AvgSpeedKph /= LapTimeAvg;

      if(AvgSpeedKph < (unsigned short)29)
      {
          AvgSpeedKph = (unsigned short)0;
      }*/
      BCDsendNumber(AvgSpeedKph,1);
      //BCDsendNumber(TravelledDistance,1);

  }