
from connection import Connection

# The Pilot class is created for you. The __init__ function will initialize the class properties and
# there are get_ and set_ functions for each of the properties. You will complete the class with the
# methodos to save and load data to/from the database based on the primary key (pilot.identification)
class User:

    # __init__()
    # Parameters: self
    #             id: integer that represents the pilot's identification number (primary key, default=0)
    #             name: string that represents the pilot's name (default=""),
    #             salary: decimal that represents the pilot's salary (default=0.0)
    #             bonus: decimal that represents the pilot's gratification (default=0.0)
    #             airline: string that represents the airline company to which the pilot is affiliated
    #                      (default="")
    #             country: string that represents the country of resident. The country indicates where
    #                      the pilot is based (may not be their country of birth, default="")
    # Return: None
    def __init__(self, username = "", name = "", passphrase = ""):
        self.__username = username
        self.__name = name
        self.__passphrase = passphrase

    # __str__()
    # Prints the object Pilot in a nicely formatted string
    # Parameters: self
    # Return: a string in the format "Pilot <identification>: <name>"
    def __str__(self):
        return "User: " + str(self.get_username())

    # set_id()
    # Process: sets the pilot's identification to the value in the parameter
    # Parameters: self
    #             id: the new identification number
    # Return: None
    def set_username(self, username):
        self.__username = username

    # set_name()
    # Process: sets the pilot's name to the value in the parameter
    # Parameters: self
    #             name: the new name
    # Return: None
    def set_name(self, name):
        self.__name = name

    # set_salary()
    # Process: sets the pilot's salary to the value in the parameter
    # Parameters: self
    #             salary: the new salary (as float)
    # Return: None
    def set_passphrase(self, passphrase):
        self.__passphrase = passphrase

    # get_username()
    # Process: returns the pilot's identification number
    # Parameters: self
    # Return: self.__id
    def get_username(self):
        return self.__username

    # get_name()
    # Process: returns the pilot's name
    # Parameters: self
    # Return: self.__name
    def get_name(self):
        return self.__name

    # get_salary()
    # Process: returns the pilot's salary
    # Parameters: self
    # Return: self.__salary
    def get_passphrase(self):
        return self.__passphrase

    def save(self, user, pwd):
        # - creates a Connection object (the class we created in file connection_solution.py)
        # - initialize the Connection with the username and password received as parameters
        # - initialize the db variable to be the "airline_db" database
        con = Connection(user=user, pwd=pwd, db="typelock_db")
        # - check if the pilot's identification number exists in the table airline_db.Pilot
        sql = "select * from user_data where username = %s"
        values = [self.get_username()]
        result = list(con.run_select(sql, values))
        # if the length of my result list is greater than zero, pilot exists in the Pilot table
        if len(result) > 0:
            # the pilot exists
            # use the appropriate function from Connection to update*** the existing
            #     tuple with the current values for this Pilot.
            sql = "update user_data set username = %s, name = %s, \
            passphrase = %s \
            where username = %s"
            values = [str(self.get_username()), str(self.get_name()), str(self.get_passphrase())]
        
        else:
            # the user does NOT exist in the user_data table
            sql = "insert into user_data(username, name, passphrase) values (%s, %s, %s)"
            values = [str(self.get_id()), str(self.get_name()), str(self.get_salary())]
        # call run_change from Connection with the sql and values I created in the if/else statement
        result = con.run_change(sql, values)
        if result == 1:
            return True
        else:
            return False

    # TODO 3. Create the function remove()
    # Process: - creates a Connection object (the class we created in file connection_solution.py)
    #          - initialize the Connection with the username and password received as parameters
    #          - use the appropriate function from Connection to delete the pilot based on the pilot's
    #                   identification number
    # Parameters: self
    #             user: the MySQL username that has permission to access the database
    #             pwd: the password for the user
    # Return: True if the data successfully affected one row in the Pilot table (insert or update);
    #         False, otherwise
    def remove(self, user, pwd):
        con = Connection(user=user, pwd=pwd, db="airline_db")
        sql = "delete from pilot where identification = %s"
        values = [self.get_id()]
        result = con.run_change(sql, values)
        if result == 1:
            return True
        else:
            return False

    # TODO 3. Create the function load()
    # Process: - create a Connection object (the class we created in file connection_solution.py)
    #          - initialize the Connection with the username and password received as parameters
    #          - use the appropriate function from Connection to find an existing pilot based on
    #               the pilot's identification number provided as a parameter
    #          - if the identification number exists in the Pilot table, set the attributes of the
    #               pilot object to be the values recovered from the database
    # Parameters: self
    #             id: integer value that represents the an existing pilot's identification number
    #             user: the MySQL username that has permission to access the database
    #             pwd: the password for the user
    # Return: True if there is an existing Pilot in the table with the provided id and the values
    #               were successfully loaded into the pilot object
    #         False if identification number was not found in the Pilot table
    def load(self, id, user, pwd):
        con = Connection(user=user, pwd=pwd, db="airline_db")
        sql = "select * from pilot where identification = %s"
        values = [str(id)]
        result = con.run_select(sql, values)
        if len(result) > 0:
            # get the first row from the resulting table
            # note that this result table has only one row because identification is PK
            result = result[0]
            # set the pilot attributes with whatever I got from the result[0]
            self.set_id(result[0])
            self.set_name(result[1])
            self.set_salary(result[2])
            self.set_bonus(result[3])
            self.set_airline(result[4])
            self.set_country(result[5])
            return True
        else:
            return False