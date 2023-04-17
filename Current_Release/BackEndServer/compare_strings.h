#ifndef COMPARE_STRINGS_H
#define COMPARE_STRINGS_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <limits.h>
#include <math.h>
#include <vector>
#include "verifyUserConstants.h"

// class definitions
class TimeWeightType;
class CharStateList;
class CharState;

/*
Name: TimeWeightType
Initialization: empty list of comparisons
Modification: insertComparison to add two CharStates being compared
                  must use the same parameter order for insertComparison
Output: the error can be found with getTimeErrorWeight
*/
class TimeWeightType
{
private:
        // time from previous buffer to current
    double firstWkgTime;
    double secondWkgTime;

        // list of times that can be directly compared
    std::vector<double> firstTimeVector;
    std::vector<double> secondTimeVector;


public:
    TimeWeightType();
    void reset();

    /*
    Name: TimeWeightType::insertComparison
    Process: adds CharState values to wkgTime, 
             if both characters are not buffers, 
                the delay values can be directly compared
                     appends wkgTimes into timeVectors,
                     resets the wkgTimes
             otherwise, waits for next wkgTime
    Function Input/Parameters: firstChar, secondChar (CharState)
    */
    void insertComparison( const CharState &firstChar, 
                           const CharState &secondChar );

    /* 
    Name: TimeWeightType::getTimeErrorWeight
    Process: finds sums of first and second time vectors, 
             multiplies each value in first such that the sums are equal
             for each value in the lists, 
                 divides the smaller by the larger to get a value between 0 and 1
                 if both are 0, gets 1
             the sum of all values from above is weighted between 0 and 1
                 as the average error ratio
    Function input/this: firstTimeVector, secondTimeVector (std::vector<double>)
          * contains multiple time delays
          * size of both vectors are equal, such that pairs can be analyzed
    Fucntion output/returned: averageErrorRatio (double)
          * value between 0 and 1
          * 1 is maximum possible error, 0 is minimum error
    */
    double getTimeErrorWeight() const;
};

/*
Name: CharState
Modification: direct access to value and delay
              isBuffer is used to represent a missing character
Output: same as modification
*/
class CharState
{
private:
public:
    char value;
    double delay;
    bool isBuffer;

    CharState();
    CharState( char charVal, double time );
    CharState( const CharState &source );
    void printListForm( const std::string end = "\n" ) const;
};


/*
Name: CharStateList
Initialization: empty list of CharStates
Modification: CharStates can be added to the list using append/insert
              CharStateList can be aligned using alignChars
Output: After aligned, getWeightTimeErrors will give a time error
*/
class CharStateList
{
private:
    std::list<CharState> chars;
public:
    CharStateList();
    CharStateList( const CharStateList &source );
    void set_word( const std::string &toSet );
    void printString() const;
    void append( const CharState &toAppend );
    void insert( CharState &toInsert, int insertIndex );
    CharState &getReference( int refIndex );
    int size() const;
    void insertBuffer( int insertIndex );
    void operator=( const CharStateList &source );
    void printListForm( const std::string end = "\n" ) const;

    /*
    Name: CharStateList::setToDelay
    Process: sets times to be relative to the previous value by 
             subtracting each time by the previous time
             the first time is set to 0
    Function input/parameters: none
    Function output/parameters: none
    */
    void setToDelay();
    std::string toString() const;
    bool applyBackspaces();

    // template functions
    template <typename RemoveIterableType>
    void removeInstances( RemoveIterableType removeIterable )
    {
        std::list<CharState>::iterator wkgState;

        // start at beginning of chars
        wkgState = chars.begin();

        // until end of chars
        while( wkgState != chars.end() )
        {
            // remove if in removeIterable
            if( removeIterable.find( wkgState->value ) != removeIterable.end() )
            {
                wkgState = chars.erase( wkgState );
            }

            // otherwise, move to next character
            else
            {
                wkgState++;
            }
        }
    }

