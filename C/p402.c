#include <stdio.h>

int lcm(int u, int v);

int main()
{
    int a, b;
    printf("Enter 2 positive numbers: ");
    scanf("%d %d", &a, &b);

    lcm(a, b);
    
    return 0;
}

int lcm( int u, int v)
{
    int m = (u < v) ? u : v;
    for (int i = m; i < u * v; i+=m){
        if (i % u == 0 && i % v == 0){           
            printf("%d is divisible by both numbers.\n", i);
            break;
        }
    } 
}