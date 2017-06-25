#include "TargetFile.h"

#include   "Extern.h"
  #include "HWI_func.h"
  #include "SpeedCalc.h"
  #include "BCDdisplay.h"
  #include "Key.h"
  #include "Eeprom.h"
#include "Alloc.h"
  #include "APP.h"

  
  PUBLIC void APP_INITIALIZE(void)
  {
	  unsigned char const stringX[] = "ahmed imbaby SW EEPROM OK :D";
	  Eeprom_Write_Block(8,(unsigned char*)&stringX , (unsigned char)sizeof(stringX));
  }
  
  PUBLIC void APP_MANAGE(void)
  {
      static unsigned blinkIndex = (unsigned char)0;
      static unsigned bIsBlinkMode = (unsigned char)0;
      unsigned short AvgSpeedKph;
      unsigned long TravelledDistance;
      unsigned char keystatus;
      
      SetCircumfirunce(2056);
 
      AvgSpeedKph =  GetAvgSpeed(1);
      TravelledDistance = GetDistance();
      TravelledDistance *= (unsigned long)10;
      TravelledDistance /= (unsigned long)16;
         
      Eeprom_Write_Block(1,(unsigned char*)&AvgSpeedKph , (unsigned char)sizeof(AvgSpeedKph));
  
      Eeprom_Read_Block(1 , (unsigned char*)&AvgSpeedKph , (unsigned char)sizeof(AvgSpeedKph));
      BCDsendNumber(AvgSpeedKph,1 );
     
      if(bIsBlinkMode == (unsigned char)0)
      {
          keystatus = GetKeyStatus(0);
          if( keystatus == NEW_STATE_LONG_PRESS)
          {
              bIsBlinkMode = (unsigned char)1;
          }
      }
      else
      {
          BlinkDigit(blinkIndex,100);
          keystatus = GetKeyStatus(0);
          if( keystatus == NEW_STATE_SHORT_PRESS)
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
              if(keystatus == NEW_STATE_LONG_PRESS )
              {
                  BlinkDigit(1,0);
                  bIsBlinkMode = (unsigned char)0;
              }
          }   
      }

      /*if( keystatus == NEW_STATE_SHORT_PRESS)
      {
          PORTBbits.RB6 ^= 1;
      }
      else if( keystatus == NEW_STATE_LONG_PRESS)
      {
          PORTBbits.RB7 ^= 1;
      }
      
      keystatus = GetKeyStatus(1);
      if( keystatus == NEW_STATE_SHORT_PRESS)
      {
          PORTBbits.RB4 ^= 1;
      }
      else if( keystatus == NEW_STATE_LONG_PRESS)
      {
          PORTBbits.RB5 ^= 1;
      }*/
      
   

  }