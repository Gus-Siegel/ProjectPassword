import mysql.connector

class Connection:
    # Connection object constructor
    def __init__(self, host="localhost", user="root", pwd="", db=""):
        self.__myDB = None
        self.__host = host
        self.__user = user
        self.__pwd = pwd
        self.__db = db

    def openConnection(self):
        self.__myDB = mysql.connector.connect(
            host = self.__host,
            user = self.__user,
            password = self.__pwd,
            database = self.__db
            )
    
    def closeConnection(self):
        self.__myDB.close()
        self.__myDB = None
    



# Connect to MySQL
connection = Connection("localhost", "root", "", "")
connection.openConnection()

# Create user database
cursor = connection.__myDB.cursor()
cursor.execute("CREATE DATABASE IF NOT EXISTS usersDB;")
connection.__myDB.database = 'usersDB'
cursor.execute("USE usersDB;")

# Create table
cursor.execute("CREATE TABLE IF NOT EXISTS users (username VARCHAR(255) PRIMARY KEY, keyData TEXT);")

# Function to determine if specified user exists and adds data accordingly
def logUser(username, keyData):
    cursor.execute("SELECT * FROM users WHERE username = %s;", (username,))
    result = cursor.fetchone()
    # If the username exists in the table, run addUser
    if result is not None:
        updateUser(username, keyData)
    # Otherwise, the user needs to be added to the table
    else:
        addUser(username, keyData)

# Function to add a new user to the table
def addUser(username, keyData):
    cursor.execute("INSERT INTO users (username, keyData) VALUES (%s, %s);", (username, keyData))
    connection.__myDB.commit()

# Function to update the keyData of an existing user
def updateUser(username, keyData):
    cursor.execute("UPDATE users SET keyData=%s WHERE username=%s;", (keyData, username))
    connection.__myDB.commit()

# Function to return the list of charStateLists of the specified user as string
def getCompleteData(username):
    cursor.execute("SELECT keyData FROM users WHERE username = %s;", (username, ))
    result = cursor.fetchone()
    if result is not None:
        return result[0]
    else:
        return None

# Funtion to return the specific charStateList of the specified user at
#   the specified index as string


# Closes connection
def shutDownDB():
    cursor.close()
    connection.closeConnection()
