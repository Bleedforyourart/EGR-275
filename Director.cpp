#include "Director.h"
#include <iostream>
#include <fstream>

//The director file is used to set and get inputs from the input files
//By doing this it converts all the inputted ata into the outputted format

Director::Director(double L , State* s0, double Dt): 
states(), inputs(), vehicle(NULL), Dt(Dt), L(L), good(false), stateInitial(1.000), time0(0.000){
    states.push_back(s0);
    vehicle = new Vehicle(*s0, L);
}
//this runs the director and sets each input in the state
bool Director::run(){
  bool result = false;
  double time0 = 0.000;

  for(unsigned i=0; i<inputs.size(); i++){
    State *state = new State();
    State *newState = vehicle->update(inputs[i]);

    //set the x position with the new state x position
    state->setXPosition(newState->getXPosition());

    //set the y position with the new state y position
    state->setYPosition(newState->getYPosition());

    //set the tire angle with the new state tire angle
    state->setTireAngle(newState->getTireAngle());

    //set the heading theta with the new state heading theta
    state->setHeadingTheta(newState->getHeadingTheta());

    states.push_back(state);
  }
  return result;
}
