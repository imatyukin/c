// Chapter 14 Exercise 3
#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* максимальное количество книг */

struct book { /* установка шаблона book */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);
void sortt(struct book * pb[], int n);
void sortv(struct book * pb[], int n);

int main(void)
{
    struct book library[MAXBKS]; /* массив структур типа book */
    struct book * pbk[MAXBKS]; /* указатели для сортировки */
    int count = 0;
    int index;

    printf("Введите название книги.\n");
    printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        printf("Теперь введите ФИО автора.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Теперь введите цену.\n");
        scanf("%f", &library[count].value);
        pbk[count] = &library[count];
        count++;
        while (getchar() != '\n')
            continue; /* очистить входную строку */
        if (count < MAXBKS)
            printf("Введите название следующей книги.\n");
    }

    printf("Каталог ваших книг:\n");
    for (index = 0; index < count; index++)
        printf("%s авторства %s: $%.2f\n", library[index].title,
               library[index].author, library[index].value);

    printf("Каталог ваших книг, отсортированный по названию:\n");
    sortt(pbk, count);
    for (index = 0; index < count; index++)
        printf("%s авторства %s: $%.2f\n", pbk[index]->title,
               pbk[index]->author, pbk[index]->value);

    printf("Каталог ваших книг, отсортированный по цене:\n");
    sortv(pbk, count);
    for (index = 0; index < count; index++)
        printf("%s авторства %s: $%.2f\n", pbk[index]->title,
               pbk[index]->author, pbk[index]->value);

    return 0;
}

void sortt(struct book * pb[], int n)
{
    int top, search;
    struct book * temp;

    for (top = 0; top < n -1; top++)
        for (search = top + 1; search < n; search++)
            if (strcmp(pb[search]->title, pb[top]->title) < 0)
            {
                temp = pb[search];
                pb[search] = pb[top];
                pb[top] = temp;
            }
}

void sortv(struct book * pb[], int n)
{
    int top, search;
    struct book * temp;

    for (top = 0; top < n - 1; top++)
        for (search = top + 1; search < n; search++)
            if (pb[search]->value < pb[top]->value)
            {
                temp = pb[search];
                pb[search] = pb[top];
                pb[top] = temp;
            }
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

