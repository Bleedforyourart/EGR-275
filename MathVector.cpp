//
//  MathVector.cpp
//  Adapted from project2 solution
//  *You should not* change this file for submission, but
//  -- when doing the optional followup, I encourage you to 
//     change this file to see whether you detect the errors
//     through your unit tests that you write.

#include "MathVector.h"
#include <sstream>
#include <iostream>
#include <iomanip>

// should initialize the numElements, and
// calls resize on the elements vector
MathVector::MathVector( int numElements )
: numElements( numElements )
{
    this->elements.resize(numElements);
}

// Takes a formatted string (line) from the file, and
// inserts each of the comma-separated values into the
// data member 'elements' of the class. Return true if
// the elements are successfully read.
//
// If there are failures in reading the elements, messages
// you should return false and put an error message in the
// status field
bool MathVector::readElements(std::string str)
{
    int i=0;
    std::stringstream error;
    try {
        
    // turn the str into a strstring
    std::istringstream elems;
    elems.str(str);
    // we will store parsed numbers in here
    std::string number;
    // we should have n elements, do the n-1 of them here
    for( i=0; i< numElements-1; i++ )
    {
        // get to the next comma
        std::getline(elems,number,',');
        // if we find a word followed by a comma:
        if(elems.good())
        {
            // turn the word (hopefully a number) into an istringstream
            std::istringstream numberStr(number);
            // read the string into a double element of this vector
            numberStr >> elements[i];
            // was it really a double? We'll find out now:
            if( !numberStr.eof( ) || numberStr.fail())
            {
                // OPTIONAL: what happens if you comment out the throw here?
                // Does your unit test detect something is wrong, or not?
                
                // oops: either not a number or failed for another reason
                throw new std::exception( );
            }
            // reset the text to avoid carrying forward data to another loop
            number="";
        }
        else
        {
            // throw an exception if no comma found
            throw new std::exception( );
        }
    }
        // if we find another comma, there are too many elements
        if( std::getline(elems,number,',').good() ) {
            error << "Unable to read line [" << str << "] (more than " << numElements << " elements)";
            status = error.str( );
            return false;
        }

        // now do the last one; should be just a number
        if( std::getline(elems,number).eof() ) {
            std::istringstream numberStr(number);
            numberStr >> elements[numElements-1];
            // this means it wasn't a number
            if( !numberStr.eof( ) || numberStr.fail() )
            {
               // OPTIONAL: which tests fail if you comment out this line?
                throw new std::exception( );
            }
        }
        // this means there are still lines left: not a good sign
        if( !elems.eof( ) )
        {
            // OPTIONAL: which tests fail if you comment out this line?
            throw new std::exception( );
        }
    }
    catch( ... )
    {
        error << "Unable to read element " << i << " of [" << str << "] (expected " << numElements << " elements)";
        status = error.str( );
        return false;
    }
    return true;

}

// produces the csv output for the vector, which should have
// commas between each number with precision set to 3
std::string MathVector::toString( )
{
    std::stringstream result;
    for( int i=0; i< numElements-1; i++ )
    {
        result << std::fixed << std::setprecision(3) << elements[i] << ",";
    }
    result << elements[numElements-1];
    return result.str( );
}

// the copy constructor does piecewise copy
// of elements and numElements
MathVector::MathVector( const MathVector& other )
{
    numElements = other.numElements;
    elements = other.elements;
}

