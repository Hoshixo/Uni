#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *values = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i<n; i++)
        scanf("%d", &values[i]);

    for (int i = 0; i<n; i++)
        if (values[i] % 2 == 1) // odd
        {
            for (int j = n-1; j<n; j++)
                if (values[j] % 2 == 0)
                {
                    int tmp = values[i];
                    values[i] = values[j];
                    values[j] = tmp;
                    break;
                }
        }
    for (int i = 0; i<n; i++)
        printf("%d ", values[i]);
    printf("\n");



    free(values);
    return 0;
}