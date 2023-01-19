#include "Vehicle.h"
#include <vector>
#include <math.h>

//Set the initial state of the vehicle
Vehicle::Vehicle():state(NULL){
  this->state = new State(0.0,0.0,0.0,0.0);
}
Vehicle::Vehicle(State s, double wheelbase):wheelbase(wheelbase){
  this->state = new State(s);
}
Vehicle::~Vehicle(){
  if(state){
    delete state;
  }
}
//Update the state of the vehicle 
State* Vehicle::update(Input *u, double ts){
  //Equation 1:
  double xposition = u->getVelocity() * cos(state->getTireAngle()) * cos(state->getHeadingTheta());
  state->setXPosition(state->getXPosition() + ts*xposition);
  //Equation 2:
  double yposition = u->getVelocity() * cos(state->getTireAngle()) * sin(state->getHeadingTheta());
  state->setYPosition(state->getYPosition() + ts*yposition);
  //Equation 3:
  double tireAngle = u->getTireAngleRate();
  state->setTireAngle(state->getTireAngle() + ts*tireAngle);
  //Equation 4:
  double headingTheta = u->getVelocity() * (1.0/wheelbase)*sin(state->getHeadingTheta());
  state->setHeadingTheta(state->getHeadingTheta() + ts*headingTheta);
  return this->state;  
}


double Vehicle::getWheelbase(){
  return this-> wheelbase;
}
State* Vehicle::getState(){
  return this->state;
}