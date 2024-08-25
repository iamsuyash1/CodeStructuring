#include <iostream>
#include <string>

/*
    This class tries to handle multiple responsibilities: authentication, 
    token generation, session management, and user data handling.
*/
class AuthManager {
public:
    // Authenticate user with username and password
    bool authenticate(const std::string& username, const std::string& password) {
        // Check username and password in the database
        // (Mocked for example)
        if (username == "admin" && password == "admin") {
            // If authentication succeeds, generate a token and create a session
            std::string token = generateToken(username);
            createSession(token);
            return true;
        }
        return false;
    }

    // Generate a token for the authenticated user
    std::string generateToken(const std::string& username) {
        // Create a simple token (Mocked for example)
        return "token_for_" + username;
    }

    // Create a session for the authenticated user
    void createSession(const std::string& token) {
        // Store the session (Mocked for example)
        std::cout << "Session created for token: " << token << std::endl;
    }

    // Get user data from the database
    User getUserData(const std::string& username) {
        // Retrieve user data (Mocked for example)
        return User(username, "user@example.com");
    }

    // Update user data in the database
    void updateUserData(const User& user) {
        // Update user data (Mocked for example)
        std::cout << "User data updated for: " << user.getUsername() << std::endl;
    }
};

/*
    This User class is responsible for both holding user data and managing user sessions, which violates SRP.
*/
class User {
private:
    std::string username;
    std::string email;
    std::string sessionToken;

public:
    User(const std::string& username, const std::string& email) 
        : username(username), email(email) {}

    // Getters for user data
    std::string getUsername() const { return username; }
    std::string getEmail() const { return email; }

    // Manage session
    void createSession() {
        // Generate and store session token
        sessionToken = "session_token_for_" + username;
        std::cout << "Session created for user: " << username << std::endl;
    }

    void endSession() {
        // End session by clearing token
        sessionToken.clear();
        std::cout << "Session ended for user: " << username << std::endl;
    }

    bool validateSession() const {
        // Validate if session token exists
        return !sessionToken.empty();
    }
};
