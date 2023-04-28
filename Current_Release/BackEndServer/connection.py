
import mysql.connector


class Connection:


    def __init__(self, host="108.174.198.179", user="root", pwd="Trakk1995!mys", db="typelock_db"):
        self.__mydb = None
        self.__host = host
        self.__user = user
        self.__pwd = pwd
        self.__db = db


    def open_con(self):
        self.__mydb = mysql.connector.connect(
            host=self.__host,
            user=self.__user,
            password=self.__pwd,
            database=self.__db)


    def get_con(self):
        return self.__mydb


    def close_con(self):
        self.__mydb.close()
        self.__mydb = None


    def run_select(self, sql, values=None):
        # opens a connection (by calling the appropriate function)
        self.open_con()
        # creates a cursor for the connection
        query = self.get_con().cursor()
        # executes the sql with the values provided as parameters
        query.execute(sql, values)
        # fetch the results into a list variable
        result = query.fetchall()
        # close the connection
        self.close_con()
        # return the resulting list
        return result

    def run_change(self, sql, values=None):
        # opens a connection (by calling the appropriate function)
        self.open_con()
        # creates a cursor for the connection
        query = self.get_con().cursor()
        # executes the sql with the values provided as parameters
        query.execute(sql, values)
        # commits the changes
        self.get_con().commit()
        # stores the number of affected rows into a result variable
        result = query.rowcount
        # close the connection
        self.close_con()
        # return the result
        return result
