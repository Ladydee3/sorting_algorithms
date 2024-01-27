#include "sort.h"

/**
 * bubble_sort - an array of integers sorts in ascending order
 * using bubble sort algorithm
 * @size: the array size
 * @array: array to be sorted
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t num, n, new_n;
	int swap;

	if (array == NULL || size < 2)
	return;

	n = size;
	while (n > 0)
	{
	new_n = 0;
	for (num = 0; num < n - 1; num++)
	{
	if (array[num] > array[num + 1])
	{
	swap = array[num];
	array[num] = array[num + 1];
	array[num + 1] = swap;
	new_n = num + 1;
	print_array(array, size);
	}
	}
	n = new_n;
	}
}
