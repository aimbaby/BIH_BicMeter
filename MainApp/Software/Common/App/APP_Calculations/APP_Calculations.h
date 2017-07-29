#include "APP_TypeDef.h"


#ifndef APP_CALCULATIONS
#define APP_CALCULATIONS

PUBLIC void APP_CALC_TIMEsetTravelTime(unsigned long TravelTime);
PUBLIC unsigned long APP_CALC_TIMEmanage(APP_INFOR_BYTE * StatusByte);
PUBLIC unsigned short APP_CALC_AVGSPDemanage
(
   APP_INFOR_BYTE * StatusByte ,
   unsigned long TravelTime , 
   unsigned long Distance
);

#endif /* APP_CALCULATIONS */