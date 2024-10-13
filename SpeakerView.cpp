/*
 * Full name: Hemi Shah
 * Student ID: 2443456
 * Chapman Email: heshah@chapman.edu
 * Course number and section: CPSC-350-03
 * Assignment or exercise number: PA3: Do You See What I See?
 */

#include "SpeakerView.h"

// default constructor for SpeakerView that takes in a string parameter for the inputFile
SpeakerView::SpeakerView(std::string inputFile){
    rowCount = 0;
    p = 0;
    this->inputFile = inputFile;
}

// destructor for  SpeakerView
SpeakerView::~SpeakerView(){}

// check to see if the input file consists of N+2 lines
bool SpeakerView::checkInputFormat(){
    // variable to count the number of lines
    int lineCount = 0;
    std::string line;

    // open input file
    std::ifstream inFile(inputFile);

    // checks to see if the input file is open
    if (inFile.is_open()) {

        // iterates through the file to read each line if a line is found and increments lineCount
        while (std::getline(inFile, line)) {
            // check to see if the first line is "BEGIN"
            if (lineCount == 0){
                if (line != "BEGIN"){
                    std::cout << "first line must be BEGIN" << std::endl;
                }
            }

            // increments lineCount
            lineCount++;
        }

        // check to see if the last line is "END"
        if (line != "END"){
            std::cout << "last line must be END" << std::endl;
        }
        
        // if lineCount is greater than 2, return true; else return false
        if (lineCount > 2){
            return true;
        } else {
            std::cout << "input file is NOT valid" << std::endl;
            return false;
        }
    }

    // closes input file
    inFile.close();
}

// calculates the size of the matrix based off the input file
void SpeakerView::calculateMatrixSize() {
    std::ifstream inFile(inputFile);
    std::string line;

    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            if (line == "BEGIN") {
                // skips the BEGIN line
                continue; 
            }
            if (line == "END") {
                // stops reading once it hits the END line
                break; 
            }

            // counts the number of columns in the current line
            int currentColCount = 0;
            for (int i = 0; i < line.length(); ++i) {
                if (line[i] == ' ') {
                    // increments for each space
                    currentColCount++; 
                }
            }

            // updates the row and column counts
            rowCount++;
            // only sets p on the first row
            if (rowCount == 1) { 
                p = currentColCount;
            }
        }
    }
    inFile.close();
}

// creates and processes the matrix, and prints the results
void SpeakerView::processMatrix() {
    // creates a matrix to hold all of the input
    float** inputMatrix = new float*[rowCount];
    for (int i = 0; i < rowCount; ++i) {
        // allocates memory for columns in each row
        inputMatrix[i] = new float[p]; 
    }

    // Populate the matrix with data from input
    std::ifstream inFile(inputFile);
    std::string line;

    if (inFile.is_open()) {
        // keeps track of the current row in the matrix
        int currentRow = 0; 
        while (std::getline(inFile, line)) {
            if (line == "BEGIN") {
                // skips the BEGIN line
                continue; 
            }
            if (line == "END") {
                // stops reading once it hits the END line
                break;
            }

            // reads each value and adds it to the matrix
            // keeps track of the current column in the row
            int currentCol = 0; 
            // holds the current number being read
            std::string currentNum; 

            for (int i = 0; i < line.length(); ++i) {
                if (line[i] == ' ') {
                    // only if current number is not empty and exists to be converted
                    if (!currentNum.empty()) { 
                        // converts from a string to a float
                        inputMatrix[currentRow][currentCol] = std::stof(currentNum); 
                        currentNum = "";
                        // moves to the next column
                        currentCol++; 
                    }
                } else {
                    // add the character to currentNum if it is not a psace
                    currentNum += line[i];
                }
            }

            // adds the last number in the line
            if (!currentNum.empty()) {
                inputMatrix[currentRow][currentCol] = std::stof(currentNum);
            }

            // moves to the next row
            currentRow++; 
        }
    }

    inFile.close();

     // populates the MonoStacks from the matrix
    for (int col = 0; col < p; ++col) {
        // for decreasing monostack 
        MonoStack<float>* monoStack = new MonoStack<float>(rowCount, 'd'); 

        // pushes values into the monotonic stack from bottom to top of each column
        for (int row = rowCount - 1; row >= 0; --row) {
            monoStack->push(inputMatrix[row][col]);
        }

        int peopleCount = 0;
        // creates a string that holds the heights
        std::string heights;
        // creates a string stream object for the heights
        std::stringstream heightSS;

        /* START OF CODE FROM CHATGPT */
        // rounds the floats to a fixed decimal space of 1
        heightSS << std::fixed << std::setprecision(1);
        /* END OF CODE FROM CHAT GPT */

        while (!monoStack->isEmpty()) {
            // increments peopleCount (number of people that can see)
            peopleCount++;
            //  gets the height of the person that can see
            heightSS << monoStack->peek() << " inches";
            if (monoStack->size() > 1) {
                heightSS << ", ";
            }
            // removes the height of the person that can see
            monoStack->pop();
        }

        // converts the stringstream to a string
        heights = heightSS.str();

        // prints the final output for the column
        std::cout << "In column " << col << " there are " << peopleCount << " that can see. ";
        std::cout << "Their heights are: " << heights << "." << std::endl;

        std::cout << std::endl;

        // dealocates the monoStack
        delete monoStack;
    }

    // deallocates the matrix
    for (int i = 0; i < rowCount; ++i) {
        // deallocates each row of the matrix
        delete[] inputMatrix[i]; 
    }
    // deallocates the array of row pointers
    delete[] inputMatrix; 
}
