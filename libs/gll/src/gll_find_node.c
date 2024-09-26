/*
** EPITECH PROJECT, 2023
** GLL_METHODE
** File description:
** Methode for gll
*/

#include "gll.h"
#include <stddef.h>

gll_node_t *gll_find_node(gll_t *list, int pos)
{
    gll_node_t *curr_node;
    int curr_pos;
    int reverse;

    if (pos > list->size)
        return NULL;
    if (pos > ((list->size - 1) / 2)) {
        reverse = 1;
        curr_pos = list->size - 1;
        curr_node = list->last;
    } else {
        reverse = 0;
        curr_pos = 0;
        curr_node = list->first;
    }
    while (curr_node && curr_pos != pos) {
        curr_node = (reverse ? (curr_node->prev) : (curr_node->next));
        curr_pos = (reverse ? (curr_pos - 1) : (curr_pos + 1));
    }
    return curr_node;
}
