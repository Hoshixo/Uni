#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n[] = {10, 10, 24, 31, 41, 50, 50, 59, 73, 74, 74};
    int r1 = 0;
    int r2 = 11;
    
    int count = 0;
    int i;
    int succ;  
    int pred; 
    
    for (int i = r1; i < r2; i++){                          
                                            
        succ = n[i+1];
        pred = n[i-1];
        int key = n[i];


        for (int j = i; j < r2; j++) { //FIND FUNCTION
            if (n[j] == key) {
                count++;
            }
        }
        printf("Find:%d %d\n", key, count); 
        count = 0;

        if (key) // DELETE FUNCTION
            n[i] = n[i - 1];
            count++;
            r2--;

        printf("Delete:%d %d\n", key, count);
        count = 0;

        r2++; //ADD FUNCTION
        n[i] = key;
        count++;
        printf("Add:%d %d\n", key, count);
        count = 0;


    }

    for (int i = 0; i<r2; i++)
        printf("%d ", n[i]);
    printf("\n");
    return 0;
}