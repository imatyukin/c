// Chapter 13 Exercise 9
/* Для упрощения подсчета в каждой строке хранится одно число и слово. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 47

int main(void)
{
    FILE *fp;
    char words[MAX];
    int wordct = 0;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stderr,"Не удается открыть файл \"wordy\".\n");
        exit(EXIT_FAILURE);
    }

    // определить текущее количество строк
    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
        wordct++;

    rewind(fp);
    puts("Введите слова для добавления в файл; для завершения");
    puts("введите символ # в начале строки.");
    while ((fscanf(stdin,"%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%3d: %s\n", ++wordct, words);

    puts("Содержимое файла:");
    rewind(fp); // возврат в начало файла
    while (fgets(words, MAX, fp) != NULL) // чтение строки, включая число
        fputs(words, stdout);
    if (fclose(fp) != 0)
        fprintf(stderr,"Ошибка при закрытии файла\n");
    puts("Программа завершена.");

    return 0;
}
