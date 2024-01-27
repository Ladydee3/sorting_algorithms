#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - get maximum value in array integers
 * @array: integer array
 * @size: array size
 *
 * Return: the maximum integer in array
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
 * radix_counting_sort -sort dugits of array of integers in ascending order
 * @size: array size
 * @array: integers array
 * @buff: buffer to store sorted array
 * @sig: significant digit to ort on
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t num;

	for (num = 0; num < size; num++)
	count[(array[num] / sig) % 10] += 1;

	for (num = 0; num < 10; num++)
	count[num] += count[num - 1];

	for (num = size - 1; (int)num >= 0; num--)
	{
	buff[count[(array[num] / sig) % 10] - 1] = array[num];
	count[(array[num] / sig) % 10] -= 1;
	}

	for (num = 0; num < size; num++)
	array[num] = buff[num];
}


/**
 * radix_sort - array of integers sorted in ascending order
 *              using the radix sort algorithm
 * @size: array size
 * @array: integers array
 *
 * Description: implements the LSD radix sort algorithm
 * prints the array after each significant digit increase
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
	return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
	return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
	radix_counting_sort(array, size, sig, buff);
	print_array(array, size);
	}

	free(buff);
}


