# include <stdlib.h>
# include <stdio.h>
# include "list.h"

listint_t *add_node_beginning(listint_t **head, int value)
{

	listint_t *newlink, *tmp;
	listint_t new;

	newlink = malloc(sizeof(listint_t));
	if (newlink == NULL)
		return NULL;
	tmp = *head;
	*head = newlink;
	newlink->next = tmp;
	newlink->value = value;

	return (newlink);
}
