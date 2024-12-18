#include "Day1.h"

// Comparator function
bool comp(int a, int b) {
    return a >= b;
}

Matrix<int, 2,Dynamic> read_columns(std::vector<std::string> lines){
    Matrix<int,2,Dynamic> out {};
    int row = 0;
    int col = 0;
    std::regex del("\\s+"); // Regex for one or more spaces
    for (auto &s : lines){
        std::sregex_token_iterator it(s.begin(), s.end(), del, -1);
        std::sregex_token_iterator end;
        row = 0;
        out.conservativeResize(Eigen::NoChange, out.cols() + 1);
        while (it != end)
        {
            int val = (stoi(*it));
            
            out(row, col) = val;
            ++row;
            ++it;
        }
        ++col;
    }
    return out;
}

int Day1::computeEx1(std::vector<std::string> inputLines) {
    Matrix<int, 2, Dynamic> in = read_columns(inputLines);
    for (int i = 0; i < in.cols(); ++i) {
        column1.push_back(in(0,i));  // First row
        column2.push_back(in(1,i));  // Second row
    }
    std::sort(column1.begin(), column1.end(), comp);    
    std::sort(column2.begin(), column2.end(), comp);
    int result = 0;
    for (size_t i = 0; i < column1.size(); i++){
        result += abs(column1[i] - column2[i]);
    }

    return result;
}

int Day1::computeEx2(std::vector<std::string> inputLines) {
    Matrix<int, 2, Dynamic> in = read_columns(inputLines);
    std::map<int, int> col2 = {};
    for (int i = 0; i < in.cols(); ++i) {
        column1.push_back(in(0,i));  // First row
        col2[in(1,i)]++;
    }
    int result = 0;
    for (auto &s : column1){
        result += s * col2[s];
    }
    return result;
}
