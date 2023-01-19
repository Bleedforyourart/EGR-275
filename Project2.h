
#pragma once
#include <stdio.h>
#include<iostream>
#include <fstream>
#include "State.h"
#include "Director.h"

#ifndef Project2_h
#define Project2_h

class Project2{
public:
  Project2(std::string inFile, std::string outFile);
  ~Project2();
  bool readInputFile();
  void run();
  bool writeOutputFile();
  std::string toString();
protected:
  std::ifstream inFile;
  std::ofstream outFile;
  std::string inFileName;
  std::string outFileName;
  std::string inputLine;
  std::string position;
  State* s0;
  double wheelbase;
  double Dt = 0.1;
  double time0 = 0.000;
  double time;
  Director *d;
};
#endif