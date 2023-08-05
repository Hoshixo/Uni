#include <stdio.h>

int main()
{
    int size = 20;
    int array[20];
    int i, j;

    printf("Enter number array elements.\n" );
    for (i=0; i<size; i++)
        scanf("%d", &array[i]);
    for (i=0; i<size; i++)
    {
        for (j = i + 1; j<size; j++)
        {
            if (array[i] == array[j])
            {
                for (int k = j; k<size; k++)
                    array[k] = array[k+1];
                size--;
                j--;            
            }
        }
    }
    for (int k = 0; k<size; k++)
        printf("%d ", array[k]);
    
    return 0;
}