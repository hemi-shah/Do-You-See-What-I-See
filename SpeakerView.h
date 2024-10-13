/*
 * Full name: Hemi Shah
 * Student ID: 2443456
 * Chapman Email: heshah@chapman.edu
 * Course number and section: CPSC-350-03
 * Assignment or exercise number: PA3: Do You See What I See?
 */

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "MonoStack.h"

class SpeakerView{
    public:
    SpeakerView(std::string inputFile);
    ~SpeakerView();

    // member variables
    int rowCount;
    int p;
    std::string inputFile;
    
    // helper functions
    bool checkInputFormat(); // check to see if the input file consists of N+2 lines
    void calculateMatrixSize(); // calculates the size of the matrix based off the input file

    // interface
    void processMatrix(); // creates and processes the matrix, and prints the results

    private:

};

#endif