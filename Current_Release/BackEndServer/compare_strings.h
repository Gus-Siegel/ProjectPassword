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

// combines time weight errors
class TimeWeightType
{
private:
        // time from previous buffer to current
    double firstWkgTime;
    double secondWkgTime;

        // list of times that can be directly compared
    std::vector<double> firstTimeVector;
    std::vector<double> secondTimeVector;

    void insertComparison( const CharState &firstChar, 
                           const CharState &secondChar );
    double getTimeErrorWeight() const;


public:
    TimeWeightType();
    void reset();

    friend double getWeightTimeErrors( const CharStateList &oneStateList, 
                                   const CharStateList &otherStateList );
};

// class containing charVal and delay
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


// class containing list of CharStates
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
    void setToDelay();
    std::string toString() const;
    bool applyBackspaces( bool APPLY_BACKSPACES_BEFORE_SET_DELAY );

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

    friend double weightTimeErrors( const CharStateList &oneStateList, 
                         const CharStateList &otherStateList );
    friend double getWeightTimeErrors( const CharStateList &oneList, 
                                       const CharStateList &otherList );
    friend double alignChars( CharStateList &oneCharStateArray, 
                              CharStateList &otherCharStateArray );
};




////////////////////////////////// CharStateList //////////////////////////////

// align characters in CharStateList such that the minimum
// error weight occurs by implementing buffers between characters
double alignCharsHelper( CharStateList &oneCharStateArray, 
                 CharStateList &otherCharStateArray, 
                 int wkgIndex, double wkgError, double &maxWkgError );

// call alignCharsHelper with necessary parameters
double alignChars( CharStateList &oneCharStateArray, 
                   CharStateList &otherCharStateArray );

// returns if character values are equal, or both a buffer
bool equalCharStateValues( const CharState &oneCharState, 
                           const CharState &otherCharState );




////////////////////////////////// TimeWeightType /////////////////////////////

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

