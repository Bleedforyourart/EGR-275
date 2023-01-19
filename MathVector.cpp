#include "MathVector.h"
#include <sstream>
#include <iomanip>
#include <iostream>

MathVector::MathVector( int numElements ): numElements( numElements ){
  this->elements.resize(numElements);  
}

//readElements will be called in order to read the elements on the input file
bool MathVector::readElements(std::string str){
  int inputCount = 0;
  int i = 0;

    std::istringstream input;
    input.str(str);
    char dummyChar = ' ';
    
    //this for loop is to read the initial position, wheelbase and dt
    for(int i=0; i < numElements-1 ;i++){
      if(input.good()){
        input >> elements[i] >> dummyChar;
        inputCount++;
        //**Unit test for all  the inputs:**//
        //std::cout<<elements.at(i) <<std::endl
        //std::cout<<elements[i]<<std::endl;
        //std::cout<<inputCount<<std::endl;
      }
      if(input.fail()){
        std::cout << "Unable to read element " << inputCount << " of [" << str << "] (expected " << numElements <<" elements)";
      return false;
      }
    }

    //this reads the 2 input values in the input file
    if(input.good()){
      input >> elements[numElements-1];
      //**Unit test for all  the inputs:**//
        //std::cout<<elements.at(i) <<std::endl
        //std::cout<<elements[i]<<std::endl;
        //std::cout<<inputCount<<std::endl;
    }
    if(input.fail()){
      std::cout << "Unable to read element " << inputCount << " of [" << str << "] (expected " << numElements <<" elements)";
      return false;
    }
    //if there is more than 2 elements read in the velocity or delta dot lines than the following line is printed
    if(!input.eof()){
      std::cout << "Unable to read line [" << str << "] (more than " << numElements << " elements)";
      return false;
    }
    return true;
  }

//this is where the mathvector converts all the inputs to a string 
//they are seperated by a comma and are set at precision 3
std::string MathVector::toString( ) { 
  std::stringstream result;
  
  for (int i = 0; i < numElements - 1; i++){
    result << std::fixed << std:: setprecision(3) << elements[i] << " , ";
  }
  result << elements[numElements-1];
  return result.str();

  }