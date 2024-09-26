/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Logger
*/

#include "Utils/Logger.hpp"

Logger &Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::log(LogLevel level, const string &message)
{
    std::lock_guard<std::mutex> lock(_logMutex);

    string timestamp = _getTimestamp();
    string levelStr = _levelToString(level);

    std::ostringstream logEntry;
    logEntry << "[" << timestamp << "] [" << levelStr << "] " << message;

    string logMessage = logEntry.str();

    if (level == LogLevel::ERROR && _consoleOutput)
        std::cerr << logMessage << std::endl;
    else if (_consoleOutput)
        std::cout << logMessage << std::endl;
    if (_fileOutput)
        _logFile << logMessage << std::endl;
}

void Logger::enable()
{
    _consoleOutput = true;
}

void Logger::disable()
{
    _consoleOutput = false;
}

void Logger::enableFileOutput(const string &filePath, bool enable)
{
    if (enable) {
        _logFile.open(filePath, std::ios::out | std::ios::app);
        if (!_logFile.is_open()) {
            std::cerr << "Failed to open log file: " << filePath << std::endl;
            return;
        }
        _fileOutput = true;
    } else {
        if (_logFile.is_open())
            _logFile.close();
        _fileOutput = false;
    }
}

Logger::Logger() : _consoleOutput(true), _fileOutput(false)
{
}

Logger::~Logger()
{
    if (_logFile.is_open())
        _logFile.close();
}

string Logger::_getTimestamp()
{
    auto now = std::chrono::system_clock::now();
    auto nowTimeT = std::chrono::system_clock::to_time_t(now);
    auto nowMs =
        std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::stringstream timestamp;
    timestamp << std::put_time(std::localtime(&nowTimeT), "%Y-%m-%d %H:%M:%S");
    timestamp << '.' << std::setfill('0') << std::setw(3) << nowMs.count();

    return timestamp.str();
}

string Logger::_levelToString(LogLevel level)
{
    vector<string> logLevelStrings = {"DEBUG", "INFO", "WARN", "ERROR"};
    vector<LogLevel> logLevels = {
        LogLevel::DEBUG, LogLevel::INFO, LogLevel::WARN, LogLevel::ERROR};

    for (size_t i = 0; i < logLevels.size(); i++)
        if (level == logLevels[i])
            return logLevelStrings[i];
    return logLevelStrings[0];
}
