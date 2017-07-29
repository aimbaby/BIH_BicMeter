#include "TargetFile.h"

#include "Extern.h"
  #include "HWIeeprom.h"
  
#include "Alloc.h"
  #include "HWI_func.h"
  
  
  
 PUBLIC void HWI_InitOscilatorCalib(void)
 {
	 unsigned char OscilatorCalibration;
	 unsigned char bIsreadSuccess = (unsigned char)0;
	 
	 while ((unsigned char)0 == bIsreadSuccess)
	 {
		 bIsreadSuccess = HWIeeprom_Read(0,&OscilatorCalibration);		 
	 }
	 OSCCAL = OscilatorCalibration;
	
 } 
  
  