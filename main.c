#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int bytes_read, line_number, _argument;
	char *line, **instruction;
	size_t len;
	FILE *file_stream;
	stack_t *some_stack;
	void (*func)(stack_t **stack, unsigned int i);
	if (argc == 1 || argc > 2)
	{
		write(2, "Usage: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	file_stream = fopen(argv[1], "r");
	if (file_stream == NULL)
	{
		write(2, "Error: Can't open file", 22);
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}

	if (file_stream == NULL)
	{
		write(2, "Error creating file stream\n0", 27);
		exit(EXIT_FAILURE);
	}

	line_number = 0;
	some_stack = NULL;
	while ((bytes_read = getline(&line, &len, file_stream)) != -1)
	{
		line_number++;
		instruction = split_line(line);
		func = get_function(instruction[0]);
		func(&some_stack, line_number);
		if (sizeof(instruction) > 1)
		{
			_argument = atoi(instruction[1]);
			initialize(&_argument);
		}
	}
	fclose(file_stream);
	printf("Here\n");


	return (0);
}
