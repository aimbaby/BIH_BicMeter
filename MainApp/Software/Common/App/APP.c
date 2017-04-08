#include <xc.h>

#include   "Extern.h"
  #include "HWI_func.h"
  #include "SpeedCalc.h"
#include "Alloc.h"
  #include "APP.h"
  
  PUBLIC void APP_INITIALIZE(void)
  {
 
  }
  
  PUBLIC void APP_MANAGE(void)
  {
      unsigned short Speed;
      Speed =  GetSpeedKph();
      PORTD = Speed/10;
      /*
      if( Speed < 50)
      {
          PORTD = 0x0;
      }
      else if( Speed < 100)
      {
          PORTD = 0x80;
      }
      else if(Speed < 200)
      {
          PORTD = 0xC0;
      }
      else if(Speed < 300)
      {
          PORTD = 0xE0;
      }
      else if(Speed < 400)
      {
          PORTD = 0xF0;
      }
      else
      {
          PORTD = 0xFF;
      } */
  }