#pragma once

#include <ctime>
#include <string>

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
    static Log& Instance();

private:
    Log() = default;
};