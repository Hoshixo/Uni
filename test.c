#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


int letter_count, num_of_guesses, word_count = 0, guess_count = 0;

char **words, *guessed_chars, current_guess;

bool read_file(char *filename, int letter_count);
void hidden_word();
void valid_letter(char c);
bool exclude_word(char c);


int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Program usage: ./program_name, file_name, letter_count, guesses.\n");
        return 1;
    }

    char *filename = argv[1];
    letter_count = atoi(argv[2]);
    num_of_guesses = atoi(argv[3]);

    if (!read_file(filename, letter_count))
        exit(1);

    printf("\tRULES:\n");
	printf("\t   - Maximum %d mistakes are allowed.\n", num_of_guesses);
	printf("\t   - Single letter guess. MUST be a letter of the Alphabet.\n");
    
    guessed_chars = (char*)malloc(num_of_guesses * sizeof(char));
    if (guessed_chars == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < word_count; i++)
    {
        printf("%s\n", words[i]);
        i++;
    }
/*
    while (guess_count < num_of_guesses)
    {
        hidden_word();
        scanf(" %c", &current_guess);   //if scanf == 1, getchar != \n???
        valid_letter(current_guess);
        printf("Guess %d/%d, Word Left %d, Letters used = ", guess_count, num_of_guesses, word_count);
        for (int i = 0; i < guess_count; i++)
            printf("%c ", guessed_chars[i]);
        printf("\n");
        
    }
*/

    free(words);
    free(guessed_chars);
    return 0;
}

void hidden_word()
{
    for (int i = 0; i < letter_count; i++)      // printing blank letter spaces 
            printf("_ ");
    printf("Enter a letter: ");
}

void valid_letter(char c)
{    
    if (isalpha(c))
    {
        for (int i = 0; i < guess_count; i++)
        {
            if (guessed_chars[i] == c)
            {
                printf("%c already used.\n", c);
                return;
            }
        }
        guessed_chars[guess_count] = c;
        guess_count++;
        return;
    }
    else
        printf("%c is not a letter.\n", c);
}





bool read_file(char *filename, int letter_count)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("%s not found.\n", filename);
        return false;
    }

    char buffer[50];                                       // allocate buffer max length of 1 word
    while (fscanf(fptr, "%s", buffer) == 1)                 // read each string
        if (strlen(buffer) == letter_count)                 // check for desired length of string
            word_count++;                                   // count amount of string read @ size of letter_count
    words = (char**)malloc(word_count * sizeof(char*));     // allocate memory for array of pointers (number of strings)
    rewind(fptr);                                           // rewind ptr back to start of array 
    int index = 0;
    char valid_word[letter_count];
    while (fscanf(fptr, "%s", buffer) == 1)                 // read every string from file
    {
        if (strlen(buffer) == letter_count)
        {
            int len = strlen(buffer);                           // get length of every string from file
            words[index] = (char*)malloc((len) * sizeof(char)); // allocate memory for size of each word +1 for '\0'
            strcpy(words[index], buffer);                       // copy word from Buffer[i] into Array[i]
            index++;                                            // increment to next word
        }
    }
    bool *excluded;
    excluded = (bool*)calloc(word_count, sizeof(bool));
    for (int i = 0; i < word_count; i++)
    {
        
    }
    fclose(fptr);
    return true;
}

bool exclude_word(char c)
{
    int cat1 = 0, cat2 = 0, cat3 = 0, cat4 = 0, cat5 = 0, cat6 = 0;
    bool excluded;
    excluded = (bool*)calloc(word_count, sizeof(bool));
    for (int i = 0; i < word_count; i++)
    {
        for (int j = i; j < letter_count; j++)
        {

        }
    }
}

/*
    2D BOOLEAN ARRAY
    char **words;
    int word_count; set from reading file x letter words

    words = (int**)malloc(word_count * sizeof(char*));
    
    int index = 0;
    char word[7];

    loop
        //read word into word;
        words[index] = (int*)malloc(7 * sizeof(char)); 6 + 1 for '\0'
        strcpy(words[index], word);
        index++;

    bool *excluse;
    excluded = (bool*)calloc(word_count, sizeof(bool));

    excluded[i] = true; // would exclude word at index i in words array

*/