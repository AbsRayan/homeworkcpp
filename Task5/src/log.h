#pragma once

#include <ctime>
#include <string>
#include <deque>

enum class LogLevel
{
    Log_Normal,
    Log_Warning,
    Log_Error
};

struct LogEvent
{
    std::time_t time;
    LogLevel level;
    std::string message;
};

class Log
{
public:
    static Log& getInstance();

    void message(LogLevel level, const std::string& msg);
    void print() const;

private:
    Log() = default;

    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;

    std::deque<LogEvent> events;
};