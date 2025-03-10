#include <iostream>
#include <fstream>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <jsoncpp/json/json.h>
#include <ctime>

#define JSON_FILE "users.json"

// Function to generate SHA-256 hash
std::string hashPassword(const std::string& password) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    const EVP_MD* algorithm = EVP_sha256();
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLength = 0;

    EVP_DigestInit_ex(context, algorithm, NULL);
    EVP_DigestUpdate(context, password.c_str(), password.size());
    EVP_DigestFinal_ex(context, hash, &hashLength);
    EVP_MD_CTX_free(context);

    std::ostringstream hashStream;
    for (unsigned int i = 0; i < hashLength; i++) {
        hashStream << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return hashStream.str();
}

// Function to generate a session token
std::string generateSessionToken() {
    unsigned char token[16];
    RAND_bytes(token, sizeof(token));

    std::ostringstream tokenStream;
    for (unsigned int i = 0; i < sizeof(token); i++) {
        tokenStream << std::hex << std::setw(2) << std::setfill('0') << (int)token[i];
    }

    return tokenStream.str();
}

// Function to load users from JSON file
Json::Value loadUsers() {
    std::ifstream file(JSON_FILE, std::ifstream::binary);
    Json::Value users;
    if (file.is_open()) {
        file >> users;
        file.close();
    }
    return users;
}

// Function to save users to JSON file
void saveUsers(const Json::Value& users) {
    std::ofstream file(JSON_FILE, std::ofstream::binary);
    file << users;
    file.close();
}

// Function to check if user exists
bool userExists(const std::string& username) {
    Json::Value users = loadUsers();
    return users.isMember(username);
}

// Function to register a user
void registerUser(const std::string& username, const std::string& password) {
    if (userExists(username)) {
        std::cerr << "❌ User already exists! Registration failed.\n";
        return;
    }

    Json::Value users = loadUsers();
    users[username]["password"] = hashPassword(password);
    saveUsers(users);
    std::cout << "✅ User registered successfully!\n";
}

// Function to verify login and generate a session token
std::string loginUser(const std::string& username, const std::string& enteredPassword) {
    Json::Value users = loadUsers();
    if (!userExists(username)) {
        std::cerr << "❌ Login failed! Account does not exist.\n";
        return "";
    }
    if (users[username]["password"].asString() == hashPassword(enteredPassword)) {
        std::string sessionToken = generateSessionToken();
        users[username]["session_token"] = sessionToken;
        saveUsers(users);
        std::cout << "✅ Login successful! Session Token: " << sessionToken << "\n";
        return sessionToken;
    } else {
        std::cerr << "❌ Login failed! Incorrect password.\n";
        return "";
    }
}

int main() {
    int choice;
    std::cout << "\n1. Register\n2. Login\nChoose an option: ";
    std::cin >> choice;

    std::string username, password;
    if (choice == 1) {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        registerUser(username, password);
    } 
    else if (choice == 2) {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        std::string sessionToken = loginUser(username, password);
        if (!sessionToken.empty()) {
            std::cout << "Your session token is: " << sessionToken << "\n";
        }
    }
    return 0;
}
