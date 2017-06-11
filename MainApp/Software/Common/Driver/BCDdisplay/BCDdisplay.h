/* 
 * File:   BCDdisplay.h
 * Author: ??????
 *
 * Created on 10 ?????, 2017, 11:26 ?
 */

#include "BCDdisplay_p.h"

#ifndef BCDDISPLAY_H
#define	BCDDISPLAY_H

PUBLIC void BCDInitialize( unsigned char bIsCommonAnode);

PUBLIC void BCDsendNumber( unsigned short Number , unsigned char DecimalPlace );

PUBLIC void BCDManage7segment(void);

#endif	/* BCDDISPLAY_H */

