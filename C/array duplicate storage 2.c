#include <stdio.h>
#include <stdbool.h>

int main()
{
    int array[10];
    int n = 0;
    bool found;
    
    for (int i = 0; i<20; i++)
    {
        int x;
        scanf("%d", &x);
        found = false;
        for (int j = 0; j<n; j++)
        {
            if (array[j] == x)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            array[n] = x;
            n++;
        }
    }
    for (int i = 0; i<n; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}