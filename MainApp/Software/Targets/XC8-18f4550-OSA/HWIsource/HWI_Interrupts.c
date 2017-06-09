#include <xc.h>

#include "Extern.h"
 #include "AppInterrupts.h"
#include "Scheduler.h"

#include "Alloc.h"
 #include "HWI_func.h"
 
PUBLIC void HWI_INTERRUPTS_INTITALIZE(void)
{
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    
    INTCON = 0b11110000; 
    INTCON3 = 0b00001000;
    
   
   
    T0CON =0b11010001; //1:4 => 1.024 ms tick
    T1CON =0b10000101;
    //T2CON =0b00000100;
    T3CON =0b10011101;

     
    INTCON2bits.INTEDG0 = 1; 
    INTCON2bits.INTEDG1 = 1;
    
    TMR0IF=0;
    TMR0IE=1;

    TMR1IF=0;
    TMR1IE=1;

    //TMR2IF=0;
    //TMR2IE=1;

    TMR3IF=0;
    TMR3IE=1;

    TMR0L= 19;
    
    TMR1 = 0;
    
    //TMR2 = 155;

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
   TMR1 = 0;
   APP_ISR3();
  }
  if(TMR2IF)
  {
      TMR2IF = 0;
      //TMR2 = 155; 
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

PUBLIC unsigned short ReloadHWtimer(unsigned char TimerId)
{

    unsigned short ElapsedTime = (unsigned short)0;
    switch(TimerId)
    {
        case 0:
        case 1:
        case 2:
            ElapsedTime = TMR1;
            TMR1 = 0;
            break;
        default:
            break;
    }
    return ElapsedTime;
}