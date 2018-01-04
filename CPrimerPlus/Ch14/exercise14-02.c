// Chapter 14 Exercise 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 16
#define MONTHS 12

void get(char *, int);

struct month
{
    char name[LEN];
    char abbrev[7];
    char monumb[3];
    int days;
};

struct month months[MONTHS] = {
        {"Январь", "ЯНВ", "01", 31},
        {"Февраль", "ФЕВ", "02", 28},
        {"Март", "МАР", "03", 31},
        {"Апрель", "АПР", "04", 30},
        {"Май", "МАЙ", "05", 31},
        {"Июнь", "ИЮН", "06", 30},
        {"Июль", "ИЮЛ", "07", 31},
        {"Август", "АВГ", "08", 31},
        {"Сентябрь", "СЕН", "09", 30},
        {"Октябрь", "ОКТ", "10", 31},
        {"Ноябрь", "НОЯ", "11", 30},
        {"Декабрь", "ДЕК", "12", 31}
};

int main(void)
{
    int year, day, i, total;
    char month[LEN];

    printf("Введите год: ");
    while (scanf("%d", &year) != 1)
    {
        // clear input stream
        while (getchar() != '\n') continue;

        printf("Введите год: ");
    }
    // clear input stream
    while (getchar() != '\n') continue;

    printf("Введите месяц названием, аббревиатурой\n");
    printf("или порядковым номером (напр. Январь, ЯНВ или 01): ");
    get(month, LEN);

    printf("Введите день: ");
    while (scanf("%d", &day) != 1)
    {
        // clear input stream
        while (getchar() != '\n') continue;

        printf("Введите день: ");
    }
    // clear input stream
    while (getchar() != '\n') continue;

    // match input to month
    for (i = 0; i < MONTHS; i++)
    {
        // if match is found, break
        if (strcmp(month, months[i].name) == 0 ||
            strcmp(month, months[i].abbrev) == 0 ||
            strcmp(month, months[i].monumb) == 0)
            break;
    }

    // if no match for month found, exit
    if (i == MONTHS)
    {
        printf("Месяц %s не найден.\n", month);
        exit(1);
    }

    // check for leap year and adjust days in February if necessary
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        months[1].days = 29;

    // check validity of date
    if (day > months[i].days)
    {
        printf("Неверная дата: нет %d дня в %s %d.\n",
               day, months[i].name, year);
        exit(1);
    }

    // get total days in year up to given date
    total = 0;
    for (int j = 0; j < i; j++)
        total += months[j].days;

    total += day;

    printf("%d дней истекло с начала %d года по %s %d включительно.\n",
           total, year, months[i].name, day);

    return 0;
}

void get(char * string, int n)
{
    // wrapper for fgets - read from stdin and replace
    // first newline with null character

    fgets(string, n, stdin);

    while (*string != '\0')
    {
        if (*string == '\n')
        {
            *string = '\0';
            break;
        }
        string++;
    }
}