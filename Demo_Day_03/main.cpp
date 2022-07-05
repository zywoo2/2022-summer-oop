#include <iostream>
#include "User.hpp"

int main(int argc, const char* argv[]) {
    bool IsAdded = false;
    IsAdded = User::AddAdministrator();
    IsAdded = User::AddAdministrator();
    IsAdded = User::AddTrivialUser("1", "456");
    IsAdded = User::AddTrivialUser("1", "567");
    IsAdded = User::AddTrivialUser("2", "567");
    IsAdded = User::AddTrivialUser("Admin", "567");
    return 0;
}