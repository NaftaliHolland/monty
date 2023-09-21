#include "monty.h"
#include <stdio.h>
int argument = 0;
/**
 * initialize - a function that initializes argument
 *
 * @_argument: adress of the variable to initialize argument with
 *
 * Return: void
 *
 */
void initialize(int *_argument)
{
	argument = *_argument;
}
