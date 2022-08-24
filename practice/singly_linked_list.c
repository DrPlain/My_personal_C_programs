#include <stdio.h>
#include <stdlib.h>

struct node
{
    int age;
    struct node *link;
};
typedef struct node node;

void add_end(node *head)
{
    node *new;
    new = malloc(sizeof(node));
    new->age = 50;
    new->link = NULL;
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while (head != NULL)
    {
        if (head->link != NULL)
            head = head->link;
        else
            head->link = new;
    }
}

int main(void)
{
    node *head, *new;
    new = malloc(sizeof(node));
    new->age = 39;
    new->link = NULL;
    head = new;

    add_end(head);
    while (head)
    {
        printf("%d", head->age);
        head = head->link;
    }

    return (0);
}