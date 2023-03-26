# headers
import socket
import pdb

class Client:
    def __init__(self, passData, userData):
        self.passData = passData
        self.userData = userData

        self.loginSuccess =self.client_program()


    def client_program(self):
        # get the hostname
        host = '108.174.198.179'
        port = 6500 # initiate port no above 1024
        print(host)
        client_socket = socket.socket() # get instance
        client_socket.connect((host,port)) # connect to the server

        username = self.userData # send over username
        print(username)

        message = self.passData # send passphrase data to server
        message = f"{message}"
        print(message)

        while message.lower().strip() != 'bye':
            client_socket.send(message.encode())  # send message
            print("Message sent")
            client_socket.send(username.encode()) # send message
            print("User sent")
            data = client_socket.recv(1024).decode() # receive response

            print('Received from server: ' + data) # receive response

            message = "bye" # again take input
            print("socket closed")
        client_socket.close() #close the connection



