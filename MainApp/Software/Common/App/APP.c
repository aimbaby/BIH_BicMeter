#include <math.h>
#include "TargetFile.h"

#include   "Extern.h"
  #include "HWI_func.h"
  #include "SpeedCalc.h"
  #include "BCDdisplay.h"
  #include "DisplayManage.h"
  #include "Key.h"
  #include "Eeprom.h"
#include "Alloc.h"
  #include "APP.h"


  //static unsigned char CircumDigit[4];
  static unsigned char WriteFlag = (unsigned char)0;
  static unsigned short Circum;
  
  /*static unsigned short ConvertDigit
  (
    unsigned char *ArrayNumbers, 
    unsigned char Size
  );*/
   
  static unsigned short IncrementDecrementSingleDigit
  (
    unsigned short Number,
    unsigned char Index, 
    unsigned char bIsincrement
  ); 
  
  //static void StopSave(void);
  
  PUBLIC void APP_INITIALIZE(void)
  {
	  //unsigned char LoopIndex;
	  Eeprom_Read_Block(1 , (unsigned char*)&Circum , (unsigned char)sizeof(Circum));	  
	 /* for(LoopIndex = (unsigned char)0 ;
	         LoopIndex < (unsigned char)sizeof(CircumDigit);LoopIndex++)
	  {
		  if(CircumDigit[LoopIndex] > (unsigned char)9)
		  {
			 CircumDigit[LoopIndex] = (unsigned char)0; 
		  }			  
	  }	*/	  
	 if(Circum > (unsigned short)9999)
	 {
		 Circum = (unsigned short)0;
	 }		 
  }
  
  PUBLIC void APP_MANAGE(void)
  {
      static unsigned blinkIndex = (unsigned char)0;
      static unsigned bIsBlinkMode = (unsigned char)0;
      unsigned short AvgSpeedKph;
      unsigned long TravelledDistance;
      unsigned char keystatus;
      unsigned char keystatus2;
	  //unsigned char Save[] = "SAVE";
      
     
    
      SetCircumfirunce(Circum);
 
      AvgSpeedKph =  GetAvgSpeed(1);
      TravelledDistance = GetDistance();
      //TravelledDistance *= (unsigned long)10;
      //TravelledDistance /= (unsigned long)16;
    
      if( (unsigned char)0 == WriteFlag)
      {
        if(bIsBlinkMode == (unsigned char)0)
        {
            BCDsendNumber(AvgSpeedKph,0,1 ,1);
			BCDsendNumber(TravelledDistance,1,1 ,1);
            keystatus = GetKeyStatus(0);
            if( keystatus == NEW_STATE_LONG_PRESS)
            {
                bIsBlinkMode = (unsigned char)1;
            }
        }
        else
        {
            //DisplaySendString(0 , &Save[0] , 4);
            BCDsendNumber(Circum,1,0 ,0);
            BlinkDigit(blinkIndex,1,100);
            keystatus = GetKeyStatus(0);
            if( keystatus == CAPTURE_STATE_SHORT_PRESSED)
            {
                blinkIndex++;
                if(blinkIndex == 4)
                {
                    blinkIndex=0;
                }
            }
            else
            {
                keystatus = GetKeyStatus(1);
                keystatus2 = GetKeyStatus(2);
                if(keystatus == NEW_STATE_LONG_PRESS )
                {
                    Eeprom_Write_Block(1,(unsigned char*)&Circum , 
                                 (unsigned char)sizeof(Circum),(void*)0);
                    BlinkDigit(1,1,0);
                    bIsBlinkMode = (unsigned char)0;
                    //WriteFlag = (unsigned char)1;
                    //DisplaySendString(0 , &Save[0] , 4);
                }
                else if(keystatus == CAPTURE_STATE_SHORT_PRESSED)
                {
                   Circum = IncrementDecrementSingleDigit(
                                          Circum,blinkIndex,(unsigned char)0);
                }		
                else if(keystatus2 == CAPTURE_STATE_SHORT_PRESSED)
                {                      
                   Circum = IncrementDecrementSingleDigit(
                                          Circum,blinkIndex,(unsigned char)1);
                }           
            }   
        }
      }
      else
      {

      }   
  }
  
  /*
  static unsigned short ConvertDigit
  (
    unsigned char *ArrayNumbers, 
    unsigned char Size
  )
  {
      unsigned short NumberReturned = (unsigned short)0;
      unsigned char LoopIndex;
      unsigned char PowIndex;
      unsigned short unitPosition = (unsigned short)1;
      
      for(LoopIndex=(unsigned char)0;LoopIndex < Size; LoopIndex++)
      {
          for(PowIndex = (unsigned char)0 ; PowIndex < LoopIndex ;
                                                          PowIndex++  )
          {
              unitPosition *=(unsigned short)10;
          }
          NumberReturned += 
                     (((unsigned short)ArrayNumbers[LoopIndex]) * unitPosition);
          unitPosition = (unsigned short)1;
      }
      
      return NumberReturned;
  }*/
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
 /* static void StopSave(void)
  {
      WriteFlag = (unsigned char)0;
  }*/