//
//  MathVector.h
//

#ifndef MathVector_h
#define MathVector_h

#include <stdio.h>
#include <string.h>
#include<iostream>
#include <fstream>
#include <vector>

class MathVector {
public:
    MathVector( int numElements );
    ~MathVector( ) { }
    bool readElements(std::string str);
    // creates a csv of this vector
    std::string toString( );
protected:
    int numElements;
    std::vector<double> elements;
    std::string inputLine;
    std::string position;
    int inputCount = 0;
};

#endif /* MathVector_h */
