#pragma once

#include <string>
#include "UserManager.h"

class CommandProcessor {
public:
    explicit CommandProcessor(UserManager& manager);

    bool processCommand(const std::string& line);

private:
    UserManager& manager;
};