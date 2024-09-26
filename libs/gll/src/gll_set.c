/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_SET
*/

#include "gll.h"
#include <stddef.h>

void *gll_set(gll_t *list, void *data, int pos)
{
    gll_node_t *curr_node = gll_find_node(list, pos);
    void *old_data = NULL;

    if (!curr_node)
        return NULL;
    old_data = curr_node->data;
    curr_node->data = data;
    return old_data;
}
