// Chapter 17 Exercise 1a
/* exercise17-01a.c -- рекурсивное решение */
#include <stdio.h>
#include <stdlib.h> /* содержит прототип функции malloc() */
#include <string.h> /* содержит прототип функции strcpy() */

#define TSIZE 45 /* размер массива для хранения названия */

struct film {
    char title[TSIZE];
    int rating;
    struct film * next; /* указывает на следующую структуру в списке */
};

char * s_gets(char * st, int n);
void show_rec(const struct film * pf); /* рекурсивная функция */

int main(void)
{
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];

    puts("Введите название первого фильма:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL) /* первая структура */
            head = current;
        else /* последующие структуры */
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        puts("Введите свое значение рейтинга <0-10>:");
        scanf("%d", &current->rating);
        while(getchar() != '\n')
            continue;
        puts("Введите название следующего фильма (или пустую строку для прекращения ввода):");
        prev = current;
    }
    if (head == NULL)
        printf("Данные не введены.");
    else
        printf ("Список фильмов:\n");
    current = head;
    while (current != NULL)
    {
        printf("Фильм: %s Рейтинг: %d\n", current->title, current->rating);
        current = current->next;
    }
    if (head != NULL)
    {
        printf("\nСписок фильмов в обратном порядке:\n");
        show_rec(head);
    }
    printf("Программа завершена.\n");

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

void show_rec(const struct film * pf)
{
    if (pf->next != NULL)
        show_rec(pf->next);
    printf("Фильм: %s Рейтинг: %d\n", pf->title, pf->rating);
}