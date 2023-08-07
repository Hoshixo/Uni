#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n[] = {10, 10, 24, 31, 41, 50, 50, 59, 73, 74, 74};
    int r1 = 0;
    int r2 = 11;
    int key = 31;
    int count = 0;
    int i;
    int succ;  
    int pred; 
    
                                
                                
    for (i = r1; i < r2; i++)   //SUCCESSOR FUNCTION
        if (n[i] == key)
            succ = n[i+1];

    for (i = r1; i < r2; i++)   //PREDECESSOR FUNCTION
        if (n[i] == key)
            pred = n[i-1];


    for (i = r1; i < r2; i++) { //FIND FUNCTION
        if (n[i] == key) {
            count++;
        }
    }
    printf("Find:%d %d\n", key, count); 
    count = 0;
 
    for (i = r1; i < r2; i++) {//DELETE FUNCTION
        if (n[i] == key){
            r2 = r2 - 1;
            for (int j = i; j < r2; j++)
                n[j] = n[j + 1];
                count++;
        }
    } 
    printf("Delete:%d %d\n", key, count);
    count = 0;

    for (i = r1; i < r2; i++) { //FIND FUNCTION
        if (n[i] == key) {
            count++;
        }
    }
    printf("Find:%d %d\n", key, count); 
    count = 0;
 
    for (i = r1; i < r2; i++) {//DELETE FUNCTION
        if (n[i] == key){
            r2 = r2 - 1;
            for (int j = i; j < r2; j++)
                n[j] = n[j + 1];
                count++;
        }
    } 
    printf("Delete:%d %d\n", key, count);
    count = 0;

    r2 = r2 + 1; //ADD FUNCTION
    n[i] = key;
    count++;
    printf("Add:%d %d\n", key, count);
    count = 0;

    for (i = r1; i < r2; i++) { //FIND FUNCTION
        if (n[i] == key) {
            count++;
        }
    }
    printf("Find:%d %d\n", key, count); 
    count = 0;

    
    
    /*PREDECESSOR array[i - 1]*/

    printf("succ:%d %d\n", key, succ);
    printf("pred:%d %d\n", key, pred);

    for (int i = 0; i<r2; i++)
        printf("%d ", n[i]);
    printf("\n");
    return 0;
}