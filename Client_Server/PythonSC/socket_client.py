# headers
import socket

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

def client_program():
    # get the hostname
    host = socket.gethostname()
    port = 5000 # initiate port no above 1024
    print(host)

    client_socket = socket.socket() # get instance
    client_socket.connect((host,port)) # connect to the server

    message = input(" -> ") # take input

    while message.lower().strip() != 'bye':
        client_socket.send(message.encode()) # send message
        data = client_socket.recv(1024).decode() # receive response

         print('Received from server: ' + data) # receive response

         message = input(" -> ") # again take input

    client_socket.close() #close the connection

client_program()




# See PyCharm help at https://www.jetbrains.com/help/pycharm/
