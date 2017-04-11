#include "Alloc.h"
#include "Scheduler.h"





static TaskConfig ArrayTask[NUM_TASKS];

PUBLIC void CreateTask( PointerVoid MangeFunction , unsigned char TaskId , unsigned char Period)
{
    if(TaskId < NUM_TASKS)
    {
        ArrayTask[TaskId].ManageFunction = MangeFunction;
        ArrayTask[TaskId].Period = Period;
        ArrayTask[TaskId].TickCounter = (unsigned char)0;
    }
}

PUBLIC void SchedulerTick(void)
{
    unsigned char TaskIndex;
    for(TaskIndex = (unsigned char)0 ;TaskIndex < NUM_TASKS ; TaskIndex++)
    {
        ArrayTask[TaskIndex].TickCounter ++;
    }   
}

PUBLIC void RunScheduler(void)
{
    static unsigned char TaskIndex;
    for(;;)
    {
        for(TaskIndex = (unsigned char)0 ; TaskIndex < NUM_TASKS ; TaskIndex++)
        {
            if(ArrayTask[TaskIndex].Period <= ArrayTask[TaskIndex].TickCounter)
            {
                ArrayTask[TaskIndex].ManageFunction();
                ArrayTask[TaskIndex].TickCounter = (unsigned char)0;
            }

        }        
    }

}