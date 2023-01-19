//
//  MathVectorTest.h
//  sprinkjm_project3
//
//  Created by Jonathan Sprinkle on 10/28/19.
//  Copyright © 2019 Jonathan Sprinkle. All rights reserved.
// 
//  You can change this file to add as many methods as you like
//  to make your testing easier


#ifndef MathVectorTest_h
#define MathVectorTest_h

#include <stdio.h>

#include "MathVector.h"

class MathVectorTest {
public:
    // You should initialize through the constructor
    MathVectorTest( );
    // call this to run the tests
    void runTests( );
    // once tests have run, get the string of results to print out
    std::string getTestResultsString( );
    // you can create as many methods as you like to
    // determine success or failure of methods as below, but
    // at least readElementsTest must be tested
    
    // This method should test whether an elements string is
    // correctly read in. 
    // In this method, create a new MathVector using the
    // first two parameters, and confirm whether the error
    // string you get matches what is passed in. Return true
    // if the error strings match, and false if not. You may
    // need to do other things, like confirm the value of each
    // element, for advanced testing.
    //
    // The arguments correspond to:
    // ** numElements -- expected elements in the elementsString
    // ** elementsString -- what should be passed to readElements
    // ** statusString -- what should be in status afte readElements
    // the return value should be true if statusString matches, and
    // the return value should be false if statusString does not match
    // NOTE: this method will be called on unit tests that test your
    // program for correctness
    bool readElementsTest( int numElements, 
                           std::string elementsString,
                           std::string statusString);

protected:
    bool constructor;
    bool readElements;
    bool toString;
};

#endif /* MathVectorTest_h */
