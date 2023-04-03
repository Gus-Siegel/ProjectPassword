#include "compare_strings.h"




/////////////////////////////////// CharState /////////////////////////////////

// CharState constructor, with charVal and time delay
CharState::CharState( char charVal, double time )
{
    value = charVal;
    delay = time;
    isBuffer = false;
}

// CharState constructor, without parameters -> buffer
CharState::CharState()
{
    isBuffer = true;
    delay = BUFFER;
    // value is undefined
}

// CharState copy constructor, deep copies values
CharState::CharState( const CharState &source )
{
    isBuffer = source.isBuffer;
    delay = source.delay;
    value = source.value;
}


void CharState::printListForm( const std::string end ) const
{
	std::cout << "{" << delay << ",'";
	if( isBuffer )
	{
		std::cout << "_";
	}
	else
	{
		std::cout << value;
	}
	std::cout << "'}" << end;
}





////////////////////////////////// CharStateList //////////////////////////////


// CharStateList constructor, initializes empty list
CharStateList::CharStateList()
{
    // initialize as empty data
}

// copy constructor, deep copies all values
CharStateList::CharStateList( const CharStateList &source )
{
    chars = source.chars;
}

// assign source list to destination list
void CharStateList::operator=( const CharStateList &source )
{
    chars = source.chars;
}


// for any CharState value equal to backspace, removes that state and the previous state
	// consecutive backspaces deletes that many previous states
// state delays are not modified
// the first character as a backspace only removes itself
// returns if all backspaces removed the previous character successfully
	// (first character backspace returns false)
bool CharStateList::applyBackspaces( bool APPLY_BACKSPACES_BEFORE_SET_DELAY )
{
	bool removedAll = true;
	std::list<CharState>::iterator wkgIter, startRemove, endRemove;
	// iterate over the list
	for( wkgIter = chars.begin(); wkgIter != chars.end(); wkgIter++ )
	{
			// need while to allow repeated backspaces consecutive
		// if the iterator's value is backspace
		while( wkgIter->value == BACKSPACE )
		{
			// set start to wkgIter, previous is available
			startRemove = wkgIter;
			if( wkgIter != chars.begin() )
			{
				startRemove--;
			}
			else
			{
				removedAll = false;
			}
			// set endRemove to wkgIter + 1 (exclusive upper bound)
			endRemove = wkgIter;
			endRemove++;
			// remove from startRemove to wkgIter, reassign
			wkgIter = chars.erase( startRemove, endRemove );

			// check the value is at the front and 
				// delay was already found
			if( wkgIter == chars.begin() && !APPLY_BACKSPACES_BEFORE_SET_DELAY )
			{
				// set the delay to 0
				wkgIter->delay = 0;
			}
		}
		// otherwise, do nothing
	}
	return removedAll;
}

// add toAppend to end of list
void CharStateList::append( const CharState &toAppend )
{
    chars.push_back( toAppend );
}

// returns reference to CharState at refIndex
CharState &CharStateList::getReference( int refIndex )
{
    std::list<CharState>::iterator refNode;
    refNode = chars.begin();
    std::advance( refNode, refIndex );

    return *refNode;
}

// inserts toInsert at insertIndex
void CharStateList::insert( CharState &toInsert, int insertIndex )
{
    std::list<CharState>::iterator insertNode;

    insertNode = chars.begin();
    std::advance( insertNode, insertIndex );

    chars.insert( insertNode, toInsert );
}

// in list, insert buffer at insertIndex
void CharStateList::insertBuffer( int insertIndex )
{
    CharState bufferChar = CharState();
    insert( bufferChar, insertIndex );
}

// display characters in list, display '_' for buffer
void CharStateList::printString() const
{
    std::list<CharState>::const_iterator printIter;

    for( printIter = chars.begin(); printIter != chars.end(); printIter++ )
    {
        if( printIter->isBuffer )
        {
            std::cout << '_';
        }
        else
        {
            std::cout << printIter->value;
        }
    }
}

