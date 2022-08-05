#include <stdio.h>
#include "../main.h"

int main(void)
{
   int num = _printf("Good morning, my name is %s\n", "Gideon");
    printf("%d\n", num);

    return (0);
}