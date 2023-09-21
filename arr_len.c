#include "monty.h"
#include <stdlib.h>

/**
 * arr_len - gets the number of elements in an array
 *
 * @arr: pointer to the array
 *
 * Return: an interger representing the number of elements in the array
 *
 */

int arr_len(char **arr)
{
	int i;

	i = 0;

	while (arr[i] != NULL)
		i++;

	return (i);
}
