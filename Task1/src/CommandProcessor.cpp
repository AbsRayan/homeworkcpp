#include "CommandProcessor.h"

#include <sstream>
#include <iostream>

CommandProcessor::CommandProcessor(UserManager& manager) : manager(manager) {}

bool CommandProcessor::processCommand(const std::string& command)
{
    if (command == "exit") 
    {
        return false;
    }
    std::istringstream iss(command);
    std::string action;
    iss >> action;
    if (action == "createUser") 
    {
        int id;
        std::string username;
        if (!(iss >> id >> username)) 
        {
            std::cout << "Invalid command format. Usage: createUser <id> <username>" << std::endl;
        }
        else if(manager.createUser(id, username)) 
        {
            std::cout << "User created successfully." << std::endl;
        } 
        else 
        {
            std::cout << "Failed to create user. ID may already exist." << std::endl;
        }
    } 
    else if (action == "createGroup") 
    {
        int id;
        if (!(iss >> id)) 
        {
            std::cout << "Invalid command format. Usage: createGroup <id>" << std::endl;
        }
        else if (manager.createGroup(id)) 
        {
            std::cout << "Group created successfully." << std::endl;
        } 
        else 
        {
            std::cout << "Failed to create group. ID may already exist." << std::endl;
        }
    }
    else if (action == "addUserToGroup") 
    {
        int userId, groupId;
        if (!(iss >> userId >> groupId)) 
        {
            std::cout << "Invalid command format. Usage: addUserToGroup <userId> <groupId>" << std::endl;
        }
        else if (manager.addUserToGroup(userId, groupId)) 
        {
            std::cout << "User added to group successfully." << std::endl;
        } 
        else 
        {
            std::cout << "Failed to add user to group. User or group ID may not exist." << std::endl;
        }
    }
    else if (action == "getUser") 
    {
        int userId;
        if (!(iss >> userId)) 
        {
            std::cout << "Invalid command format. Usage: printUser <userId>" << std::endl;
        }
        else
        {
            manager.getUser(userId);
        }
    }
    else if (action == "getGroup") 
    {
        int groupId;
        if (!(iss >> groupId)) 
        {
            std::cout << "Invalid command format. Usage: printGroup <groupId>" << std::endl;
        }
        else
        {
            manager.getGroup(groupId);
        }
    }
    else if (action == "allUsers") 
    {
        manager.allUsers();
    } 
    else if (action == "allGroups") 
    {
        manager.allGroups();
    }
    else if (action == "deleteUser") 
    {
        int userId;
        if (!(iss >> userId)) 
        {
            std::cout << "Invalid command format. Usage: deleteUser <userId>" << std::endl;
        }
        else if (manager.deleteUser(userId)) 
        {
            std::cout << "User deleted successfully." << std::endl;
        } 
        else 
        {
            std::cout << "Failed to delete user. ID may not exist." << std::endl;
        }
    } 
    else if (action == "deleteGroup") 
    {
        int groupId;
        if (!(iss >> groupId)) 
        {
            std::cout << "Invalid command format. Usage: deleteGroup <groupId>" << std::endl;
        }
        else if (manager.deleteGroup(groupId)) 
        {
            std::cout << "Group deleted successfully." << std::endl;
        } 
        else 
        {
            std::cout << "Failed to delete group. ID may not exist." << std::endl;
        }
    }
    else 
    {
        std::cout << "Unknown command." << std::endl;
    }

    return true;
}