void CharStateList::printListForm( const std::string end ) const
{
    std::cout << "{";
    std::list<CharState>::const_iterator wkgIter;
    std::list<CharState>::const_iterator tempIter;

    wkgIter = chars.begin();
    while( wkgIter != chars.end() )
    {
        wkgIter->printListForm( "" );
        wkgIter++;
        if( wkgIter != chars.end() )
        {
            std::cout << ",";
        }
    }

    std::cout << "}" << end;
}

// set charVals in list to match toSet, sets delays to 0
void CharStateList::set_word( const std::string &toSet )
{
    unsigned int strInd;
    CharState currentChar;
    chars.clear();

    for( strInd = 0; strInd < toSet.size(); strInd++ )
    {
        currentChar = CharState( toSet[ strInd ], 0.0 );
        chars.push_back( currentChar );
    }
}

// input: all delays are a time the character was pressed. 
	// output: delays become time from previous press to current press
void CharStateList::setToDelay()
{
	double prevTime, newTime;
	std::list<CharState>::iterator wkgState;
	
	// only process if elements exist
	if( chars.size() > 0 )
	{
		prevTime = chars.begin()->delay;
		wkgState = chars.begin();
		for( wkgState = chars.begin(); wkgState != chars.end(); wkgState++ )
		{
			newTime = wkgState->delay;
			wkgState->delay -= prevTime;
			prevTime = newTime;
		}

	}
}

// size of list
int CharStateList::size() const
{
    return chars.size();
}








// call alignCharsHelper with necessary parameters
int alignChars( CharStateList &oneCharStateArray, 
                 CharStateList &otherCharStateArray )
{
    double maxWkgError = MAX_SPELLING_ERROR;
    int wkgIndex = 0;
    double wkgError = 0;
    return alignCharsHelper( oneCharStateArray, 
                 otherCharStateArray, 
                 wkgIndex, wkgError, maxWkgError );
}

