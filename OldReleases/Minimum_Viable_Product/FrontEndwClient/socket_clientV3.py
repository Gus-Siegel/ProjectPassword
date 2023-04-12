# headers
import socket

class Client:
    def __init__(self, passData, userData, IDphrase):
        self.passData = passData
        self.userData = userData
        self.IDphrase = IDphrase

        self.loginSuccess =self.client_program()


    def client_program(self):
        # get the hostname
        host = '108.174.198.179'
        port = 5500 # initiate port no above 1024
        print("Connecting to "+ host) # print IP
        client_socket = socket.socket() # get instance
        client_socket.connect((host,port)) # connect to the server

        username = self.userData # take in username from GUI
        print(username)

        message = self.passData # take in passphrase data from GUI
        message = f"{message}" # typecast to string
        print(message) #print to display

        passphraseKey = self.IDphrase # take in Key passphrase from GUI
        print(passphraseKey)

        # loop sending messages until given the close key
        while message.lower().strip() != 'bye':
            client_socket.send(message.encode())  # send passphrase Biometrics message
            print("User's passphrase sent")
            client_socket.send(username.encode()) # send username message
            print("Username:" + username + " sent")
            #client_socket.send(passphraseKey.encode())  # send Key message
            #print("Passphrase key:" + passphraseKey + " sent")
            data = client_socket.recv(1024).decode() # receive response


            print('Received from server: ' + data) # receive response

            message = "bye" # again take input
            print("socket closed by server")
        client_socket.close() #close the connection
        print("TCP socket connection closed, client side")



