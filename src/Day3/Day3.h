#ifndef DAY3_H
#define DAY3_H

#include "../Day/Day.h"
#include <regex>
#include <string>
#include <iostream>

class Day3 : public Day {
    public:
        Day3() : Day(3) {}
	    int computeEx1(std::vector<std::string> inputLines) override;
        int computeEx2(std::vector<std::string> inputLines) override;
};
#endif // DAY3_H