// align characters in CharStateList such that the minimum
// error weight occurs by implementing buffers between characters
double alignCharsHelper( CharStateList &oneCharStateArray, 
                 CharStateList &otherCharStateArray, 
                 int wkgIndex, double wkgError, double &maxWkgError )
{
    // initialize all variables for function
    int oneArraySize, otherArraySize;
    int minLoss, mistypeLoss, insertFirstLoss, insertSecondLoss;
    CharState oneCurrent, otherCurrent;
    CharStateList insertFirstArray, sameSecondArray;
    CharStateList sameFirstArray, insertSecondArray;
    CharStateList mistypeFirstArray, mistypeSecondArray;
    CharStateList modifiedOneArray, modifiedOtherArray;

    // stop recursing if wkgError greater than maximum
    if( wkgError >= maxWkgError )
    {
        // return value to prevent option from being chosen
        return maxWkgError + 1;
    }

    // find sizes of arrays
    oneArraySize = oneCharStateArray.size();
    otherArraySize = otherCharStateArray.size();

    // end recursion if index passed both sizes
    if( wkgIndex >= oneArraySize && wkgIndex >= otherArraySize )
    {
        // if current error is less than maximum fount, replace
        if( wkgError < maxWkgError )
        {
            maxWkgError = wkgError;
        }

        return wkgError;
    }

    // case 1: only oneArray has ran out of characters
    if( wkgIndex >= oneArraySize )
    {
        // insert buffer in oneChar
        oneCharStateArray.insertBuffer( wkgIndex );

        // continue iterating
        return alignCharsHelper( oneCharStateArray, otherCharStateArray, 
                            wkgIndex + 1, wkgError + MISSING_CHAR_WEIGHT, 
                            maxWkgError );
    }

    // case 2: only otherArray has ran out of characters
    if( wkgIndex >= otherArraySize )
    {
        // insert buffer in otherChar
        otherCharStateArray.insertBuffer( wkgIndex );

        // continue iterating
        return alignCharsHelper( oneCharStateArray, otherCharStateArray, 
                            wkgIndex + 1, wkgError + MISSING_CHAR_WEIGHT, 
                            maxWkgError );
    }


    // all cases where either array ran out of characters complete

    // get references to CharState at wkgIndex
    oneCurrent = oneCharStateArray.getReference( wkgIndex );
    otherCurrent = otherCharStateArray.getReference( wkgIndex );


    // case 3: both characters are equal
    if( equalCharStateValues( oneCurrent, otherCurrent ) )
    {
        // continue iterating, do not modify wkgError
        return alignCharsHelper( oneCharStateArray, otherCharStateArray, 
                            wkgIndex + 1, wkgError, maxWkgError );
    }


    // all cases with obvious errors completed
    // perform all cases, and use case with least cost



    // initialize StateLists
    insertFirstArray = CharStateList();
    sameSecondArray = CharStateList();
    sameFirstArray = CharStateList();
    insertSecondArray = CharStateList();
    mistypeFirstArray = CharStateList();
    mistypeSecondArray = CharStateList();

    // case 4: current character was mistyped. 
    // do not add buffers, continue with MISTYPE_WEIGHT
    mistypeFirstArray = oneCharStateArray;
    mistypeSecondArray = otherCharStateArray;
    mistypeLoss = alignCharsHelper( mistypeFirstArray, mistypeSecondArray, 
                               wkgIndex + 1, wkgError + MISTYPE_WEIGHT, 
                               maxWkgError );

    // case 5: missing character in firstArray
    // add buffer to firstArray, continue with MISSING_CHAR_WEIGHT
    insertFirstArray = oneCharStateArray;
    sameSecondArray = otherCharStateArray;
    insertFirstArray.insertBuffer( wkgIndex );
    insertFirstLoss = alignCharsHelper( insertFirstArray, sameSecondArray, 
                        wkgIndex + 1, wkgError + MISSING_CHAR_WEIGHT, 
                        maxWkgError );

    // case 6: missing character in secondArray
    // add buffer to secondArray, continue with MISSING_CHAR_WEIGHT
    sameFirstArray = oneCharStateArray;
    insertSecondArray = otherCharStateArray;
    insertSecondArray.insertBuffer( wkgIndex );
    insertSecondLoss = alignCharsHelper( sameFirstArray, insertSecondArray, 
                         wkgIndex + 1, wkgError + MISSING_CHAR_WEIGHT, 
                         maxWkgError );

    // case 4: priority 1
    if( mistypeLoss <= insertFirstLoss && 
        mistypeLoss <= insertSecondLoss )
    {
        // set variables from case 4
        minLoss = mistypeLoss; 
        modifiedOneArray = mistypeFirstArray;
        modifiedOtherArray = mistypeSecondArray;
    }

    // case 5: priority 2
    else if( insertFirstLoss <= insertSecondLoss )
    {
        // set variables from case 5
        minLoss = insertFirstLoss;
        modifiedOneArray = insertFirstArray;
        modifiedOtherArray = sameSecondArray;
    }

    // case 6: priority 3
    else
    {
        // set variables from case 6
        minLoss = insertSecondLoss;
        modifiedOneArray = sameFirstArray;
        modifiedOtherArray = insertSecondArray;
    }


    // terminate by adjusting arrays based on minimum condition
    oneCharStateArray = modifiedOneArray;
    otherCharStateArray = modifiedOtherArray;

    return minLoss;
}


// returns if character values are equal, or both a buffer
bool equalCharStateValues( const CharState &oneCharState, 
                           const CharState &otherCharState )
{
    // return false if exclusively are buffer
    if( oneCharState.isBuffer ^ otherCharState.isBuffer )
    {
        return false;
    }

    // return success if both are buffer
    if( oneCharState.isBuffer )
    {
        return true;
    }

    // return comparison of values
    return oneCharState.value == otherCharState.value;
}


