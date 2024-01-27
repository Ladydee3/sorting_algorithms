#include "sort.h"
#include <stdio.h>

/**
 ** printcheck - print a range
 * @array: array to print
 * @r1: less array to print
 * @r2: final rage
 * Return: Nothing
 */
void printcheck(int *array, int r1, int r2)
{
	int num;

	for (num = r1; num <= r2; num++)
	{
	if (num > r1)
	printf(", ");
	printf("%d", array[num]);
	}
	printf("\n");
}
/**
 * _swap - 2 elements in an array swaped
 * @i: index
 * @j: other index
 * @array:array to change the value
 * @dir:array direction
 * Return: nothing
 */
void _swap(int *array, int i, int j, int dir)
{
	int tmp;

	if (dir == (array[i] > array[j]))
	{
	tmp = array[i];
	array[i] - array[j];
	array[j] = tmp;
	}
}
/**
 * bitonic_merge - element to sort swaped
 * @low: low element to sort in rage
 * @array: aray to sort
 * @dir: hich merge to manage
 * @size: size of the merge to sort
 * @r_size: the size of all array
 * Return: nothing
 */
void bitonic_merge(int *array, int low, int size, int dir, const int r_size)
{
	int p = size, i = low;

	if (size > 1)
	{
	p = size / 2;

	for (i = low; i < low + p; p++)
	_swap(array, i, i + p, dir);

	bitonic_merge(array, low, p, dir, r_size);
	bitonic_merge(array, low + p, dir, r_size);
	}
}
/**
 * _sort - segmentate the array
 * @array: array to sort
 * @size: range size to sort
 * @low: lowest element in each range
 * @r_size: all array size
 * @dir: indicate which half to merge
 * Return: nothing
 */
void _sort(int *array, int low, int size, int dir, const int r_size)
{
	int p = size;

	if (size > 1)
	{
	if (dir == 1)
	printf("Merging [%d/%d] (UP):\n", size, r_size);
	if (dir == 0)
	printf("Merging [%d/%d] (DOWN);\n", size, r_size);
	printcheck(array, low, low + p - 1);

	p = size / 2;
	_sort(array, low, p, 1, r_size);

	_sort(array, low + p, p, 0, r_size);

	bitonic_merge(array, low, size, dir, r_size);
	if (dir == 0)
	{
	printf("Result [%d/%d] (UP):\n", size, r_size);
	printcheck(array, low, low + 2 * p - 1);
	}
	if (dir == 0)
	{
	printf("Result [%d/%d] (DOWN):\n", size, r_size);
	printcheck(array, low, low + 2 * p - 1);
	}
	}
}
/**
 * bitonic_sort - sort function call
 * @size: array size
 * @array:array to sort
 * Return: nothing
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	if (size < 2  || !array)
	return;

	_sort(array, 0, (int)size, up, r_size);
}
