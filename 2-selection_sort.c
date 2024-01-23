#include "sort.h"

/**
 * swap_ints - two integers in an array swaped
 * @a: first integer swap
 * @b: second integer swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - array of integer in ascending order
 *                  using the selection sort algorithm
 * @size: array size
 * @array: array of integer
 *
 * Description: array printed after each swa
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t num, k;

	if (array == NULL || size < 2)
	return;

	for (num = 0; num < size - 1; num++)
	{
	min = array + num;
	for (k = num + 1; k < size; k++)
	min = (array[k] < *min)	? (array + k) : min;

	if ((array + num) != min)
	{
	swap_ints(array + num, min);
	print_array(array, size);
	}
	}
}
