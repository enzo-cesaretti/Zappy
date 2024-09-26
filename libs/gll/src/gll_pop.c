/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_POP
*/

#include "gll.h"
#include <stddef.h>

void *gll_pop(gll_t *list)
{
    gll_node_t *node = NULL;
    void *data = NULL;

    if (!list)
        return NULL;
    node = list->first;
    if (!node)
        return NULL;
    data = node->data;
    if (!gll_remove(list, 0))
        return NULL;
    return data;
}

void *gll_pop_back(gll_t *list)
{
    gll_node_t *node = NULL;
    void *data = NULL;

    if (!list)
        return NULL;
    node = list->last;
    if (!node)
        return NULL;
    data = node->data;
    if (!gll_remove(list, (list->size - 1)))
        return NULL;
    return data;
}
