#include "main.h"

void mark_as_completed(void)
{
	int convert;
	task *ptr = head;
	char *input = malloc(sizeof(char) * 13);
	printf("Enter the task number or name to mark as completed: ");
	read_line(input, 13);
	convert = str_to_int(input);

	if (ptr == NULL)
	{
		printf("Add task to proceed\n");
		return;
	}
	if (convert != -1)
		input = index_to_name(convert);
	if (input == NULL)
		ptr = NULL;

	while (ptr != NULL)
	{
		if (strcmp(ptr->name, input) == 0)
		{
			ptr->status = "Completed";
			printf("Task marked as completed!\n");
			return;
		}
		else
			ptr = ptr->next;
	}
	printf("Enter a valid Task name / number\n");
}

char *index_to_name(int index)
{
	task *ptr;

	ptr = head;

	while (ptr != NULL)
	{
		if (ptr->index == index)
		{
			return (ptr->name);
		}
		else
			ptr = ptr->next;
	}

	return (NULL);
}
