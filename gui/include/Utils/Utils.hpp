/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Utils
*/

#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

#define UNUSED __attribute__((unused))

class Utils {
    public:
        Utils() = default;
        ~Utils() = default;

        static vector<string> split(const string &str, string delim);
};
