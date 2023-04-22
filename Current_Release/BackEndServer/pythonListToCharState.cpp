#include "pythonListToCharState.h"

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
CharStateList readCharStateListFromString( const std::string str )
{
	int wkgInd = 0;
      CharStateList resultList;

	// read format from string
      resultList = readCharStateListFromString( str, wkgInd );

	return resultList;
}

// formats charStateList for readCharStateListFromString
CharStateList formatCharStateList( CharStateList resultList )
{
	// remove instances of EXCLUDED_CHAR_STATE_CHARS from resultList
	resultList.removeInstances( EXCLUDED_CHAR_STATE_CHARS );

	// apply backspaces before if set
	if( APPLY_BACKSPACES_BEFORE_SET_DELAY )
	{
		resultList.applyBackspaces();
	}

	// set to delay if the input is time-based
	if( TIME_BASED_INPUT )
	{
		resultList.setToDelay();
	}

	// apply backspaces after if set
	if( APPLY_BACKSPACES_AFTER_SET_DELAY )
	{
		resultList.applyBackspaces();
	}

	return resultList;
}

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
CharStateList readCharStateListFromString( const std::string str, int &wkgInd )
{
	CharStateList resultList = CharStateList();

	// ignore list initializer
	wkgInd++;

	// iterate to list terminator
	while( !isListTerminator( str[ wkgInd ] ) )
	{
		// read CharState from list if list initializer
		if( isListInitializer( str[ wkgInd ] ) )
		{
			resultList.append( readCharStateFromString( str, wkgInd ) );
		}
		// otherwise, skip character
		else
		{
			wkgInd++;
		}
	}

	// ignore list terminator
	wkgInd++;

	return formatCharStateList( resultList );
}

CharState readCharStateFromString( const std::string str, int &wkgInd )
{
	CharState resultState = CharState();

	// ignore list initializer
	wkgInd++;

	// iterate to list terminator
	while( !isListTerminator( str[ wkgInd ] ) )
	{
		// read char from string if character initializer, store as charVal
		if( isCharInitializer( str[ wkgInd ] ) )
		{
			resultState.value = readCharFromString( str, wkgInd );
			resultState.isBuffer = false;
		}
		// read double from string if a digit, store as timeValue
		else if( isFloatDigit( str[ wkgInd ] ) )
		{
			resultState.delay = readDoubleFromString( str, wkgInd );
		}
		// otherwise, skip character
		else
		{
			wkgInd++;
		}
	}

	// ignore list terminator
	wkgInd++;

	return resultState;
}

char readCharFromString( const std::string str, int &wkgInd )
{
	std::string strVal;
	// read character as a string
	strVal = readStringFromString( str, wkgInd );

	// case empty
	if( strVal.size() == 0 )
	{
		// set to EMPTY_STRING_CHAR
		return EMPTY_STRING_CHAR;
	}

	// case single character
	if( strVal.size() == 1 )
	{
		// set to character value
		return strVal[0];
	}

	// case PYTHON_BACKSPACE_STR
	if( strVal == PYTHON_BACKSPACE_STR )
	{
		// set to BACKSPACE
		return BACKSPACE;
	}

	// otherwise, unregonized
	return UNRECOGNIZED_CHAR;
}

std::string readStringFromString( const std::string str, int &wkgInd )
{
	char initializer, terminator;
	std::string resultStr;

	// store first as string identifier
	initializer = str[ wkgInd ];
	wkgInd++;
	terminator = initializer;

	// iterate to terminator
	while( str[ wkgInd ] != terminator )
	{
		// store character in resultStr
		resultStr.push_back( str[ wkgInd ] );
		wkgInd++;
	}

	// ignore terminator
	wkgInd++;

	return resultStr;
}


double readDoubleFromString( const std::string str, int &wkgInd )
{
	double preRadix;
	double postRadix = 0.0;

	// read pre-radix part
	preRadix = readIntAsDoubleFromString( str, wkgInd );

	// only find post-radix part if a radix point is included
	if( isRadixPoint( str[ wkgInd ] ) )
	{
		// ignore radix point
		wkgInd++;

		// read post-radix part
		postRadix = readPostRadixFromString( str, wkgInd );
	}

	// return sum of double and pre-radix part
	return preRadix + postRadix;
}

int readIntFromString( const std::string str, int &wkgInd )
{
	int wkgInt = 0;

	// iterate until non-digit
	while( isDigit( str[ wkgInd ] ) )
	{
		// add digit to STANDARD_BASE * wkgInt
		wkgInt = wkgInt * STANDARD_BASE + digitCharToInt( str[ wkgInd ] );
		wkgInd++;
	}

	return wkgInt;
}

double readIntAsDoubleFromString( const std::string str, int &wkgInd )
{
	double wkgDouble = 0.0;

	// iterate until non-digit
	while( isDigit( str[ wkgInd ] ) )
	{
		// add digit to STANDARD_BASE * wkgDouble
		wkgDouble = wkgDouble * STANDARD_BASE + 
				(double)digitCharToInt( str[ wkgInd ] );
		wkgInd++;
	}

	return wkgDouble;
}

double readPostRadixFromString( const std::string str, int &wkgInd )
{
	double wkgResult = 0.0;
	double multiplier = 1.0;

	while( isDigit( str[ wkgInd ] ) )
	{
		// divide multiplier by STANDARD base
		multiplier /= STANDARD_BASE;

		// add weighted character to wkgResult
		wkgResult += digitCharToInt( str[ wkgInd ] ) * multiplier;

		wkgInd++;
	}

	return wkgResult;
}


bool isDigit( const char value )
{
	// between 0 and 9 inclusive
	return value >= '0' && value <= '9';
}

bool isFloatDigit( const char value )
{
	// is a digit, or radix point
	return isDigit( value ) || isRadixPoint( value );
}

int digitCharToInt( const char value )
{
	return (int)( value - '0' );
}

bool isListInitializer( const char value )
{
	return value == '['|| value == '{' || value == '(';
}

bool isListTerminator( const char value )
{
	return value == ']' || value == '}' || value == ')';
}

bool isCharInitializer( const char value )
{
	return value == '\'' || value == '\"';
}

bool isCharTerminator( const char value )
{
	return isCharInitializer( value );
}

bool isRadixPoint( const char value )
{
	return value == '.';
}



