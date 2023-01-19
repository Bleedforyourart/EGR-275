#ifndef Director_h
#define Director_h

#include <stdio.h>
#include <string>
#include "State.h"
#include "Vehicle.h"
#include "Input.h"

class Director{
  public:
    Director(double L, State* s0, double Dt);
    ~Director();
    bool run();
    void setInputs( std::vector<Input*> inputs){
        this->inputs = inputs;
    }
    std::vector<Input*> getInputs() const {
      return inputs;
    }
    std::vector<State*> getStates() const {
      return states;
    }
    double getStateInitial() const{
      return this->stateInitial;
    }
    double getT0() const {
      return this->time0;
    }
    double getDT() const {
      return this->Dt;
    }
    bool isGood(){
      return good;
    }
    private:
      std::vector<State*> states;
      std::vector<Input*> inputs;
      Vehicle* vehicle;
      double Dt = 0.1;
      double L;
      bool good;
      double time0 = 0.000;
      double stateInitial = 1.000;
};
#endif
