#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int n;
    scanf("%d", &n);
    int *values = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);

    int count = 0;
    for (int i = 0; i < n; i++){    //-7, 1, 5, |2|, -4, 3, 0
        int left_sum = 0;
        for (int j = 0; j < i; j++){
            left_sum += values[j];
        }
        int right_sum = 0;
        for (int j = i+1; j < n; j++){
            right_sum += values[j];
        }
        if (left_sum == right_sum)
            count++;
    }
    printf("%d\n", count);

    return 0;
}