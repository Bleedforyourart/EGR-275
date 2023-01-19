// project3
// main.cpp
// You should change this file per the project instructions

#include <iostream>
#include <string>
#include "MathVectorTest.h"

int main(int argc, const char * argv[]) {
    
    /* Test Case 1: Usage Statement */
    if (argc > 1){
        std::cout << "Usage: ./project3" << std::endl;
        return EXIT_FAILURE;
    }

    /* call the test function 
       do not edit the below three lines */
    MathVectorTest tester;
    tester.runTests( );
    std::string result = tester.getTestResultsString( );
    /* end calling the test function */
    
    /* add your own code to print the result to the stdout */
    std::cout << result << std::endl;
    
    return EXIT_SUCCESS;
}

