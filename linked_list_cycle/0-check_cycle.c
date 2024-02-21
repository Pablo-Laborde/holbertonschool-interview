#include "lists.h"


/**
* check_cycle- func
* @list: listint_t
* Return: int
*/
int check_cycle(listint_t *list)
{
	int rv = 0;
	listint_t* aux = list;

	while (aux)
	{
		if (aux->next == list)
		{
			rv = 1;
			break;
		}
		aux = aux->next;
	}
	return (rv);
}
