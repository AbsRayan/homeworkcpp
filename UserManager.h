#pragma once

#include "User.h"
#include "Group.h"
#include <unordered_map>

class UserManager {
public:
    bool createUser(int id, const std::string& username);
    bool createGroup(int id);

    bool addUserToGroup(int userId, int groupId);

    void printUser(int userId) const;
    void printGroup(int groupId) const;
    void printAllUsers() const;
    void printAllGroups() const;

    bool deleteUser(int userId);
    bool deleteGroup(int groupId);
private:
    std::unordered_map<int, User> users;
    std::unordered_map<int, Group> groups;
};