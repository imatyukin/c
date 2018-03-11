// Chapter 17 Exercise 7
/* компилировать вместе с tree1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree1.h"

#define SLEN 81

void printitem(Item item);
char menu(void);
void showwords (const Tree * pt);
void findword (const Tree * pt);
char * s_gets(char * st, int n);

int main(void)
{
    Tree wordcount;
    FILE * fp;
    char filename[SLEN];
    char word[SLEN];
    Item entry;
    char choice;

    printf("Введите имя файла, подлежащего обработке: \n");
    s_gets(filename, SLEN);
    if ((fp = fopen(filename, "r")) == 0)
    {
        printf("Не удается открыть файл %s. Программа завершена.\n", filename);
        exit(EXIT_FAILURE);
    }
    InitializeTree(&wordcount);
    while (fscanf(fp, "%s", word) == 1 && !TreeIsFull(&wordcount))
    {
        strcpy(entry.wrd, word);
        AddItem(&entry, &wordcount);
    }
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 's' : showwords(&wordcount);
                break;
            case 'f' : findword(&wordcount);
                break;
            default : puts("ошибка в switch");
        }
    }
    fclose(fp);
    puts("Программа завершена.");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // поиск новой строки
        if (find) // если адрес не равен NULL,
            *find = '\0'; // поместить туда нулевой символ
        else
            while (getchar() != '\n')
                continue; // отбросить остаток строки
    }

    return ret_val;
}

char menu(void)
{
    int ch;

    puts("Программа подсчета слов");
    puts("Введите букву, которая соответствует интересующему варианту:");
    puts("s) показать список слов f) найти слово");
    puts("q) выйти из программы");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n') /* отбросить оставшуюся часть строки */
            continue;
        ch = tolower(ch);
        if (strchr("sfq",ch) == NULL)
            puts("Введите s, f или q:");
        else
            break;
    }
    if (ch == EOF) /* обнаружение EOF приводит к завершению программы */
        ch = 'q';

    return ch;
}

void showwords (const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("Записи отсутствуют.");
    else
        Traverse(pt, printitem);
}

void findword (const Tree * pt)
{
    char word[SLEN];
    Item entry;
    const Item * pi;

    if (TreeIsEmpty(pt))
    {
        puts("Записи отсутствуют.");
        return; /* выйти из функции, если дерево пустое */
    }
    printf("Введите слово для поиска: ");
    scanf("%s", word);
    while (getchar() != '\n')
        continue;
    strcpy(entry.wrd, word);
    pi = WhereInTree(&entry, pt);
    if (pi == NULL)
        printf("%s не находится в списке.\n", word);
    else
        printf("%s встречается %d раз(а).\n", word, pi->count);
}

void printitem(Item item)
{
    printf("%3d: %s\n", item.count,
           item.wrd);
}
