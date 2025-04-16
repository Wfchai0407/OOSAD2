#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;

public:
    User(const std::string& username, const std::string& password);
    virtual ~User() = default;
    
    bool login(const std::string& inputUsername, const std::string& inputPassword);
    bool registerUser(const std::string& newUsername, const std::string& newPassword);
    std::string getUsername() const;
};

#endif 