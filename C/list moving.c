#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *values = (int*)malloc(n * sizeof(int));
    for (int i = 0; i<n; i++)
        scanf("%d", &values[i]);
    int loc4 = 2;

    for (int i = 0; i<n; i++)
    {
        if (values[i] == 3)
        {
            while (values[loc4] != 4)
            {
                loc4++;
            }
            int tmp = values[i+1]; //store value of values[i+1] before removing
            values[i+1] = values[loc4]; //swap values[i+1] and values[loc4]
            values[loc4] = tmp;    //place value[i+1] to loc4
        }
    }
    for (int i = 0; i<n; i++)
        printf("%d ", values[i]);
    
    printf("\n");
    free(values);

    return 0;
}