#include "sort.h"

/**
 * swap_node - swaps two node in a doubly-linked list
 * @first: first of the two nodes
 * @second: second of the two nodes
 */
void swap_node(listint_t *first, listint_t *second)
{
	listint_t *prev_first, *next_second;

	prev_first = first->prev;
	next_second = second->next;
	first->next = next_second;
	first->prev = second;
	second->next = first;
	second->prev = prev_first;
	if (prev_first != NULL)
		prev_first->next = second;
	if (next_second != NULL)
		next_second->prev = first;
}

/**
 * insertion_sort_list - uses insertion sort to sort a doubly linked list
 * @list: pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *key, *unsorted, *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	key = *list;
	while (key)
	{
		if (key->next == NULL)
			break;
		if (key->n > (key->next)->n)
		{
			unsorted = key->next;
			sorted = key;
			while (sorted)
			{
				swap_node(sorted, unsorted);
				if (unsorted->prev == NULL)
					*list = unsorted;
				print_list(*list);
				sorted = unsorted->prev;
				if (sorted == NULL || unsorted->n > sorted->n)
					break;
			}
		}
		else
			key = key->next;
	}
}
