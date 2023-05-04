// compile:
//     g++ -Wall mockTestWithServer.cpp compare_strings.cpp pythonListToCharState.cpp verifyUser.cpp -o outfile


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
#include <unordered_map>
#include <exception>


class UsersMock;
class DatabaseMock;
class User;


const std::string User1Name = "Conor Tumaini";
const std::string User1Data = "[['h', 1682189375.5505714], ['e', 1682189377.6744502], ['l', 1682189380.12833], ['l', 1682189382.8606822], ['o', 1682189384.479007], [' ', 1682189385.269934], ['w', 1682189386.2646034], ['o', 1682189389.7380085], ['r', 1682189395.8718057], ['l', 1682189397.7561014], ['d', 1682189398.8961163]]";

const std::string User2Name = "Eoforhild Aisyah";
const std::string User2Data = "[['h', 1682000579.0561047], ['e', 1682000579.1364262], ['l', 1682000579.2768068], ['l', 1682000579.437289], ['o', 1682000579.5882292], [' ', 1682000579.6782236], ['\x08', 1682000580.0801368], [' ', 1682000580.700954], ['w', 1682000581.0809455], ['o', 1682000581.171554], ['r', 1682000581.2415357], ['l', 1682000581.3714507], ['d', 1682000581.4521375]]";

const std::string User3Name = "Felix Marysia";
const std::string User3Data = "[['h', 1679889122], ['e', 1679889123], ['l', 1679889124], ['l', 1679889125], ['o', 1679889126], [' ', 1679889127], ['w', 1679889128], ['o', 1679889129], ['r', 1679889130], ['l', 1679889131], ['d', 1679889132]]";



class User {
public:
    std::string name;
    std::string username;
    std::string userdata;
};

class DatabaseMock
{
private:
    // names map userdata (assume name and username are equal
    std::unordered_map<std::string,std::string> userMap;

public:
    bool containsName( std::string name ) {
        return userMap.find( name ) != userMap.end(); 
    }

    User getUser( std::string name ) {
        User resultUser;
        resultUser.name = name;
        resultUser.username = name;
        resultUser.userdata = userMap[ name ];

        return resultUser;
    }

    void addUser( User user ) {
        userMap[ user.name ] = user.userdata;
    }
};

class UsersMock
{
private:    
    int userCount = 0;
    std::string ctrlCode = "login";
    bool expectedResult;
    bool allTestsPassed = true;

public:
    UsersMock( std::string socketStr )  {
        if( socketStr == "invalid" ) {
            std::cerr << "[ERROR] Socket connot be created!\n";
        }
        else {
            std::cout << "[INFO] Socket has been created!\n";
        }
        std::cout << "[INFO] Socket is listening now.\n";
    }