    friend double getWeightTimeErrors( const CharStateList &oneList, 
                                       const CharStateList &otherList );
    friend double alignChars( CharStateList &oneCharStateArray, 
                              CharStateList &otherCharStateArray );
};




////////////////////////////////// CharStateList //////////////////////////////

/*
Name: alignCharsHelper
Process: optimized brute-force recursion: 
         stop recursion if end of both lists, no error at lowest depth
         stop recursion if wkgError passed maxWkgError - optimization
            return maxWkgError + 1 (represents invalid solution)
         case 1/2: one of the lists has terminated, 
            append a BUFFER to the terminated list
         after case 1/2, both lists have remaining characters
            use next character values
         case 3: both characters are equal
             move to next character on both
         do not know which error occurred, try all of them
         case 4: first character was mistyped
             move to next character on both
              - consider mistype
         case 5/6: one of the lists is missing a character
             move to the next character on one, append buffer to other
              - consider missing character
         returns lowest error of cases 4,5,6
Function input/parameters: oneCharStateArray, otherCharStateArray (CharStateList)
                           wkgIndex, wkgError, maxWkgError
Function output/parameters: oneCharStateArray, otherCharStateArray (CharStateList)
         * buffers are set in both lists as a placeholder for 
         * a missing character
Function output/returned: wkgError (double)
         * weighted error of recursive steps from wkgIndex to end of both lists
*/
double alignCharsHelper( CharStateList &oneCharStateArray, 
                 CharStateList &otherCharStateArray, 
                 int wkgIndex, double wkgError, double &maxWkgError );

// call alignCharsHelper with necessary arameters
// returns ratio of errors to maximum error that could
//    occur with the input parameter sizes
double alignChars( CharStateList &oneCharStateArray, 
                   CharStateList &otherCharStateArray );

// returns if character values are equal, or both a buffer
bool equalCharStateValues( const CharState &oneCharState, 
                           const CharState &otherCharState );




////////////////////////////////// TimeWeightType /////////////////////////////
/*
Name: getWeightTimeErrors
Process: iterates over CharStates in both lists, 
         inserting the comparison for each
         returns error weight using TimeWeightType
Function input/parameters: oneStateList, otherStateList (CharStateList)
      * both lists must have the same size
      * if they do not have the same size,
      *    apply alignChars()
Function output/return: error (double)
      * value between 0 and 1, 
      *    1 is worst error, 0 is best error
Dependencies: TimeWeightType
*/
double getWeightTimeErrors( const CharStateList &oneList, 
                            const CharStateList &otherList );








////////////////////////////////// other functions ////////////////////////////
// display a vector of ValueType
template <typename ValueType>
void printVector( const std::vector<ValueType> vector, 
                  std::string end = "\n" )
{
    std::cout << "[ ";

    typename
    std::vector<ValueType>::const_iterator iter;

    for( iter = vector.begin(); iter != vector.end(); iter++ )
    {
        std::cout << *iter;

        // do not display seperator if next iter is end of vector
        if( iter + 1 != vector.end() )
        {
            std::cout << ", ";
        }
    }

    std::cout << " ]" << end;

}


// sum values in a vector
template <typename ValueType>
ValueType sumVector( const std::vector<ValueType> vector )
{
    typename
    std::vector<ValueType>::const_iterator iter;

    ValueType sum = 0; // assume zero can be assigned to ValueType

    // add each element in vector
    for( iter = vector.begin(); iter != vector.end(); iter++ )
    {
        sum += *iter;
    }
    return sum;
}

#ifndef MIN_FUNCTION
#define MIN_FUNCTION
// minimum of two values
template <typename ValueType>
ValueType min( const ValueType &one, const ValueType &other )
{
	if( one < other )
	{
		return one;
	}
	return other;
}
#endif // MIN_FUNCTION


#ifndef MAX_FUNCTION
#define MAX_FUNCTION
// maximum of two values
template <typename ValueType>
ValueType max( const ValueType &one, const ValueType &other )
{
	if( one > other )
	{
		return one;
	}
	return other;
}
#endif // MAX_FUNCTION







#endif // COMPARE_STRINGS_H

