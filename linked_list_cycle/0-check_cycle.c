#include "lists.h"


/**
* check_cycle- func
* @list: listint_t
* Return: int
*/
int check_cycle(listint_t *list)
{
	listint_t* snake_head = list, snake_tail = list;

	while (snake_head)
	{
		snake_head = snake_head->next;
		if (snake_head == snake_tail)
			return (1);
	}
	return (0);
}
