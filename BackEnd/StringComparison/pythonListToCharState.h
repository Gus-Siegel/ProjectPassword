#ifndef PYTHON_LIST_TO_CHAR_STATE_LIST_H
#define PYTHON_LIST_TO_CHAR_STATE_LIST_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "compare_strings.h"


// value constants
#ifndef BACKSPACE
#define BACKSPACE 0x08
#endif // BACKSPACE
const int CHAR_STRING_SIZE = 3;
const int STANDARD_BASE = 10;
const bool TIME_BASED_INPUT = true; // set to true if input contains times
const std::string PYTHON_BACKSPACE_STR = (std::string)"\\x08";
// any UNRECOGNIZED_CHAR and EMPTY_STRING_CHAR is 
// 	treated the same as another
const char UNRECOGNIZED_CHAR = (char)128; // first extended ascii character
const char EMPTY_STRING_CHAR = '\0'; // null character
const char BACKSPACE_CHAR = (char)0x08;


	// APPLY_BACKSPACES to remove characters before any backspace
	// setting both has the same result as only setting BEFORE_SET_DELAY
// before set delay: time taken to press backspace is added to next character
const bool APPLY_BACKSPACES_BEFORE_SET_DELAY = false;
// after set delay: time taken to press backspace is ignored in the list
const bool APPLY_BACKSPACES_AFTER_SET_DELAY = true;



CharStateList readCharStateListFromString( const std::string str, int &wkgInd );
CharStateList readCharStateListFromString( const std::string str );
CharState readCharStateFromString( const std::string str, int &wkgInd );
char readCharFromString( const std::string str, int &wkgInd );
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



