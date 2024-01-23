#include "sort.h"

/**
 * shell_sort - sort array using shell_sort algorithm
 * @size: array size
 * @array: array
 * Return: NULL
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, num, k;
	int temp;

	if (array == NULL)
	return;
	while (gap < size / 3)
	gap = gap * 3 + 1;

	while (gap > 0)
	{
	for (num = gap; num < size; num++)
	{
	temp = array[num];
	k = num;
	while (k >= gap && array[k - gap] > temp)
	{
	array[k] = array[k - gap];
	k -= gap;
	}
	array[k] = temp;
	}
	print_array(array, size);
	gap /= 3;
	}
}
