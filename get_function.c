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
		{"NULL", NULL}
	};

	i = 0;

	while (i < 4)
	{
		if (!strcmp(functions[i].opcode, opcode))
			return (functions[i].f);
		i++;
	}
	return (NULL);
}
