//
//  State.h
//
#ifndef State_h
#define State_h

#include <stdio.h>
#include "MathVector.h"
#include <cmath>
#include <math.h>
#define _USE_MATH_DEFINES

//Per the guidelines the tire angle deltas are defined here
#define DELTA_MAX 0.5236
#define DELTA_MIN -0.5236
#define HEADING_MIN 0
#define HEADING_MAX (2*M_PI)

class State : public MathVector {
private:
    double newXPos;
    double newYPos;
    double newTireAngle;
    double newHeadingTheta;
    double s0;
    double state0 = 1.000;
    double Dt = 0.1;
    double L;
    bool good;
    double time0 = 0.000;
public:
    State( );
    State( double x, double y, double angle, double theta );
    ~State( ) { }
    State( const State& other );
    double getXPosition( );
    double getYPosition( );
    double getTireAngle( );
    double getHeadingTheta( );
    void setXPosition(double newXPosition);
    void setYPosition(double newYPosition);
    void setTireAngle(double newTireAngle);
    void setHeadingTheta(double newHeadingTheta);
};

#endif /* State_h */
