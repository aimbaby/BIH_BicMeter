

#ifndef APP_TYPEDEF_H
#define APP_TYPEDEF_H

/*
typedef union
{
	struct
	{
		unsigned char CurrentState : 2;
		unsigned char EEPsaveFlag : 1;
		unsigned char IncrementFlag :1;
		unsigned char DecrementFlag :1;
		unsigned char ClearFlag :1;
		unsigned char SleepFlag :1;
		unsigned char KphFlag :1;
	};
	unsigned char INFO_BYTE;
}APP_INFOR_BYTE;*/

typedef struct
{
	unsigned char CurrentState : 2;
	unsigned char EEPsaveFlag : 1;
	unsigned char IncrementFlag :1;
	unsigned char DecrementFlag :1;
	unsigned char ClearFlag :1;
	unsigned char SleepFlag :1;
	unsigned char KphFlag :1;
}APP_INFOR_BYTE;

typedef struct
{
	unsigned short Circum;
	APP_INFOR_BYTE StatusByte;
	unsigned short TravelledDistance;
	unsigned long TravelTime; /* minutes */
}APP_NVM_DATA;

#endif /* APP_TYPEDEF_H */