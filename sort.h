#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stilib.h>

/*comparison direction macros for bitonic sort*/
#define UP 0
#define DOWN 1

/*enum bool - Enumeration of boolean values*/
typedef enum bool
{
	false = 0,
	true
} bool;


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: integer stored in the node
 * @prev: pointer to the previous element of list
 * @next: pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* swapping  helper*/
void swap_ints(int *a, int *b);

/* printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* regular functions ptototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);



#endif
