#include "main.h"

size_t read_line(char *str, size_t size)
{
        int ch;
        size_t i;

        i = 0;
        while (1)
        {
                ch = getc(stdin);

                if (ch == '\n')
                        break;
                if (i == size - 1)
                {
			if (realloc(str, sizeof(char) * (size + 2)) != NULL)
				size += 2;
		}
                str[i] = ch;
                i++;
        }
        str[i] = '\0';

	return (i);
}
