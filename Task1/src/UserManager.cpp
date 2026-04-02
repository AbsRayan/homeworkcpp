#include <iostream>
#include "UserManager.h"

bool UserManager::createUser(int id, const std::string& username) 
{
    if (users.find(id) != users.end()) 
    {
        return false;
    }
    users.emplace(id, std::make_shared<User>(id, username));
    return true;
}

bool UserManager::createGroup(int id) 
{
    if (groups.find(id) != groups.end()) 
    {
        return false;
    }
    groups.emplace(id, std::make_shared<Group>(id));
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

    std::shared_ptr<User> user = userIt->second;
    std::shared_ptr<Group> newGroup = groupIt->second;

    std::shared_ptr<Group> currentGroup = user->getGroup();
    if (currentGroup && currentGroup->getId() == groupId) 
    {
        return true;
    }

    if (currentGroup) 
    {
        currentGroup->removeUser(userId);
    }

    newGroup->addUser(user);
    user->setGroup(newGroup);

    return true;
}

bool UserManager::removeUserFromGroup(int userId)
{
    auto userIt = users.find(userId);
    if (userIt == users.end()) 
    {
        return false;
    }

    std::shared_ptr<User> user = userIt->second;
    std::shared_ptr<Group> group = user->getGroup();
    if (!group) 
    {
        return false;
    }
    group->removeUser(userId);
    user->setGroup(nullptr);

    return true;
}

void UserManager::getUser(int userId) const 
{
    auto userIt = users.find(userId);
    if (userIt == users.end()) 
    {
        std::cout << "User not found." << std::endl << std::endl;
        return;
    } 

    std::shared_ptr<User> user = userIt->second;
    std::cout << "User ID: " << user->getId() << std::endl;
    std::cout << "Username: " << user->getUsername() << std::endl;

    std::shared_ptr<Group> group = user->getGroup();
    if (group)
    {
        std::cout << "Group ID: " << group->getId() << std::endl;
    } 
    else 
    {
        std::cout << "No group." << std::endl;
    }
}

void UserManager::getGroup(int groupId) const 
{
    auto groupIt = groups.find(groupId);
    if (groupIt == groups.end()) 
    {
        std::cout << "Group " << groupId << " not found." << std::endl << std::endl;
        return;
    }
    std::shared_ptr<Group> group = groupIt->second;
    std::vector<std::shared_ptr<User>> groupUsers = group->getUsers();

    std::cout << "Group ID: " << group->getId() << std::endl << "Users: ";
    
    if (groupUsers.empty()) 
    {
        std::cout << "no users in this group.";
    }
    else 
    {
        for (const auto& user : groupUsers) 
        {
            std::cout << user->getUsername() << " ID: " << user->getId() << "; ";
        }
    }
    std::cout << std::endl;
}

bool UserManager::deleteUser(int userId) 
{
    auto userIt = users.find(userId);
    if (userIt == users.end()) 
    {
        return false;
    }

    std::shared_ptr<User> user = userIt->second;
    std::shared_ptr<Group> group = user->getGroup();

    if(group) 
    {
        group->removeUser(userId);
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

    std::shared_ptr<Group> group = groupIt->second;
    std::vector<std::shared_ptr<User>> groupUsers = group->getUsers();
    
    for (const auto& user : groupUsers) 
    {
        user->clearGroup();
    }

    groups.erase(groupIt);
    return true;
}

void UserManager::allUsers() const 
{
    if (users.empty()) 
    {
        std::cout << "No users." << std::endl;
        return;
    }
    std::cout << std::endl;
    for (const auto& pair : users) 
    {
        getUser(pair.first);
        std::cout << std::endl;
    }
}

void UserManager::allGroups() const 
{
    if (groups.empty()) 
    {
        std::cout << "No groups." << std::endl;
        return;
    }
    std::cout << std::endl;
    for (const auto& pair : groups) 
    {
        getGroup(pair.first);
        std::cout << std::endl;
    }
}