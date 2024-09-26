/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_GET
*/

#include "gll.h"
#include <stddef.h>

void *gll_get(gll_t *list, int pos)
{
    gll_node_t *node = gll_find_node(list, pos);

    if (node)
        return node->data;
    return NULL;
}
