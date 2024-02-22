#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;
	listint_t *current;
	listint_t *temp;
	listint_t *reset;
	int i;

	head = NULL;
	add_nodeint(&head, 0);
	add_nodeint(&head, 1);
	add_nodeint(&head, 2);
	add_nodeint(&head, 3);
	add_nodeint(&head, 4);
	add_nodeint(&head, 98);
	add_nodeint(&head, 402);
	add_nodeint(&head, 972);
	add_nodeint(&head, 1024);
	add_nodeint(&head, 2048);
	print_listint(head);

	current = head;
	for (i = 0; i < 6; i++)
	{
		if (i == 4)
			temp = current;
		current = current->next;
	}
	reset = current->next;
	current->next = temp;

	if (check_cycle(head) == 0)
		printf("Linked list has no cycle\n");
	else if (check_cycle(head) == 1)
		printf("Linked list has a cycle\n");

	current = head;
	for (i = 0; i < 6; i++)
		current = current->next;
	current->next = reset;

	free_listint(head);

	return (0);
}
