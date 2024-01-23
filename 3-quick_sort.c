#include "sort.h"

/**
 * swap -array of integer in ascending order
 * @array: sorted elements
 * @j: right element
 * @i: left element
 * @size: array size
 */
void swap(int *array, int i, int j, int size)
{
	int aux;

	if (array[i] == array[j])
	return;
	aux = array[i];
	array[i] = array[j];
	array[j] = aux;
	print_array(array, size);
}

/**
 * partition - sort arry partition
 * @array: element to be sorted
 * @end: right side
 * @size: array size
 * @start: left side
 * Return: pivot sorted
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int split_idx = start;
	int j;

	for (j = start; j < end; j++)
	if (array[j] < pivot)
	swap(array, split_idx++, j, size);
	swap(array, split_idx, end, size);
	return (split_idx);
}

/**
 * recursive - quick_sort core
 * @array: sorted element
 * @size: array size
 * @start: left side
 * @end: right size
 */
void recursive(int *array, int start, int end, int size)
{
	if (start < end)
	{
	int pivot_pos = partition(array, start, end, size);

	recursive(array, start, pivot_pos - 1, size);
	recursive(array, pivot_pos + 1, end, size);
	}
}

/**
 * quick_sort - array of integers sorted in ascending order
 * @size: array size
 * @array: element to be sorted
 */
void quick_sort(int *array, size_t size)
{
	recursive(array, 0, size - 1, size);
}


