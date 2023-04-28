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
    instance = setItUp()
    cursor = instance.__mydb.cursor
    cursor.execute("SELECT * FROM user_data WHERE username = %s;", (username,))
    result = cursor.fetchone()
    instance.close_con()
    if result is not None:
        updateUser(username, keyData)
    else:
        addUser(username, keyData)


# name: updateUser
# parameters: String username, String keyData
# summary: Accepts a username and an entry of the passphrase. Adds the
#          passphrase entry into the user's keyData file.
def updateUser(username, keyData):
    instance = setItUp()
    cursor = instance.__mydb.cursor
    cursor.execute("INSERT INTO user_data (username, passphrase) VALUES (%s, %s);", (username, keyData))
    instance.__mydb.commit()
    instance.close_con()

# name: addUser
# parameters: String username, String keyData
# summary: Accepts a username and an entry of the passphrase. Adds the
#          user to the database along with the provided entry/entries
def addUser(username, keyData):
    instance = setItUp()
    cursor = instance.__mydb.cursor
    cursor.execute("UPDATE user_data SET passphrase=%s WHERE username=%s;", (keyData, username))
    instance.__mydb.commit()
    instance.close_con()

# name: getData
# parameters: String username
# summary: Returns the string representation of the list of CharStateLists for
#          the specified user
def getData(username):
    instance = setItUp()
    cursor = instance.__mydb.cursor
    cursor.execute("SELECT passphrase FROM user_data WHERE username = %s;", (username,))
    result = cursor.fetchone()
    instance.close_con()
    if result is not None:
        return result[0]
    else:
        return None
