// Упражнение по программированию 11.7
#include <stdio.h>
#include <string.h>

#define LENGTH 100

char * mystrncpy(char *s1, const char *s2, size_t n);

int main(void)
{
    char s1[LENGTH];
    char s2[LENGTH];
    int n;

    printf("Введите первую строку: ");
    fgets(s1, LENGTH, stdin);
    printf("Введите вторую строку: ");
    fgets(s2, LENGTH, stdin);
    while (s1[0] !='\0' || s2[0] != '\0') {
        if (*s1 == '\n' || *s2 == '\n')
        {
            *s1 = '\0';
            *s2 = '\0';
            break;
        }

        printf("Введите количество символов, которые нужно скопировать из строки 2 в строку 1: ");
        scanf("%d", &n);
        while (getchar() != '\n')
            continue;
        if (n > LENGTH)
            n = LENGTH;

        printf("%s", mystrncpy(s1, s2, n));

        memset(&s1[0], 0, sizeof(s1));

        printf("Введите первую строку: ");
        fgets(s1, LENGTH, stdin);
        printf("Введите вторую строку: ");
        fgets(s2, LENGTH, stdin);
    }
    puts("Программа завершена.");

    return 0;
}

char * mystrncpy(char *s1, const char *s2, size_t n)
{
    char *s = s1;

    while (n > 0 && *s2 != '\0') {
        *s++ = *s2++;
        --n;
    }
    while (n > 0) {
        *s++ = '\0';
        --n;
    }

    return s1;
}