#include <iostream>
#include <string>

#include "UserManager.h"
#include "CommandProcessor.h"

int main()
{
    UserManager manager;
    CommandProcessor processor(manager);
    std::string command;
    while(true)
    {
        std::cout << "[Enter command]: ";
        std::getline(std::cin, command);

        if (!processor.processCommand(command)) 
        {
            break;
        }
    }
    return 0;
}