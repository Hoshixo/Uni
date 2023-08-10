#include <stdio.h>

int prime(int value);

int main()
{
    int a;

    printf("Enter a number to check for prime: ");
    scanf("%d", &a);

    prime(a);

    return 0;
}

int prime(int value)
{   
    for (int i = 2; i < value; i++){
        if (value % i == 0)
            printf("%d is not a prime number.\n", value);
        else
            printf("%d is a prime number.\n", value);
        break;     
    }
}