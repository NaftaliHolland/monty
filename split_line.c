#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * split_line - splits an instruction into opcode and arguments
 *
 * @instruction: full instruction as a string
 *
 * Return: an array of strings containing the opcode and arguments
 *
 */
char **split_line(char *instruction)
{
	unsigned long int i;
	char **split_instruction, *token;

	split_instruction = malloc(2 * sizeof(char *));
	if (split_instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (i < sizeof(instruction) - 1)
	{
		if (instruction[i] == ' ')
			break;
		i++;
	}
	if (i == sizeof(instruction) - 1)
		split_instruction[0] = instruction;
	else
	{
		token = strtok(instruction, " ");
		split_instruction[0] = token;
		token = strtok(NULL, " ");
		split_instruction[1] = token;
	}

	return (split_instruction);
}

