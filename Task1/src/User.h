#pragma once
#include <string>
#include <memory>

class Group;

class User {
public:
    User(int id, const std::string& username);

    int getId() const;
    const std::string& getUsername() const;

    std::shared_ptr<Group> getGroup() const;
    void setGroup(const std::shared_ptr<Group>& newGroupId);
    void clearGroup();
private:
    int id;
    std::string username;
    std::weak_ptr<Group> group;
};