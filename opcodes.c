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

	if (stack == NULL)
		exit(EXIT_FAILURE);

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
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	printf("%d\n", temp->n);
}
/**
 * pop - removes the top element of the stack
 *
 * @stack: pointer to a pointer to the first element of the stack_t stack
 * @line_number: the line in the file where the opcode is
 *
 * Return: void
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next_node;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next_node = top->next;

	*stack = next_node;
	if (next_node != NULL)
		next_node->prev = NULL;

	free(top);
}
/**
 * nop - does nothing
 *
 * @stack: pointer to a pointer to the head node of a linked list
 * @line_number: the number of the line of the file where the instruction is
 *
 * Return: void
 *
 */
void nop(stack_t **stack __attribute__((unused)),  unsigned int line_number __attribute__((unused)))
{
}

/**
 * swap - swaps the two elements of the stack
 *
 * @stack: pointer to a pointer to the head node of a linked list
 * @line_number: the line number the opcode is
 *
 * Return: void
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *second, *third;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	second = temp->next;
	third = second->next;


	temp->next = second->next;
	second->prev = NULL;
	temp->prev = second;
	second->next = temp;

	if (third != NULL)
		third->prev = temp;

	*stack = second;
}

/**
 * add - adds the top two elements of the stack
 *
 * @stack: pointer to a pointer to the head node of a linked list
 * @line_number: the line number of the file in which the opcode is
 *
 * Return: void
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	second = temp->next;

	sum = temp->n + second->n;

	second->n = sum;
	second->prev = NULL;
	*stack = second;

	free(temp);
}

/**
 * sub - subtracts the top element from the second top element of the stack
 *
 * @stack: pointer to a pointer to the head node of a linked list
 * @line_number: the line number of the file in which the opcode is
 *
 * Return: void
 *
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *temp, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	second = temp->next;

	value = second->n - temp->n;

	second->n = value;
	second->prev = NULL;
	*stack = second;

	free(temp);
}

/**
 * my_div - divides the second top element by the first top element of the stack
 *
 * @stack: pointer to a pointer to the head node of a linked list
 * @line_number: the line number of the file in which the opcode is
 *
 * Return: void
 *
 */

void my_div(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *temp, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	second = temp->next;

	value = second->n / temp->n;

	second->n = value;
	second->prev = NULL;
	*stack = second;

	free(temp);
}

/**
 * mul - multiplies the second top element by the first top element of the stack
 *
 * @stack: pointer to a pointer to the head node of a linked list
 * @line_number: the line number of the file in which the opcode is
 *
 * Return: void
 *
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *temp, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	second = temp->next;

	value = second->n * temp->n;

	second->n = value;
	second->prev = NULL;
	*stack = second;

	free(temp);
}

/**
 * mod - computes the division of the second top element of the stack by the top
 *
 * @stack: pointer to a pointer to the head node of a linked list
 * @line_number: the line number of the file in which the opcode is
 *
 * Return: void
 *
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *temp, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	second = temp->next;

	value = second->n % temp->n;

	second->n = value;
	second->prev = NULL;
	*stack = second;

	free(temp);
}

/**
 * pchar - prints the char at the top of the stack
 *
 * @stack: pointer to a pointer to the head node of a linked list
 * @line_number: the line number of the file where the opcode is
 *
 * Return: void
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char ascii_char;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_char = (char)((*stack)->n);
	printf("%c\n", ascii_char);
}
/**
 * pstr - prints the string starting at the top of the stack followed by a new line
 *
 * @stack: pointer to a pointer to the head node of a linked list
 * @line_number: the line number of the file where the opcodes
 * 
 * Return: void
 *
 */

void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;
	char ascii_char;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;

		ascii_char = (char)(temp->n);
		printf("%c", ascii_char);

		temp = temp->next;
	}

	printf("\n");
}
