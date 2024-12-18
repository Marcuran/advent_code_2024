#ifndef DAY2_H
#define DAY2_H

#include "../Day/Day.h"
#include <vector>
#include <regex>
#include <iostream>
#include <cmath>
#include <set>


class Day2 : public Day {
    public:
        Day2() : Day(2) {}
	    int computeEx1(std::vector<std::string> inputLines) override;
        int computeEx2(std::vector<std::string> inputLines) override;
    private:
        std::vector<std::vector<int>> input = {};
};

#endif // DAY2_H
