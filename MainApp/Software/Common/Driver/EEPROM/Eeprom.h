/* 
 * File:   Eeprom.h
 * Author: ??????
 *
 * Created on 24 ?????, 2017, 11:38 ?
 */
#include "Eeprom_p.h"

#ifndef EEPROM_H
#define	EEPROM_H

PUBLIC unsigned char Eeprom_Write_Block
(
    unsigned char address , 
    void *DataPtr ,                                               
    unsigned char BlockSize,
    void (*ptrFnCallback)(void)
);

PUBLIC unsigned char Eeprom_Read_Block
(   
    unsigned char address , 
    void *DataPtr , 
    unsigned char BlockSize 
);

PUBLIC void EepromManage(void);
#endif	/* EEPROM_H */

