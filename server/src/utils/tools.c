/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** parser
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **parser(const char *input, const char *sep)
{
    char **tab = NULL;
    char *str = strdup(input);
    char *token = strtok(str, sep);
    int i;

    for (i = 0; token; i++) {
        tab = realloc(tab, sizeof(char *) * (i + 1));
        tab[i] = strdup(token);
        token = strtok(NULL, sep);
    }
    tab = realloc(tab, sizeof(char *) * (i + 1));
    tab[i] = NULL;
    free(str);
    return (tab);
}

char *int_to_char(int num)
{
    char *str = malloc(12);

    if (str != NULL) {
        sprintf(str, "%d", num);
    }
    return str;
}
