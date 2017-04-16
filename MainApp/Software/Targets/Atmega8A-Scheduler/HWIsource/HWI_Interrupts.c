#include "TargetFile.h"

#include "Extern.h"
 #include "AppInterrupts.h"
#include "Scheduler.h"

#include "Alloc.h"
 #include "HWI_func.h"
 
PUBLIC void HWI_TIMERS_INTITALIZE(void)
{
	
	TCCR0 |= (1<<CS01)|(1<<CS00);
	TCNT0 = (unsigned char)194;
	
	// enable overflow interrupt
	TIMSK |= (1 << TOIE0);
	
	GICR |= (1 << INT0);                    //Enable INT0
	MCUCR |= (1<<ISC01)|(1<<ISC00);         //INT0 is executed on every edge
	    
	GICR |= (1 << INT1);                    //Enable INT1
	MCUCR |= (1<<ISC11)|(1<<ISC10);         //INT1 is executed on every edge
		
	DDRD |= (1<<DDRD2)|(1<<DDRD3);
	
	// enable global interrupts
	sei();
}


// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_OVF_vect)
{
	TCNT0 = (unsigned char)194;
	SchedulerTick();	
}

ISR(INT0_vect)
{
	APP_ISR1(); 
}

ISR(INT1_vect)
{
	APP_ISR2();
}
