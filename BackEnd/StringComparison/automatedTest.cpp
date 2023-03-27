// compiling:
// 	g++ -Wall automatedTest.cpp compare_strings.cpp pythonListToCharState.cpp verifyUser.cpp -o outFile
#define CONFIG_CATCH_MAIN
#include "pythonListToCharState.h"
#include "compare_strings.h"
#include "verifyUser.h"


//#include "gtest/gtest.h"

#include <string>
#include <stdio.h>
#include <iostream>

const double DOUBLE_ERROR_BOUND = .00001;


std::string alignStringWithString( const std::string oneStr, 
						const std::string otherStr );
bool testErrors( const std::string strOne, const std::string strTwo, 
			double expectedSpellError, double expectedTimeError );
bool performTests();
bool assertDoubleEquals( double oneDouble, double otherDouble );


template <typename INPUT_TYPE>
bool assertEquals( const INPUT_TYPE oneInput, const INPUT_TYPE otherInput )
{
	if( oneInput != otherInput )
	{
		std::cout << oneInput << " is not equal to " << otherInput << "\n";
		return false;
	}

	std::cout << "Passed assertEquals test (" << oneInput << " == " << otherInput << ")\n";
	return true;
}

int main()
{
	performTests();

	printf( "\n\nProgram end\n" );
	return 0;
}



bool performTests()
{
	bool allTestsPassed = true; // true until a test fails
	std::cout << "\n\n\n";

	// start of tests
		// align characters
	// missing consecutive charters
	allTestsPassed &= assertEquals( (std::string)"a______ short string", 
			alignStringWithString( "a short string", "another short string" ) );
	allTestsPassed &= assertEquals( (std::string)"another short string", 
			alignStringWithString( "another short string", "another short string" ) );
	// multiple sections of errors, mistype and extra
	allTestsPassed &= assertEquals( (std::string)"this_one is a lo_ger strin_", 
			alignStringWithString( "thisone is a loger strin", 
                    "this one's longer string" ) );
	allTestsPassed &= assertEquals( (std::string)"this one'_s __longer string", 
			alignStringWithString( "this one's longer string", 
                    "thisone is a loger strin" ) );
	// no errors
	allTestsPassed &= assertEquals( (std::string)"hello, world", 
			alignStringWithString( "hello, world", "hello, world" ) );

		// verify user
	// randomly generated values (calculated manually)
	allTestsPassed &= testErrors( 
		"[[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
		"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
		0, .432702 );
	// testing identical delays
	allTestsPassed &= testErrors( 
		"[[987654321,'a'],[987654323,'a'],[987654324,'a'],[987654326,'a'],[987654327,'a'],[987654329,'a']]", 
		"[[987655321,'a'],[987655323,'a'],[987655324,'a'],[987655326,'a'],[987655327,'a'],[987655329,'a']]", 
		0, 0 );
	// testing delays are proportionately off
	allTestsPassed &= testErrors( 
		"[[987654321,'a'],[987654323,'a'],[987654327,'a'],[987654332,'a'],[987654333,'a'],[987654339,'a']]", 
		"[[987655321,'a'],[987655325,'a'],[987655333,'a'],[987655343,'a'],[987655345,'a'],[987655357,'a']]", 
		0, 0 );
	// testing delays of zero (first is free, others have value 0 -> 4/5 error)
	allTestsPassed &= testErrors( 
		"[[987654321,'a'],[987654323,'a'],[987654323,'a'],[987654323,'a'],[987654333,'a']]", 
		"[[987655321,'a'],[987655321,'a'],[987655333,'a'],[987655343,'a'],[987655343,'a']]", 
		0, .8 );
	// testing extra character (from first case)
	allTestsPassed &= testErrors( 
		"[[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
		"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.06253,'b'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
		MISSING_CHAR_WEIGHT, .432702 );
	// testing mistyped character (from first case)
	allTestsPassed &= testErrors( 
		"[[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
		"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'b'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
		MISTYPE_WEIGHT, .432702 );

	// test testErrors
	std::cout << "\nTest testErrors displays errors when incorrect values are given\n";
	testErrors( 
		"[[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
		"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
		2.5, .432802 );


	// display test results
	if( !allTestsPassed ) {
		std::cout << "\n\nAt least one test was not passed.\n";
	} else {
		std::cout << "\n\nAll tests passed.\n";
	}


	return allTestsPassed;
}


std::string alignStringWithString( const std::string oneStr, 
						const std::string otherStr )
{
	CharStateList listOne;
	CharStateList listTwo;

	listOne.set_word( oneStr );
	listTwo.set_word( otherStr );

	alignChars( listOne, listTwo );

	return listOne.toString();
}


bool testErrors( const std::string strOne, const std::string strTwo, 
			double expectedSpellError, double expectedTimeError )
{
	std::cout << "Testing errors:\n";
	CharStateList oneList, otherList;
	double timeError, spellingError;
	bool passedTests = true;
	oneList = readCharStateListFromString( strOne );
	otherList = readCharStateListFromString( strTwo );

	spellingError = alignChars( oneList, otherList );
	timeError = getWeightTimeErrors( oneList, otherList );

	if( expectedSpellError != -1 )
	{
		if( !assertDoubleEquals( expectedSpellError, spellingError ) )
		{
			std::cout << " - Spelling Error is not expected\n";
			passedTests = false;
		}
	}

	if( expectedTimeError != -1 )
	{
		if( !assertDoubleEquals( expectedTimeError, timeError ) )
		{
			std::cout << " - Time Error is not expected\n";
			passedTests = false;
		}
	}

	return passedTests;
}


bool assertDoubleEquals( double oneDouble, double otherDouble )
{
	if( ( oneDouble < ( otherDouble + DOUBLE_ERROR_BOUND ) ) && 
		( oneDouble > ( otherDouble - DOUBLE_ERROR_BOUND ) ) )
	{
		std::cout << "Passed assertEquals test (" << oneDouble << " == " << otherDouble << ")\n";
		return true;
	}

	std::cout << oneDouble << " is not equal to " << otherDouble << "\n";
	return false;

}


