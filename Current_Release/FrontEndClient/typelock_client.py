#headers import socket
import socket
import time
#import pdb


class Client:
    def __init__(self, host = '108.174.198.179', port = 6500):
        self.host = host
        self.port = port

    #Name: connect
    #Method: establish socket instance, connect to server, print message
    #Parameters: self
    #Output: none
    #Return: none
    #dependencies: socket, connect
    def connect(self):
        #get instance
        self.client_socket = socket.socket()
        #connect to server
        self.client_socket.connect((self.host, self.port))
        # print connection message
        print("Connecting to " + self.host)

    #Name: send_message
    #Method: Send message via connection
    #Parameters: self, message
    #Output: none
    #Return: none
    #Dependencies: send, encode
    def send_message(self, message):
        self.client_socket.send(message.encode())
        time.sleep(1)

    #Name: receive_message
    #Method: Receive messages from server side
    #Parameters: self
    #Output: none
    #Return: none
    #Dependencies: recv, decode
    def receive_message(self):
        return self.client_socket.recv(1024).decode()

    #Name: close_connection
    #Method: close socket connection
    #Parameters: self
    #Output: none
    #Return: none
    #dependencies: close
    def close_connection(self):
        self.client_socket.close()

#Parameters: self, loginPass, loginUser, IDphrase, login_result
#Return: May need to return true or false
class Login:
    def __init__(self, login_Pass, login_User, ID_phrase):
        self.loginPass = login_Pass
        self.loginUser = login_User
        self.IDphrase = ID_phrase
        self.operation = 'login'

    # Name: user_login
    # Parameters: self, loginPass, loginUser, IDphrase, login_result
    # Return: May need to return true or false
    def user_login(self):
        
        #call instance of client
        client = Client()
        #connect to server
            #function: connect
        client.connect()
        print("Connecting to server")

        #set operation command
        ctrl_op = self.operation

        #set username
        username = self.loginUser
        #set message metrics
        message = f"{self.loginPass}"
        control = self.operation
        passPhrase = self.IDphrase

        # loop message until given the close key
        while message.lower().strip() != 'bye' :
            client.send_message(message)
            client.send_message(username)
            
            client.send_message(ctrl_op)
            #set up passphrase key for future
            print("Username:" + username + " and login attempt sent.")

            #retrieve login result and display
            #cpp booleans are not capitalized so we need to convert
            login_result = client.receive_message()
            
            print(type(login_result))

            if ord(login_result):
                print("In true statement")
                print("Login attempt: " + login_result)
                login_result = True

            else:
                print("In else statement")
                print("Login attempt: " + login_result)
                login_result = False


            #set message to close request
            message = "bye"
            print("Socket closed by server")

        #close socket connection on client side
        client.close_connection()
        print("TCP socket connection closed") 

        #my var for clarification
        return login_result   

class Signup:
    def __init__(self, new_user_pass, new_user_name, 
                 new_user_username, passphrase_key):
        self.operation = 'signup'
        self.new_user_pass = new_user_pass
        self.new_user_name = new_user_name
        self.new_user_username = new_user_username
        self.passphrase_key = passphrase_key

    def user_signup(self):
                #call instance of client
        client = Client()
        #connect to server
            #function: connect
        client.connect()
        print("Connecting to server")
        #set control string 
        ctrl_op = self.operation
        #set username
        name = self.new_user_name
        username = self.new_user_username
        #set message metrics
        message = f"{self.new_user_pass}"
        passPhrase = self.passphrase_key

        # loop message until given the close key
        while message.lower().strip() != 'bye' :
            client.send_message(message)
            client.send_message(username)
            client.send_message(ctrl_op)
            client.send_message(name)

            #set up passphrase key for future
            print("New user:" + username + " and data sent.")

            #retrieve login result and display
            signup_result = client.receive_message()
            print(type(signup_result))
            print(signup_result)
            if ord(signup_result):
                print("In true")
                print("Signup attempt: Success")
                signup_result = True

            else:
                print("In else statement")
                print("Signup attempt: Fail")
                signup_result = False

            #set message to close request
            message = "bye"
            print("Socket closed by server")

        #close socket connection on client side
        client.close_connection()
        print("TCP socket connection closed") 

        #my var for clarification
        print("Signup socket closed" )

        return signup_result 
    