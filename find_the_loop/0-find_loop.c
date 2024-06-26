/* Ex 0 */
#include "lists.h"


/**
* find_listint_loop- func
* @head: listint_t *
* Return: listint_t *
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a = NULL, *b = NULL;

	if (!head)
		return (NULL);
	a = head;
	b = head;
	while (b && b->next)
	{
		b = b->next->next;
		if (a == b)
		{
			do {
				a = a->next;
				if (a == head)
					return (head);
			} while (a != b);
			return (find_listint_loop(head->next));
		}
		a = a->next;
	}
	return (head);
}
