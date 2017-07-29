#include <string.h>
#include "TargetFile.h"

#include   "Extern.h"
  #include "HWI_func.h"
  #include "SpeedCalc.h"
  #include "BCDdisplay.h"
  #include "DisplayManage.h"
  #include "Eeprom.h"
  #include "APP_HMI.h"
  #include "APP_Calculations.h"
  #include "APP_SleepManage.h"
#include "Alloc.h"
  #include "APP.h"

#define MAX_DISPLAY_NUMBER               (unsigned short)9999
#define DEFAULT_CIRCUM                   (unsigned short)2000
#define DEFAULT_TRAVEL_DIST              (unsigned short)0
#define DEFAULT_TRAVEL_TIME              (unsigned short)0

#define APP_STATE_DIST                   (unsigned char)0x0
#define APP_STATE_TIME                   (unsigned char)0x01
#define APP_STATE_AVGSPD                 (unsigned char)0x02
#define APP_STATE_CIRCUM                 (unsigned char)0x03

  static APP_NVM_DATA APP_DATA;
  
  static unsigned short IncrementDecrementSingleDigit
  (
    unsigned short Number,
    unsigned char Index, 
    unsigned char bIsincrement
  ); 
  
  PUBLIC void APP_INITIALIZE(void)
  {
	 Eeprom_Read_Block(1 , &APP_DATA , (unsigned char)sizeof(APP_DATA));	  
  
	 if(APP_DATA.Circum > MAX_DISPLAY_NUMBER)
	 {
		 APP_DATA.Circum = DEFAULT_CIRCUM;
	 }
	 if(APP_DATA.TravelledDistance > MAX_DISPLAY_NUMBER)
	 {
		 APP_DATA.TravelledDistance = DEFAULT_TRAVEL_DIST;
	 }		 
	 if(APP_DATA.TravelledDistance > MAX_DISPLAY_NUMBER)
	 {
		 APP_DATA.TravelTime = DEFAULT_TRAVEL_TIME;
	 }
	 SetCircumfirunce(APP_DATA.Circum);
	 SetDistance(APP_DATA.TravelledDistance);
	 APP_CALC_TIMEsetTravelTime(APP_DATA.TravelTime);
  }
  
  PUBLIC void APP_MANAGE(void)
  {
    unsigned long TravelTime;
    unsigned short AvgSpeed;
	unsigned short CurrentSpeed;
    unsigned long TravelledDistance;
	APP_INFOR_BYTE StatusByte;
	
	memcpy(&StatusByte,&APP_DATA.StatusByte,sizeof(APP_INFOR_BYTE));
    
    TravelledDistance = GetDistance();
      
    APP_HMImanage(&StatusByte);
    TravelTime = APP_CALC_TIMEmanage(&StatusByte);
    AvgSpeed = APP_CALC_AVGSPDemanage(&StatusByte , TravelTime , TravelledDistance);
    APP_SLEEPmanage(&StatusByte);
	
    CurrentSpeed =  GetAvgSpeed(StatusByte.KphFlag);	
	
	BCDsendNumber(CurrentSpeed,0,1,1);
	BCDsendNumber(TravelTime ,1 ,0 ,1);
      
    switch(StatusByte.CurrentState)
    {
		case APP_STATE_DIST:
		break;
        
        case APP_STATE_TIME:
        break;

		case APP_STATE_AVGSPD:
		break;
		
		case APP_STATE_CIRCUM:
		break;
		
		default:
		break;
	}


      
  }
  
  static unsigned short IncrementDecrementSingleDigit
  (
    unsigned short Number,
    unsigned char Index,
    unsigned char bIsincrement
  )
  {
      unsigned short NumberReturned = (unsigned short)0;
      unsigned short Link;
      unsigned char LoopIndex;
      unsigned char PowIndex;
      unsigned char Output[NUMBER_DIGITS];
      unsigned short unitPosition = (unsigned short)1;


      for( LoopIndex = (unsigned char)0; LoopIndex < NUMBER_DIGITS ; LoopIndex++)      
      {          
          if((Number != (unsigned short)0) )      
          { 
              Link = Number;
              Number = (unsigned short)(Number/(unsigned short)10);
              Output[LoopIndex] = Link - 
                                  (unsigned short)(Number * (unsigned short)10);
          }
		  else
		  {
			  Output[LoopIndex] = (unsigned short)0;
		  }			         
      }   

      if((unsigned char)0 == bIsincrement)
      {
          if((unsigned char)0 == Output[Index])
          {
              Output[Index] =(unsigned char)9;
          }
          else
          {
              Output[Index]--;            
          }        
      }
      else
      {
          if( (unsigned char)9 == Output[Index])
          {
              Output[Index] = (unsigned char)0;
          }
          else
          {  
              Output[Index]++;  
          }  
      }
      
      for(LoopIndex=(unsigned char)0;LoopIndex < NUMBER_DIGITS; LoopIndex++)
      {
          for(PowIndex = (unsigned char)0 ; PowIndex < LoopIndex ;
                                                          PowIndex++  )
          {
              unitPosition *=(unsigned short)10;
          }
          NumberReturned += 
                     (((unsigned short)Output[LoopIndex]) * unitPosition);
          unitPosition = (unsigned short)1;
      }
      
      return NumberReturned;
  }