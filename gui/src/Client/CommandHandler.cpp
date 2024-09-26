/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** CommandHandler
*/

#include "Client/CommandHandler.hpp"
#include <functional>
#include <iostream>
#include <map>
#include "Utils/Logger.hpp"

using std::function;
using std::map;

const map<string, function<void(vector<string> args, Engine &engine)>> commands{
    {"msz", CommandHandler::msz},
    {"sgt", CommandHandler::sgt},
    {"sst", CommandHandler::sgt},
    {"bct", CommandHandler::bct},
    {"tna", CommandHandler::tna},
    {"pnw", CommandHandler::pnw},
    {"ppo", CommandHandler::ppo},
    {"plv", CommandHandler::plv},
    {"pin", CommandHandler::pin},
    {"pdi", CommandHandler::pdi},
    {"pic", CommandHandler::pic},
    {"pie", CommandHandler::pie},
    {"pbc", CommandHandler::pbc},
};

CommandHandler::CommandHandler()
{
}

void CommandHandler::setBuffer(const string &buffer)
{
    _buffer.clear();
    _buffer = buffer;
}

void CommandHandler::handleCommand(Engine &engine)
{
    if (_buffer.empty())
        return;

    vector<string> tokens = Utils::split(_buffer, "\n");
    if (tokens.empty())
        return;

    for (string &token : tokens) {
        vector<string> cmds = Utils::split(token, " ");

        _command = cmds[0];
        _args = vector<string>(cmds.begin() + 1, cmds.end());

        if (commands.find(_command) != commands.end()) {
            commands.at(_command)(_args, engine);
        } else {
            LOG_INFO("Unknown command: " + _command);
        }
        _command.clear();
        _args.clear();
    }
}

void CommandHandler::msz(vector<string> args, Engine &engine)
{
    if (args.size() == 0)
        return;

    int width = std::stoi(args[0]);
    int height = std::stoi(args[1]);
    DataMap mapData(width, height);
    engine.createMap(mapData);

    LOG_INFO("Creating map: " + args[0] + "x" + args[1]);
    engine.updateMap();
}

void CommandHandler::sgt(vector<string> args UNUSED, Engine &engine UNUSED)
{
    if (args.size() == 0)
        return;

    DataMap &mapData = engine.getMapData();
    mapData.setFrequency(std::stoi(args[0]));

    LOG_INFO("Setting frequency: " + args[0]);
    engine.updateMap();
}

void CommandHandler::bct(vector<string> args UNUSED, Engine &engine UNUSED)
{
    if (args.size() == 0)
        return;

    DataMap &mapData = engine.getMapData();
    int x = std::stoi(args[0]);
    int y = std::stoi(args[1]);

    Inventory &inv = mapData.getTile(x, y).getInventory();
    inv.food = std::stoi(args[2]);
    inv.linemate = std::stoi(args[3]);
    inv.deraumere = std::stoi(args[4]);
    inv.sibur = std::stoi(args[5]);
    inv.mendiane = std::stoi(args[6]);
    inv.phiras = std::stoi(args[7]);
    inv.thystame = std::stoi(args[8]);
    engine.updateMap();
}

void CommandHandler::tna(vector<string> args, Engine &engine)
{
    if (args.size() == 0)
        return;

    string team = args[0];
    engine.getMapData().addTeam(team);

    LOG_INFO("Adding team: " + args[0]);
    engine.updateMap();
}

void CommandHandler::pnw(vector<string> args, Engine &engine)
{
    if (args.size() == 0)
        return;

    int id = std::stoi(args[0]);
    int x = std::stoi(args[1]);
    int y = std::stoi(args[2]);
    Orientation orientation = static_cast<Orientation>(std::stoi(args[3]));
    int level = std::stoi(args[4]);
    string team = args[5];

    DataPlayer player(id, orientation, team, level);
    player.x = x;
    player.y = y;
    engine.getMapData().addPlayer(player, x, y);

    LOG_INFO("New player[" + std::to_string(id) + "]");
    engine.updateMap();
}

void CommandHandler::ppo(vector<string> args, Engine &engine)
{
    if (args.size() == 0)
        return;

    int id = std::stoi(args[0]);
    int x = std::stoi(args[1]);
    int y = std::stoi(args[2]);
    Orientation orientation = static_cast<Orientation>(std::stoi(args[3]));

    engine.getMapData().movePlayer(id, x, y);
    DataPlayer &player = engine.getMapData().getPlayer(id);
    player.setOrientation(orientation);

    LOG_INFO("Player[" + std::to_string(id) + "] set to (" + std::to_string(x) + ", "
        + std::to_string(y) + ")");
    engine.updateMap();
}

void CommandHandler::plv(vector<string> args, Engine &engine)
{
    if (args.size() == 0)
        return;

    int id = std::stoi(args[0]);
    int level = std::stoi(args[1]);

    DataPlayer &player = engine.getMapData().getPlayer(id);
    player.setLevel(level);

    LOG_INFO("Player[" + std::to_string(id) + "] level set to " + std::to_string(level));
    engine.updateMap();
}

void CommandHandler::pin(vector<string> args, Engine &engine)
{
    if (args.size() == 0)
        return;

    int id = std::stoi(args[0]);
    int x = std::stoi(args[1]);
    int y = std::stoi(args[2]);
    DataPlayer &player = engine.getMapData().getTile(x, y).getPlayer(id);
    Inventory &inv = player.getInventory();

    inv.food = std::stoi(args[3]);
    inv.linemate = std::stoi(args[4]);
    inv.deraumere = std::stoi(args[5]);
    inv.sibur = std::stoi(args[6]);
    inv.mendiane = std::stoi(args[7]);
    inv.phiras = std::stoi(args[8]);
    inv.thystame = std::stoi(args[9]);

    LOG_INFO("Player[" + std::to_string(id) + "] inventory updated");
    engine.updateMap();
}

void CommandHandler::pdi(vector<string> args, Engine &engine)
{
    if (args.size() == 0)
        return;

    int id = std::stoi(args[0]);

    engine.getMapData().removePlayer(id);

    LOG_INFO("Player[" + std::to_string(id) + "] dead");
    engine.updateMap();
}

void CommandHandler::pic(vector<string> args, Engine &engine)
{
    if (args.size() == 0)
        return;

    int x = std::stoi(args[0]);
    int y = std::stoi(args[1]);

    for (size_t i = 3; i < args.size(); i++) {
        int id = std::stoi(args[i]);
        DataPlayer &player = engine.getMapData().getPlayer(id);
        if (player.getState() == IDLE)
            player.setState(INCANTATION);
    }

    LOG_INFO("Incantation started at (" + std::to_string(x) + ", " + std::to_string(y) + ")");
    engine.updateMap();
}

void CommandHandler::pie(vector<string> args, Engine &engine UNUSED)
{
    if (args.size() == 0)
        return;

    int x = std::stoi(args[0]);
    int y = std::stoi(args[1]);

    DataTile &tile = engine.getMapData().getTile(x, y);
    for (auto &[id, player] : tile.getPlayers()) {
        if (player.getState() == INCANTATION) {
            player.setState(IDLE);
        }
    }

    LOG_INFO("Incantation ended at (" + std::to_string(x) + ", " + std::to_string(y) + ")");
    engine.updateMap();
}

void CommandHandler::pbc(vector<string> args, Engine &engine UNUSED)
{
    if (args.size() == 0)
        return;

    int id = std::stoi(args[0]);
    string msg = args[1];

    LOG_INFO("Player[" + std::to_string(id) + "] broadcast says: " + msg);
    engine.updateMap();
}
