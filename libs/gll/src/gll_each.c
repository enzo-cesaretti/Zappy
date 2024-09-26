/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_EACH
*/

#include "gll.h"
#include <stddef.h>

void gll_each(gll_t *list, void (*f)(void *))
{
    gll_node_t *curr_node = list->first;

    while (curr_node) {
        (*f)(curr_node->data);
        curr_node = curr_node->next;
    }
}

void gll_each_reverse(gll_t *list, void (*f)(void *))
{
    gll_node_t *curr_node = list->last;

    while (curr_node) {
        (*f)(curr_node->data);
        curr_node = curr_node->prev;
    }
}
