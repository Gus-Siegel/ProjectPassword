import connection
import mysql.connector

# name: setItUp
# parameters: none
# summary: Creates, opens, and returns a connection object
def setItUp():
    instance = connection.Connection()
    instance.open_con()
    return instance

# name: logUser
# parameters: String username, String keyData
# summary: Accepts a username and an entry of the passphrase. If the user
#          is found in the database, updateUser is run. Otherwise, the
#          user is new and addUser is run.
def logUser(username, keyData):
    # check for user in table
    isPreexisting = isUser(username)
    # run appropriate data entry function
    if isPreexisting:
        updateUser(username, keyData)
    else:
        addUser(username, keyData)


# name: updateUser
# parameters: String username, String keyData
# summary: Accepts a username and an entry of the passphrase. Adds the
#          passphrase entry into the user's keyData file.
def updateUser(username, keyData):
    # retrieve user's current data as a string
    partialData = getData(username)
    # if user has any existing data, append keyData to the end
    if partialData is not None:
        keyData = appendData(partialData, keyData)

    # create connection, get cursor for database queries
    instance = setItUp()
    cursor = instance.__mydb.cursor
    # find the specified user in the database and update their data
    cursor.execute("UPDATE user_data SET passphrase=%s WHERE username=%s;", (keyData, username))
    instance.__mydb.commit()
    instance.close_con()

# name: addUser
# parameters: String username, String keyData
# summary: Accepts a username and an entry of the passphrase. Adds the
#          user to the database along with the provided entry/entries
def addUser(username, keyData):
    # create connection, get cursor for database queries
    instance = setItUp()
    cursor = instance.__mydb.cursor
    # Add user and data as a new row in the table
    cursor.execute("INSERT INTO user_data (username, passphrase) VALUES (%s, %s);", (username, keyData))
    instance.__mydb.commit()
    instance.close_con()

# name: getData
# parameters: String username
# summary: Returns the string representation of the list of CharStateLists for
#          the specified user
def getData(username):
    # create connection, get cursor for database queries
    instance = setItUp()
    cursor = instance.__mydb.cursor
    # find the specified user and store their data in result
    cursor.execute("SELECT passphrase FROM user_data WHERE username = %s;", (username,))
    result = cursor.fetchone()
    instance.close_con()
    if result is not None:
        return result[0]
    else:
        return None

# name: appendData
# parameters: String partialData, String keyData
# summary: Appends the keyData being added to the end of the user's complete
#          keyData file, returns the result as a string. Not for use outside
#          this file.
def appendData(partialData, keyData):
    finalData = partialData + "\n~\n" + keyData
    return finalData

# name: isUser
# parameters: String username
# summary: Search if the specified user exists in the database, return as bool
def isUser(username):
    # create connection, get cursor for database queries
    instance = setItUp()
    cursor = instance.__mydb.cursor
    # find the user in the database
    cursor.execute("SELECT * FROM user_data WHERE username = %s;", (username,))
    result = cursor.fetchone()
    instance.close_con()
    # if the user is found, return True
    if result is not None:
        return True
    else:
        return False
