#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - 2 integers in a array swaped
 * @a:first integer swap
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
 * max_heapify - binary tree turned into complete binary heap
 * @size: array/tree size
 * @base: index of the base row of the tree
 * @root: binary tree root node
 * @array: array integers representing a binary tree
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right,  large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
	large = left;
	if (right < base && array[right] > array[large])
	large =  right;

	if (large != root)
	{
	swap_ints(array + root, array + large);
	print_array(array, size);
	max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - array of intergers sorted in ascending order
 *             using heap sort algorithm
 * @size: array size
 * @array: integers array
 *
 * Description: sift-down heap sort algorithm implemented
 *           print the array after each swap
 */
void heap_sort(int *array, size_t size)
{
	int num;

	if (array == NULL || size < 2)
	return;

	for (num = (size / 2) - 1; num >= 0; num --)
	max_heapify(array, size, size, num);

	for (num = size - 1; num > 0; num--)
	{
	swap_ints(array, array + num);
	print_array(array, size);
	max_heapify(array, size, num, 0);
	}
}
