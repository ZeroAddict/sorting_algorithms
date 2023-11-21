#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly LL using insertion sort
 * @list: the addr of a ptr to the head of a list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *data1, *data2;

	if (list == NULL || *list == NULL)
		return;
	data1 = (*list)->next;

	while (data1 != NULL)
	{
		data2 = data1->next;
		while (data1->prev != NULL && data1->prev->n > data1->n)
		{
			data1->prev->next = data1->next;

			if (data1->next)
				data1->next->prev = data1->prev;
			data1->next = data1->prev;
			data1->prev = data1->next->prev;
			data1->next->prev = data1;

			if (!data1->prev)
				*list = data1;
			else
				data1->prev->next = data1;
			print_list(*list);
		}
		data1 = data2;
	}
}
