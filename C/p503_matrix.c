#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int** allocate_matrix(int size);
void free_matrix(int **A, int size);
void fill_rand_asc(int **A, int size);
void print_matrix(int **A, int size);
void matrix_multiplication(int **a, int **b, int **c, int size);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Program useage: ./program_name n\n");
        return 1;
    }
    int n = atoi(argv[1]) / 2;
    int **A = allocate_matrix(n);
    int **B = allocate_matrix(n);
    int **C = allocate_matrix(n);

    fill_rand_asc(A, n);
    fill_rand_asc(B, n);

    printf("Matrix A:\n");
    print_matrix(A, n);
    printf("Matrix B:\n");
    print_matrix(B, n);

    matrix_multiplication(A, B, C, n);
    printf("Matrix C:\n");
    print_matrix(C, n);

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}

int** allocate_matrix(int size)
{
    int **A =  (int**)malloc(size * sizeof(int*)); // allocating rows
    for (int i = 0; i < size; i++)
        A[i] = (int*)malloc(size * sizeof(int)); // allocating columns
    return A;
}

void free_matrix(int **A, int size)
{
    for (int i = 0; i < size; i++)
        free(A[i]);
    free(A);
}

void fill_rand_asc(int **A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == 0)
                A[i][j] = rand() % MAX;
            else
                A[i][j] = A[i][j-1] + rand() % (MAX-A[i][j-1]);
        }
    }
}

void print_matrix(int **A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

void matrix_multiplication(int **A, int **B, int **C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < size; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}