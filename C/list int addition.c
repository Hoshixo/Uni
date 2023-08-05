#include <stdio.h>
#include <stdlib.h>

int main()
{    
    int n;
    printf("Enter number of its desired: ");
    scanf("%d", &n);
    int *array = (int*)malloc(n * sizeof(int));
    if (!array)
    {
        printf("memory allocation failed");
        return 1;
    }

    for (int i=0; i<n; i++)
        scanf("%d", &array[i]);

    int sum = 0;
    for (int i=0; i<n; i++)
        sum += array[i];    
    
    printf("%i", sum);
    free(array);

    return 0;
}