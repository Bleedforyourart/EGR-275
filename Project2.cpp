#include "Project2.h"  
#include <sstream>
#include "Input.h"
#include <iomanip>
#include <iostream>
#include <math.h>

Project2::Project2(std::string inputFile, std::string outputFile)
:inFileName(inputFile), outFileName(outputFile), s0(NULL){
}

bool Project2::readInputFile(){
  d = NULL;
  bool result = false;
  std::string line;
  std::string inputLine;
  std::istringstream inLineStream(line);
  int linecount = 0;

inFile.open(inFileName);

/*Get the first three inputs from the input file
Once the inputs are received they will be printed in the terminal
//If there is an error then that will be noted in the terminal*/
if(inFile.is_open()){
  double newXPos = 0.00;
  double newYPos = 0.00;
  double newTireAngle =0.00;
  double newHeadingTheta = 0.00;

  getline(inFile, line);
  for (int i = 0; linecount < 3; i++){
    if (!line.empty()){
      inLineStream.clear();
      inLineStream.str(line);

      //Get the initial position from input file
      inLineStream >> inputLine;
      if(inputLine == "InitialPose:"){
        inLineStream >> position;
        s0 = new State();
        s0->readElements(position);
        }
      
      //Get the initial wheelbase form input file
      else if(inputLine == "Wheelbase:"){
        inLineStream >> wheelbase;
        }

      //Get the Dt from input file
      else if(inputLine == "Dt:"){
        inLineStream >> Dt;
      }

      else{
        std::cout<<"found error in first 3 lines---aborting" << std::endl;
      }
    
      getline(inFile,line);
      linecount++; 

/*Now that we have the inputs we will use the director to 
convert the inputted data to the output format
We want to make sure that there is data for the DT, wheelbase, and initials state. 
Also we need to ensure that we have read 3 lines of inputs*/
  if(Dt != 0 && wheelbase != 0 && s0 != NULL && linecount == 3 ){
    d = new Director(wheelbase, s0, Dt);
    std::vector<Input*> inputs;

    while(!line.empty()){
      Input *i = new Input();
      if(i->readElements(line)){
        inputs.push_back(i);
      }
      else{
        return result;
      }
        getline(inFile, line);
      }
      result = true;
      d->setInputs(inputs);
      }
      }
    }

  //Print the IP, WB and DT to verify that the inputs were correctly received.
  std::cout << "Initial Position: " << position  << std::endl;
  std::cout << "Wheelbase: " << wheelbase << std::endl;
  std::cout << "Dt: " << Dt << std::endl;
  }

  //If the file is unable to open then we will report an error
  else{
    std::cout << "Unable to open the file." <<std::endl;
    std::cout << "Check main.cpp and ensure line 20 has the correct input and output file name."<< std::endl;
  }
  return result;
}

Project2::~Project2(){
  bool state0=(NULL);
  if (s0){
    delete s0;
  }

  if(inFile.is_open()){
    inFile.close();
  }
}

// Call on the director to convert the inputted data into its outputted format
void Project2::run(){
  d->run();
  return;
  }

//Here is where we write our Ouput file with all of our inputs

bool Project2::writeOutputFile(){
  bool result = false;
  double time0;
  double Dt;
  double time;

  //We open our output file and then use the director to get our states/inputs
  outFile.open(outFileName);
  if(outFile.is_open()){
    if(d != NULL){
      time0 = d->getT0();
      Dt = d->getDT();
      double time = 0.000;

      std::vector<State*> outputs = d ->getStates();
      std::vector<Input*> inputs = d->getInputs();
      time = time0;

      if(outputs.size() != inputs.size()+1){
        std::cout << "Outputs should be 1 larger than inputs, unless both are empty" << std::endl;
      }
      else{
        outFile << "                      | tire  | hdng  | car   | delta" << std::endl;
        outFile << "time: | x:    | y:    | angle:| theta:| vlcty:| dot:"  << std::endl;
        unsigned i=0;
        for(i=0; i<inputs.size();i++){
          outFile << std::fixed << std::setprecision(3) << time << " , ";
          outFile << outputs[i]->toString() << " , ";
          outFile << inputs[i]->toString() << std::endl;
          time = time + Dt;
        }
        outFile << std::endl;
        outFile << "The car has stopped. Here are the final results:" << std::endl;
        outFile << "travel                   tire  | hdng" <<std::endl;
        outFile << "time:  | x:    | y:    | angle:| theta:" <<std::endl; 
        outFile << time << " , ";
        outFile << outputs[i]->toString() << std::endl;
        result = true;
      }
    }
  }
    return result;
}