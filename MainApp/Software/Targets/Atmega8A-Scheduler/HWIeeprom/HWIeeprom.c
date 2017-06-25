#include "TargetFile.h"

#include "Alloc.h"
    #include "HWIeeprom.h"

PUBLIC unsigned char HWIeeprom_Write(unsigned char address , unsigned char Data)
{
    unsigned char WriteSuccess;
	/* Wait for completion of previous write */

    if((unsigned char)0 == (EECR & (1<<EEWE)) )
    {
        /* Set up address and data registers */
        EEAR = address;
        EEDR = Data;
        /* Write logical one to EEMWE */
        EECR |= (1<<EEMWE);
        /* Start eeprom write by setting EEWE */
        EECR |= (1<<EEWE);
		WriteSuccess = (unsigned char)1;
    }
    else
    {
        WriteSuccess = (unsigned char)0;
    }
   
    return WriteSuccess;
}
PUBLIC unsigned char HWIeeprom_Read(unsigned char address , unsigned char *Data)
{
    unsigned char ReadSuccess;
	/* Wait for completion of previous write */

    if((unsigned char)0 == (EECR & (1<<EEWE)) )
    {
        /* Set up address register */
        EEAR = address;
        /* Start eeprom read by writing EERE */
        EECR |= (1<<EERE);
        /* Return data from data register */
        *Data = EEDR;
        ReadSuccess = (unsigned char)1;
    }
    else
    {
        ReadSuccess = (unsigned char)0;
    }
    
    return ReadSuccess;
}