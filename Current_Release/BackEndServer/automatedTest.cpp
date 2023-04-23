// compiling:
//     g++ -Wall compare_strings.cpp pythonListToCharState.cpp verifyUser.cpp automatedTest.cpp -o outFile
#define CONFIG_CATCH_MAIN
#include "pythonListToCharState.h"
#include "compare_strings.h"
#include "verifyUser.h"




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
    printf( "testing alignment with consecutive missing characters:\n" );
    allTestsPassed &= assertEquals( (std::string)"a______ short string", 
            alignStringWithString( "a short string", "another short string" ) );
    allTestsPassed &= assertEquals( (std::string)"another short string", 
            alignStringWithString( "another short string", "another short string" ) );
    // multiple sections of errors, mistype and extra
    printf( "testing alignment with different types of errors:\n" );
    allTestsPassed &= assertEquals( (std::string)"this_one is a lo_ger strin_", 
            alignStringWithString( "thisone is a loger strin", 
                    "this one's longer string" ) );
    allTestsPassed &= assertEquals( (std::string)"this one'_s __longer string", 
            alignStringWithString( "this one's longer string", 
                    "thisone is a loger strin" ) );
    // no errors
    printf( "testing alignment without errors:" );
    allTestsPassed &= assertEquals( (std::string)"hello, world", 
            alignStringWithString( "hello, world", "hello, world" ) );

        // verify user
    // randomly generated values (calculated manually)
    printf( "testing with pseudo-random delays:" );
    allTestsPassed &= testErrors( 
"[[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
    
"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
        0, .432702 );
    // testing identical delays
    printf( "testing identical delays:" );
    allTestsPassed &= testErrors( 
"[[987654321,'a'],[987654323,'a'],[987654324,'a'],[987654326,'a'],[987654327,'a'],[987654329,'a']]", 

"[[987655321,'a'],[987655323,'a'],[987655324,'a'],[987655326,'a'],[987655327,'a'],[987655329,'a']]", 
        0, 0 );
    // testing delays are proportionately off
    printf( "testing delays consistently off:" );
    allTestsPassed &= testErrors( 
    
"[[987654321,'a'],[987654323,'a'],[987654327,'a'],[987654332,'a'],[987654333,'a'],[987654339,'a']]", 
    
"[[987655321,'a'],[987655325,'a'],[987655333,'a'],[987655343,'a'],[987655345,'a'],[987655357,'a']]", 
        0, 0 );
    // testing delays of zero (first is free, others have value 0 -> 4/5 error)
    printf( "testing time to press key is zero:" );
    allTestsPassed &= testErrors( 
        "[[987654321,'a'],[987654323,'a'],[987654323,'a'],[987654323,'a'],[987654333,'a']]", 
        "[[987655321,'a'],[987655321,'a'],[987655333,'a'],[987655343,'a'],[987655343,'a']]", 
        0, .8 );

    // testing extra character (from first case)
    printf( "testing extra character:" );
    allTestsPassed &= testErrors( 
        "[[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
        "[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.06253,'b'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
        (double)1/(double)7, .432702 );

    // testing mistyped character (from first case)
    printf( "testing mistyped character:" );
    allTestsPassed &= testErrors( 
"[[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 

"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'b'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
        (double)1/(double)6, .432702 );

