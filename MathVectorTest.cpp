//
//  MathVectorTest.cpp
//  You WILL need to change this file.
//  Provide implementations for runTests and readElementsTest that exercise the
//    class (as well as implementations for any other methods you create).

#include "MathVectorTest.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

MathVectorTest::MathVectorTest( ){
   // you will need to implement the constructor or 
   // else your initializations may be wrong
  this->constructor = false;
  this->readElements = false;
  this->toString = false;   
} 

void MathVectorTest::runTests() {
   // call your own methds---as many as you like, or arrange tests as you like
  
 //---------------------------Start of constructor tests---------------------------------//
  //There are three tests that check if the numElements equals the vector elements size. 
  //If they are equal then constructor stays true and if it fails it goes false.

//-------------Test Case 4: Too many-------------//
constructor = true;
    MathVector consTest1(0);
  if (consTest1.getNumElements() == consTest1.getElements().size() == 3){
    }
    else{
    constructor = false;
  }
  //-------------Test Case 5: Four element input--------------//
    if(constructor == true){
      MathVector consTest3(4);
      if(consTest3.getNumElements() == consTest3.getElements().size()){
    }
      else{
        constructor = false;
        }
  }
    //-------------Test Case 6: Two element input--------------//
    if (constructor == true){
    MathVector consTest2(2);
    if (consTest2.getNumElements() == consTest2.getElements().size()){
    }
    else{
      constructor=false;
    }
  }
//--------------------------End of the constructor tests---------------------------//
  
 //-------------------------Start of readElements tests----------------------------//
readElements = true;
  
//-------------Test Case 4: Too many--------------------------//
  if(readElements){
    readElements = readElementsTest(2, "1.0,0.2,-1", "Unable to read line [1.0,0.2,-1] (more than 2 elements)");
        this->readElements=false;
    }
  
  //-------------Test Case 5: Four element input--------------//
  if(readElements){
    readElements = readElementsTest(4, "0,0,0,0", "");
    this->readElements=true;
    }

  //-------------Test Case 6: Two element input--------------//
    if(readElements){
    readElements = readElementsTest(2, "0,0", "");
    this->readElements=true;
    }
//---------------Test Case 7: Non-numerical elements---------//
  if(readElements){
    this->readElements = readElementsTest(2, "0.1,0.a0", "Unable to read element 1 of [0.1,0.a0] (expected 2 elements)");
    }
  else{
    this->readElements=false;
    }

  //---------------Test Case 8:Copy of Non-numerical elements---------//
    if(readElements){
    this->readElements = readElementsTest(4, "0.1,0.0,0.0,0a.0", "Unable to read element 3 of [0.1,0.0,0.0,0a.0] (expected 4 elements)");
    }
  else{
    this->readElements=false;
    }

  //---------------Test Case 9:Missing numerical elements---------//
  if(readElements){
    readElements = readElementsTest(4, "0.1,0.0,", "Unable to read element 2 of [0.1,0.0,] (expected 4 elements)");
    }
  else{
    this->readElements=false;
    }

  //---------------Test Case 10:Missing numerical elements v2------//
  if(readElements){
    readElements = readElementsTest(4, "0.1,0.0,0.0,", "Unable to read element 3 of [0.1,0.0,0.0,] (expected 4 elements)");
    }
  else{
    this->readElements=false;
    }

   //---------------Test Case 11:Missing numerical elements v3------//
  if(readElements){
    readElements = readElementsTest(4, "0.1,0.0,0.0", "Unable to read element 2 of [0.1,0.0,0.0] (expected 4 elements)");
    }
  else{
    this->readElements=false;
    }

   //---------------Test Case 12:Returns false for wrong input------//
  if(readElements){
    readElements = readElementsTest(4, "0.1,0.0,0.0,0.0", "Unable to read element 2 of [0.1,0.0,0.0] (expected 4 elements)");
    }
  else{
    this->readElements=false;
    }
  //-------------------------End of the readElements tests----------------------------//
  
  toString = true;
  
  return;
}

bool MathVectorTest::readElementsTest( int numElements, std::string elementsString, std::string statusString ){

    bool result = false;
    
    MathVector tester(numElements);
  
    tester.readElements(elementsString);
    std::string status = tester.getStatus();

  //-------------------------Start of the toString tests----------------------------//
  if (statusString == status){
    result = true;
  }
  else{
  std::cout << "The status output was: " << "\"" << status << "\"" << " , however, it should have been: " << "\"" << statusString << "\"" << std::endl;
    }
   return result;
}
//---------------------------End of the toString tests------------------------------//

std::string MathVectorTest::getTestResultsString() {
   std::stringstream str;
//Test Case 2: Start lines
    str << "Beginning tests."<< std::endl;
    if (!constructor){
      str << "   UNIT TEST FAILED: Constructor" << std::endl;
    }
  if (!readElements){
      str << "   UNIT TEST FAILED: readElements" << std::endl;
    }
  if (!toString){
      str << "   UNIT TEST FAILED: toString" << std::endl;
    }

  //Test Case 3: End lings
  str << "Tests complete.";

    return str.str( );
}

