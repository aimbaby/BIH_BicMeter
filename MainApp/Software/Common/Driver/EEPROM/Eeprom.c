#include "Extern.h"
    #include "HWIeeprom.h"

#include "Alloc.h"
    #include "Eeprom.h"

static unsigned char WriteRequest;
static unsigned char DataArray[EEPROM_BUFFER_SIZE];
static unsigned char EEPROMaddr;
static unsigned char DataSize;
static void (*WriteFnCallback)(void);

PUBLIC unsigned char Eeprom_Write_Block
(
    unsigned char address , 
    void *DataPtr ,                                               
    unsigned char BlockSize,
    void (*ptrFnCallback)(void)
)
{
    unsigned char WriteGranted;
    unsigned char LoopIndex;
	unsigned char *LocDataPtr = (unsigned char*)DataPtr;
	
	
    if( ((unsigned char)0 == WriteRequest)&& (BlockSize <= EEPROM_BUFFER_SIZE))
    {
        WriteRequest = (unsigned char)1;

        for(LoopIndex = (unsigned char)0 ; LoopIndex < BlockSize; LoopIndex ++ )
        {
            DataArray[LoopIndex] = LocDataPtr[LoopIndex];
        }
        DataSize = BlockSize;
        EEPROMaddr = address;
        WriteFnCallback = ptrFnCallback;
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
    void *DataPtr , 
    unsigned char BlockSize
)
{
    unsigned char LoopIndex = (unsigned char)0 ;
    unsigned char ReadSuccess;
    unsigned char ReadGranted;
	
	unsigned char *LocDataPtr = (unsigned char *)DataPtr;
    
    if( (unsigned char)0 == WriteRequest)
    {     
        while(LoopIndex < BlockSize  )
        {
           ReadSuccess = HWIeeprom_Read(address + LoopIndex , &LocDataPtr[LoopIndex]); 
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
            if(WriteFnCallback != (void*)0)
            {
                WriteFnCallback();
            }          
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