std::string CharStateList::toString() const
{
	std::list<CharState>::const_iterator wkgState;
	std::string resultStr = (std::string)"";

	for( wkgState = chars.begin(); wkgState != chars.end(); wkgState++ )
	{
		if( wkgState->isBuffer )
		{
			resultStr += "_";
		}
		else
		{
			resultStr += wkgState->value;
		}
	}

	return resultStr;
}












////////////////////////////////// TimeWeightType /////////////////////////////

// contructor, resets data
TimeWeightType::TimeWeightType()
{
    reset();
}



/* 
    Current Algorithm:
Input: two aligned lists of delays
Weights one list such that its average matches other
Find sum of differences of each pair. 
Divide differences by sum of array and size to get average key ratio
*/
double TimeWeightType::getTimeErrorWeight() const
{
    std::vector<double>::const_iterator wkgOne, wkgOther;

    double oneSum, otherSum, oneRatio, weightedOne, weightedOther;
    double minDelay, maxDelay;
    double sumOfRatios = 0;
    double averageRatioError;

    // find sum of each vector
    oneSum = sumVector( firstTimeVector );
    otherSum = sumVector( secondTimeVector );

    // error case:
    if( oneSum == 0 || otherSum == 0 )
    {
        // divide by zero
        return (double)1;
    }

    // find ratio to multiply one by to weight with other
    oneRatio = otherSum / oneSum;


    for( wkgOne = firstTimeVector.begin(), 
         wkgOther = secondTimeVector.begin();
             wkgOne != firstTimeVector.end(); 
                 wkgOne++, wkgOther++ )
    {
        // weight both such that vector sums are equal
        weightedOne = *wkgOne * oneRatio;
        weightedOther = *wkgOther;

        // find min/max of weighted values
        minDelay = min( weightedOne, weightedOther );
        maxDelay = max( weightedOne, weightedOther );

        // do not penalize for indeterminate
        if( maxDelay == 0 )
        {
            sumOfRatios += 1;
        }
        else
        {
            // add ratio of min:max delay to sumOfRatios
            sumOfRatios += minDelay / maxDelay;
        }
    }

    // find average error ratio
    averageRatioError = 1 - sumOfRatios / (double)firstTimeVector.size();
    return averageRatioError * TIME_ERROR_WEIGHT;
}

void TimeWeightType::insertComparison( const CharState &firstChar, 
                                       const CharState &secondChar )
{
    // case first is not a buffer
    if( !firstChar.isBuffer )
    {
        // add timeOne to firstWkgTime
        firstWkgTime += firstChar.delay;
    }

    // case second is not a buffer
    if( !secondChar.isBuffer )
    {
        // add timeTwo to secondWkgTime
        secondWkgTime += secondChar.delay;
    }

    // case both are not buffers
    if( !firstChar.isBuffer && !secondChar.isBuffer )
    {
        // append working times to time vectors
        firstTimeVector.push_back( firstWkgTime );
        secondTimeVector.push_back( secondWkgTime );

        // reset wkgTimes
        firstWkgTime = 0;
        secondWkgTime = 0;
    }
}



// reset all values for comparison
void TimeWeightType::reset()
{
    firstWkgTime = 0;
    secondWkgTime = 0;
    firstTimeVector.clear();
    secondTimeVector.clear();
}





	
// get weighted error representing time differences in two CharStateLists
    // state lists must be equal size, using alignChars if necessary
double getWeightTimeErrors( const CharStateList &oneStateList, 
                            const CharStateList &otherStateList )
{
    std::list<CharState>::const_iterator wkgOneChar, wkgOtherChar;
    TimeWeightType timeErrors = TimeWeightType();

    // insert comparison of each value in each list
    for( wkgOneChar = oneStateList.chars.begin(), 
         wkgOtherChar = otherStateList.chars.begin();
             wkgOneChar != oneStateList.chars.end();
                 wkgOneChar++, wkgOtherChar++ )
    {
        timeErrors.insertComparison( *wkgOneChar, 
                                     *wkgOtherChar );
    }

    // return error weight of timeErrors
    return timeErrors.getTimeErrorWeight();
}




