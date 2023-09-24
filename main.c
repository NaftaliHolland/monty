#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int bytes_read, line_number, _argument;
	char **instruction, *line;
	size_t len;
	FILE *file_stream;
	stack_t *some_stack;
	void (*func)(stack_t **stack, unsigned int i);
	if (argc == 1 || argc > 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	file_stream = fopen(argv[1], "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_number = 0;
	some_stack = NULL;
	line = malloc(sizeof(char) * 20);
	if (line == NULL)
	{
		fclose(file_stream);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	} while ((bytes_read = getline(&line, &len, file_stream)) != -1)
	{
		line_number++;
		if (bytes_read == 1 && line[0] == '\n')
			continue;

		line[bytes_read - 1] = '\0';
		instruction = split_line(line);
		if (*instruction[0] == '#')
			continue;
		func = get_function(instruction[0]);
		if (arr_len(instruction) > 1)
		{
			if ((strcmp("0", instruction[1]) == 0) || (strcmp("-0", instruction[1]) == 0))
				_argument = 0;

			else if((_argument = atoi(instruction[1])) == 0 && func == push)
			{
				free(line);
				fclose(file_stream);
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			initialize(&_argument);
		}
		else if(arr_len(instruction) == 1 && func == push)
		{
			free(line);
			fclose(file_stream);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction[0]);
			free(line);
			fclose(file_stream);
			exit(EXIT_FAILURE);
		}
		func(&some_stack, line_number);
	}
	fclose(file_stream);
	free(line);

	exit(EXIT_SUCCESS);
}
