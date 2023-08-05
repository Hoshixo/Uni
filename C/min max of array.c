#include <stdio.h>
#include <stdlib.h>

int main()
{    
    //int values[100]; //static memory allocation
    int n;
    scanf("%d", &n);
    int *values = (int*)malloc(n * sizeof(int)); //Dynamic approach 
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);
    
    int min = values[0];
    int max = values[0];
    for (int i = 1; i < n; i++){
        if (values[i] < min)
            min = values[i];
        if (values[i] > max)
            max = values[i];
    }
    printf("Min = %d, Max = %d\n", min, max);
    free(values);

    return 0;
}