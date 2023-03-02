# headers
import socket

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

def server_program():
    # get the hostname
    host = 127.00
    port = 5000 # initiate port no above 1024

    server_socket = socket.socket() # get instance
    #bind() takes a tuple as arg
    server_socket.bind((host,port)) # bind host address and port together

    # configure how many client the server can listen simultaneously
    server_socket.listen(2)
    conn, address = server_socket.accept() # accept new connection
    print("Connection from: " + str(address))

    while True:
        # receive data stream. it won't accept data packet greater than 1024 bytes
        data = conn.recv(1024).decode()
        if not data:
            # if data is not received break
            break

        print("from connected user: " +str(data))
        data = input(' -> ')
        conn.send(data.encode()) #send data to the client

    conn.close() # close the connection




if __name__ == '__main__':
    server_program()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
