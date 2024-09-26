/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Inventory
*/

#pragma once

class Inventory {
    public:
        Inventory(int food = 0, int linemate = 0, int deraumere = 0, int sibur = 0,
            int mendiane = 0, int phiras = 0, int thystame = 0);
        ~Inventory() = default;

        int food;
        int linemate;
        int deraumere;
        int sibur;
        int mendiane;
        int phiras;
        int thystame;
};
