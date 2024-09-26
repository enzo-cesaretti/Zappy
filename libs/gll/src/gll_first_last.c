/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_FIRST & GLL_LAST
*/

#include "gll.h"
#include <stddef.h>

void *gll_first(gll_t *list)
{
    if (!list->first)
        return NULL;
    return list->first->data;
}

void *gll_last(gll_t *list)
{
    if (!list->last)
        return NULL;
    return list->last->data;
}
