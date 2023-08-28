/*
    open a file
    read how many lines are in the file
    allocation a 2D array of lines size
    rewind the file
    read each line of the file, and store into 2D array
    close the file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **words;
int word_count = 0;

bool read_file(char *filename);

int main()
{
    char *filename = "dictionary.txt";
    if (!read_file(filename))
        exit(1);

    for (int i = 0; i < word_count; i++)
        printf("%s\n", words[i]);

    //free a dynamic 2D array
    for (int i = 0; i < word_count; i++)
        free(words[i]);
    free(words);
    return 0;
}


bool read_file(char *filename)
{
    FILE *fptr = fopen(filename, "r");  // r = reading, w = writing
    if (fptr == NULL)
    {
        printf("%s not found\n", filename);
        return false;
    }

    char buffer[128];
    while (fscanf(fptr, "%127s", buffer) == 1)        // reading from a file
        word_count++;
    printf("%d\n", word_count);      
    words = (char**)malloc(word_count * sizeof(char*));
    rewind(fptr);
    int idx = 0;
    while (fscanf(fptr, "%127s", buffer) == 1)
    {
        // allocate some memory
        int len = strlen(buffer);
        words[idx] = (char*)malloc((len + 1) * sizeof(char));
        // copy from buffer into memory
        strcpy(words[idx], buffer);
        idx++;
    }
    fclose(fptr);
    return true;
}

