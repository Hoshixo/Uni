#include <stdio.h>

int count = 0;
// Function to find an integer in the array
int find(int arr[], int size, int num_key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num_key) 
            count++; // Found the num_key at index i
    }
    return count; // num_key not found in the array
}

// Function to add an integer to the array
void add(int arr[], int *size, int capacity, int num_key) {
    if (*size == capacity) {
        printf("Array is full. Cannot add the element.\n");
        return;
    }
    count++;
    arr[*size] = num_key;
    (*size)++;
}

// Function to delete an integer from the array
void delete(int arr[], int *size, int num_key) {
    int index = find(arr, *size, num_key);
    if (index != -1) {
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1]; // Shift elements to the left
        }
        count--;
        (*size)--;
    }
}

// Function to find the predecessor of an integer in the array
int predecessor(int arr[], int size, int num_key) {
    int pred = -1; // Initialize to an invalid value
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < num_key && (pred == -1 || arr[i] > pred)) {
            pred = arr[i];
        }
    }
    
    return pred;
}

// Function to find the successor of an integer in the array
int successor(int arr[], int size, int num_key) {
    int succ = -1; // Initialize to an invalid value
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > num_key && (succ == -1 || arr[i] < succ)) {
            succ = arr[i];
        }
    }
    
    return succ;
}

int main() {
    int arr[10] = {1, 4, 7, 7, 9, 12};
    int size = 5;
    int capacity = 10;

    int num_key = 7;
    int index = find(arr, size, num_key);
    if (count > 0)
        printf("find %d: %d.\n", num_key, count);
    else 
        printf("find %d: %d\n", num_key, count);

    num_key = 7;
    delete(arr, &size, num_key);
    printf("delete %d: %d", num_key, count);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    num_key = 7;
    find(arr, size, num_key);
    if (count > 0)
        printf("find %d: %d.\n", num_key, count);
    else 
        printf("find %d: %d\n", num_key, count);

    num_key = 7;
    delete(arr, &size, num_key);
    printf("delete %d: ", num_key);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    num_key = 7;
    add(arr, &size, capacity, num_key);
    printf("add %d: ", num_key);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    num_key = 7;
    int count = find(arr, size, num_key);
    if (count > 0)
        printf("find %d: %d.\n", num_key, count);
    else 
        printf("find %d: %d\n", num_key, count);

    num_key = 7;
    int pred = predecessor(arr, size, num_key);
    if (pred != -1) {
        printf("Pred %d: %d\n", num_key, pred);
    } else {
        printf("pred %d\n", num_key);
    }

    num_key = 7;
    int succ = successor(arr, size, num_key);
    if (succ != -1) {
        printf("Succ %d: %d\n", num_key, succ);
    } else {
        printf("succ %d\n", num_key);
    }

    return 0;
}
