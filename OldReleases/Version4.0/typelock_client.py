# headers
import socket

class Client:
    #parameters: self, loginPass, loginUser, IDphrase, host number, port number
    def __init__(self, loginPass, loginUser, IDphrase, 
                 host='108.174.198.179', port = 5500):
        self.loginPass = loginPass
        self.loginUser = loginUser
        self.IDphrase = IDphrase
        self.host = host 
        self.port = port
        self.loginSuccess =self.connect()

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
        print("Connecting to" + self.host)

    #Name: send_message
    #Method: Send message via connection
    #Parameters: self, message
    #Output: none
    #Return: none
    #Dependencies: send, encode
    def send_message(self, message):
        self.client_socket.send(message.encode())

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

    def user_login(self)
        #connect to server
            #function: connect
        self.connect()

        #set username
        username = self.loginUser
        #set message metrics
        message = f"{self.loginPass}"
        passPhrase = self.IDphrase

        # loop message until given the close key
        while message.lower().strip() != 'bye' :
            self.send_message(message)
            self.send_message(username)
            #set up passphrase key for future
            print("Username:" + username + " and login attempt sent")

            #retrieve login result and display
            loginResult = self.receive_message()
            if loginResult:
            print("Login attempt: Success")

            else:
            print("Login attempt: Fail")

            #set message to close request
            message = "bye"
            print("Socket closed by server")

        #close socket connection on client side
        self.close_connection()
        print("TCP socket connection closed")

#TODO class login
    #will call upon client

#TODO class signUp
    #will call upon client


