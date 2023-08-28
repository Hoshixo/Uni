#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int n, r1, r2, range;
int *nums, *counts_array;
bool use_counts_array = false;

int print();

int gen_rand();
void drive();
void test();
int find(int v);    
int add(int v);                //binary search
int delete(int v);             //binary search
int pred(int v);                 //binary search
int succ(int v);                 //binary search, 
int min();
int max();

int cmp_int(const void *a, const void *b); //compare function for qsort
int binary_search(int v); //return -1 if not there or index in nums of the first one

int main(int argc, char * argv[])
{

    if (argc != 4){
        printf("Program usage: ./program_name n r1 r2\n");
        return 1;
    }
    
    n = atoi(argv[1]);
    r1 = atoi(argv[2]);
    r2 = atoi(argv[3]);
    range = r2 - r1 + 1;



    if (range < n)
      {counts_array = (int*)calloc(range, sizeof(int));
       use_counts_array = true;
       for (int i = 0; i < n; i++){            //counts_array array
         counts_array[gen_rand() % range]++;}
      }
    else
      {nums = (int*)malloc(1.1 * n * sizeof(int));
       //printf("memory useage: %lu bytes \n\n", 1.1 * n * sizeof(int));
       for (int i = 0; i < 1.1 * n; i++){            //nums array
         nums[i] = gen_rand() % range + r1;}
       qsort(nums, 1.1 * n, sizeof(int), cmp_int);
      }    

    // Now you decide which benchmark to use, performance or functionality 
    if (n < 0) // n is negative, so functionality testing 
        test();
    else 
        drive(); 
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

int binary_search(int v)
{
    int lower = 0;
    int upper = 1.1 * n - 1;
    int middle = (upper + lower) / 2;
    while (lower <= upper)
    {
        middle = (upper + lower) / 2;
        // is it a -1 adjust it
        
        if (nums[middle] == v)
        {   
            while (middle > 0 && nums[middle - 1] == v)
                middle--;
            return middle;
        }
        else if (nums[middle] == -1)
        {
            while (middle < 0 && nums[middle-1] == -1)
                middle--;
            return middle;
        }
        else if (nums[middle] < v)
            lower = middle + 1;
        else
            upper = middle - 1;
    }
    
    return -(middle);
    
}

int find(int v)
{
    if (use_counts_array)
        return counts_array[v-r1];
    else
    {
        int count = 0; 
        int index = binary_search(v);
        if (index >= 0)
        {
            for (int i = index; i < 1.1 * n && nums[i] == v; i++)
                count++;
        }
        return count;
    }
}

int add(int v)    //DOUBLE CHECK THIS FUNCTION      
{
    if (use_counts_array)
    {
        counts_array[v-r1]++;
        return 1;
    }
    int index = binary_search(v);
    if (index < 0)
    {
        index = -(index);  
        printf("index = %d\n", index);
    }                                         
    // Find next -1 to right of index
    for (int i = index; i <= n - 1; i++)
    {
        if (nums[i] == -1)
            break;
        else if (nums[i] > v)
            nums[i + 1] = nums[i];
        else
            break;
    }
    nums[index] = v;                          
    return 1;                                   // return the index where the new element was added
}

int delete(int v)
{   
    if (use_counts_array)
    {
        if (counts_array[v - r1] == 0)
          return 0;
        counts_array[v - r1]--;
        return 1;
    }
    int index = binary_search(v);
    if (index > 0)
    {
        nums[index] = - 1;     
        return 1; 
    }                                            
    return 0;
}

int succ(int v)
{
    if (use_counts_array) 
    {
        int index = v - r1 + 1;
        while (index < range && counts_array[index] <= 0)
            index++;
        if (index < range) {
            int successor = index + r1;
            return successor;
        }
        else
            return -1;
    }
    else
    {
        int index = binary_search(v);
        if (index < 0) {
            index = -(index + 1);  // Calculate the insertion point for the value v
        }
        else {
            // Handle duplicate values
            while (index < n && nums[index] == v)
                index++;
        }
        if (index < n)    
            return nums[index];
        else
            return -1;
    }
    return -2;
}

int pred(int v)
{
    if (use_counts_array)
    {
        int index = v - r1 - 1;
        while (index < range && counts_array[index] <= 0)
            index--;
        if (index < range)
        {
            int predecessor = index + r1;
            return predecessor;       
        }
        else return -1;
    }
    else
    {
        int index = binary_search(v);
        while (index < n && nums[index] <= 0)
            index--;
        if (index < n)
        {
            int predecessor = index + r1;
            return predecessor;
        }
        return -1;
    }
}

int min() {
    int min_value = 0;
    if (use_counts_array)
    {
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {         // Check for positive non-zero elements
                min_value = i + r1;     // Calculate the actual value based on index and r1
                break;                  // We found the smallest non-zero positive value, so no need to continue
            }
        }
        return min_value;
    }
 return -1;   
}

int max()
{
    int max_value = 0;
    if (use_counts_array)
    {
        for (int i = n; i > 0; i--)
        {
            if (nums[i] < n)
            {
                max_value = i + r1;
                break;
            }
        }
        return max_value;
    }
 return -1;   
}


int print()
{
    if (use_counts_array)
    {
        printf("Counts Array\n");
        printf("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]\n[");
        for (int i = 0; i < range; i++)
            printf("%d, ", counts_array[i]);
        printf("]\n");
    }
    else
    {
        printf("Nums Array\n");
        for (int i = 0; i < 1.1 * n; i++)
            printf("%d ", nums[i]);
        printf("\n");
    }
}

int function_print(int v)
{
    print();
    printf("find %d : %d \n", v, find(v));
    printf("Delete %d : %d \n", v, delete(v));
    print();
    printf("find %d : %d \n", v, find(v));
    printf("Delete %d : %d \n", v, delete(v));
    print();
    printf("find %d : %d \n", v, find(v));
    printf("Add %d : %d \n", v, add(v));
    print();
    printf("find %d : %d \n", v, find(v));
    printf("Succ %d : %d \n", v, succ(v));
    printf("Pred %d : %d \n", v, pred(v));
    printf("Min %d \n", min());
    printf("Max %d \n", max());
}


void test()
{
    int hnums [] = {10, 10, 24, 31, 41, 50, 50, 59, 73, 74, 74};
    n = 11;
    nums = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        nums[i] = hnums[i];
    use_counts_array = false;

    int num = min();
    for (; num != -1;)
    {
        printf("Find %d %d ", num, find(num));
        printf("Delete %d %d ", num, delete(num));
        printf("Find %d %d ", num, find(num));
        printf("Delete %d %d ", num, delete(num));
        printf("Add %d %d ", num, add(num));
        printf("Find %d %d ", num, find(num));
        printf("Pred %d %d ", num, pred(num));
        printf("Succ %d %d ", num, succ(num));
        printf("\n");
    }
}

void drive()
{
    int r = rand() % range + r1;
    //int r = 16;
    //int t = 14;
    function_print(r);
    /*print();
    printf("find %d : %d \n", t, find(t));
    printf("Add %d : %d \n", t, add(t));
    print();*/
    


    




    // this function performs n * 7 loops, each loop generates a
    // random value between 0 and 7 to select which op to use 
    // and randomly selects a 'key' that you will use for the op
    // op = find, add, delete, succ, pred, min, max
    // you also need to add timing to this function

    // rough outline
    /*
    for loop iterating n * 7 times 
        op = random number between 0 and 7 
        key = random number in range 
        switch (op) 
            case 0: find(key)
            case 1: add(key)
            etc 
    */
}