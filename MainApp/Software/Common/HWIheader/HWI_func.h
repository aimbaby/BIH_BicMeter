PUBLIC void HWI_INTERRUPTS_INTITALIZE(void);
PUBLIC void HWI_DIGITAL_INITIALIZE(void);
PUBLIC void HWI_DIGITAL_SLEEP(void);

PUBLIC unsigned char HWI_DIGI_READ(unsigned char pin);
PUBLIC void HWI_DIGI_WRITE(unsigned char pin,unsigned char val);

PUBLIC void HWI_4Digit_WRITE(unsigned char port,unsigned char val);
PUBLIC unsigned char HWI_4Digit_READ(unsigned char port);

PUBLIC void HWI_8Digit_WRITE(unsigned char port,unsigned char val);
PUBLIC unsigned char HWI8Digit_READ(unsigned char port);

PUBLIC void HWI_Delay_msec(unsigned short Time);
PUBLIC void HWI_Delay_usec(unsigned short Time);
PUBLIC void HWI_Delay_nsec(unsigned short Time);
 
PUBLIC unsigned short ReloadHWtimer(unsigned char TimerId);

PUBLIC void SendMCUtoSleep(void);

PUBLIC void HWI_InitOscilatorCalib(void);
