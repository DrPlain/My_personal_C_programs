#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    
    char c = 'a';
    c ^= 0b00001000;
    putchar(c);
    return 0;
}