    User getUser() {
        userCount++;
        User returnUser;

        // initailize 3 users
        if( userCount == 1 ) {
            std::cout << "user 1 creating account\n";
            returnUser.name = User1Name;
            returnUser.username = User1Name;
            returnUser.userdata = User1Data;
            ctrlCode = "new user";
            expectedResult = true;
        }
        else if( userCount == 2 ) {
            std::cout << "user2 creating account\n";
            returnUser.name = User2Name;
            returnUser.username = User2Name;
            returnUser.userdata = User2Data;
            ctrlCode = "new user";
            expectedResult = true;
        }
        else if( userCount == 3 ) {
            std::cout << "user3 creating account\n";
            returnUser.name = User3Name;
            returnUser.username = User3Name;
            returnUser.userdata = User3Data;
            ctrlCode = "new user";
            expectedResult = true;
        }
        else if( userCount == 4 ) {
            std::cout << "user1 creating account with user3 information\n";
            returnUser.name = User3Name;
            returnUser.username = User3Name;
            returnUser.userdata = User1Data;
            ctrlCode = "new user";
            expectedResult = false;
        }
        else if( userCount == 5 ) {
            std::cout << "user3 creating account with user3 information\n";
            returnUser.name = User3Name;
            returnUser.username = User3Name;
            returnUser.userdata = User3Data;
            ctrlCode = "new user";
            expectedResult = false;
        }

        // try to login to account with correct data
        else if( userCount == 6 ) {
            std::cout << "user1 logging into user1 account\n";
            returnUser.name = User1Name;
            returnUser.username = User1Name;
            returnUser.userdata = User1Data;
            ctrlCode = "login";
            expectedResult = true;
        }
        else if( userCount == 7 ) {
            std::cout << "user2 logging into user2 account\n";
            returnUser.name = User2Name;
            returnUser.username = User2Name;
            returnUser.userdata = User2Data;
            ctrlCode = "login";
            expectedResult = true;
        }

        // try to login with incorrect data
        else if( userCount == 8 ) {
            std::cout << "user1 logging into user2 account\n";
            returnUser.name = User2Name;
            returnUser.username = User2Name;
            returnUser.userdata = User1Data;
            ctrlCode = "login";
            expectedResult = false;
        }
        else if( userCount == 9 ) {
            std::cout << "user2 logging into user1 account\n";
            returnUser.name = User1Name;
            returnUser.username = User1Name;
            returnUser.userdata = User2Data;
            ctrlCode = "login";
            expectedResult = false;
        }
        else if( userCount == 10 ) {
            std::cout << "user1 logging into user3 account\n";
            returnUser.name = User3Name;
            returnUser.username = User3Name;
            returnUser.userdata = User1Data;
            ctrlCode = "login";
            expectedResult = false;
        }

        // end after testing complete
        else {
            std::cerr << "No more user data\n";
            std::cout << "\n\n";
            if( !allTestsPassed ) {
                 std::cout << "At least one test not passed\n";
            } else {
                std::cout << "All tests passed\n";
            }
            exit( 0 );
        }

        return returnUser;
    }

    std::string getControlCode() {
        return ctrlCode;
    }

    bool wasExpecting( bool actualResult )
    {
        if( actualResult != expectedResult ) {
            std::cerr << "[ERROR]: expected " << expectedResult << " but got "
                      << actualResult << " instead\n";
        }
        else {
            std::cout << "The result was expected\n";
        }
        allTestsPassed &= actualResult == expectedResult;

        return actualResult == expectedResult;
    }
};


int main()
{
    UsersMock users = UsersMock( "5000" );
    DatabaseMock database;

    std::string name, username, userdata, ctrcode;
    std::string testdata;

    // while receiving - display and echo message
    while( true ) {
        std::cout << "\n";
        // get the user and their control code
        User currentUser = users.getUser();
        ctrcode = users.getControlCode();
        name = currentUser.name;
        username = currentUser.username;
        userdata = currentUser.userdata;

        // notify user received
        std::cout << "user received: " << name << "\n";

        // case control code is "login"
        if( ctrcode == "login" ) {
            // skip if name not in database
            if( !database.containsName( name ) ) {
                std::cout << "This account does not exist\n";
                users.wasExpecting( false );
                continue;
            }

            // access data from the database
            testdata = database.getUser( name ).userdata;

            // determine if user is verified
            if( verifyUser( testdata, userdata ) ) {
                std::cout << "Verified\n"; // tell user they are verified
                users.wasExpecting( true );
            } else {
                std::cout << "Not verified\n"; // tell user not verified
                users.wasExpecting( false );
            }
        }

        // otherwise, control code is "new user"
        else {
            // skip if name in database
            if( database.containsName( name ) ) {
                std::cout << "This account already exists\n";
                users.wasExpecting( false );
                continue;
            }

            // set data into database
            database.addUser( currentUser );
            std::cout << "User added to database\n";
            users.wasExpecting( true );
       }
    }

    std::cout << "\n\nProgram End\n"; // will not run due to while loop
    return 0;
}




