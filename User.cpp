#include "User.h"

User::User(int id, const std::string& username) : id(id), username(username) {}

int User::getId() const 
{
    return id;
}

const std::string& User::getUsername() const 
{
    return username;
}

std::optional<int> User::getGroupId() const 
{
    return groupId;
}

void User::setGroupId(std::optional<int> newGroupId) 
{
    groupId = newGroupId;
}