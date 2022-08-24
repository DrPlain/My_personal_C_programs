#include <stdio.h>
#include <stdarg.h>

int main(void)
{
    int a [50], i, size, position, index;
    int new_value;

    printf("Enter size of array not more than 50: ");
    scanf("%d", &size);
    putchar('\0');

    if (size > 50)
    {
        printf("Out of bounds\nSize should less than or equal to 50\n");
        return (1);
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            printf("Enter value %d: ", i + 1);
            scanf("%d", &a[i]);
        }
        printf("\nThe values you entered are:");
        for (i = 0; i < size; i++)
        {
            if (i != size - 1)
                printf("%d, ", a[i]);
            else
                printf("%d", a[i]);
        }
        printf("\nAt what position do want to insert a value?: ");
        scanf("%d", &position);

        if (position < 1 || position > size)
        {
            printf("Out of bounds\nInsertion cannot be done at that position");
            return (1);
        }
        else
        {
            index = position - 1;
            printf("\nEnter the new value: ");
            scanf("%d", &new_value);
            printf("\n%d", new_value);
            for (i = size - 1; i >= index; i--)
                a[i++] = a[i];
            a[index] = new_value;
            size++;
            printf("\nThe new values of your array are:");
            for (i = 0; i < size; i++)
            {
                if (i != size - 1)
                    printf("%d, ", a[i]);
                else
                    printf("%d", a[i]);
            }
        }
    }
    return (0);
}