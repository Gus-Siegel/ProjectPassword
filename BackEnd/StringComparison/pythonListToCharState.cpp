#include "pythonListToCharState.h"

CharStateList readCharStateListFromString( const std::string str )
{
	int wkgInd = 0;
	return readCharStateListFromString( str, wkgInd );
}

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

	if( APPLY_BACKSPACES_BEFORE_SET_DELAY )
	{
		resultList.applyBackspaces( APPLY_BACKSPACES_BEFORE_SET_DELAY );
	}
	if( TIME_BASED_INPUT )
	{
		resultList.setToDelay();
	}
	if( APPLY_BACKSPACES_AFTER_SET_DELAY )
	{
		resultList.applyBackspaces( APPLY_BACKSPACES_BEFORE_SET_DELAY );
	}

	return resultList;
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
	char charInit;
	char charEnd;
	char evaledChar;
	std::string charAsString;

	// read quotation initializer from string, store as charInit
	charInit = str[ wkgInd ];
	charEnd = charInit; // assume start and end are the same character
	wkgInd++;

	// read character being evaluated
	evaledChar = str[ wkgInd ];

	// case empty string
	if( evaledChar == charEnd )
	{
		// avoid case evaluated character is equal to initializer
			// next character is not end marker
		if( str[ wkgInd + 1 ] != charEnd )
		{
			// return recognition of empty string
			return EMPTY_STRING_CHAR;
		}
	}

	// case evaluated char is more than one character
	if( str[ wkgInd + 1 ] != charEnd )
	{
		// convert to string
		charAsString = (std::string)""; // empty string
			// iterate until character is end
		while( str[ wkgInd ] != charEnd )
		{
			// read character, push onto evaluated character
			charAsString.push_back( str[ wkgInd ] );
			wkgInd++;
		}
		// skip charEnd
		wkgInd++;

			// not necessary if c++ evaluates python's backspace as 0x08
		// check string equal to python's backspace string
		if( charAsString == PYTHON_BACKSPACE_STR )
		{
			return BACKSPACE_CHAR;
		}
		// otherwise, unrecognized
		return UNRECOGNIZED_CHAR;
	}
	// end case multiple character char, assume single

	// skip evaluated character and charEnd
	wkgInd += 2;

	// return evaluated character
	// if evaluated character is c++'s ascii backspace, 
	// 		will return equivalent of BACK_SPACE_CHAR
	return evaledChar;
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
	return value == '[';
}

bool isListTerminator( const char value )
{
	return value == ']';
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



