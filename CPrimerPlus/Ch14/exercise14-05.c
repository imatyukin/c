// Chapter 14 Exercise 5
#include <stdio.h>
#include <string.h>

#define LEN 14
#define CSIZE 4
#define SCORES 3

struct name {
    char first[LEN];
    char last[LEN];
};
struct student {
    struct name person;
    float scores[SCORES];
    float mean;
};

void get_scores(struct student ar[], int lim);
void find_means(struct student ar[], int lim);
void show_class(const struct student ar[], int lim);
void show_ave(const struct student ar[], int lim);

int main(void)
{
    struct student class[CSIZE] ={
            { "Флип", "Снайд"},
            { "Клэр", "Воянс"},
            { "Бинго", "Хиггс"},
            { "Фойн", "Хантер"}
    };

    get_scores(class, CSIZE);
    find_means(class, CSIZE);
    show_class(class, CSIZE);
    show_ave(class, CSIZE);

    return 0;
}

void get_scores(struct student ar[], int lim)
{
    int i,j;

    for (i = 0; i < lim; i++)
    {
        printf("Введите %d оценок для %s %s:\n", SCORES,
               ar[i].person.first, ar[i].person.last);
        for (j = 0; j < SCORES; j++)
        {
            while (scanf("%f", &ar[i].scores[j]) != 1)
            {
                scanf("%*s");
                puts("Используйте числовой ввод.");
            }
        }
    }
}

void find_means(struct student ar[], int lim)
{
    int i, j;
    float sum;

    for (i = 0; i < lim; i++)
    {
        for (sum = 0, j = 0; j < SCORES; j++)
            sum += ar[i].scores[j];
        ar[i].mean = sum / SCORES;
    }
}

void show_class(const struct student ar[], int lim)
{
    int i, j;
    char wholename[2*LEN];

    for (i = 0; i < lim; i++)
    {
        strcpy(wholename, ar[i].person.first);
        strcat(wholename, " ");
        strcat(wholename, ar[i].person.last);
        printf("%27s: ", wholename);
        for (j = 0; j < SCORES; j++)
            printf("%6.1f ", ar[i].scores[j]);
        printf(" Средняя оценка = %5.2f\n", ar[i].mean);
    }
}

void show_ave (const struct student ar[], int lim)
{
    int i, j;
    float total;

    printf("\n%27s: ", "СРЕДНИЕ ОЦЕНКИ ПО ЭКЗАМЕНАМ");
    for (j = 0; j < SCORES; j++)
    {
        for (total = 0, i = 0; i < lim; i++)
            total += ar[i].scores[j];
        printf("%6.2f ", total / lim);
    }
    for (total = 0, i = 0; i < lim; i++)
        total += ar[i].mean;
    printf(" Средняя оценка по всем = %5.2f\n", total / lim);
}

