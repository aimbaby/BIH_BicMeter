#include <xc.h>

#include "Extern.h"
 #include "AppInterrupts.h"
#include "Scheduler.h"

#include "Alloc.h"
 #include "HWI_func.h"
 
PUBLIC void HWI_TIMERS_INTITALIZE(void)
{
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    
    INTCON = 0b11110000; 
    INTCON3 = 0b00001000;
   
    T0CON =0b11010001; //1:4 => 1.024 ms tick
    T1CON =0b10000101;
    T3CON =0b10011101;

     
    INTCON2bits.INTEDG0 = 1; 
    INTCON2bits.INTEDG1 = 1;
    
    TMR0L= 19;


    TMR1IF=0;
    TMR1IE=1;


    TMR3IF=0;
    TMR3IE=1;


    TMR1L=0;
    TMR1H=0xAA;

    TMR3L=0;
    TMR3H=0;

}


void interrupt ISR(void)
{
  if(TMR0IF)
  {
   TMR0IF=0;
   TMR0L=18;
   SchedulerTick();
  }
  if(TMR3IF)
  {
   TMR3IF=0;
   TMR3H = 0xEF;
   TMR3L = 0;
  }
  if(TMR1IF)
  {
   TMR1IF=0;
   TMR1L=0;
   TMR1H=0xAA;
  }
  
  if((unsigned char)1 == INT0IF)
  {
      INT0IF = 0;
      APP_ISR1(); 
  }
        
  if((unsigned char)1 == INT1IF)    
  {  
      INT1IF = 0;
      APP_ISR2();   
  }  
}