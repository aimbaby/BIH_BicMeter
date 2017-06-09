#include "TargetFile.h"

#include "Extern.h"
 #include "AppInterrupts.h"
#include "Scheduler.h"

#include "Alloc.h"
 #include "HWI_func.h"
 
PUBLIC void HWI_INTERRUPTS_INTITALIZE(void)
{
	//Timer 1 configuration
	TCCR1B |= (1<<CS11);
	TCNT1 = (unsigned short)0x7FFF;
	
	//Timer 0 configuration
	TCCR0 |= (1<<CS01)|(1<<CS00);
	TCNT0 = (unsigned char)194;
	
	// enable overflow interrupt
	TIMSK |= (1 << TOIE0);
	TIMSK |= (1 << TOIE1);
	
	GICR |= (1 << INT0);                    //Enable INT0
	MCUCR |= (1<<ISC01)|(1<<ISC00);         //INT0 is executed on every edge
	    
	GICR |= (1 << INT1);                    //Enable INT1
	MCUCR |= (1<<ISC11)|(1<<ISC10);         //INT1 is executed on every edge
		
	DDRD |= (1<<DDRD2)|(1<<DDRD3);
	
	// enable global interrupts
	sei();
}

PUBLIC unsigned short ReloadHWtimer(unsigned char TimerId)
{
	unsigned short TimeExe = (unsigned short)0;
	switch(TimerId)
	{
		case 0:
		case 1:
		case 2:
		    TimeExe = (TCNT1 - (unsigned short)0x7FFF) <<(unsigned char)1;
			TCNT1 = (unsigned short)0x7FFF;
			break;
		default:
			break;	
	}
	return TimeExe;
}

// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_OVF_vect)
{
	TCNT0 = (unsigned char)194;
	SchedulerTick();	
}

ISR(TIMER1_OVF_vect)
{
	TCNT1 = (unsigned short)0x7FFF;
	APP_ISR3();
}

ISR(INT0_vect)
{
	APP_ISR1(); 
}

ISR(INT1_vect)
{
	APP_ISR2();
}
