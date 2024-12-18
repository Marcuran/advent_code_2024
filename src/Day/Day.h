#ifndef DAY_H
#define DAY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string FOLDER = "src/Day";

class Day
{
public:
    int dayNumber;
    std::fstream ex1OutFile, ex1OutTestFile, ex2OutFile, ex2OutTestFile;
    std::vector<std::string> Ex1InLines, Ex2InLines, Ex1InTestLines, Ex2InTestLines;

    Day(int dayNumber); // Constructor declaration
	virtual ~Day();     // Destructor declaration (optional but recommended for cleanup)
    
	void ex1();
    virtual int computeEx1(std::vector<std::string> inputLines) = 0;
    void ex2();
    virtual int computeEx2(std::vector<std::string> inputLines) = 0;
};

#endif // DAY_H
