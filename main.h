#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

void print_prompts(void);

typedef struct task_s
{
	char *name;
	char status[11];
	task_s *next
}task;

#ifdef TASK
	task *head = NULL;
#else
	extern task *head;
#endif /* TASK */


#endif /* MAIN_H */