/*
    // testing backspace character with APPLY_BACKSPACES_AFTER_SET_DELAY = true
    allTestsPassed &= testErrors( 
    "[[987654321,'a'],[987654332,'a'],[987654333,'a'],[987654339,'a']]", 
        "[[987655321,'a'],[987655325,'a'],[987655333,''],[987655343,'a'],[987655345,'a'],[987655357,'a']]", 
        0, 0 );
*/

    // testing backspace character with APPLY_BACKSPACES_BEFORE_SET_DELAY = true
    allTestsPassed &= testErrors( 
"[[428944.64934,'a'],[428944.73761,'a'],[428944.84000,'a'],[428944.83761,''],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
    
"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
        0, .432702 );

    // testing backspace character in python string form
    printf( "testing single backspace in string form:" );
    allTestsPassed &= testErrors( 

"[[428944.64934,'a'],[428944.73761,'a'],[428944.84000,'a'],[428944.83761,'\\x08'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
    
"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
        0, .432702 );

    // testing backspace at beginning
    printf( "testing backspace at beginning of input:" );
    allTestsPassed &= testErrors( 
"[[428944.74934,'\\x08'],[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 

"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
        0, .432702 );

    // testing consecutive backspaces
    printf( "testing consecutive backspaces:" );
    allTestsPassed &= testErrors( 
"[[428944.74934,'a'],[428944.83761,'a'],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 

"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a'],[725894.14825,'a'],[725894.15625,'a'],[725894.15825,''],[725895.14625,'']]", 
        0, .432702 );


    // testing excessive backspaces
    printf( "testing excessive backspaces:" );
    allTestsPassed &= testErrors(     
"[[428942.74934,'h'],[428942.83761,'a'],[428942.88302,'l'],[428942.90400,'o'],[253324133,''],[253324134,''],[253324135,''],[253324136,''],[253324137,''],[253324138,''],[253324139,''],[428944.74934,'h'],[428944.83761,'e'],[428944.86697,'l'],[428944.88302,'l'],[428944.90400,'o'],[428944.93121,'!']]", 

"[[725894.04638,'h'],[725894.04970,'e'],[725894.06244,'l'],[725894.10041,'l'],[725894.11396,'o'],[725894.14625,'!']]", 
        0, .432702 );

    printf( "testing backspace after applying shift:\n" );
    allTestsPassed &= assertEquals( 
        true, 
        verifyUser( 
"[['h', 1681409664.3148472], ['e', 1681409664.3856945], ['l', 1681409664.506178], ['l', 1681409664.6450906], ['o', 1681409664.7839513]]", 
"[['', 1681409669.388498], ['H', 1681409669.5087724], ['\x08', 1681409670.6833558], ['h', 1681409671.910111], ['e', 1681409671.9707484], ['l', 1681409672.1010258], ['l', 1681409672.2317235], ['o', 1681409672.3730693]]" ) );

    printf( "\ntesting shift without backspace:\n" );
    allTestsPassed &= assertEquals( 
        true, 
        verifyUser( 
"[['', 1681414474.626238], ['H', 1681414474.8164868], ['e', 1681414474.9887047], ['l', 1681414475.068764], ['l', 1681414475.2091506], ['o', 1681414475.3612146]]", 
"[['', 1681414477.7330792], ['H', 1681414477.8731878], ['e', 1681414478.0337863], ['l', 1681414478.1243467], ['l', 1681414478.2661805], ['o', 1681414478.4083936]]" ) );

    printf( "\ntesting with/without shift:\n" );
    allTestsPassed &= assertEquals( 
        true, 
        verifyUser( 
"[['H', 1681414474.8164868], ['e', 1681414474.9887047], ['l', 1681414475.068764], ['l', 1681414475.2091506], ['o', 1681414475.3612146]]", 
"[['', 1681414477.7330792], ['H', 1681414477.8731878], ['e', 1681414478.0337863], ['l', 1681414478.1243467], ['l', 1681414478.2661805], ['o', 1681414478.4083936]]" ) );

    printf( "\ntesting with several invalid characters and empty strings:\n" );
    allTestsPassed &= assertEquals( 
        true, 
        verifyUser( 
"[['inv1', 1681414474.626238], ['H', 1681414474.8164868], ['e', 1681414474.9887047], ['inv2', 1681414474.9887053], ['l', 1681414475.068764], ['l', 1681414475.2091506], ['o', 1681414475.3612146]]", 

"[['', 1681414477.7330792], ['H', 1681414477.8731878], ['', 1681414477.8731900], ['e', 1681414478.0337863], ['', 1681414478.0339123], ['', 1681414478.0339999], ['l', 1681414478.1243467], ['l', 1681414478.2661805], ['o', 1681414478.4083936], ['abcdefghijklmnopqr', 1681414498.4083936]]" ) );

    printf( "\ntesting backspace immidiately following empty string:\n" );
    allTestsPassed &= assertEquals( 
        true, 
        verifyUser( 
"[['', 1681415275.8009114], ['H', 1681415275.9909139], ['e', 1681415276.183202], ['l', 1681415276.353324], ['l', 1681415276.5538523], ['l', 1681415276.7446933], ['', 1681415276.9755976], ['', 1681415277.5572484], ['\x08', 1681415279.9734032], ['o', 1681415280.3859582]]", 

"[['', 1681415283.665579], ['H', 1681415283.7754946], ['e', 1681415283.916678], ['l', 1681415284.0266845], ['l', 1681415284.1577969], ['o', 1681415284.3182552]]" ) );

    printf( "\ntesting excessive incorrect characters,\n" );
    printf( "    need reasonable processing time:\n" );
    allTestsPassed &= assertEquals( 
        false, 
        verifyUser( 
"[['h', 1682000579.0561047], ['e', 1682000579.1364262], ['l', 1682000579.2768068], ['l', 1682000579.437289], ['o', 1682000579.5882292], [' ', 1682000579.6782236], ['\x08', 1682000580.0801368], [' ', 1682000580.700954], ['w', 1682000581.0809455], ['o', 1682000581.171554], ['r', 1682000581.2415357], ['l', 1682000581.3714507], ['d', 1682000581.4521375]]", 
"[['a', 1682000868.3357854], ['a', 1682000868.9170344], ['a', 1682000868.947716], ['a', 1682000868.9777012], ['a', 1682000869.007734], ['a', 1682000869.0377486], ['a', 1682000869.0689647], ['a', 1682000869.1081364], ['a', 1682000869.138131], ['a', 1682000869.168122], ['a', 1682000869.1981087], ['a', 1682000869.2387128], ['a', 1682000869.2687027], ['a', 1682000869.2986834], ['a', 1682000869.3292542], ['a', 1682000869.3595815], ['a', 1682000869.4003181], ['a', 1682000869.430417], ['a', 1682000869.460519], ['a', 1682000869.490428], ['a', 1682000869.5209446], ['a', 1682000869.5613875], ['a', 1682000869.592179], ['a', 1682000869.622691], ['a', 1682000871.0126889], ['a', 1682000871.0427032], ['a', 1682000871.0727048], ['a', 1682000871.1134865], ['a', 1682000871.1432314], ['a', 1682000871.173589], ['a', 1682000871.213883], ['a', 1682000871.2438815], ['a', 1682000871.2742655], ['a', 1682000871.315014], ['a', 1682000871.345214], ['a', 1682000871.3754985], ['a', 1682000871.4058135], ['a', 1682000871.4363], ['a', 1682000871.4762733], ['a', 1682000871.5062912], ['a', 1682000871.5362914], ['a', 1682000871.5664477], ['a', 1682000871.5970142]]" ) );



    // test testErrors
    std::cout << "\nTest testErrors displays errors when incorrect values are given:";
    allTestsPassed &= !testErrors( 
"[[428944.64934,'a'],[428944.73761,'a'],[428944.84000,'a'],[428944.83761,''],[428944.86697,'a'],[428944.88302,'a'],[428944.90400,'a'],[428944.93121,'a']]", 
    
"[[725894.04638,'a'],[725894.04970,'a'],[725894.06244,'a'],[725894.10041,'a'],[725894.11396,'a'],[725894.14625,'a']]", 
        2.5, .432802 );




    // display test results
    if( !allTestsPassed ) 
    {
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
    std::cout << "\nTesting errors:\n";
    CharStateList oneList, otherList;
    double timeError, spellingError;
    bool passedTests = true;
    oneList = readCharStateListFromString( strOne );
    otherList = readCharStateListFromString( strTwo );
    spellingError = alignChars( oneList, otherList );
    timeError = getWeightTimeErrors( oneList, otherList );

    printf( "testing spell error:\n" );

    if( !assertDoubleEquals( expectedSpellError, spellingError ) )
    {
        std::cout << " - Spelling Error is not expected\n";
        passedTests = false;
    }

    printf( "testing time error:\n" );
    if( !assertDoubleEquals( expectedTimeError, timeError ) )
    {
        std::cout << " - Time Error is not expected\n";
        passedTests = false;
    }

    printf( "\n" );
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


