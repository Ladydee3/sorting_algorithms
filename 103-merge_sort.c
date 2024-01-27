#include "sort.h"

void merge_subarr(int *subarr, int *buf, size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void mege_sort(int *array, size_t size);

/**
 * merge_subarr - subarr of integes sorted
 * @buff: buffer to store sorted subarray
 * @mid: array middle index
 * @subarr: subarrar of array integers to sort
 * @front: array front index
 * @back: array back index
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
	size_t num, j, k = 0;

	printf("merging....\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (num = front, j = mid; num < mid && j < back; k++)
	buff[k] = (subarr[num] < subarr[j]) ? subarr[num++] : subarr[j++];
	for (; num < mid; num++)
	buff[k++] = subarr[num];
	for (; j < back; j++)
	buff[k++] = subarr[j];
	for (num = front, k = 0; num < back; num++)
	subarr[num] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - implement the merge sort algorithm recurion
 * @subarr: subarray of array of integers to sort
 * @front: subarray front index
 * @back: subarray back index
 * @buff: buffer to store sorted result
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
	mid = front + (back - front) / 2;
	merge_sort_recursive(subarr, buff, front, mid);
	merge_sort_recursive(subarr, buff, mid, back);
	merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - array integers sorted in ascending order using
 *              the merge sort algorithm
 * @array: array of integers
 * @size: array size
 *
 * Description: the top-down mergesort algorithm implememted
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
	return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
	return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}

