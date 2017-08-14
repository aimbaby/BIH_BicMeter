#include "TargetFile.h"


#include "Alloc.h"
	#include "HWI_func.h"
	
#define POWER_DOWN    (unsigned char)(1<<SM1)	


PUBLIC void SendMCUtoSleep(void)
{	
	/* change INT0 interrupt source to level */
	MCUCR &= (unsigned char)~((1<<ISC01)|(1<<ISC00));         
	/* set sleep Mode */
	MCUCR |= POWER_DOWN;
	cli();
	/* sleep enable */
	MCUCR |= (unsigned char)(1<<SE);
	sei();
	/* Sleep Instruction */
	__asm__ __volatile__ ( "sleep" "\n\t" :: );
	/* Disable sleep */
	MCUCR &= (unsigned char) (~(unsigned char)(1<<SE));
}