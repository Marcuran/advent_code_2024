#include "Day.h"

Day::Day(int dayNumber) : dayNumber(dayNumber) {
    std::ifstream ex1InFile, ex1InTestFile, ex2InFile, ex2InTestFile;

    std::string ex1OutFilePath = FOLDER + std::to_string(dayNumber) + "/out/ex1.txt";
    std::string ex2OutFilePath = FOLDER + std::to_string(dayNumber) + "/out/ex2.txt";
	ex1OutFile.open(ex1OutFilePath, std::ios::out);
	ex2OutFile.open(ex2OutFilePath, std::ios::out);
    
	std::string ex1OutTestFilePath = FOLDER + std::to_string(dayNumber) + "/out/ex1_test.txt";
    std::string ex2OutTestFilePath = FOLDER + std::to_string(dayNumber) + "/out/ex2_test.txt";
	ex1OutTestFile.open(ex1OutTestFilePath, std::ios::out);
	ex2OutTestFile.open(ex2OutTestFilePath, std::ios::out);

	std::string ex1InFilePath = FOLDER + std::to_string(dayNumber) + "/in/ex1.txt";
	std::string ex2InFilePath = FOLDER + std::to_string(dayNumber) + "/in/ex2.txt";
	ex1InFile.open(ex1InFilePath);
    ex2InFile.open(ex2InFilePath);
	
	std::string ex1InTestFilePath = FOLDER + std::to_string(dayNumber) + "/in/ex1_test.txt";
	std::string ex2InTestFilePath = FOLDER + std::to_string(dayNumber) + "/in/ex2_test.txt";
	ex1InTestFile.open(ex1InTestFilePath);
	ex2InTestFile.open(ex2InTestFilePath);

	std::string line;

    if (!ex1InFile.is_open()) {
        std::cerr << "Error opening file: " << ex1InFilePath << '\n';
    }
    if (!ex2InFile.is_open()) {
        std::cerr << "Error opening file: " << ex2InFilePath << '\n';
    }
    while (getline(ex1InFile, line)) {
        Ex1InLines.push_back(line);
    }
    while (getline(ex2InFile, line)) {
        Ex2InLines.push_back(line);
    }

    if (!ex1InTestFile.is_open()) {
        std::cerr << "Error opening file: " << ex1InTestFilePath << '\n';
    }
    if (!ex2InTestFile.is_open()) {
        std::cerr << "Error opening file: " << ex2InTestFilePath << '\n';
    }
    while (getline(ex1InTestFile, line)) {
        Ex1InTestLines.push_back(line);
    }
    while (getline(ex2InTestFile, line)) {
        Ex2InTestLines.push_back(line);
    }	

    if (!ex1OutFile.is_open()) {
        std::cerr << "Error opening file: " << ex1OutFilePath << '\n';
    }
    if (!ex2OutFile.is_open()) {
        std::cerr << "Error opening file: " << ex2OutFilePath << '\n';
    }

	if (!ex1OutTestFile.is_open()) {
        std::cerr << "Error opening file: " << ex1OutTestFilePath << '\n';
    }
    if (!ex2OutTestFile.is_open()) {
        std::cerr << "Error opening file: " << ex2OutTestFilePath << '\n';
    }
}

Day::~Day() {
    if (ex1OutFile.is_open()) {
        ex1OutFile.close();
    }
    if (ex2OutFile.is_open()) {
        ex2OutFile.close();
    }
	if (ex1OutTestFile.is_open()) {
        ex1OutTestFile.close();
    }
	if (ex2OutTestFile.is_open()) {
        ex2OutTestFile.close();
    }
}

void Day::ex1() {
    ex1OutTestFile << "Day "<< this->dayNumber << " Exercise 1 Test Output" << '\n';
    ex1OutTestFile << this->computeEx1(Ex1InTestLines) << '\n';

    ex1OutFile << "Day "<< this->dayNumber << " Exercise 1 Output" << '\n';
    ex1OutFile << this->computeEx1(Ex1InLines) << '\n';
}


void Day::ex2() {
    ex2OutTestFile << "Day "<< this->dayNumber << " Exercise 2 Test Output" << '\n';
    ex2OutTestFile << this->computeEx2(Ex2InTestLines) << '\n';
    
    ex2OutFile << "Day "<< this->dayNumber << " Exercise 2 Output" << '\n';
    ex2OutFile << this->computeEx2(Ex2InLines) << '\n';
}

