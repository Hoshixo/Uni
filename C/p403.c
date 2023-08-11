#include <stdio.h>
#include <stdbool.h>

bool prime(int value);

int main()
{
    int a;

    printf("Enter a number to check for prime: ");
    scanf("%d", &a);

    printf("%d \n", prime(a));

    return 0;
}

bool prime(int value)
{   
    for (int i = 2; i < value; i++){
        if (value % i == 0)
            return false;    
    }
    return true;
}