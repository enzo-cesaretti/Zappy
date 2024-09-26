/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** Generic Linkedlist
*/

#include "gll.h"
#include <stdlib.h>

gll_t *gll_init(void)
{
    gll_t *list = malloc(sizeof(gll_t));

    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

gll_node_t *gll_init_node(void *data)
{
    gll_node_t *node = malloc(sizeof(gll_node_t));

    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
