/* 
 * File:   Scheduler.h
 * Author: ??????
 *
 * Created on 03 ?????, 2017, 12:12 ?
 */

#include "Scheduler_p.h"


#ifndef SCHEDULER_H
#define	SCHEDULER_H

typedef void (*PointerVoid)(void);

typedef struct
{
    PointerVoid ManageFunction;
    unsigned char Period;
    unsigned char TickCounter;
}TaskConfig;

PUBLIC void CreateTask( PointerVoid MangeFunction , unsigned char TaskId , unsigned char Period);

PUBLIC void RunScheduler(void);

PUBLIC void SchedulerTick(void);

#endif	/* SCHEDULER_H */

