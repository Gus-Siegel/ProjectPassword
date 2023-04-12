#ifndef PYTHON_LIST_TO_CHAR_STATE_LIST_H
#define PYTHON_LIST_TO_CHAR_STATE_LIST_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "compare_strings.h"

const int CHAR_STRING_SIZE = 3;
const int STANDARD_BASE = 10;
const bool TIME_BASED_INPUT = true; // set to true if input contains times


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



