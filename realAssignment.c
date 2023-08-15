#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, r1, r2, range, key;
int *nums, *counts;

int gen_rand();

void drive();
void test();

void use_counts(int n, int r1, int r2);
void use_nums(int n, int r1, int r2);

int find(int array[], int n);            //binary search
int add(int v);               //binary search
int delete(int v);            //binary search
int pred(int v);              //binary search
int succ(int v);              //binary search, 
int min();
int max();

void print_int_array(int array[], int n);
int cmp_int(const void *a, const void *b); //compare function for qsort
int binary_search(int array[], int n, int value); //return -1 if not there or index in nums of the first one

int main(int argc, char * argv[])
{
    srand(0);

    /*
    if (argc != 4){
        printf("Program usage: ./program_name n r1 r2\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    int r1 = atoi(argv[2]);
    int r2 = atoi(argv[3]);
    */

    int n = 11;
    int r1 = 1;
    int r2 = 100;
    int range = r2 - r1 + 1;
    int key = gen_rand() % range + r1;

   
    if (range < n)
        use_counts(n, r1, r2);
    else if (range > n)
        use_nums(n, r1, r2);
    
    nums = (int*)malloc(n * sizeof(int));
    counts = (int*)calloc(range, sizeof(int));

    printf("memory useage: %lu bytes \n", n * sizeof(int));

    //fill nums with random numbers, between r1 and r2
    for (int i = 0; i < n; i++)
        nums[i] = gen_rand() % range + r1;
    
    qsort(nums, n, sizeof(int), cmp_int);
    print_int_array(nums, n);
    


    /*
    clock_t start = clock();
    for (int i = 0; i < n; i++){
        if (!binary_search(values, n, values[i]))
            printf("Didn't find %d\n", values[i]);
    }
    double duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken for Binary search: %lf\n", duration);
    */
    

    free(nums);
    return 0;
}


int gen_rand()
{
    return RAND_MAX == 0x7ffffff ? rand() : rand() << 16 | rand() << 1 | rand() & 1;
}

int cmp_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int binary_search(int array[], int n, int value) //for assignment int not bool
{
    int lower = 0;
    int upper = n-1;
    int middle = (upper + lower) / 2;
    while (lower <= upper)
    {
        int middle = (upper + lower) / 2;
        if (array[middle] == value){        
            while (array[middle] == value)        
                array[middle] - 1;
            return middle;
        }
        else if (array[middle] < value)
            lower = middle + 1;
        else 
            upper = middle -1;
    }
    return -middle;
}

void print_int_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int find(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}


void use_counts(int n, int r1, int r2)
{  
    int* counts = (int*)calloc(range, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++);
    {
        int randomvalue = rand()% range + r1;
        counts[randomvalue - r1]++;
    }
    for (int i = 0; i < range; i++)
        printf("value %d: %d occurances\n", i+r1, counts[i]);
    free(counts);

}

void use_nums(int n, int r1, int r2)
{
    int* nums = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
        for (int i = 0; i < n; i++) {
            nums[i] = rand() % range + r1;
        }

        
        for (int i = 0; i < n; i++) {
            printf("Value %d: %d\n", i + 1, nums[i]);
        }

        free(nums);
}






void drive()
{

}