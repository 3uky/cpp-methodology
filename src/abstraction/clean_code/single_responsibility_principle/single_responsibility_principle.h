#pragma once

#include <string>
#include <iostream>

namespace srp_violation
{

// The UserService class is responsible for two tasks: authenticating users and logging activities.
// If there are changes to how we log activities (e.g., log format, log storage method), we would need to change the UserService class, even though the authentication logic may not need to change.
class UserService 
{
public:
    void authenticateUser(const std::string& username, const std::string& password) 
    {
        std::cout << "Authenticating user " << username << std::endl;
        logActivity("User authenticated");
    }

    void logActivity(const std::string& message) 
    {
        std::cout << "Log: " << message << std::endl;
    }
};

}


// AuthService now only handles user authentication, and any changes to authentication logic are confined to this class.
// Logger now only handles logging activities, so changes to logging logic won't affect user authentication.
// Each class has a single responsibility, making it easier to maintain and extend. For example, if we need to change the logging format, we only modify the Logger class
namespace srp_compliance
{

class AuthService 
{
public:
    void authenticateUser(const std::string& username, const std::string& password)
    {
        std::cout << "Authenticating user " << username << std::endl;
    }
};

class Logger 
{
public:
    void logActivity(const std::string& message)
    {
        std::cout << "Log: " << message << std::endl;
    }
};

}
