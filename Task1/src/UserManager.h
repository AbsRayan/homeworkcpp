#pragma once

#include "User.h"
#include "Group.h"
#include <memory>
#include <string>
#include <unordered_map>

class UserManager {
public:
    bool createUser(int id, const std::string& username);
    bool createGroup(int id);

    bool addUserToGroup(int userId, int groupId);
    bool removeUserFromGroup(int userId);

    void getUser(int userId) const;
    void getGroup(int groupId) const;
    void allUsers() const;
    void allGroups() const;

    bool deleteUser(int userId);
    bool deleteGroup(int groupId);
private:
    std::unordered_map<int, std::shared_ptr<User>> users;
    std::unordered_map<int, std::shared_ptr<Group>> groups;
};