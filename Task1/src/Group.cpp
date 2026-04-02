#include "Group.h"
#include "User.h"

#include <algorithm>

Group::Group(int id) : id(id) {}

int Group::getId() const 
{
    return id;
}

const std::vector<std::shared_ptr<User>> Group::getUsers() const 
{
    std::vector<std::shared_ptr<User>> result;
    
    for (const auto& user : users) 
    {
        auto sharedUser = user.lock();
        if (sharedUser)
        {
            result.push_back(sharedUser);
        }
    }
    return result;
}

void Group::addUser(const std::shared_ptr<User>& user) 
{
    for (const auto& weakUser : users) 
    {
        auto sharedUser = weakUser.lock();
        if (sharedUser && sharedUser->getId() == user->getId())
        {
            return; // User already in the group
        }
    }

    users.push_back(user);
}

void Group::removeUser(int userId) 
{
    users.erase(
        std::remove_if(users.begin(), users.end(),
           [userId](const std::weak_ptr<User>& weakUser) 
            {
                auto sharedUser = weakUser.lock();
                return !sharedUser || sharedUser->getId() == userId;
            }), 
        users.end()
    );
}