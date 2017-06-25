#include "TargetFile.h"

#include "Alloc.h"
    #include "HWIeeprom.h"

PUBLIC unsigned char HWIeeprom_Write(unsigned char address , unsigned char Data)
{
    unsigned char WriteSuccess;
    if((unsigned char)0 == EECON1bits.WR )
    {
        EEADR = address;
        EEDATA = Data;
        EECON1bits.EEPGD = (unsigned char)0;
        EECON1bits.CFGS = (unsigned char)0;
        EECON1bits.WREN = (unsigned char)1;

        INTCONbits.GIE = (unsigned char)0;
        EECON2 = (unsigned char)0x55;
        EECON2 = (unsigned char)0xAA;
        EECON1bits.WR = (unsigned char)1;
        INTCONbits.GIE = (unsigned char)1;      
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
    if((unsigned char)0 == EECON1bits.WR )
    {
        EEADR = address;
        EECON1bits.EEPGD = (unsigned char)0;
        EECON1bits.CFGS = (unsigned char)0; 
        EECON1bits.RD = (unsigned char)1;
        *Data = EEDATA;
        ReadSuccess = (unsigned char)1;
    }
    else
    {
        ReadSuccess = (unsigned char)0;
    }
    
    return ReadSuccess;
}