#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//global variables
int *values, r1, r2, n;

//function prototypes
int gen_rand();
void print_int_array(int array[], int n);
int cmp_int(const void *a, const void *b);
bool binary_search(int array[], int n, int value);
bool sequential_search(int array[], int n, int value);

int main(int argc, char *argv[])
{
    srand(0);

    if (argc != 4){
        printf("Program usage: ./program name n r1 r2\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    int r1 = atoi(argv[2]);
    int r2 = atoi(argv[3]);

    values = (int*)malloc(n * sizeof(int));
    printf("memory usage: %lu bytes \n", n * sizeof(int));
    
    //fill values with random numbers, between r1 and r2
    int range = r2 - r1 + 1;
    for (int i = 0; i < n; i++)
        values[i] = gen_rand() % range + r1;
    
    qsort(values, n, sizeof(int), cmp_int);

    //print_int_array(values, n);

    //sequential search
    clock_t start = clock();

    for (int i = 0; i < n; i++){
        if (!sequential_search(values, n, values[i]))
            printf("Didn't find %d\n", values[i]);
    }

    double duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken for Sequential search: %lf\n", duration);

    //binary search
    start = clock();

    for (int i = 0; i < n; i++){
        if (!binary_search(values, n, values[i]))
            printf("Didn't find %d\n", values[i]);
    }

    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken for binary search: %lf\n", duration);


    free(values);
    return 0;
}

int gen_rand()
{
    return RAND_MAX == 0x7ffffff ? rand() : rand() << 16 | rand() << 1 | rand() & 1;
}

void print_int_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

//negative int if a < b, positive int if a > b, 0 if a == b
//return a - b
int cmp_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

bool binary_search(int array[], int n, int value) //for assignment int not bool
{
    int lower = 0;
    int upper = n-1;
    while (lower <= upper)
    {
        int middle = (upper + lower) / 2;
        if (array[middle] == value)         //shift left while array[middle] == value
            return true;                    //if array[middle] == -1...   do what
        else if (array[middle] < value)
            lower = middle + 1;
        else 
            upper = middle -1;
    }
    return false;
}

bool sequential_search(int array[], int n, int value)
{
    for (int i = 0; i < n; i++)
        if (array[i] == value)
            return true;
    return false;
}