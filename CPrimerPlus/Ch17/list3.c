/* list3.c: переделанный list.c -- функции для поддержки операций со списком */
#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

/* функции интерфейса */

/* устанавливает список в пустое состояние */
void InitializeList(List * plist)
{
    plist->items = 0;
}

/* возвращает true, если список пуст */
bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

/* возвращает true, если список полон */
bool ListIsFull(const List * plist)
{
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}

/* возвращает количество узлов */
unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

/* добавляет элемент в список */
/* предполагается, что для типа Item определена операция = */
bool AddItem(Item item, List * plist)
{
    if (plist->items == MAXSIZE)
        return false;
    else
    {
        plist->entries[plist->items++] = item;
        return true;
    }
}

/* посещает каждый узел и выполняет функцию, указанную pfun */
void Traverse (const List * plist, void (* pfun)(Item item) )
{
    int i;
    for (i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]); /* применить функцию к элементу списка */
}

/* функция malloc() не использовалась, поэтому освобождать нечего */
/* устанавливает член items в 0 */
void EmptyTheList(List * plist)
{
    plist->items = 0;
}
