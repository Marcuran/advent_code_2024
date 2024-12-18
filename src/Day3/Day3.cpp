#include "Day3.h"

std::vector<std::vector<int>> extractMultiplications(std::vector<std::string> inputLines){
	std::vector<std::vector<int>> output = {};
	std::regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");
	std::smatch matches;
	for(auto &line: inputLines){
		std::regex_iterator<std::string::iterator> rit(line.begin(),line.end(),pattern);
		std::regex_iterator<std::string::iterator> rend;
		while(rit != rend){
			output.push_back({stoi((*rit)[1].str()),stoi((*rit)[2].str())});
			++rit; // Move to the next match
		}
	}
	
	return output;
}

std::vector<std::vector<int>> extractMultiplicationsEx2(std::vector<std::string> inputLines){
	std::vector<std::vector<int>> output = {};
	std::vector<std::vector<int>> muls = {};
	std::string activatingDelimiter = "do()";
	std::string deactivatingDelimiter = "don't()";
	std::string substring = "";
	size_t pos = 0; // Tracks the current position in the string
	size_t endPos = 0;
	size_t startPos = 0;
	bool doMul = true;
	for (auto &line : inputLines){
		pos = 0;
		while (pos < line.length())
		{
			if (doMul)
			{
				endPos = line.find(deactivatingDelimiter, pos);
				if (endPos == std::string::npos)
				{
					substring = line.substr(pos);
					pos = line.length();
				}
				else{
					substring = line.substr(pos, endPos - pos);
					pos = endPos + deactivatingDelimiter.length();
					doMul = false;
				}
				muls = extractMultiplications({substring});
				output.insert(output.end(), muls.begin(), muls.end());
			}
			else{
				startPos = line.find(activatingDelimiter,pos);
				if (startPos == std::string::npos){
					pos = line.length();
				}
				else{
					doMul = true;
					pos = startPos + activatingDelimiter.length();
				}
			}
		}
	}
	return output;
}

int day3Compute(std::vector<std::vector<int>> input){
	int result = 0;
	for (auto &multiplicationElements : input){
		result += multiplicationElements[0] * multiplicationElements[1];
	}
	return result;
}

int Day3::computeEx1(std::vector<std::string> inputLines) {
	return day3Compute(extractMultiplications(inputLines));
}

int Day3::computeEx2(std::vector<std::string> inputLines) {
	return day3Compute(extractMultiplicationsEx2(inputLines));
}
