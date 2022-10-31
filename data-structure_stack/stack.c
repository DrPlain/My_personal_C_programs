
#include "stack.h"

int main(){
    int poped_item;

    stack = createStack(size);
    push(2);
    push(3);
    push(4);
    push(5);
   
    display();
    putchar('\n');
    poped_item = pop();
    poped_item = pop();
    display();

    char *s = "gideon";
    int i = 0;
    char c;
    while (s[i])
    {
        c = s[i];
        push(c);
        i++;
    }
    display();

}