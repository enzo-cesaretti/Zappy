/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Logger
*/

#pragma once

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

enum class LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR,
};

class Logger {
    public:
        static Logger &getInstance();

        void log(LogLevel level, const string &message);

        void enable();
        void disable();

        void enableFileOutput(const string &filePath, bool enable);

    private:
        Logger();
        ~Logger();

        Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;

        string _getTimestamp();
        string _levelToString(LogLevel level);

        bool _consoleOutput;
        bool _fileOutput;
        std::ofstream _logFile;
        std::mutex _logMutex;
};

#define LOG_DEBUG(message) Logger::getInstance().log(LogLevel::DEBUG, message)
#define LOG_INFO(message)  Logger::getInstance().log(LogLevel::INFO, message)
#define LOG_WARN(message)  Logger::getInstance().log(LogLevel::WARN, message)
#define LOG_ERROR(message) Logger::getInstance().log(LogLevel::ERROR, message)
