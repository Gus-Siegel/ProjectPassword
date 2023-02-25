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





////////////////////////////////// CharStateList //////////////////////////////


// CharStateList constructor, initializes empty list
CharStateList::CharStateList()
{
    // nothing to initialize
}

// assign source list to destination list
void CharStateList::operator=( const CharStateList &source )
{
    chars = source.chars;
}




// add toAppend to end of list
void CharStateList::append( CharState &toAppend )
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











////////////////////////////////// TimeWeightType /////////////////////////////

// contructor, resets data
TimeWeightType::TimeWeightType()
{
    reset();
}




double TimeWeightType::getTimeErrorWeight() const
{
    std::vector<double>::const_iterator wkgOne, wkgOther;

    double oneSum, otherSum, oneRatio, weightedOne, weightedOther;
    double difference, sumOfDifferences = 0, averageDifference;
    double errorRatio;

    // find sum of each vector
    oneSum = sumVector( firstTimeVector );
    otherSum = sumVector( secondTimeVector );

    // error case:
    if( oneSum == 0 || otherSum == 0 )
    {
        // divide by zero
        return (double)INT_MAX;
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

        // add weighted difference to sumOfDifferences
        difference = weightedOne - weightedOther;
        sumOfDifferences += abs( difference );
    }

    // find average error ratio
    averageDifference = sumOfDifferences / firstTimeVector.size();
    errorRatio = averageDifference / otherSum;

    // return weighted error
    return errorRatio * TIME_ERROR_WEIGHT;
}

// TODO: modify parameters to be CharStates, such that 
//       buffer can be analyzed from boolean instead of delay
void TimeWeightType::insertComparison( double timeOne, double timeTwo )
{
    // case timeOne is not a buffer
    if( timeOne != BUFFER )
    {
        // add timeOne to firstWkgTime
        firstWkgTime += timeOne;
    }

    // case timeTwo is not a buffer
    if( timeTwo != BUFFER )
    {
        // add timeTwo to secondWkgTime
        secondWkgTime += timeTwo;
    }

    // case timeOne and timetwo are not buffers
    if( timeOne != BUFFER && timeTwo != BUFFER )
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
        timeErrors.insertComparison( wkgOneChar->delay, 
                                     wkgOtherChar->delay );
    }

    // return error weight of timeErrors
    return timeErrors.getTimeErrorWeight();
}







