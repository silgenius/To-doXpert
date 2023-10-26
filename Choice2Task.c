#include "main.h"

int Choice2Task(int choice)
{
	char input[50];
	choice += '0';
	switch (choice)
	{
		case '1':
			add_task();
			break;
		case '2':
			delete_task();
			break;
		case '3':
			print_task();
			break;
		case '4':
			mark_as_completed();
			break;
		case '7':
			printf("input file name: ");
			read_line(input, 13);
			task_to_file(input);
			break;
		case '9':
			return (0);
		default:
			printf("Pls provide a choice\n");
	}

	return (1);
}
