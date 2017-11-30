// Chapter 12 Exercise 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 400

char ** get_words(int n);
static void find_word(char **start, char **end);

int main(void)
{
    int n;
    char ** words;

    printf("Сколько слов вы хотите ввести?\n");
    if (scanf("%d", &n) == 1 && n > 0)
    {
        while (getchar() != '\n')
            continue;
        words = get_words(n);

        printf("Вот введенные вами слова:\n");
        for (int i = 0; i < n; i++)
            printf("%s\n", words[i]);
    }

    return 0;
}

char ** get_words(int n)
{
    char tmp[LIMIT];
    int i;
    char * word_start;
    char * word_end;
    int word_length;

    char ** word_array = (char **) malloc(n * sizeof(char *));

    printf("Теперь введите %d слов:\n", n);
    word_start = fgets(tmp, LIMIT, stdin);

    for (i = 0; i < n; i++)
    {
        // find the start and end of next word
        find_word(&word_start, &word_end);

        // if word_start points to null char, there are no more
        // words to find; exit loop
        if (*word_start == '\0')
            break;

        // allocate memory for new word and copy from tmp
        word_length = word_end - word_start;
        word_array[i] = (char *) malloc((word_length + 1) * sizeof(char));
        if (word_array[i] != NULL)
        {
            strncpy(word_array[i], word_start, word_length);
            word_array[i][word_length] = '\0';
        }

        word_start = word_end;
    }

    // if less than n words found, set remaining elements of
    // word_array to null string
    if (i < n)
        for (; i < n; i++)
        {
            word_array[i] = (char *) malloc(sizeof(char));
            *word_array[i] = '\0';
        }

    return word_array;
}

static void find_word(char **start, char **end)
{
    // takes two pointers to pointers to char
    // sets *start to point to first character of first
    // word occuring after **start and sets *end to point
    // to the character immediately after the word

    while (isspace(**start))
        (*start)++;

    *end = *start;

    while (!isspace(**end) && **end != '\0')
        (*end)++;
}

