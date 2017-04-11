/* 
 * File:   SpeedCalc.h
 * Author: ??????
 *
 * Created on 04 ?????, 2017, 10:31 ?
 */

#include "SpeedCalc_p.h"

#ifndef SPEEDCALC_H
#define	SPEEDCALC_H

PUBLIC void SpeedCalcNotifyInitialize(void);

PUBLIC void SensorOneNotify(void);

PUBLIC void SensorTwoNotify(void);

PUBLIC void SpeedCalcManage(void);

PUBLIC void SetDistance(unsigned long Distance);

PUBLIC unsigned long GetDistance(void);

PUBLIC void SetCircumfirunce(unsigned char Circum);

PUBLIC unsigned short GetAvgSpeed(void);

#endif	/* SPEEDCALC_H */

