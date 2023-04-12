#include "verifyUser.h"

bool verifyUser( const std::string strOne, const std::string strTwo )
{
	CharStateList oneList, otherList;
	oneList = readCharStateListFromString( strOne );
	otherList = readCharStateListFromString( strTwo );
	return verifyUser( oneList, otherList );
}


bool verifyUser( CharStateList &one, CharStateList &other )
{
	double spellingError, timeError;

	spellingError = alignChars( one, other );
	timeError = getWeightTimeErrors( one, other );
	return ( timeError + spellingError ) < MAX_ACCEPTABLE_USER_ERROR;
}

