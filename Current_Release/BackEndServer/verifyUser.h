#ifndef VERIFY_USER_H
#define VERIFY_USER_H

#include "compare_strings.h"
#include "pythonListToCharState.h"
#include "verifyUserConstants.h"
#include <string>


// subprocess of verifyUser(std::string,std::string), described above
// gets spelling and time errors, compares to acceptable error constants
//    to determine if user will be verfied, returning result
bool verifyUser( CharStateList &one, CharStateList &other );

/*
Name: verifyUser
Process: converts both parameters to a CharStateLists, 
         aligns the characters in both lists to minimize
         the spelling difference between them, 
         gets the time error based on the key press times, 
         then compares the time and spelling errors 
         to MAX_ACCEPTABLE_SPELLING_ERROR and MAX_ACCEPTABLE_TIME_ERROR
         to determine if the difference in parameter data 
         pass verification requirements. 
Function input/parameters: strOne (std::string), strTwo (std::string)
       * formatted as a python list of lists, 
       * where each sub-list contains a time (in seconds), 
       * and a character value (basic character or /x08 for backspace)
       *   - strings that do not have exactly one character, 
       *     and characeters in EXCLUDED_CHAR_STATE_CHARS
       *     will be ignored
       * there is no required order of the character value and time, 
       *     as long as both are provided within each sublist
       * Example: 
       *     (std::string)"[['T', 1681570037.1353717], [1681570038.109123, 'e'], ['s', 1681570039.4204078], ['t', 1681570041.1297593], ['!', 1681570042.9106834]]"
       * further explanation is provided in pythonListToCharState.cpp
Function output/return: userVerified (bool)
Dependencies: compare_strings.cpp, pythonListToCharState.cpp, 
              verifyUserContants.h
*/
bool verifyUser( const std::string strOne, const std::string strTwo );
#endif // VERIFY_USER_H