/* Упражнение по программированию 11.12 */
#include <stdio.h>
#include <ctype.h> // для isspace()
#include <stdbool.h> // для bool, true, false

int main(void)
{
    char c; // прочитанный символ
    int low_ct = 0; // количество строчных символов
    int up_ct = 0; // количество прописных символов
    int dig_ct = 0; // количество цифр
    int n_words = 0; // количество слов
    int punc_ct = 0; // количество знаков препинания
    bool inword = false; // == true, если c находится в слове

    printf("Введите текст, подлежащий анализу (EOF для завершения):\n");
    while ((c = getchar()) != EOF)
    {
        if (islower(c))
            low_ct++;
        else if (isupper(c))
            up_ct++;
        else if (isdigit(c))
            dig_ct++;
        else if (ispunct(c))
            punc_ct++;
        if (!isspace(c) && !inword)
        {
            inword = true; // начало нового слова
            n_words++; // подсчет слов
        }
        if (isspace(c) && inword)
            inword = false; // достигнут конец слова
    }
    printf("\nслов = %d, строчных = %d, прописных = %d, "
                   "цифр = %d, препинаний = %d\n",
           n_words,low_ct,up_ct, dig_ct, punc_ct);

    return 0;
}