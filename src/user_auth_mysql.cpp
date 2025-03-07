#include <iostream>
#include <mysql/mysql.h>  // MySQL Library
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <string>
#include <sstream>
#include <iomanip>

// MySQL Connection Info
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "your_mysql_password"  // Change this!
#define DB_NAME "ecomdb"

// Function to generate a random salt
std::string generateSalt(int length = 16) {
    unsigned char salt[length];
    RAND_bytes(salt, length);

    std::ostringstream saltHex;
    for (int i = 0; i < length; i++) {
        saltHex << std::hex << std::setw(2) << std::setfill('0') << (int)salt[i];
    }
    return saltHex.str();
}

// Function to hash passwords using SHA-256
std::string hashPassword(const std::string& password, const std::string& salt, int iterations = 100000) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    const EVP_MD* algorithm = EVP_sha256();
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLength = 0;
    std::string currentHash = salt + password;

    for (int i = 0; i < iterations; i++) {
        EVP_DigestInit_ex(context, algorithm, NULL);
        EVP_DigestUpdate(context, currentHash.c_str(), currentHash.size());
        EVP_DigestFinal_ex(context, hash, &hashLength);
        std::ostringstream hashStream;
        for (unsigned int j = 0; j < hashLength; j++) {
            hashStream << std::hex << std::setw(2) << std::setfill('0') << (int)hash[j];
        }
        currentHash = hashStream.str();
    }

    EVP_MD_CTX_free(context);
    return salt + ":" + currentHash;  // Store salt and hash together
}

// Function to connect to MySQL
MYSQL* connectToDatabase() {
    MYSQL* conn = mysql_init(NULL);
    if (conn == NULL) {
        std::cerr << "❌ MySQL initialization failed!" << std::endl;
        return NULL;
    }

    if (!mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0)) {
        std::cerr << "❌ MySQL connection failed: " << mysql_error(conn) << std::endl;
        return NULL;
    }

    std::cout << "✅ Connected to MySQL successfully!" << std::endl;
    return conn;
}

// Function to check if a user already exists
bool userExists(MYSQL* conn, const std::string& username) {
    std::ostringstream query;
    query << "SELECT id FROM users WHERE username = '" << username << "';";

    if (mysql_query(conn, query.str().c_str()) != 0) {
        std::cerr << "❌ MySQL query failed: " << mysql_error(conn) << std::endl;
        return false;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    bool exists = (mysql_num_rows(result) > 0);
    mysql_free_result(result);
    return exists;
}

// Function to register a user (Insert into MySQL)
void registerUser(MYSQL* conn, const std::string& username, const std::string& email, const std::string& password) {
    if (userExists(conn, username)) {
        std::cerr << "❌ User already exists! Registration failed.\n";
        return;
    }

    std::string salt = generateSalt();
    std::string hashedPassword = hashPassword(password, salt);

    std::ostringstream query;
    query << "INSERT INTO users (username, email, password_hash) VALUES ('"
          << username << "', '" << email << "', '" << hashedPassword << "');";

    if (mysql_query(conn, query.str().c_str()) == 0) {
        std::cout << "✅ User registered successfully!\n";
    } else {
        std::cerr << "❌ Registration failed: " << mysql_error(conn) << std::endl;
    }
}

// Function to verify login (Retrieve & check password)
bool loginUser(MYSQL* conn, const std::string& username, const std::string& enteredPassword) {
    std::ostringstream query;
    query << "SELECT password_hash FROM users WHERE username = '" << username << "';";

    if (mysql_query(conn, query.str().c_str()) != 0) {
        std::cerr << "❌ MySQL query failed: " << mysql_error(conn) << std::endl;
        return false;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (result == NULL || mysql_num_rows(result) == 0) {
        std::cerr << "❌ User not found!\n";
        return false;
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    std::string storedHash = row[0];
    mysql_free_result(result);

    // Extract salt from stored hash
    size_t delimiterPos = storedHash.find(":");
    if (delimiterPos == std::string::npos) {
        std::cerr << "❌ Stored password format is incorrect!\n";
        return false;
    }
    
    std::string storedSalt = storedHash.substr(0, delimiterPos);
    std::string hashedEnteredPassword = hashPassword(enteredPassword, storedSalt);

    return hashedEnteredPassword == storedHash;
}

// Main function
int main() {
    MYSQL* conn = connectToDatabase();
    if (conn == NULL) return 1;

    int choice;
    std::cout << "\n1. Register\n2. Login\nChoose an option: ";
    std::cin >> choice;

    std::string username, email, password;
    if (choice == 1) {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter email: ";
        std::cin >> email;
        std::cout << "Enter password: ";
        std::cin >> password;
        registerUser(conn, username, email, password);
    } 
    else if (choice == 2) {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        if (loginUser(conn, username, password)) {
            std::cout << "✅ Login successful!\n";
        } else {
            std::cout << "❌ Login failed! Incorrect password or user not found.\n";
        }
    }

    mysql_close(conn);
    return 0;
}
