#ifndef DAY4_H
#define DAY4_H

#include "../Day/Day.h"
#include <vector>
#include <regex>
#include <iostream>

class Day4 : public Day {
    public:
        Day4() : Day(4) {}
	    int computeEx1(std::vector<std::string> inputLines) override;
        int computeEx2(std::vector<std::string> inputLines) override;
};

#endif // DAY4_H
