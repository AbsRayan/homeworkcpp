#include "log.h"

int main()
{
    Log& log1 = Log::getInstance();
    Log& log2 = Log::getInstance();
    
    for (int i = 0; i < 12; ++i)
    {
        log1.message(LogLevel::Log_Normal, "Message " + std::to_string(i));
    }

    log2.print();

    return 0;
}