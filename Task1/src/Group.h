#pragma once

#include <memory>
#include <vector>

class User;

class Group {
public:
    Group(int id);

    int getId() const;
    
    void addUser(const std::shared_ptr<User>& user);
    void removeUser(int userId);

    const std::vector<std::shared_ptr<User>> getUsers() const;
private:
    int id;
    std::vector<std::weak_ptr<User>> users;
};