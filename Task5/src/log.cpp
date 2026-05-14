#include "log.h"

#include <iostream>

std::string LogLevelToString(LogLevel level)
{
    switch (level)
    {
        case LogLevel::Log_Normal:
            return "Normal";
        case LogLevel::Log_Warning:
            return "Warning";
        case LogLevel::Log_Error:
            return "Error";
        default:
            return "Unknown";
    }
}

Log& Log::getInstance()
{
    static Log instance;
    return instance;
}

void Log::message(LogLevel level, const std::string& msg)
{
    LogEvent event;
    event.time = std::time(nullptr);
    event.level = level;
    event.message = msg;

    events.push_back(event);

    if (events.size() > 10)
    {
        events.pop_front();
    }
}

void Log::print() const
{
    for (const auto& event : events)
    {
        std::cout << std::ctime(&event.time)
                  << "[" << LogLevelToString(event.level) << "] " 
                  << event.message << std::endl;
    }
}