#include <iostream>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <type_traits>
#include <unistd.h>
#include "compare_strings.h"
#include "pythonListToCharState.h"
#include "verifyUser.h"
//#include "database.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>





// Checks If a c-style string is an integer
bool is_int(char *c) {
  while (*c != '\0')
  {
    if (*c < '0' || *c > '9')
      return false;
    c++;
  }
  return true;
}

int main(int argc, char **argv) {

            
    if (argc != 2 || !is_int(argv[1])) {
        std::cerr << "[ERROR] Port is not provided via command line parameters!\n";
        return -1;
    }
    
    // Create a socket & get the file descriptor
    int sock_listener = socket(AF_INET, SOCK_STREAM, 0);
    // Check If the socket is created
    if (sock_listener < 0) {
        std::cerr << "[ERROR] Socket cannot be created!\n";
        return -2;
    }

    std::cout << "[INFO] Socket has been created.\n";
    // Address info to bind socket
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(std::atoi(argv[1]));
    //server_addr.sin_addr.s_addr = INADDR_ANY;
    // OR
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);
    
    char buf[INET_ADDRSTRLEN];


        // Bind socket
        if (bind(sock_listener, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            std::cerr << "[ERROR] Created socket cannot be binded to ( "
                    << inet_ntop(AF_INET, &server_addr.sin_addr, buf, INET_ADDRSTRLEN)
                    << ":" << ntohs(server_addr.sin_port) << ")\n";
            return -3;
        }

        std::cout << "[INFO] Sock is binded to ("  
                    << inet_ntop(AF_INET, &server_addr.sin_addr, buf, INET_ADDRSTRLEN)
                    << ":" << ntohs(server_addr.sin_port) << ")\n";


        // Start listening
        if (listen(sock_listener, SOMAXCONN) < 0) {
            std::cerr << "[ERROR] Socket cannot be switched to listen mode!\n";
            return -4;
        }
        std::cout << "[INFO] Socket is listening now.\n";
    while (true){
        // Accept a call
        sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr); 
        int sock_client; 
        if ((sock_client = accept(sock_listener, (sockaddr*)&client_addr, &client_addr_size)) < 0) {
            std::cerr << "[ERROR] Connections cannot be accepted for a reason.\n";
            return -5;
        }

        std::cout << "[INFO] A connection is accepted now.\n";
        
        
        

        // Get name info
        char host[NI_MAXHOST];
        char svc[NI_MAXSERV];
        if (getnameinfo(
                (sockaddr*)&client_addr, client_addr_size,
                host, NI_MAXHOST,
                svc, NI_MAXSERV, 0) != 0) {
            std::cout << "[INFO] Client: (" << inet_ntop(AF_INET, &client_addr.sin_addr, buf, INET_ADDRSTRLEN)
                    << ":" << ntohs(client_addr.sin_port) << ")\n"; 
        } else {
            std::cout << "[INFO] Client: (host: " << host << ", service: " << svc << ")\n";
        }

        
        char msg_buf[4096];
        char user_name[4096];
        char control_string[4096];
        //Session userDB = startSession("localhost", 3306, "username", "password");
        //userDB.sql("CREATE TABLE IF NOT EXISTS users (username VARCHAR(255) PRIMARY KEY, keyData JSON)").execute();
        //userDB.sql("USE users").execute();
        int bytes;
        int user_bytes;
        int control_bytes;
        std::fstream db_file; 
        std::string db_data;
        std::string db_user;
        std::string db_pass;
        std::string deli = ":";

        
        
    // While receiving - display & echo msg
        while(true)
        {
            db_file.open("testdb.txt");

            bytes = recv(sock_client, &msg_buf, 4096, 0);
            std::cout << "Message recieved\n";
            // Check how many bytes recieved
            if (bytes == 0) {
                std::cout << "[INFO] Client is disconnected.\n";
                break;
            }
            else if (bytes < 0) {
                std::cerr << "[ERROR] Something went wrong while receiving data!.\n";
                break;
            }
            // If there is no data, it means server is disconnected
            user_bytes = recv(sock_client, &user_name, 4096, 0);
            std::string user_string = user_name;
            std::cout << "user recived " << std::string(user_name, 0 ,user_bytes) << "\n";
            if (user_bytes == 0) {
                std::cout << "[INFO] Client is disconnected.\n";
                break;
            }
            else if (user_bytes < 0) {
                std::cerr << "[ERROR] Something went wrong while receiving data!.\n";
                break;
            }
            control_bytes = recv(sock_client, &control_string, 4096, 0);
            // If something gone wrong
            if (control_bytes == 0) {
                std::cout << "[INFO] Client is disconnected.\n";
                break;
            }
            else if (control_bytes < 0) {
                std::cerr << "[ERROR] Something went wrong while receiving data!.\n";
                break;
            }
            std::cout << control_string;
            if( strcmp(control_string, "login") != 0)//check if creating new user
            {
                std::cout << "Seaching database if user exists\n";
                //add to database
                getline(db_file, db_data);

                while(!db_file.eof() && db_user != user_string)
                {
                    //split it into username and password
                    std::cout << db_data << "\n";
                    // get user data from database
                    db_user = db_data.substr(0, db_data.find(deli));
                    db_pass = db_data.substr(db_data.find(deli) + 1);
                    std::cout << "user namer " << db_user << "\n";
                    std::cout << "password "<< db_pass << "\n";
                    getline(db_file, db_data);

                }
                if(db_file.eof())
                {
                    std::ofstream testing;
                    testing.open("testdb.txt", std::ios_base::app);
                    std::cout << "Adding new user\n";
                    
                    //send back true to the client
                    std::cout << "to be added to the " << user_name << ":" << msg_buf << "\n";
                    // while(!testing.eof)
                    // {
                    //     getline(testing, db_data);
                    // }
                    testing << user_name << ":" << msg_buf << "\n";
                    testing.close();

                    bool True = true;
                    if (send(sock_client, &True, sizeof(true), 0) < 0) {
                        std::cerr << "[ERROR] Message cannot be send, exiting...\n";
                        break;
                    }
                }
                else
                {
                    bool True = false;
                    if (send(sock_client, &True, sizeof(True), 0) < 0) {
                        std::cerr << "[ERROR] Message cannot be send, exiting...\n";
                        break;
                    }
                }
                db_file.close();


            }
            else
            {
                // If there is some bytes
                
                // Print message
                std::cout << "client> " << std::string(msg_buf, 0, bytes) << "\n";
                
                //read a line from the "data base"
                getline(db_file, db_data);
                while(!db_file.eof() && db_user != user_string)
                {
                    //split it into username and password
                    std::cout << db_data << "\n";
                    // get user data from database
                    db_user = db_data.substr(0, db_data.find(deli));
                    db_pass = db_data.substr(db_data.find(deli) + 1);
                    std::cout << "user namer " << db_user << "\n";
                    std::cout << "password "<< db_pass << "\n";
                    getline(db_file, db_data);

                }
                if(db_user != user_string)
                {
                    bool False = false;
                    send(sock_client, &False, sizeof(False), 0);
                    std::cout << "User name not found, aborting \n";
                    break;
                }
            

                // while(strcmp(user_name, db_user) != 0 || db_file){
                //     //read a line from the "data base"

                //     //split it into username and password
                // }
                

                const std::string wordOne = msg_buf;
                const std::string wordTwo = db_pass;
                bool temp;
                std::cout << "dataB> " << wordTwo << "\n";

                //check if string matches string from file via micheals code
                if(verifyUser(wordOne, wordTwo)){
                    temp = true;
                    std::cout << "User Verified \n";
                }
                else{
                    temp = false;
                    std::cout << "User Fail \n";
                }
                //send back 

                // strcpy(output, temp.c_str());    

                if (send(sock_client, &temp, sizeof(temp), 0) < 0) {
                    std::cerr << "[ERROR] Message cannot be send, exiting...\n";
                    break;
                }
            }
    

        }

    // Close client socket
    close(sock_client);
    std::cout << "[INFO] Client socket is closed.\n";
    }
    return 0;
}