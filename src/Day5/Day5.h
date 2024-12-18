#ifndef DAY5_H
#define DAY5_H

#include "../Day/Day.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <regex>
#include <set>
#include <algorithm>

class Day5 : public Day {
    public:
        Day5() : Day(5) {}  // Use the base class constructor
	    int computeEx1(std::vector<std::string> inputLines) override; // Override for specific behavior
        int computeEx2(std::vector<std::string> inputLines) override; // Override for specific behavior
};

#endif // DAY4_H
