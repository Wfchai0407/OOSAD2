#include "User.h"
#include <map>
#include <iostream>

using namespace std;

// Static map to store user credentials
static map<string, string> userCredentials;

User::User(const string& username, const string& password) 
    : username(username), password(password) {}

bool User::login(const string& inputUsername, const string& inputPassword) {
    auto it = userCredentials.find(inputUsername);
    if (it != userCredentials.end() && it->second == inputPassword) {
        return true;
    }
    return false;
}

bool User::registerUser(const string& newUsername, const string& newPassword) {
    if (userCredentials.find(newUsername) != userCredentials.end()) {
        return false; // Username already exists
    }
    userCredentials[newUsername] = newPassword;
    return true;
}

string User::getUsername() const {
    return username;
} 