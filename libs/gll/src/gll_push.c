/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_PUSH
*/

#include "gll.h"

int gll_push(gll_t *list, void *data)
{
    gll_node_t *new_node = gll_init_node(data);

    if (list->size == 0) {
        list->last = new_node;
    } else {
        list->first->prev = new_node;
        new_node->next = list->first;
    }
    list->first = new_node;
    list->size++;
    return 0;
}

int gll_push_back(gll_t *list, void *data)
{
    gll_node_t *new_node = gll_init_node(data);

    if (list->size == 0) {
        list->first = new_node;
    } else {
        list->last->next = new_node;
        new_node->prev = list->last;
    }
    list->last = new_node;
    list->size++;
    return 0;
}
