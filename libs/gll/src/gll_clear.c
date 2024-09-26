/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_CLEAR
*/

#include "gll.h"
#include <stdlib.h>

void gll_clear(gll_t *list)
{
    gll_node_t *curr_node = list->first;
    gll_node_t *next_node;

    while (curr_node) {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
}
