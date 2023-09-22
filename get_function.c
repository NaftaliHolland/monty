#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * get_function - constructs the instruction node
 *
 * @opcode: the opcode name
 *
 * Return: pointer to the instruction node
 *
 */
void (*get_function(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", my_div},
		{"mul", mul},
		{"mod", mod},
		{"NULL", NULL}
	};

	i = 0;

	while (i < 11)
	{
		if (!strcmp(functions[i].opcode, opcode))
			return (functions[i].f);
		i++;
	}
	return (NULL);
}
