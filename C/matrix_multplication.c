#include <stdio.h>
#define SIZE 3

int main()
{
    int A[SIZE][SIZE] = { {4, 6, 1},
                          {2, 1, 4},
                          {5, 2, 3} };

    int B[SIZE][SIZE] = { {4, 1, 3},
                          {2, 5, 5},
                          {1, 2, 3} };
    
    int C[SIZE][SIZE];
    for (int row = 0; row<SIZE; row++)
    {
        for (int col = 0; col<SIZE; col++){   
            C[row][col] = 0;
            for (int k = 0; k<SIZE; k++){
                C[row][col] += A[row][k] * B[k][col];
            }
        }
    }
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++)
            printf("%d ", C[row][col]);
        printf("\n");
    }   

    return 0;
}