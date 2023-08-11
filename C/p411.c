#include <stdio.h>

int gcd_value(int a, int b);

int main()
{
    int a, b;

    printf("Enter numbers: ");
    scanf("%d %d", &a, &b);

    printf("%d", gcd_value(a, b));

    return 0;
}

int gcd_value(int a, int b)
{
    int m = (a < b) ? a : b;
    for (int i = m; i >= 1; i--)
        if (a % i == 0 && b % i == 0)
            return i;
    return 1;
}