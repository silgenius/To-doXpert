#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_prompts(void);
void add_task(void);
void delete_task();
size_t read_line(char *str, size_t size);
void task_to_file(char *filename);
void print_task(void);
void mark_as_completed(void);

typedef struct task_s
{
	int index;
	char *name;
	char *status;
	char *due_date;
	struct task_s *next;
}task;

extern task *head;
extern int task_index;

int str_to_int(char *input);
void task_loop(void);
int Choice2Task(int choice);
void free_mem(void);

char *index_to_name(int index);
#endif /* MAIN_H */
