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
#define DEFAULT_TRAVEL_DIST              (unsigned long)0
#define DEFAULT_TRAVEL_TIME              (unsigned long)0
#define APP_BLINK_RATE                   (unsigned char)100


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
    unsigned short AvgSpeed;
	unsigned short CurrentSpeed;
    APP_INFOR_BYTE StatusByte;
	
	memcpy(&StatusByte,&APP_DATA.StatusByte,sizeof(APP_INFOR_BYTE));
    
    APP_DATA.TravelledDistance = GetDistance();
         
    APP_HMImanage(&StatusByte);
    APP_DATA.TravelTime = APP_CALC_TIMEmanage(&StatusByte);
    AvgSpeed = APP_CALC_AVGSPDemanage(&StatusByte , APP_DATA.TravelTime , APP_DATA.TravelledDistance);
    APP_SLEEPmanage(&StatusByte);
	
    CurrentSpeed =  GetAvgSpeed(StatusByte.KphFlag);	
	
	BCDsendNumber(CurrentSpeed,0,1,1);

    switch(StatusByte.CurrentState)
    {
		case APP_STATE_DIST:
		    BCDsendNumber(APP_DATA.TravelledDistance ,1 ,1 ,1);
		break;
        
        case APP_STATE_TIME:
		
		    if((unsigned char)1 == StatusByte.ExtraIncrementFlag)
			{
				APP_CALC_TIMEsetTravelTime((unsigned long)0);
			}		
			BCDsendNumber(APP_DATA.TravelTime ,1 ,0 ,1);
			
        break;

		case APP_STATE_AVGSPD:
		    BCDsendNumber(1,1,0,1);
		break;
		
		case APP_STATE_CIRCUM:
			
			if(StatusByte.DisplayState == HMI_APPLY_STATE)
			{
				if((unsigned char)1 == StatusByte.ExtraIncrementFlag)
				{
					if(APP_DATA.CircumBlinkIndex == (NUMBER_DIGITS - (unsigned char)1))
					{
						APP_DATA.CircumBlinkIndex = (unsigned char)0;
					}
					else
					{
						APP_DATA.CircumBlinkIndex ++;
					}
					
				}
				else if((unsigned char)1 == StatusByte.ExtraDecrementFlag)
				{
					if(APP_DATA.CircumBlinkIndex == (unsigned char)0)
					{
						APP_DATA.CircumBlinkIndex = NUMBER_DIGITS - (unsigned char)1;
					}
					else
					{
						APP_DATA.CircumBlinkIndex --;	
					}					
				}
				else if((unsigned char)1 == StatusByte.IncrementFlag )
				{
					APP_DATA.Circum = IncrementDecrementSingleDigit(
					              APP_DATA.Circum,APP_DATA.CircumBlinkIndex,(unsigned char)0);
				}
				else if ((unsigned char)1 == StatusByte.DecrementFlag)
				{
					APP_DATA.Circum = IncrementDecrementSingleDigit(
					              APP_DATA.Circum,APP_DATA.CircumBlinkIndex,(unsigned char)1);

				}
				else
				{
					
				}
				BlinkDigit(APP_DATA.CircumBlinkIndex,1,APP_BLINK_RATE);
			}				
			else
			{
				BlinkDigit(APP_DATA.CircumBlinkIndex,1,0);
			}

			BCDsendNumber(APP_DATA.Circum ,1, 0,0);
			SetCircumfirunce(APP_DATA.Circum);
		break;
		
		default:
		memset(&StatusByte,0,sizeof(StatusByte));
		break;
	}

	memcpy(&APP_DATA.StatusByte,&StatusByte,sizeof(APP_INFOR_BYTE));
    
	if(StatusByte.EEPsaveFlag == (unsigned char)1)
	{
		if((unsigned char)1 == 
		     Eeprom_Write_Block(1,&APP_DATA,(unsigned char)sizeof(APP_DATA),NULL))
			 {
				APP_DATA.StatusByte.EEPsaveFlag = (unsigned char)0;
			 }
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