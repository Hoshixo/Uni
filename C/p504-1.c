#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count = 0;
char **words;

bool read_file(char *filename);


int main()
{
    char filename[] = "dictionary.txt";
    if (!read_file(filename))
    {
        exit(1);
    }
    int char_count = 0;
    for (int i = 0; i < count; i++)
        char_count += strlen(words[i]);
    printf("words: %d, characters: %d\n", count, char_count);

    for (int i = 0; i < count; i++)
        free(words[i]);
    free(words);

    return 0;
}

bool read_file(char *filename)               
{
    FILE *fptr = fopen(filename, "r");       
    if (fptr == NULL)
    {
        printf("%s not found\n", filename);
        return false;
    }
    char buffer[128];                        

    while (fscanf(fptr, "%s", buffer) == 1)    
        count++;                             
    
    words = (char**)malloc(count * sizeof(char *));  
    rewind(fptr);                             
    int index = 0;                                  
    while (fscanf(fptr, "%s", buffer) == 1)    
    {       
        int len = strlen(buffer);               
        words[index] = (char*)malloc((len + 1) * sizeof(char));   
        strcpy(words[index], buffer);           
        index++;
    }

    fclose(fptr);                               // close file
    return true;
}