/* 
 * File:   HWIeeprom.h
 * Author: ??????
 *
 * Created on 24 ?????, 2017, 11:35 ?
 */

#ifndef HWIEEPROM_H
#define	HWIEEPROM_H

PUBLIC unsigned char HWIeeprom_Write(unsigned char address , unsigned char Data);
PUBLIC unsigned char HWIeeprom_Read(unsigned char address , unsigned char *Data);

#endif	/* HWIEEPROM_H */

