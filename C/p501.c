#include <stdio.h>

int main()
{
    char next = 'B';        //(a)
    char current = 'y';     // (b)
    char *ptr;              // (c)
    ptr = &current;         // (d)
    *ptr = '0';             // (e)
    ptr = &next;            // (f)
    *ptr = 'd';
    printf("%u\n", ptr);
    printf("%c %c\n", next, current);

    return 0;
}