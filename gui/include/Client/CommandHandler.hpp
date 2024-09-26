/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** CommandHandler
*/

#pragma once

#include "Engine/Engine.hpp"
#include "Utils/Utils.hpp"

class CommandHandler {
    public:
        CommandHandler();
        ~CommandHandler() = default;

        void setBuffer(const string &buffer);
        void handleCommand(Engine &engine);

        static void msz(vector<string> args, Engine &engine);
        static void sgt(vector<string> args, Engine &engine);
        static void bct(vector<string> args, Engine &engine);

        static void tna(vector<string> args, Engine &engine);

        static void pnw(vector<string> args, Engine &engine);
        static void ppo(vector<string> args, Engine &engine);
        static void plv(vector<string> args, Engine &engine);
        static void pin(vector<string> args, Engine &engine);
        static void pdi(vector<string> args, Engine &engine);

        static void pic(vector<string> args, Engine &engine);
        static void pie(vector<string> args, Engine &engine);

        static void pbc(vector<string> args, Engine &engine);

    private:
        string _buffer;
        string _command;
        vector<string> _args;
};
