#ifndef DAY1_H
#define DAY1_H

#include "../Day/Day.h"
#include <vector>
#include <regex>
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

class Day1 : public Day {
    public:
        Day1() : Day(1) {}
        int computeEx1(std::vector<std::string> inputLines) override;
        int computeEx2(std::vector<std::string> inputLines) override;
    private:
        std::vector<int> column1;
        std::vector<int> column2;
    };

#endif // DAY1_H
