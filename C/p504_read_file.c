#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count = 0;
char **words;
/*
words {
    * = malloc(sizeof(str)), copy str int
    *
    *
    *
    * 
}
*/
bool read_file(char *filename);


int main()
{
    char filename[] = "dictionary.txt";
    if (!read_file(filename))
    {
        exit(1);
    }
       
    for (int i = 0; i < count; i++)
        printf("%s\n", words[i]);
        // free 2D dynamically allocated array
    for (int i = 0; i < count; i++)
        free(words[i]);
    free(words);

    return 0;
}

bool read_file(char *filename)                  // take given file name
{
    FILE *fptr = fopen(filename, "r");          // open 'r' for read
    if (fptr == NULL)
    {
        printf("%s not found\n", filename);
        return false;
    }
    char buffer[128];                           // allocate buffer

    while (fscanf(fptr, "%s", buffer) == 1)     // read each string
        count++;                                // count amount of strings read
    
    words = (char**)malloc(count * sizeof(char *));  // allocate memory
    rewind(fptr);                               // rewinds ptr back to start of array
    int index = 0;                                  
    while (fscanf(fptr, "%s", buffer) == 1)     // read every string from file
    {       
        int len = strlen(buffer);               // get length of every string from file
        words[index] = (char*)malloc((len + 1) * sizeof(char));   // allocate memory
        strcpy(words[index], buffer);           // copy into memory
        index++;
    }

    fclose(fptr);                               // close file
    return true;
}