

#ifndef APP_TYPEDEF_H
#define APP_TYPEDEF_H


#define HMI_NORMAL_STATE                       (unsigned char)0x0
#define HMI_APPLY_STATE                        (unsigned char)0x1


typedef struct
{
	unsigned char CurrentState : 2;
	unsigned char EEPsaveFlag : 1;
	unsigned char IncrementFlag :1;
	unsigned char DecrementFlag :1;
	unsigned char ExtraIncrementFlag :1;
	unsigned char ExtraDecrementFlag :1;
	unsigned char ClearFlag :1;
	unsigned char SleepFlag :1;
	unsigned char KphFlag :1;
	unsigned char DisplayState :1;
}APP_INFOR_BYTE;

typedef struct
{
	unsigned short Circum;
	unsigned char CircumBlinkIndex;
	APP_INFOR_BYTE StatusByte;
	unsigned long TravelledDistance;
	unsigned long TravelTime; /* minutes */
}APP_NVM_DATA;

#endif /* APP_TYPEDEF_H */