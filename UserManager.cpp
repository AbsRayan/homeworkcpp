#include <iostream>
#include "UserManager.h"

bool UserManager::createUser(int id, const std::string& username) 
{
    if (users.find(id) != users.end()) 
    {
        return false;
    }
    users.emplace(id, User(id, username));
    return true;
}

bool UserManager::createGroup(int id) 
{
    if (groups.find(id) != groups.end()) 
    {
        return false;
    }
    groups.emplace(id, Group(id));
    return true;
}

bool UserManager::addUserToGroup(int userId, int groupId) 
{
    auto userIt = users.find(userId);
    auto groupIt = groups.find(groupId);

    if (userIt == users.end() || groupIt == groups.end()) 
    {
        return false;
    }

    if (userIt->second.getGroupId().has_value() && userIt->second.getGroupId().value() == groupId) 
    {
        return true;
    }

    if (userIt->second.getGroupId().has_value()) 
    {
        int oldGroupId = userIt->second.getGroupId().value();
        groups.at(oldGroupId).removeUser(userId);
    }

    userIt->second.setGroupId(groupId);
    groupIt->second.addUser(userId);

    return true;
}

void UserManager::printUser(int userId) const 
{
    auto userIt = users.find(userId);
    if (userIt != users.end()) 
    {
        const User& user = userIt->second;
        std::cout << "User ID: " << user.getId() << std::endl << "Username: " << user.getUsername();
        if (user.getGroupId()) 
        {
            std::cout << std::endl << "Group ID: " << *user.getGroupId();
        }
        else 
        {
            std::cout << " no group assigned";
        }
        std::cout << std::endl << std::endl;
    } 
    else 
    {
        std::cout << "User not found." << std::endl << std::endl;
        return;
    }
}

void UserManager::printGroup(int groupId) const 
{
    auto groupIt = groups.find(groupId);
    if (groupIt == groups.end()) 
    {
        std::cout << "Group " << groupId << " not found." << std::endl << std::endl;
        return;
    }
    const Group& group = groupIt->second;
    std::cout << "Group ID: " << group.getId() << std::endl << "Users: ";
    if (group.getUserIds().empty()) 
    {
        std::cout << "No users in this group.";
    }
    for (int userId : group.getUserIds()) 
    {
            std::cout << userId << " ";
    }
    std::cout << std::endl << std::endl;
}

bool UserManager::deleteUser(int userId) 
{
    auto userIt = users.find(userId);
    if (userIt == users.end()) 
    {
        return false;
    }
    if (userIt->second.getGroupId().has_value()) 
    {
        int groupId = userIt->second.getGroupId().value();
        groups.at(groupId).removeUser(userId);
    }
    users.erase(userIt);
    return true;
}

bool UserManager::deleteGroup(int groupId) 
{
    auto groupIt = groups.find(groupId);
    if (groupIt == groups.end()) 
    {
        return false;
    }
    for (int userId : groupIt->second.getUserIds()) 
    {
        users.at(userId).setGroupId(std::nullopt);
    }
    groups.erase(groupIt);
    return true;
}

void UserManager::printAllUsers() const 
{
    if (users.empty()) 
    {
        std::cout << "No users." << std::endl << std::endl;
        return;
    }
    std::cout << "Users:" << std::endl;
    for (const auto& pair : users) 
    {
        printUser(pair.first);
    }
}

void UserManager::printAllGroups() const 
{
    if (groups.empty()) 
    {
        std::cout << "No groups." << std::endl << std::endl;
        return;
    }
    std::cout << "Groups:" << std::endl;
    for (const auto& pair : groups) 
    {
        printGroup(pair.first);
    }
}