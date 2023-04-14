#include <mysqlx/xdevapi.h>
#include "pythonListToCharState.h"
#include "compare_strings.h"
#include <iostream>
#include <vector>


int main() {
    // Start a session with the MySQL database
    Session userDB = startSession("localhost", 3306, "username", "password");

    // Create the users table if it doesn't already exist
    userDB.sql("CREATE TABLE IF NOT EXISTS users (username VARCHAR(255) PRIMARY KEY, keyData JSON)").execute();

    // Ensure we're using the newly created database
    userDB.sql("USE users").execute();

    //TODO: Get in touch w/ server team and ask about event handling

    return 0;
}

/*
    name: startSession
    parameters:
    summary: Returns a working session with the mySQL database
*/
Session startSession(string host, int port, string& user, string& password) {
    // attempt session start with provided parameters
    try {
        return Session(host, port, user, password);
    } 
    // return an error message in case of failure
    catch (const mysqlx::Error& err) {
        cerr << "Error connecting to the database: " << err.what() << endl;
        exit(1);
    }
}

/*
    name: logUser
    parameters: Session userDB, String username, __ keyData
    summary: Searches the database for an entry matching the provided username.
             If found, logs the attempt as an existing user with function
             existingUser(). Otherwise, creates new entry in database
             with function newUser().
*/
void logUser(Session& userDB, string& username, vector& keyData) {
    try {
        RowResult result = userDB.sql("SELECT * FROM users WHERE username = :username")
                                 .bind("username", username)
                                 .execute();
        if (result.count() == 0) {
            newUser(userDB, username, keyData);
        } else {
            existingUser(userDB, username, keyData);
        }
    } catch (const mysqlx::Error& err) {
        cerr << "Error saving key data for user in the database: " << err.what() << endl;
    }
}


/*
    name: newUser
    parameters: Session userDB, String username, __ keyData
    summary: Creates new entry in sql database with username as the primary
             key, and the vector of initialization attempts (single attempt
             temporarily).
*/
void newUser(Session& userDB, string& username, vector& keyData) {
    // attempt to add the new user into the database
    try {
        userDB.sql("INSERT INTO users (username, keyData) VALUES (:username, :keyData)")
               .bind("username", username)
               .bind("keyData", keyData)
               .execute();
    } 
    // return an error message in case of failure
    catch (const mysqlx::Error& err) {
        cerr << "Error adding user to the database: " << err.what() << endl;
    }
}

/*
    name: existingUser
    parameters: Session userDB, String username, __ keyData
    summary: Modifies the user's entry to append their newest login attempt
             onto the vector containing their attempt history. If we
             decide on voiding old attempts after the total reaches a
             certain number, drop the oldest one from the vector.
*/
void existingUser(Session& session, const string& username, const vector& keyData) {
    // attempt appending the new login attempt to user's keyData history
    try {
        userDB.sql("UPDATE users SET keyData = CONCAT(keyData, :keyData) WHERE username = :username")
               .bind("username", username)
               .bind("keyData", keyData)
               .execute();
    } 
    // return an error message in case of failure
    catch (const mysqlx::Error& err) {
        cerr << "Error appending key data to user in the database: " << err.what() << endl;
    }
}