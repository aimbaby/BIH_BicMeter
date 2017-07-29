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

PUBLIC void BCDsendNumber
(
    unsigned long Number , 
    unsigned char Line ,
    unsigned char DecimalPlace,
    unsigned char EnableTranc
);

PUBLIC void BCDManage7segment(void);

PUBLIC void BlinkDigit
(
    unsigned char Index , 
    unsigned char Line, 
    unsigned char duration
);

PUBLIC void Segment7SendString
( 
    unsigned char Position, 
    unsigned char Line,
    unsigned char * Data, 
    unsigned char Length
);


#endif	/* BCDDISPLAY_H */

