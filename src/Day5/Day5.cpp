#include "Day5.h"


struct ex5Data {
	std::map<int,std::set<int>> rules = {};
	std::vector<std::vector<int>> sequences = {};
};

int countCorrectSequence(ex5Data inputData){
	std::set<int> encounteredNumbers = {};
	bool foundError = false;
	int middleSum = 0;
	std::set<int> intersect;

	for (auto &sequence : inputData.sequences)
	{
		encounteredNumbers = {};
		foundError = false;
		for (auto &element : sequence)
		{
			encounteredNumbers.insert(element);
			auto it = inputData.rules.find(element);
			intersect.clear();
			if (it != inputData.rules.end())
			{
				std::set_intersection(
					inputData.rules[element].begin(),
					inputData.rules[element].end(),
					encounteredNumbers.begin(),
					encounteredNumbers.end(),
					std::inserter(intersect, intersect.begin()));
				if(!intersect.empty()){
					for(auto &hey: encounteredNumbers){
						std::cout << hey <<" ";
					}
					std::cout << '\n';
					for(auto &hey: inputData.rules[element]){
						std::cout << hey <<" ";
					}
					std::cout << '\n';
					for(auto &hey: intersect){
						std::cout << hey <<" ";
					}
					std::cout << '\n';
					foundError = true;
					break;
				}
			}
		}
		if(!foundError){
			middleSum += sequence[(sequence.size() - 1) / 2];
		}
	}
	return middleSum;
}

ex5Data generateData(std::vector<std::string> inputLines){
	ex5Data out;
	int key;
	int value;
	std::vector<int> sequence;
	char separator = '|';
	for (auto &line : inputLines)
	{
		if(line.find('|') != std::string::npos){
			std::istringstream stream(line);
			stream >> key >> separator >> value;
			out.rules[key].insert(value);
			// cout << key << "  " << value <<'\n';
		}
		if(line.find(',')!= std::string::npos){
			std::regex re(","); 
			std::sregex_token_iterator it(line.begin(), line.end(), re, -1);
			std::sregex_token_iterator end;
			sequence = {};
			while (it != end)
			{
				sequence.push_back(std::stoi(*it));
				// cout << std::stoi(*it) << " ";
				it++;
			}
			// cout << '\n';
			out.sequences.push_back(sequence);
		}
	}
	return out;
}

int Day5::computeEx1(std::vector<std::string> inputLines)
{
	return countCorrectSequence(generateData(inputLines));
}

int Day5::computeEx2(std::vector<std::string> inputLines) {

	return 0;
}
