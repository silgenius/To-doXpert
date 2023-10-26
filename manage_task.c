#include "main.h"
task *head = NULL;
int task_index = 1;

void add_task(void)
{
	char *name;
	task *ptr;
	int check;

	name = malloc(sizeof(char) * 50);
	if (name == NULL)
		printf("Error\n");
	do
	{
		printf("Enter Task Name: ");
		check = read_line(name, 50);
		if (!(check))
			printf("No task name detected\n");
	}while (check == 0);

	ptr = malloc(sizeof(task));
	if (ptr == NULL)
		printf("Error\n");
	ptr->index = task_index;
	ptr->name = strdup(name);
	ptr->status = "uncompleted";
	ptr->due_date = "unknown";
	ptr->next = head;

	head = ptr;
	task_index++;
}

void delete_task()
{
	task *ptr = head, *tmp, *slow;
	char *input;
	input = malloc(sizeof(char) * 13);
	printf("Provide task name to be deleted: ");
	read_line(input, 13);

	if (str_to_int(input) != - 1)
		input = index_to_name(str_to_int(input));
	if (ptr == NULL)
	{
		printf("No task available to be deleted\n");
		return;
	}
	else
	{
		slow = ptr;
		while (ptr != NULL)
		{
			if (strcmp(ptr->name, input) == 0)
			{
				tmp = slow->next;
				slow = tmp->next;
				free(tmp);
			}
			else
			{
				slow = ptr;
				ptr = ptr->next;
			}
		}
	}

	printf("Task deleted successfully\n");
}

void print_task(void)
{
	int i = 1;
	task *ptr;

	ptr = head;
	if (ptr == NULL)
	{
		printf("No task found\n");
	}

	while (ptr != NULL)
	{
		printf("%d.", ptr->index);
		printf(" Task Name: %5s\n", ptr->name);
		printf("   Due Date: %5s\n", ptr->due_date);
		printf("   Status: %5s\n", ptr->status);

		ptr = ptr->next;
		i++;
	}
}

void task_to_file(char *filename)
{
	FILE *file_ptr;
	task *ptr;

	ptr = head;

	if (ptr == NULL)
	{
		printf("No task can be found\n");
		return;
	}
	if ((file_ptr = fopen(filename, "a")) == NULL)
	{
		printf("Cant open file\n");
		return;
	}

	while (ptr != NULL)
	{
		fputc(ptr->index, file_ptr);
		fputs("  Task name ", file_ptr);
		fputc(':', file_ptr);
		fputs(ptr->name, file_ptr);
		fputs("    Task status ", file_ptr);
		fputc(':', file_ptr);
		fputs(ptr->status, file_ptr);
		fputc('\n', file_ptr);
		ptr = ptr->next;
	}

	fclose(file_ptr);
}

void free_mem(void)
{
	task *ptr;
	
	while (head != NULL)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
