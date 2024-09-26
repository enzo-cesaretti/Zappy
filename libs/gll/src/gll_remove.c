/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_REMOVE
*/

#include "gll.h"
#include <stdlib.h>

void *gll_remove(gll_t *list, int pos)
{
    gll_node_t *curr_node = gll_find_node(list, pos);
    void *data = NULL;

    if (!curr_node)
        return NULL;
    data = curr_node->data;
    if (!curr_node->prev)
        list->first = curr_node->next;
    else
        curr_node->prev->next = curr_node->next;
    if (!curr_node->next)
        list->last = curr_node->prev;
    else
        curr_node->next->prev = curr_node->prev;
    list->size--;
    free(curr_node);
    return data;
}
