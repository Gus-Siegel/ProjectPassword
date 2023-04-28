#include <mysqlx/xdevapi.h>
#include "pythonListToCharState.h"
#include "compare_strings.h"
#include <iostream>
#include <sstream>
#include <vector>


int main() {
    // Start a session with the MySQL database
    Session userDB = startSession("localhost", 3306, "username", "password");

    // Create the users table if it doesn't already exist
    userDB.sql("CREATE TABLE IF NOT EXISTS users (username VARCHAR(255) PRIMARY KEY, keyData TEXT)").execute();

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
    name: logUser - signs up a user if not there
    parameters: Session userDB, String username, __ keyData
    summary: Searches the database for an entry matching the provided username.
             If found, logs the attempt as an existing user with function
             existingUser(). Otherwise, creates new entry in database
             with function newUser().
*/
void logUser(Session& userDB, string& username, string& keyData) {
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
    parameters: Session userDB, String username, String keyData
    summary: Creates new entry in sql database with username as the primary
             key, and the vector of initialization attempts (single attempt
             temporarily).
*/
void newUser(Session& userDB, string& username, string& keyData) {
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
void existingUser(Session& session, const string& username, const string& keyData) {
    // attempt appending the new login attempt to user's keyData history
    try {
        // retrieve user's data in string form for modification
        userDB.sql("SELECT keyData FROM users WHERE username = :username")
               .bind("username", username)
               .execute();
        result = mysql_store_result(session);
        row = mysql_fetch_row(result);
        string currentData = row[0];

        // appends keyData to the string storing user's data
        if (!(currentData.isSpace()))
        {
            // adds delimiter before new entry if currentData isn't empty
            currentData << "\n~\n";
        }
        currentData << keyData;

        // updates user's row with new data string
        userDB.sql("UPDATE users SET keyData = :keyData WHERE username = :username")
               .bind("username", username)
               .bind("keyData", currentData)
               .execute();
    } 
    // return an error message in case of failure
    catch (const mysqlx::Error& err) {
        cerr << "Error appending key data to user in the database: " << err.what() << endl;
    }
}

/*
    name: pullAllUserData
    parameters: String username
    summary: Deserializes and returns the complete keyData array of the specified user,
             as a vector of CharStateLists
*/
std::list<CharStateList> pullAllUserData(const string& username)
{
    try {
        // retrieve user's data in string form
        userDB.sql("SELECT keyData FROM users WHERE username = :username")
               .bind("username", username)
               .execute();
        result = mysql_store_result(session);
        row = mysql_fetch_row(result);
        string currentData = row[0];

        // convert data to list form
        list<CharStateList> stored = stringToList(currentData);

        // return list
        return stored;
    } 
    // return an error message in case of failure
    catch (const mysqlx::Error& err) {
        cerr << "Error retrieving key data from user in the database: " << err.what() << endl;
    }
}


/*
    name: pullUserEntry
    parameters: String username, int entry
    summary: Deserializes and returns the keyData entry for the specified user at the
             specified index
*/
CharStateList pullUserEntry(const string& username, const int& entryIndex)
{
     try {
        // retrieve user's data in string form
        userDB.sql("SELECT keyData FROM users WHERE username = :username")
               .bind("username", username)
               .execute();
        result = mysql_store_result(session);
        row = mysql_fetch_row(result);
        string currentData = row[0];

        // convert data to list form
        list<CharStateList> stored = stringToList(currentData);

        // return specified entry
        auto l_front = stored.begin();
        std::advance(l_front, entryIndex);
        return l_front;
    } 
    // return an error message in case of failure
    catch (const mysqlx::Error& err) {
        cerr << "Error retrieving key data from user in the database: " << err.what() << endl;
    }
}

/*
    name: stringToList
    parameters: String dataString
    summary: converts charStateLists stored as a single string in the database to
             a list containing them in their standard forms
*/
std::list<CharStateList> stringToList(const string& dataString)
{
    vector<string> tokens;
    stringstream ss(dataString);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, '~');
        tokens.push_back(substr);
    }

    List<CharStateList> convertedList;
    for (i = 0; i < tokens.size(); i++)
    {
        convertedList.push_back( CharStateList(tokens[i]) )
    }

    return convertedList;
}

/*
    name: listToString
    parameters: list<CharStateList> dataList
    summary: converts a list of charStateLists into singular string form for
             storage in the SQL database. This is necessary because SQL colums
             can't hold dynamic arrays, so we store it as a string to keep
             from using nested databases.
*/
string vectorToString(list<CharStateList> dataList)
{
    // [TODO] this method not necessary for pulling data from table yet, 
    //        but will be needed in the future
}
