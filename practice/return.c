#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct node
    {
        int age;
        struct node *next;
    };

    struct node *new_node, *temp;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Failure to allocate memory");
        exit(1);
    }
    temp = new_node;

    printf("Enter your value: ");
    scanf("%d", &temp->age);
    printf("%d", temp->age);
    
    return (0);
}