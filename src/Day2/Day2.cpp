#include "Day2.h"
std::set<int>  ACCEPTABLE_ABSOULUTE_JUMPS = {1, 2, 3};

std::vector<std::vector<int>> transformStringVectorToIntVectorVector(std::vector<std::string> inStringVector){
    std::vector<std::vector<int>> outIntVector = {};
    std::regex del("\\s+"); // Regex for one or more spaces
    std::vector<int> outLine = {};
    for (auto &s : inStringVector){
        std::sregex_token_iterator it(s.begin(), s.end(), del, -1);
        std::sregex_token_iterator end;
        outLine = {};
        while (it != end){
            int val = (stoi(*it));
            outLine.push_back(val);
            ++it;
        }
        outIntVector.push_back(outLine);
    }
    return outIntVector;
}

bool checkLineSafety(std::vector<int> line){
    bool direction;
    if(line.size()<1){
        if(line.size()==1) return true;
    }
    direction = std::signbit(line[1] - line[0]);
    long unsigned int i = 0;
    int diff = 0;
    while (line.size() > (i + 1))
    {
        diff = line[i + 1] - line[i];
        if(direction != std::signbit(diff) || ACCEPTABLE_ABSOULUTE_JUMPS.find(abs(diff)) == ACCEPTABLE_ABSOULUTE_JUMPS.end()){
            return false;
        }
        i++;
    }
    return true;
}

int Day2::computeEx1(std::vector<std::string> inputLines){
    int result = 0;
    for (auto &line : transformStringVectorToIntVectorVector(inputLines))
    {
        if(checkLineSafety(line)) ++result;
    }
    return result;
}

int Day2::computeEx2(std::vector<std::string> inputLines){
    int result = 0;
    int column = 0;
    for(auto &line : transformStringVectorToIntVectorVector(inputLines))
    {
        if (checkLineSafety(line))
            ++result;
        else{
            column = line.size();
            while (column > 0)
            {
                std::vector<int> subVector(line);
                subVector.erase(subVector.begin()+column-1);
                // for(auto &elem : subVector) cout << elem << " ";
                // cout << endl;
                if (checkLineSafety(subVector))
                {
                    result++;
                    // cout << "worked !" << endl;
                    break;
                }
                column--;
            }
        }
    }
    return result;
}