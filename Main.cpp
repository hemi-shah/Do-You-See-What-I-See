/*
 * Full name: Hemi Shah
 * Student ID: 2443456
 * Chapman Email: heshah@chapman.edu
 * Course number and section: CPSC-350-03
 * Assignment or exercise number: PA3: Do You See What I See?
 */

#include <iostream>
#include "SpeakerView.h"

int main(int argc, char* argv[]){
    // checks to see if the argument count is not 3 and returns 1 if true
    if (argc != 2){
        return 1;
    }

    // creates a speakerView object that takes a command line arguement as input
    SpeakerView speakerView(argv[1]);

    // calls all of the speakerView methods
    speakerView.checkInputFormat();
    speakerView.calculateMatrixSize();
    speakerView.processMatrix();

    return 0;
}