//
//  Input.h
//

#ifndef Input_h
#define Input_h

#include <stdio.h>
#include "MathVector.h"

class Input : public MathVector {
public:
    Input( );
    Input(double velocity, double anglerate);
    ~Input( ) { }
    Input( const Input& other );
    double getVelocity( );
    double getTireAngleRate( );
};

#endif /* Input_h */
