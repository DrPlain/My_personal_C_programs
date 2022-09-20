#include "list.h"
#include <stdlib.h>

int main(void)
{
	listint_t *head;
	unsigned int count;

	head = NULL;
	add_node_beginning(&head, 34);
	add_node_beginning(&head, 50);
	add_node_beginning(&head, 100);
	add_node_beginning(&head, 1450);
	
	count = print_listint(head);
	printf("This list contains %d nodes\n", count);

}
