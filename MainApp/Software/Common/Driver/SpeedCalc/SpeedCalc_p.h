/* 
 * File:   SpeedCalc_p.h
 * Author: ??????
 *
 * Created on 07 ?????, 2017, 03:22 ?
 */

#ifndef SPEEDCALC_P_H
#define	SPEEDCALC_P_H

#define SpeedCalcTaskRate                                 20 //ms , minimum 5
#define SpeedCalFilterBufferSize                          36  //short

/* bufferSize * taskRate = 36 * circumference / factor  */
/* Resolution in Km/H = 36 * circumference /(bufferSize * taskRate) */


#define AVG_THRESHOLD                                     1

#endif	/* SPEEDCALC_P_H */

