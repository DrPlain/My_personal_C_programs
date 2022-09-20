#ifndef _LIST_H
#define _LIST_H

/**
 * struct listint_t - A linked linked struct to store integers
 * @num: Integers
 * @next: Address of next node
 */

typedef struct listint_t
{
	int value;
	int count;
	struct listint_t *next;
}listint_t;

listint_t *add_node_beginning(listint_t **head, int num);
listint_t *del_node(listint_t **head, unsigned int index);
unsigned int print_listint(listint_t *head);
	
#endif
