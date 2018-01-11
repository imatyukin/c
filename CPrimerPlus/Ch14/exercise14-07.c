// Chapter 14 Exercise 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* максимальное количество книг */
#define CONTINUE 0
#define DONE 1

struct book { /* определение шаблона book */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
struct pack {
    struct book book; // разные пространства имен для двух идентификаторов book
    bool delete_me;
};
/*
Стратегия: вместо того, чтобы перегруппировывать массив структур каждый раз,
когда происходит удаление, мы объединим структуру с членом данных, который
указывает, помечен ли элемент для последующего удаления. В конце программы
будут отображаться и сохраняться только те элементы, которые не помечены как
подлежащие удалению. Информацию об удалении можно было бы хранить в отдельном
массиве, но помещение ее в структуру вместе со структурой book позволяет держать
информацию вместе.
*/
char * s_gets(char * st, int n);
int getlet(const char * s);
int getbook(struct pack * pb);
void update(struct pack * item);

int main(void)
{
    struct pack library[MAXBKS]; /* массив структур */
    int count = 0;
    int deleted = 0;
    int index, filecount, open;
    FILE * pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "r")) != NULL)
    {
        while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
        {
            if (count == 0)
                puts("Текущее содержимое файла book.dat:");
            printf("%s авторства %s: $%.2f\n",library[count].book.title,
                   library[count].book.author, library[count].book.value);
            printf("Хотите изменить или удалить эту запись?<y/n> ");
            if (getlet("yn") == 'y')
            {
                printf("Введите c для изменения или d для удаления записи: ");
                if (getlet("cd") == 'd')
                {
                    library[count].delete_me = true;
                    deleted++;
                    puts("Запись помечена для удаления.");
                }
                else
                    update(&library[count]);
            }
            count++;
        }
        fclose(pbooks);
    }
    filecount = count - deleted;
    if (count == MAXBKS)
    {
        fputs("Файл book.dat заполнен.", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Введите названия новых книг.");
    puts("Нажмите [enter] в начале строки, чтобы закончить ввод.");
    open = 0;
    while (filecount < MAXBKS)
    {
        if (filecount < count)
        {
            while (library[open].delete_me == false)
                open++;
            if (getbook(&library[open]) == DONE)
                break;
        }
        else if (getbook(&library[filecount]) == DONE)
            break;
        filecount++;
        if (filecount < MAXBKS)
            puts("Введите название следующей книги.");
    }
    puts("Каталог ваших книг:");
    for (index = 0; index < filecount; index++)
        if (library[index].delete_me == false)
            printf("%s авторства %s: $%.2f\n",library[index].book.title,
                   library[index].book.author, library[index].book.value);
    if ((pbooks = fopen("book.dat", "w")) == NULL)
    {
        fputs("Не удается открыть файл book.dat для вывода.\n",stderr);
        exit(EXIT_FAILURE);
    }
    for (index = 0; index < filecount; index++)
        if (library[index].delete_me == false)
            fwrite(&(library[index].book), size, 1, pbooks);
    fclose(pbooks);
    puts("Программа завершена.");

    return 0;
}

int getlet(const char * s)
{
    char c;
    c = getchar();

    while (strchr(s, c) == NULL)
    {
        printf ("Введите символ из списка %s\n", s);
        while( getchar() != '\n')
            continue;
        c = getchar();
    }
    while (getchar() != '\n')
        continue;

    return c;
}

int getbook(struct pack * pb)
{
    int status = CONTINUE;

    if (s_gets(pb->book.title, MAXTITL) == NULL || pb->book.title[0] == '\0')
        status = DONE;
    else
    {
        printf ("Теперь введите имя автора: ");
        s_gets (pb->book.author, MAXAUTL);
        printf ("Теперь введите цену книги: ");
        while (scanf("%f", &pb->book.value ) != 1)
        {
            puts("Используйте числовой ввод.");
            scanf("%*s");
        }
        while (getchar() != '\n')
            continue; /* очистить входную строку */
        pb->delete_me = false;
    }

    return status;
}

void update(struct pack * item)
{
    struct book copy;
    char c;
    copy = item->book;

    puts("Введите букву, обозначающую желаемое действие:");
    puts("t) изменить название a) изменить автора");
    puts("v) изменить цену s) выйти с сохранением изменений");
    puts("q) выйти без сохранения изменений");
    while ( (c = getlet("tavsq")) != 's' && c != 'q')
    {
        switch ( c )
        {
            case 't' : puts("Введите новое название: ");
                s_gets (copy.title, MAXTITL);
                break;
            case 'a' : puts("Введите ФИО нового автора: ");
                s_gets (copy.author, MAXAUTL);
                break;
            case 'v' : puts("Введите новую цену: ");
                while (scanf("%f", &copy.value) != 1)
                {
                    puts ("Введите числовое значение: ");
                    scanf("%*s");
                }
                while( getchar() != '\n')
                    continue;
                break;
        }
        puts("t) изменить название a) изменить автора");
        puts("v) изменить цену s) выйти с сохранением изменений");
        puts("q) выйти без сохранения изменений");
    }
    if (c == 's')
        item->book = copy;
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

