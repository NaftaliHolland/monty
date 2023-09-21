#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * push - pushes element to the stack
 *
 * @stack: pointer to a pointer to first element of a stack_t stack
 * @line_number: the line number the opcode is
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new;

	if (stack == NULL)
		return;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->next = *stack;
	new->n = argument;
	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
}

/**
 * pall - prints the elements of a stack
 *
 * @stack: pointer to a pointer to the first element of a stack_t stack
 * @line_number: the line number the opcode is
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		return;
	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}

/**
 * pint - prints values at the top of the stack
 *
 * @stack: pointer to a pointer to the first element of a stack_t stack
 * @line_number: the line number of the opcode
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: Can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	printf("%d\n", temp->n);
}
