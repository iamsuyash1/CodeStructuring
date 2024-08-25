#include <iostream>
#include <string>
#include <unordered_map>

// This class is responsible only for user authentication.
class Authenticator {
public:
    bool authenticate(const std::string& username, const std::string& password) {
        // Perform user authentication (e.g., check against a database)
        // Mocked authentication for this example
        if (username == "user" && password == "password") {
            return true;
        }
        return false;
    }
};

// This class is responsible for generating tokens, such as JWTs (JSON Web Tokens).
class TokenGenerator {
public:
    std::string generateToken(const std::string& username) {
        // In a real-world scenario, you'd use a library to create a JWT
        // Mocked token generation for this example
        return "token_for_" + username;
    }

    bool validateToken(const std::string& token) {
        // Validate the token (e.g., check signature, expiration, etc.)
        // Mocked token validation for this example
        return !token.empty();
    }
};

// This class manages user sessions. It’s responsible for creating, validating, and ending sessions.
class SessionManager {
private:
    std::unordered_map<std::string, std::string> sessionStore; // Maps tokens to users

public:
    void createSession(const std::string& token, const std::string& username) {
        sessionStore[token] = username;
        std::cout << "Session created for user: " << username << std::endl;
    }

    void endSession(const std::string& token) {
        sessionStore.erase(token);
        std::cout << "Session ended for token: " << token << std::endl;
    }

    bool validateSession(const std::string& token) {
        return sessionStore.find(token) != sessionStore.end();
    }

    std::string getUsernameForToken(const std::string& token) {
        return sessionStore[token]; 
    }
};

// These classes are responsible for handling user data, such as retrieving and updating user profiles.
class User {
private:
    std::string username;
    std::string email;

public:
    User(const std::string& username, const std::string& email) 
        : username(username), email(email) {}

    std::string getUsername() const { return username; }
    std::string getEmail() const { return email; }

    void setEmail(const std::string& newEmail) {
        email = newEmail;
    }
};

class UserDataHandler {
public:
    User getUserData(const std::string& username) {
        // Fetch user data from database (mocked here)
        return User(username, "user@example.com");
    }

    void updateUserData(const User& user) {
        // Update user data in the database (mocked here)
        std::cout << "Updated email for user " << user.getUsername() << " to " << user.getEmail() << std::endl;
    }
};

class SSOService {
private:
    Authenticator authenticator;
    TokenGenerator tokenGenerator;
    SessionManager sessionManager;
    UserDataHandler userDataHandler;

public:
    std::string login(const std::string& username, const std::string& password) {
        if (authenticator.authenticate(username, password)) {
            std::string token = tokenGenerator.generateToken(username);
            sessionManager.createSession(token, username);
            return token;
        }
        return "";
    }

    void logout(const std::string& token) {
        sessionManager.endSession(token);
    }

    bool validateRequest(const std::string& token) {
        return sessionManager.validateSession(token) && tokenGenerator.validateToken(token);
    }

    User getUserProfile(const std::string& token) {
        if (validateRequest(token)) {
            std::string username = sessionManager.getUsernameForToken(token); // Hypothetical method
            return userDataHandler.getUserData(username);
        }
        throw std::runtime_error("Invalid token");
    }
};

int main() {
    SSOService ssoService;

    // User tries to log in
    std::string token = ssoService.login("user", "password");

    if (!token.empty()) {
        std::cout << "Login successful! Token: " << token << std::endl;

        // Validate token and get user profile
        if (ssoService.validateRequest(token)) {
            User user = ssoService.getUserProfile(token);
            std::cout << "User Profile: " << user.getUsername() << ", " << user.getEmail() << std::endl;
        }

        // User logs out
        ssoService.logout(token);
    } else {
        std::cout << "Login failed!" << std::endl;
    }

    return 0;
}



