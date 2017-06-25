#include "Extern.h"
    #include "HWIeeprom.h"

#include "Alloc.h"
    #include "Eeprom.h"

static unsigned char WriteRequest;
static unsigned char DataArray[EEPROM_BUFFER_SIZE];
static unsigned char EEPROMaddr;
static unsigned char DataSize;

PUBLIC unsigned char Eeprom_Write_Block
(
    unsigned char address , 
    unsigned char *DataPtr ,                                               
    unsigned char BlockSize
)
{
    unsigned char WriteGranted;
    unsigned char LoopIndex;
    if( ((unsigned char)0 == WriteRequest)&& (BlockSize <= EEPROM_BUFFER_SIZE))
    {
        WriteRequest = (unsigned char)1;

        for(LoopIndex = (unsigned char)0 ; LoopIndex < BlockSize; LoopIndex ++ )
        {
            DataArray[LoopIndex] = DataPtr[LoopIndex];
        }
        DataSize = BlockSize;
        EEPROMaddr = address;
        WriteGranted = (unsigned char)1;
    }
    else
    {
        WriteGranted = (unsigned char)0;
    }
    return WriteGranted;
}
PUBLIC unsigned char Eeprom_Read_Block
(   
    unsigned char address , 
    unsigned char *DataPtr , 
    unsigned char BlockSize
)
{
    unsigned char LoopIndex = (unsigned char)0 ;
    unsigned char ReadSuccess;
    unsigned char ReadGranted;
    
    if( (unsigned char)0 == WriteRequest)
    {     
        while(LoopIndex < BlockSize  )
        {
           ReadSuccess = HWIeeprom_Read(address + LoopIndex , &DataPtr[LoopIndex]); 
           if((unsigned char)1 == ReadSuccess)
           {
                LoopIndex++;
           }
        } 
        ReadGranted = (unsigned char)1;
    }
    else
    {
        ReadGranted = (unsigned char)0;
    }
    
    return ReadGranted;
    
}

PUBLIC void EepromManage(void)
{
    static unsigned char WriteIndex = ((unsigned char)0);
    unsigned char WriteSuccess;
    
    if((unsigned char)1 == WriteRequest )
    {
        if(WriteIndex == DataSize)
        {
            WriteIndex = (unsigned char)0;
            WriteRequest = (unsigned char)0;
        }
        else
        {
            WriteSuccess = HWIeeprom_Write((EEPROMaddr + WriteIndex) , DataArray[WriteIndex]);
            if( (unsigned char)1 == WriteSuccess )
            {
                WriteIndex++;            
            }
        }
    }  
}