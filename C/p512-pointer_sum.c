#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    scanf("%d", &n);
    int *array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        array[i] = rand() % 20 + 1;
        printf("%d ", array[i]);
    }
    printf("\n");
    int *ptr = array;
    int sum = 0;
    while (ptr < array + n)
    {
        sum += *ptr;
        ptr++;
    }    
    printf("sum = %d\n", sum);

    return 0;
}