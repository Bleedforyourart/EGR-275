#include <iostream>
//#include "Vehicle.cpp"
#include "Vehicle.h"
//#include "State.cpp"
#include "State.h"
//#include "Input.cpp"
#include "Input.h"
//#include "MathVector.cpp"
#include "MathVector.h"
//#include "Project2.cpp"
#include "Project2.h"
//#include "Director.cpp"
#include "Director.h"

//Be sure to adjust the input file numbers to run the program with the various input files


int main(int argc, const char * argv[]) {

  if(argc !=3){
    std::cout<<"Usage: project2 inputFile outputFile"<<std::endl;
    return -1;
  }
  Project2 project2(("inputFile1.txt"),("outputFile1.txt"));
  bool d = false;
  if(project2.readInputFile()){
  project2.run();
  }
else{}
//once input file has been inputted then write the output
project2.writeOutputFile();
return 0;
}
