#include <stdlib.h>
#include <stdio.h>
#include "list.h"

unsigned int print_listint(listint_t *head)
{
	unsigned int count = 0;
	listint_t *current;

	current = head;
	if (current == NULL)
		return (count);
	
	while(current)
	{
		printf("%d\n", current->value);
		current = current->next;
		count++;
	}
	return (count);
}
