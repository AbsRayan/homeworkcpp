#include "Group.h"
#include <algorithm>

Group::Group(int id) : id(id) {}

int Group::getId() const 
{
    return id;
}

const std::vector<int>& Group::getUserIds() const 
{
    return userIds;
}

void Group::addUser(int userId) 
{
    userIds.push_back(userId);
}

void Group::removeUser(int userId) 
{
    userIds.erase(std::remove(userIds.begin(), userIds.end(), userId), userIds.end());
}