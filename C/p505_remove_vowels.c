#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count = 0;
char **words;
bool read_file(char *filename);
bool contains_vowel(char *str);


int main()
{
    char filename[] = "dictionary.txt";
    if (!read_file(filename))
        exit(1);

    FILE *fptr = fopen("no_vowel_dict.txt", "w");

    for (int i = 0; i < count; i++)
        if (!contains_vowel(words[i]))
            fprintf(fptr, "%s\n", words[i]);
    fclose(fptr);

    for (int i = 0; i < count; i++)
        free(words[i]);
    free(words);

    return 0;
}

bool contains_vowel(char *str)
{
    // a, e, i, o, u
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e'  || 
            str[i] == 'i'  || str[i] == 'o'  || str[i] == 'u')
            return true;
    }
    return false;
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