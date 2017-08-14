#include <string.h>
#include "TargetFile.h"

#include   "Extern.h"
  #include "SpeedCalc.h"
  #include "BCDdisplay.h"
  #include "DisplayManage.h"
  #include "Eeprom.h"
  #include "APP_HMI.h"
  #include "APP_Calculations.h"
  #include "APP_SleepManage.h"
  #include "Led.h"
#include "Alloc.h"
  #include "APP.h"
  
#define SET_MPH(x)          do\
                            {\
								x = (x * (unsigned short)10) + (unsigned short)8;\
								x /= (unsigned short)16;\
							}while(0)
							

#define MAX_DISPLAY_NUMBER               (unsigned short)9999
#define DEFAULT_CIRCUM                   (unsigned short)2000
#define DEFAULT_TRAVEL_DIST              (unsigned long)0
#define DEFAULT_TRAVEL_TIME              (unsigned long)0
#define DEFAULT_MAX_SPEED                (unsigned short)0
#define DEFAULT_BLINK_INDEX              (unsigned char)0

#define SEG7_BLINK_RATE                   (unsigned char)100
#define LED_BLINK_RATE                    (unsigned char)20


#define APP_STATE_DIST                   (unsigned char)0x0
#define APP_STATE_TIME                   (unsigned char)0x01
#define APP_STATE_AVGSPD                 (unsigned char)0x02
#define APP_STATE_MAXSPD                 (unsigned char)0x03
#define APP_STATE_CIRCUM                 (unsigned char)0x04

  static APP_NVM_DATA APP_DATA;
  
  static unsigned short IncrementDecrementSingleDigit
  (
    unsigned short Number,
    unsigned char Index, 
    unsigned char bIsincrement
  ); 
  
  unsigned short ConvertMinutesHM(unsigned long TimeMinutes);

  
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
	 if(APP_DATA.MaxSpeed > MAX_DISPLAY_NUMBER)
	 {
		 APP_DATA.MaxSpeed = DEFAULT_MAX_SPEED;
	 }
	 if(APP_DATA.CircumBlinkIndex >= NUMBER_DIGITS)
	 {
		 APP_DATA.CircumBlinkIndex = DEFAULT_BLINK_INDEX;
	 }
	 SetCircumfirunce(APP_DATA.Circum);
	 SetDistance(APP_DATA.TravelledDistance);
	 APP_CALC_TIMEsetTravelTime(APP_DATA.TravelTime);
	 APP_CALC_MAXSPDmanage_Set(APP_DATA.MaxSpeed);
  }
  
  PUBLIC void APP_MANAGE(void)
  {
    unsigned short AvgSpeed;
	unsigned short CurrentSpeed;
	unsigned short MaxSpeed;
	unsigned short TimeHoursMinutes;
	unsigned long TravelledDistance;
	APP_INFOR_BYTE StatusByte;
	
	memcpy(&StatusByte,&APP_DATA.StatusByte,sizeof(APP_INFOR_BYTE));
    
	StatusByte.SleepFlag = (unsigned char)0;
    APP_HMImanage(&StatusByte);
	DisableDistanceCntr(StatusByte.StopMeasureFlag);
	APP_DATA.TravelledDistance = GetDistance();
	CurrentSpeed =  GetAvgSpeed(1);
	if((unsigned short)0 != CurrentSpeed)
	{
	    APP_DATA.TravelTime = APP_CALC_TIMEmanage(&StatusByte);		
		StatusByte.SleepFlag = (unsigned char)0;
	}
	else
	{
		
	}	
	
    AvgSpeed = APP_CALC_AVGSPDmanage(&StatusByte , APP_DATA.TravelTime , APP_DATA.TravelledDistance);
    APP_DATA.MaxSpeed = APP_CALC_MAXSPDmanage(&StatusByte , CurrentSpeed);
	APP_SLEEPmanage(&StatusByte,&APP_DATA);
	
	
	TravelledDistance = APP_DATA.TravelledDistance;
	MaxSpeed = APP_DATA.MaxSpeed;
	
	if((unsigned char)0 == StatusByte.KphFlag)
	{
		SET_MPH(MaxSpeed);
		SET_MPH(CurrentSpeed);
		SET_MPH(AvgSpeed);
		SET_MPH(TravelledDistance);
	}
	else
	{
		
	}
	

	ExclusiveSwitchLedOnOff((unsigned char)1,StatusByte.CurrentState);
	BlinkLedOnOff(StatusByte.CurrentState , LED_BLINK_RATE , StatusByte.StopMeasureFlag);
	SwitchLedOnOff(StatusByte.KphFlag , MPH_LED);
	SwitchLedOnOff((0x1 & ((unsigned char)~StatusByte.KphFlag)) , KPH_LED);

    switch(StatusByte.CurrentState)
    {
		case APP_STATE_DIST:
			if((unsigned char)1 == StatusByte.ExtraIncrementFlag)
			{
				APP_CALC_TIMEsetTravelTime((unsigned long)0);
				SetDistance((unsigned long)0);
				APP_DATA.TravelTime = (unsigned long)0;
			}				
			BCDsendNumber(CurrentSpeed,0,1,1);
		    BCDsendNumber(TravelledDistance ,1 ,1 ,1);
		break;
        
        case APP_STATE_TIME:
		
		    if((unsigned char)1 == StatusByte.ExtraIncrementFlag)
			{
				APP_CALC_TIMEsetTravelTime((unsigned long)0);
				SetDistance((unsigned long)0);
				APP_DATA.TravelTime = (unsigned long)0;
			}		
			TimeHoursMinutes = ConvertMinutesHM(APP_DATA.TravelTime);
			BCDsendNumber(TimeHoursMinutes ,1 ,2 ,0);
			BCDsendNumber(CurrentSpeed,0,1,1);		
        break;

		case APP_STATE_AVGSPD:
		    BCDsendNumber(AvgSpeed,1,1,1);
			BCDsendNumber(CurrentSpeed,0,1,1);
		break;
		
		case APP_STATE_MAXSPD:	
			if((unsigned char)1 == StatusByte.ExtraIncrementFlag)
			{
				APP_CALC_MAXSPDmanage_Set(0);	
			}				
			BCDsendNumber(MaxSpeed , 1 ,1 ,1);
			BCDsendNumber(CurrentSpeed,0,1,1);
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
				BlinkDigit(APP_DATA.CircumBlinkIndex,1,SEG7_BLINK_RATE);
			}				
			else
			{
				BlinkDigit(APP_DATA.CircumBlinkIndex,1,0);
			}

			BCDsendNumber(APP_DATA.Circum ,1, 0,0);
			SetCircumfirunce(APP_DATA.Circum);
			DisplaySendString(0,0,"CIRC",4);
			
		break;
		
		default:
			BCDsendNumber(CurrentSpeed,0,1,1);
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
  
  
  unsigned short ConvertMinutesHM(unsigned long TimeMinutes)
  {
	  unsigned short Hours;
	  unsigned char Minutes;
	  Hours = (TimeMinutes / (unsigned long)60);
	  Minutes = (unsigned char)(TimeMinutes - ((unsigned long)60 * (unsigned long)Hours));
	  
	  Hours = (unsigned short)Minutes + (unsigned short)(Hours * (unsigned short)100);
	  return Hours;
  }