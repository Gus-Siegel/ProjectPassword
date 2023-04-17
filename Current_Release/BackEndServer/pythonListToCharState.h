#ifndef PYTHON_LIST_TO_CHAR_STATE_LIST_H
#define PYTHON_LIST_TO_CHAR_STATE_LIST_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "compare_strings.h"
#include "verifyUserConstants.h"


// value constants
const int STANDARD_BASE = 10;



/*
Name: readCharStateListFromString(std::string)
Process: reads the data from the string, 
         then modified the data. 
         all characters in EXCLUDED_CHAR_STATE_CHAR
             are removed prior to setting the list to delays
         backspaces are moved in order based on APPLY_BACKSPACES_BEFORE_SET_DELAY
Function input/parameters: str (std::string)
     * see readCharStateListFromString(std::string,int)
Function output/returned: resultList (std::string)
     * contains data, modified based on constants from EXCLUDED_CHAR_STATE
Dependencies: compare_strings.cpp, verifyUserConstants.h
*/
CharStateList readCharStateListFromString( const std::string str, int &wkgInd );

/*
Name: readCharStateListFromString(std::string,int)
Process: iterates over the string, reading a CharState whenever a
         list initializer is encountered, 
         stops iterating when a list terminator is encountered
Function output/return: resultList (CharStateList)
Function input/parameters: str, (std::string)

Parameter Content: 
 * python list of lists, 
 * where each sub-list contains a time (time.time())
 * and a string value (basic character or /x08 for backspace)
 *   - each time must be greater than the one before it (excluding the first)
 *   - strings that do not have exactly one character (excluding /x08)
 *     will be replaced by UNRECOGNIZED_CHAR or EMPTY_STRING_CHAR
 *   - if one of the data are not provided, the CharState will hold garbage data

Formatting: 
 * lists can be initialized or terminated using tuple/list/set format
 *      - {}()[]
 *      - a list without a list terminator will result in loss of data, 
 *        and crash the program if not terminated before the end of the string
 *      - terminating the list early will result in garbage data
 * 
 * sub-lists can contain data in any order
 *    as long as a character and time are provided within each sublist
 *      - ['a',123456789.8765432] and [123456789.8765432,'a'] are valid
 *      - order does not need to be consistent with previous instances
 * 
 * key value is initialized by a ' or ", and immidiately terminated
 *    when that same character is encountered
 *      - [''',12345678.87654321] will give an error
 *         - python will provide "'" when ' is in a string
 * 
 * time can be read as an integer or double
 *      - any digit before a . is included in the 'whole number'
 *      - any digit after a . is included in the 'decimal number'
 *      - a leading 0 is not required (.12345)
 *      - if a . is not provided, the digit will be stored as a 'whole number'
 *      - negative numbers cannot be read
 *      - any character that is not a digit and not the first . represents
 *        the end of the time
 * when reading lists, any character that does not represent 
 *    the initialization of a valid subclass type
 *    or termination of the list will be ignored
 *      - for the main list: [ ]
 *      - for sub-lists: ' " <digit> . ]
 *      - commas and whitespace will not effect how data is read
 *           [['a'123.321]['b'321.123]]
 *           and 
 *           [ [ 'a' , 123.321 ] , [ 'b' , 321.123 ] ]
 *           are valid
*/
/*
Example generating valid input in python:
>>> import time
>>> num_keys = int( input( "Enter number of keys to be pressed: " ) )
>>> key_list = []
>>> for key_ind in range( num_keys ):
...     char_val = input( "Enter a character: " )
...     key_list.append( [ char_val, time.time() ] )
>>> print( key_list )

output: 
    [['T', 1681579019.7828708], ['e', 1681579020.690203], ['s', 1681579021.70593], ['t', 1681579023.342321], ["'", 1681579027.6499062]]

*/
CharStateList readCharStateListFromString( const std::string str );


CharState readCharStateFromString( const std::string str, int &wkgInd );
char readCharFromString( const std::string str, int &wkgInd );
std::string readStringFromString( const std::string str, int &wkgInd );
double readDoubleFromString( const std::string str, int &wkgInd );
int readIntFromString( const std::string str, int &wkgInd );
bool isDigit( const char value );
int digitCharToInt( const char value );
double readPostRadixFromString( const std::string str, int &wkgInd );
double readIntAsDoubleFromString( const std::string str, int &wkgInd );
bool isListInitializer( const char value );
bool isListTerminator( const char value );
bool isCharInitializer( const char value );
bool isCharTerminator( const char value );
bool isRadixPoint( const char value );
bool isFloatDigit( const char value );

#endif // #define PYTHON_LIST_TO_CHAR_STATE_LIST



