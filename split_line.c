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
	char **split_instruction, *token;
	split_instruction = malloc(2 * sizeof(char *));
	token = strtok(instruction, " ");
	split_instruction[0] = token;
	token = strtok(NULL, " ");
	if (token == NULL)
		return (split_instruction);
	split_instruction[1] = token;

	return (split_instruction);
}

