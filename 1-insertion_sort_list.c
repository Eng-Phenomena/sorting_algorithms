#include "sort.h"

/**
 * insertion_sort_list - sorting a list
 * @list: linked list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *af, *pre;

	if (list && *list && (*list)->next)
	{
		tmp = (*list)->next;
		af = tmp->next;
		pre = tmp->prev;

		while (tmp)
		{
			if (tmp->n <  pre->n)
			{
				while (pre && tmp->n < pre->n)
				{
					if (af)
						af->prev = pre;
					tmp->next = pre;
					tmp->prev = pre->prev;
					if (pre->prev)
						(pre->prev)->next = tmp;
					pre->prev = tmp;
					pre->next = af;
					af = pre;
					pre = tmp->prev;
					if ((*list)->prev)
						*list = (*list)->prev;
					print_list(*list);
				}
			}
			tmp = af;
			af = tmp->next;
			pre = tmp->prev;
		}
	}
}
