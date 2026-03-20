#pragma once
#include <string>
#include <optional>

class User {
public:
    User(int id, const std::string& username);

    int getId() const;
    const std::string& getUsername() const;

    std::optional<int> getGroupId() const;
    void setGroupId(std::optional<int> newGroupId);

private:
    int id;
    std::string username;
    std::optional<int> groupId;
};