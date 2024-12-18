#include "Day4.h"

std::vector<std::string> convertInputDiagonal(std::vector<std::string> matrix){
	std::vector < std::string > outputLines = {};
	long unsigned int iteratorRow = 0;
	long unsigned int iteratorColumn = 0;
	long unsigned int diagonalLeftIndex = 0;
	long unsigned int diagonalRightIndex = 0;
	std::vector<std::string> diagonalLeftLines = {};
	std::vector<std::string> diagonalRightLines = {};
	int diagonalRightTempIndex = 0;

	// diagonal lines
	for(auto &line: matrix){
		iteratorColumn = 0;
		for (auto &character : line){
			diagonalRightTempIndex = iteratorColumn - iteratorRow;
			if (diagonalRightTempIndex < 0)
				diagonalRightIndex = (abs(diagonalRightTempIndex) + line.size() - 1);
			else 
				diagonalRightIndex = abs(diagonalRightTempIndex);

			if(diagonalRightLines.size() <= diagonalRightIndex){
				diagonalRightLines.push_back({character});
			}
			else{
				diagonalRightLines[diagonalRightIndex] += character;
			}

			diagonalLeftIndex = iteratorColumn + iteratorRow;
			if(diagonalLeftLines.size() <= diagonalLeftIndex){
				diagonalLeftLines.push_back({character});
			}
			else{
				diagonalLeftLines[diagonalLeftIndex] += character;
			}
			++iteratorColumn;
		}
		++iteratorRow;
	}
	diagonalLeftLines.insert(diagonalLeftLines.end(), diagonalRightLines.begin(), diagonalRightLines.end());
	return diagonalLeftLines;
}

std::vector < std::string > convertInputForEachDirection(std::vector<std::string> matrix)
{
	std::vector<std::string> outputLines = {};
	std::vector<std::string> verticalLines = {};
	long unsigned int iteratorColumn = 0;


	// horizontal lines
	for(auto &line: matrix){
		outputLines.push_back(line);
	}

	// vertical lines
	for(auto &line: matrix){
		iteratorColumn = 0;
		for (auto &character : line){
			if(verticalLines.size() <= iteratorColumn){
				verticalLines.push_back({character});
			}
			else{
				verticalLines[iteratorColumn] += character;
			}
			iteratorColumn++;
		}
	}

	

	outputLines.insert(outputLines.end(), verticalLines.begin(), verticalLines.end());
	std::vector<std::string> diagonal = convertInputDiagonal(matrix);
	outputLines.insert(outputLines.end(), diagonal.begin(), diagonal.end());
	return outputLines;
}

int countSubstrtingInString(std::vector<std::string> input){
	std::regex pattern1("XMAS");
	std::regex pattern2("SAMX");
	std::smatch matches;

	int result = 0;
	for (auto &line : input)
	{
		auto
        words_1_begin 
        = std::sregex_iterator( 
            line.begin(), 
            line.end(), 
            pattern1); 
  
    	auto words_1_end = std::sregex_iterator();
		auto
        words_2_begin 
        = std::sregex_iterator( 
            line.begin(), 
            line.end(), 
            pattern2); 
  
    	auto words_2_end = std::sregex_iterator();
		result += std::distance(words_1_begin, words_1_end) + std::distance(words_2_begin, words_2_end);
	}
	return result;
}

int countCrossMas(std::vector<std::string> matrix){
	size_t nbRows = matrix.size();
	size_t nbCols = matrix[0].size();
	std::string diagRight = "";
	std::string diagLeft = "";
	int result = 0;
	for (size_t i = 1; i < nbRows - 1; i++)
	{
		for (size_t j=1; j < nbCols-1;j++){
			if(matrix[i][j]=='A'){
				diagRight = std::string(1, matrix[i - 1][j - 1]) + matrix[i + 1][j + 1];
				diagLeft = std::string(1,matrix[i-1][j+1])+matrix[i+1][j-1];
				if ((diagRight == "MS" || diagRight == "SM") && (diagLeft == "MS" || diagLeft == "SM"))
				{
					result++;
				}
			}
		}
	}
	return result;
}

int Day4::computeEx1(std::vector<std::string> inputLines) {
	return countSubstrtingInString(convertInputForEachDirection(inputLines));
}

int Day4::computeEx2(std::vector<std::string> inputLines) {
	return countCrossMas(inputLines);

}
