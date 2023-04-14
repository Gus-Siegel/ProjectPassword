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
	return spellingError <= MAX_ACCEPTABLE_SPELLING_ERROR && 
             timeError <= MAX_ACCEPTABLE_TIME_ERROR;
}

