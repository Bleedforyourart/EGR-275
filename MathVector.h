//
//  MathVector.h
//  You should *not* change this file

#ifndef MathVector_h
#define MathVector_h

#include <stdio.h>
#include <string>
#include <vector>

class MathVector {
public:
    // should initialize the numElements, and
    // calls resize on the elements vector
    MathVector( int numElements );
    
    // the copy constructor does piecewise copy
    // of elements and numElements
    MathVector( const MathVector& other );
    
    // NOTE: 
    // To make testing easier, only the copy constructor, NOT the
    // assignment operator or destructor, implementation is provided
    // This breaks the rule of 3, but makes the homework easier
    // MathVector& operator=(const MathVector& other);
    // ~MathVector( );
    
    // Takes a formatted string (line) from the file, and
    // inserts each of the comma-separated values into the
    // data member 'elements' of the class. Return true if
    // the elements are successfully read.
    //
    // If there are failures in reading the elements, messages
    // you should return false, and store an error msg in
    // the string value of status
    bool readElements( std::string str );
    // creates a csv of this vector
    std::string toString( );
    // get the current status msg
    std::string getStatus( ) { return status; }
    // get the numElements
    int getNumElements( ) { return numElements; }
    // get a ref to the vector of values
    std::vector<double> getElements( ) { return elements; }
protected:
    // the number of elements (given during construction)
    int numElements;
    // elements of this vector
    std::vector<double> elements;
    // is empty if no errors, holds the error msg otherwise
    std::string status;
};

#endif /* MathVector_h */
