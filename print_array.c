#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - print array of integers
 *
 * @size: number of elements in an array
 * @array: array to be prnted
 */
void print_array(const int *array, size_t size)
{
	size_t num;

	num = 0;
	while (array && num < size)
	{
	if (num > 0)
	printf(", ");
	printf("%d", array[num]);
	++num;
	}
	printf("\n");
}
