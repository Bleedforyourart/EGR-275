#include "Input.h"

Input::Input():MathVector(2){}

//Here we are getting the velocity and anglerate from the inputfile and assing them to a vector
Input::Input(double velocity, double anglerate):MathVector(2){
  velocity = 0;
  elements.at(0) = velocity;
  anglerate = 0;
  elements.at(1) = anglerate;
}

Input::Input(const Input& other):MathVector(other){
  }
//Creating a getter for tire angle rate in order to calculate x,y,and tire angle
double Input::getTireAngleRate(){return elements.at(1);}

//Creating a getter for the velocity in order to calculate x, y, tire angle and headingtheta
double Input::getVelocity(){return elements.at(0);}