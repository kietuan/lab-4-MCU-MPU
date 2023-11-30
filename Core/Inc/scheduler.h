/*
 * scheduler.h
 *
 *  Created on: Nov 30, 2023
 *      Author: tuankiet
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_


#define SCH_MAX_TASKS 100

typedef struct task
{
	void (*function) (void); //nếu không có hàm nào thì gán NULL vào đây
	int delay; //counter
	int period;//the init for the delay when delay is 0; period == 0 if this is an one-shot task
	int runMe; //Incremented (by scheduler) when task is due to execute // this is a flag to run if > 0
	// unsigned int id;
}task;


void SCH_Init(void);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

int SCH_Add_Task(void (*function)(void), int initial_delay, int period);  // return the added task

void SCH_Delete_Tasks_Name(void (*function)(void));


#endif /* INC_SCHEDULER_H_ */
