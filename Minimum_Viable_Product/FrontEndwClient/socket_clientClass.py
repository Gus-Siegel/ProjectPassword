# headers
import socket
import pdb # for debugging

class ClientV1:
    def __init__(self, passData, userData, IDphrase):
        self.passData = passData
        self.userData = userData
        self.IDphrase = IDphrase

        self.loginSuccess =self.client_program()


    def client_program(self):
        # get the hostname
        host = '108.174.198.179'
        port = 6500 # initiate port no above 1024
        print("Connecting to "+ host) # print IP
        client_socket = socket.socket() # get instance
        client_socket.connect((host,port)) # connect to the server

        username = self.userData # send over username
        print(username)

        message = self.passData # send passphrase data to server
        message = f"{message}" # typecast to string
        print(message) #print to display

        passphraseKey = self.IDphrase # send the key of the passphrase being tested against
        print(passphraseKey)

        # loop sending messages until given the close key
        while message.lower().strip() != 'bye':
            client_socket.send(message.encode())  # send passphrase Biometrics message
            print("Message sent")
            client_socket.send(username.encode()) # send username message
            print("User:" + username " sent")
            client_socket.send(passphraseKey.encode())  # send Key message
            data = client_socket.recv(1024).decode() # receive response

            #if data == True:


            print('Received from server: ' + data) # receive response

            message = "bye" # again take input
            print("socket closed")
        client_socket.close() #close the connection



