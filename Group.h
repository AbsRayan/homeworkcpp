#pragma once
#include <string>
#include <vector>

class Group {
public:
    Group(int id);

    int getId() const;
    const std::vector<int>& getUserIds() const;

    void addUser(int userId);
    void removeUser(int userId);
private:
    int id;
    std::vector<int> userIds;
};