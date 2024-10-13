# Do-You-See-What-I-See?
A C++ program that calculates which audience members can see a speaker by processing seating heights with a monotonic stack, simulating visibility in a column-wise arrangement.

## Identifying Information: 
1. Full name: Hemi Shah
2. Student ID: 2443456
3. Chapman Email: heshah@chapman.edu
4. Course number and section: CPSC-350-03
5. Assignment or exercise number: PA3: Do You See What I See?

## Project Description
This project demonstrates my proficiency in C++ and algorithmic problem solving, with a focus on custom data structures like monotonic stacks.
The program processes audience seating heights from a text file and computes how many people in each column have an unobstructed view of the speaker.
Using a monotonic stack for efficient visibility calculations, the project simulates real-world seating arrangements and ensures the solution adheres to 
strict coding guidelines, including avoiding non-primitive data structures. The objective is to output clear results describing which audience members can 
see the speaker, based on their heights, for each column in the seating arrangement.

## Key Features
- Monotonic Stack Implementation: A custom templated MonoStack class supporting both increasing and decreasing stacks.
- Column-wise Visibility Calculation: Determines how many people in each column can see the speaker based on their heights.
- File Input Processing: Reads audience seating heights from a plain text file with structured input.
- Object-Oriented Design: Implements a SpeakerView class with modular, maintainable code.
- Command Line Interface: Takes input file name as a command line argument for processing.


## Files
1. input.txt
2. Main.cpp
3. main.exe
4. MonoStack.h
5. SpeakerView.cpp
6. SpeakerView.h
7. TStack.h
8. README.md

## Known Error 
- There are no known errors in this program.

## References
- Utilized TStack.h file from class lecture
- Used Chat GPT to learn how to use std::fixed and std::setprecision using iomanip and sstream

## Running Instructions
- To compile:     g++ *.cpp -o ./main.exe
- To run:         ./main.exe input.txt
