# headers
import socket
import pdb

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

class Client:
    def __init__(self, passData):
        self.passData = passData
        self.client_program()


    def client_program(self):
        # get the hostname
        host = '108.174.198.179'
        port = 5500 # initiate port no above 1024
        print(host)
        client_socket = socket.socket() # get instance
        client_socket.connect((host,port)) # connect to the server

        message = self.passData # send passphrase data to server

        while message.lower().strip() != 'bye':
            client_socket.send(message.encode()) # send message
            data = client_socket.recv(1024).decode() # receive response

            print('Received from server: ' + data) # receive response

            message = input(" -> ") # again take input

        client_socket.close() #close the connection

Client("Hello World")

