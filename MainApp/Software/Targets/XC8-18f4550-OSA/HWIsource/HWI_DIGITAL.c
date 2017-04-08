 #include <xc.h>


#include "Alloc.h"
  #include "HWI_func.h"
  

PUBLIC void HWI_DIGITAL_INITIALIZE(void)
{

    
    
    TRISD = 0x0;
    PORTD = 0x0;
}
  
PUBLIC unsigned char HWI_DIGI_READ(unsigned char pin)
{
 return (0);
}
PUBLIC void HWI_DIGI_WRITE(unsigned char pin,unsigned char value)
{
}