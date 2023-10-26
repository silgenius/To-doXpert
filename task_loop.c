#include "main.h"

void task_loop(void)
{
	int convert, x = 1;

	char *input;

	while (x)
	{
		input = malloc(sizeof(char) * 2);
		if (input == NULL)
		{
			printf("Cant allocate memory");
			return;
		}
		printf("Enter your choice: ");
		read_line(input, 2);

		if ((convert = str_to_int(input)) != -1)
		{
			if (convert > 9)
		{
				printf("Pls enter a valid choice\n");
			}
			else
				x = Choice2Task(convert);
		}
		else
			printf("Pls input digit only\n");

		free(input);
	}
}

int str_to_int(char *input)
{
	int result = 0;
	char *ptr = input;

	while (*ptr != '\0')
	{
		if (!(*ptr >= 48 && *ptr <= 57))
		{
			return (-1);
		}
		else
		{
			result = result * 10 + (*ptr - '0');
		}
		ptr++;
	}
	return (result);
}
