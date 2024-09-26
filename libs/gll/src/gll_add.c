/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_ADD
*/

#include "gll.h"
#include <stddef.h>

void add_at_pos(gll_t *list, gll_node_t *curr_node, gll_node_t *new_node)
{
    if (curr_node) {
        new_node->prev = curr_node->prev;
        new_node->next = curr_node;
        if (!curr_node->prev)
            list->first = new_node;
        else
            curr_node->prev->next = new_node;
        curr_node->prev = new_node;
    } else {
        list->last->next = new_node;
        new_node->prev = list->last;
        list->last = new_node;
    }
}

int gll_add(gll_t *list, void *data, int pos)
{
    gll_node_t *new_node = NULL;
    gll_node_t *curr_node = NULL;

    if (pos > list->size)
        return -1;
    new_node = gll_init_node(data);
    if (list->size == 0) {
        list->first = new_node;
        list->last = new_node;
        list->size++;
        return 0;
    }
    curr_node = gll_find_node(list, pos);
    add_at_pos(list, curr_node, new_node);
    list->size++;
    return 0;
}
