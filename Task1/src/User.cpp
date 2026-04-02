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

std::shared_ptr<Group> User::getGroup() const 
{
    return group.lock();
}

void User::setGroup(const std::shared_ptr<Group>& newGroup) 
{
    group = newGroup;
}

void User::clearGroup() 
{
    group.reset();
}