#include "State.h"

State::State():MathVector(4)
{
  double newXPos = 0.0;
  double newYPos = 0.0;
  double newTireAngle = 0.0;
  double newHeadingTheta = 0.0;
}

State::State(double x, double y, double angle, double theta):MathVector(3){
  x=0.000;
  y=0.000;
  angle=0.000;
  theta=0.000;
}

State::State(const State& other):MathVector(other){
  }
// Pull the state x position
double State::getXPosition(){
  return elements.at(0); 
  }
// Set the new x position 
void State::setXPosition(double newXPos){
  elements.at(0) = newXPos;
  } 

// Pull the state  y position
double State::getYPosition(){
  return elements.at(1); 
} 
// Set the new y position
void State::setYPosition(double newYPos){
  elements.at(0) = newYPos;
  } 
// Pull the state tire angle
double State::getTireAngle(){
  return elements.at(2); 
  } 
  //set the new tire angle
void State::setTireAngle(double newTireAngle){ 
  if(newTireAngle <= -0.5236){
    this->setTireAngle(-0.5236);
  }
  else if (newTireAngle >= 0.5236){
    this->setHeadingTheta(0.5236);
  }
  else{
    elements.at(2) = newTireAngle;
  }
}
// Pull the state heading theta. 
double State::getHeadingTheta(){
  return elements.at(3); 
  } 

//set the heading theta
void State::setHeadingTheta(double newHeadingTheta){  
  elements.at(3) = newHeadingTheta; 
  while(this->getHeadingTheta() < 0){
    this->setHeadingTheta(this->getHeadingTheta() + 2*M_PI);
    }
  while(this->getHeadingTheta() > 2*M_PI){
    this->setHeadingTheta(this->getHeadingTheta() - 2*M_PI);
  }
}