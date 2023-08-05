#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *values = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);
    int clumps = 0;
    bool inside_clumps = false;
    for (int i = 0; i < n-1; i++){ //check values[i] = values[i+1], n-1 or we go out of our range
        if (!inside_clumps && values[i] == values[i+1]){
            clumps++;
            inside_clumps = true;
        }
        else if (values[i] != values[i+1]){
            inside_clumps = false;
        }
    }
    printf("%d", clumps);

    return 0;
}





/*
int main()
{
    int array_count;
    int clump_count;

    printf("Enter number of ints: ");
    scanf("%d", &array_count);

    int array[array_count];

    for (int i=0; i<array_count; i++)
    {
        scanf("%d", &array[i]);
        if (array[i] == array[i-1] && array[i] != array[i-2])
            clump_count += 1;            
    }
    printf("Clump counts: %d", clump_count);

    return 0;
}
*/