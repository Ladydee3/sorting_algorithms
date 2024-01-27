#include "sort.h"

/**
 * swap - 2 node in doubly-linked list swaps
 * @a: first node address
 * @b: second node address
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
	a->prev->next = b;
	if (b->next)
	b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
/**
 * tail_traverse - fuction that sort from tail back
 * @list: original head list
 * @tail: list tail
 * @head: list head
 *
 * Return: new head list
 */
listint_t *tail_traverse(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
	if (tail->n < tail->prev->n)
	{
	swap(tail->prev, tail);
	if (tail->prev == NULL)
	list = tail;
	print_list(list);
	}
	else
	tail = tail->prev;
	if (tail->prev == NULL)
		head = tail;
	}
	return (head);
}

/**
 * coctail_sort_list - linked list using shaker sort
 *
 * @list: doubly linked list to be sorted
 */
void coctail_sort_list(listint_t **list)
{
	listint_t *tail, *head, *len;
	int num = 0, k = 0, swaped = 1;

	if (!list || !*list)
	return;
	len = *list;
	for (num = 0; len; num++)
	{
	len = len->next;
	}
	if (num < 2)
	return;
	head = *list;
	while (k < num)
	{
	swaped = 0;
	while (head && head->next)
	{
	if (head->n > head->n)
	{
	swap(head, head->next);
	swaped++;
	if (head->prev->prev == NULL)
	*list = head->prev;
	print_list(*list);
	}
	else
	head = head->next;
	if (head->next == NULL)
	tail = head;
	}
	head = tail_traverse(head, tail, *list);
	*list = head;
	k++;
	}
}



