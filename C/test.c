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
        int key = n[i];                          
                                            
        succ = n[i+1];
        pred = n[i-1];


        for (int j = r1; j < r2; j++) { //FIND FUNCTION
            if (n[j] == key) {
                count++;
            }
        }
        printf("Find:%d %d\n", key, count); 
        count = 0;
    
        /*if number is there, delete 1 instance
          if number not there, print delete 0*/

        for (int j = r1; j < r2; j++) {//DELETE FUNCTION
            if (n[j] == key){
                for (int k = j; k < r2 - 1; k++)
                    n[k] = n[k + 1];
                count++;
                r2--;
            }
        } 
        printf("Delete:%d %d\n", key, count);
        count = 0;

        for (int j = r1; j < r2; j++) { //FIND FUNCTION
            if (n[j] == key) {
                count++;
            }
        }
        printf("Find:%d %d\n", key, count); 
        count = 0;
    
        for (int j = r1; j < r2; j++) {//DELETE FUNCTION
            if (n[j] == key){
                r2 = r2 - 1;
                for (int k = j; k < r2; k++)
                    n[k] = n[k + 1];
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

        for (int j = r1; j < r2; j++) { //FIND FUNCTION
            if (n[j] == key) {
                count++;
            }
        }
        printf("Find:%d %d\n", key, count); 
        count = 0;
    

        printf("succ:%d %d\n", key, succ);
        printf("pred:%d %d\n\n\n", key, pred);
    }

    for (int i = 0; i<r2; i++)
        printf("%d ", n[i]);
    printf("\n");
    return 0;
}