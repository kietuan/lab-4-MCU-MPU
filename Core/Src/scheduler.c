/*
 * scheduler.c
 *
 *  Created on: Nov 30, 2023
 *      Author: tuankiet
 */




#include "scheduler.h"
#include "main.h"

static task task_array[SCH_MAX_TASKS]; //array assign the task

static void SCH_Delete_Tasks (int index)
{
	task_array[index].function = NULL;
	task_array[index].runMe = 0;
}

// void SCH_Delete_Tasks_Name (void(*func) (void))
// {
// 	for (int i = 0; i <SCH_MAX_TASKS; i ++)
// 	{
// 		if (task_array[i].function == func)
// 			SCH_Delete_Tasks(i);
// 	}
// }

void SCH_Init(void)
{
	for (int i = 0; i < SCH_MAX_TASKS; i++)
	{
		SCH_Delete_Tasks(i);
	}
}

void SCH_Update(void)
{
	for (int i = 0; i < SCH_MAX_TASKS; i++)
	{
		if (task_array[i].function != NULL)
		{
			if (task_array[i].delay == 0) //the task is due to run
			{
				task_array[i].runMe += 1; //flag

				if (task_array[i].period != 0)
					task_array[i].delay = task_array[i].period;
			}
			else // delay >0
			{
				task_array[i].delay -= 1;
			}
		}
	}
}

int SCH_Add_Task ( void (*function) (void), int initial_delay, int period) //to add task to the array
{
	int index = 0;

	//find the gap
	while ((task_array[index].function != NULL) && (index < SCH_MAX_TASKS)) index++;

	if (index == SCH_MAX_TASKS)
		return SCH_MAX_TASKS;

	task_array[index].function 	= function;
	task_array[index].delay 	= initial_delay;
	task_array[index].period 	= period;
	task_array[index].runMe 	= 0;

	return index; //return the position
}

void SCH_Dispatch_Tasks(void)
{
	int i = 0;
	for (i = 0; i< SCH_MAX_TASKS; i++)
	{
		if (task_array[i].function != NULL && task_array[i].runMe > 0)
		{
			task_array[i].function();
			task_array[i].runMe -= 1;
			if (task_array[i].period == 0) //nếu đây là hàm chỉ chạy 1 lần
			{
				SCH_Delete_Tasks(i);
			}
		}
	}
}
