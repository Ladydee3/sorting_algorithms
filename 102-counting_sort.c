#include "sort.h"

/**
 * get_max - get maximum value in an array of integers
 * @size: array size:
 * @array: integers array
 *
 * Return: maximum integer in array
 */
int get_max(int *array, int size)
{
	int max, num;

	for (max = array[0], num = 1; num < size; num++)
	{
	if (array[num] > max)
	max = array[num];
	}

	return (max);
}

/**
 * counting_sort - array of integers sorted in ascending order
 *                 using counting sort algorithm
 * @size: array size
 * @array: array of integers
 *
 * Description: counting array printed after setting it up
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, num;

	if (array == NULL || size < 2)
	return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
	free(sorted);
	return;
	}

	for (num = 0; num < (max + 1); num++)
	count[num] = 0;
	for (num = 0; num < (int)size; num++)
	count[array[num]] += 1;
	for (num = 0; num < (max + 1); num++)
	count[num] += count[num - 1];
	print_array(count, max + 1);

	for (num = 0; num < (int)size; num++)
	{
	sorted[count[array[num]] - 1] = array[num];
	count[array[num]] -= 1;
	}

	for (num = 0; num < (int)size; num++)
	array[num] = sorted[num];

	free(sorted);
	free(count);
}


