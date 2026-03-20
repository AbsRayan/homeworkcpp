#include <iostream>
#include "UserManager.h"

int main() {
    UserManager manager;

    manager.printAllUsers();
    manager.printAllGroups();

    manager.createUser(1, "alice");
    manager.createUser(2, "bob");

    manager.createGroup(10);
    manager.createGroup(20);

    manager.addUserToGroup(1, 10);
    manager.addUserToGroup(2, 20);

    manager.printAllUsers();
    manager.printAllGroups();

    return 0;
}