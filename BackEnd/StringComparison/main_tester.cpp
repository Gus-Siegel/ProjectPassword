// compiling from command line: 
    // g++ -Wall compare_strings.cpp pythonListToCharState.cpp verifyUser.cpp main_tester.cpp -o outFile


#include "compare_strings.h"
#include "pythonListToCharState.h"
#include "verifyUser.h"
#include <string>

// test alignCharsHelper function
void testAlignChars( const std::string &strOne, const std::string &strTwo );
CharStateList testPythonListConversion( const std::string pythonStr );
void testVerifyUser( CharStateList &one, CharStateList &other );
void testVerifyUser( const std::string strOne, const std::string strTwo );

int main()
{
    // alignChars
    testAlignChars( "a short string", 
                    "another short string" );
    testAlignChars( "thisone is a loger strin", 
                    "this one's longer string" );
    testAlignChars( "hello, world", 
                    "hello, world" );

    // verifyUser (verbose)
    testVerifyUser( "[[\"q\",13579642.0982],[\"B\",13579643.031789],[13579644.031789,'p']]", 
			"[ [ \",\", 2684213 ], [ \"q\", 2684218 ], [\"p\", 2684220] ]" );

    testVerifyUser( "[]", "[['a',1.304]]" );

    testVerifyUser( "[['h',1735462.012], ['e',1735462.017], ['l',1735462.023], ['l',1735462.04], ['o',1735462.0513] ]", 
			"[['h',912348018],['e',912348021], ['l',912348042], ['l',912348088], ['o',912348921]]" );

    testVerifyUser( "[[123654789.012,'h'], [123654789.029,'e'], [123654789.052,'l'], [123654789.092,'l'], [123654789.10313,'o'] ]", 
			"[['h',321456987.018], ['e',321456987.0435], ['l',321456987.078], ['l',321456987.138], ['o',321456987.154695] ]" );

    // verifyUser (final function)
    std::cout << "Second Input: should return False: ";
    std::cout << verifyUser( "[[\"q\",13579642.0982],[\"B\",13579643.031789],[13579644.031789,'p']]", 
					"[ [ \",\", 2684213 ], [ \"q\", 2684218 ], [\"p\", 2684220] ]" ) << "\n";
    std::cout << "Last Input: should return True: ";
    std::cout << verifyUser( "[[123654789.012,'h'], [123654789.029,'e'], [123654789.052,'l'], [123654789.092,'l'], [123654789.10313,'o'] ]", 
			"[['h',321456987.018], ['e',321456987.0435], ['l',321456987.078], ['l',321456987.138], ['o',321456987.154695] ]" ) << "\n";

    testVerifyUser( "[[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
	"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]" );

    std::cout << "\n\nProgram End\n";
    return 0;
}


// test alignCharsHelper function
void testAlignChars( const std::string &strOne, const std::string &strTwo )
{
    CharStateList listOne;
    CharStateList listTwo;
    double errorWeight;

    std::cout << "Input for aligning characters:\n";
    // set words from strings into list
    listOne.set_word( strOne );
    std::cout << "  ";
    listOne.printString();
    std::cout << "\n";

    listTwo.set_word( strTwo );
    std::cout << "  ";
    listTwo.printString();
    std::cout << "\n";

    // call function being tested
    errorWeight = alignChars( listOne, listTwo );

    if( errorWeight > MAX_SPELLING_ERROR )
    {
        std::cout << "Recursion terminated due to too many errors";
    }
    else
    {
        std::cout << "Output for aligning characters\n";
        std::cout << "  ";
        listOne.printString();
        std::cout << "\n";
        std::cout << "  ";
        listTwo.printString();
        std::cout << "\n";

        printf( "Spelling error: %f\n", errorWeight );
    }

    std::cout << "\n\n\n";
}


void testVerifyUser( const std::string strOne, const std::string strTwo )
{
	CharStateList oneList, otherList;
	std::cout << "--------------- Verifying similarity of two lists -------------\n";
	// convert strings to lists
	oneList = testPythonListConversion( strOne );
	otherList = testPythonListConversion( strTwo );

	// test lists
	testVerifyUser( oneList, otherList );
}


void testVerifyUser( CharStateList &one, CharStateList &other )
{
	double spellingError, timeError;

	spellingError = alignChars( one, other );

	if( spellingError > MAX_SPELLING_ERROR )
	{
		std::cout << "Recursion terminated due to too many errors\n\n";
	}
	else
	{
		timeError = getWeightTimeErrors( one, other );
		printf( "Spelling error = %f\n", spellingError );
		printf( "Time error = %f\n\n", timeError );
	}
}




CharStateList testPythonListConversion( const std::string pythonStr )
{
	CharStateList listResult;

	std::cout << "Input: \"" << pythonStr << "\"\n";
	listResult = readCharStateListFromString( pythonStr );
	std::cout << "Interpreted as: ";
	listResult.printListForm();
	std::cout << "\n";

	return listResult;
}




