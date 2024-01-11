#include <stdlib.h>
#include "lists.h"


listint_t *insert_node(listint_t **head, int number) {
	listint_t *nn = NULL, *aux = NULL;

	nn = malloc(sizeof(listint_t));
	if (nn) {
		nn->n = number;
		nn->next = NULL;
		if (head) {
			aux = *head;
			if (!aux || (aux->n > number)) {
					nn->next = aux;
					*head = nn;
			}
			else {
				while (aux->next && (aux->next->n < number))
					aux = aux->next;
				if (!aux->next)
					aux->next = nn;
				else {
					nn->next = aux->next;
					aux->next = nn;
				}
			}
		}
	}
	return (nn);
}
