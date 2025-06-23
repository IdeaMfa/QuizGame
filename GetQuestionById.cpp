#include "Question.h"

#include <fstream>

Question GetQuestionById(const std::string& filename, const std::string& IdTag)
{
	// Needed variables and lists
	std::ifstream ReadFile(filename);
	Question result;
	std::string questionText;
	std::string answerLine;
	std::vector<std::string> partsOfAnswerLine;

	if (!ReadFile.is_open()) {
		std::cerr << "Error: Couldn't open file: " << filename << std::endl;
		return Question(); // or handle the error appropriately
	}

	// Find the corresponding section in db and take data into variables
	std::string line;
	while (std::getline(ReadFile, line)) {
		if (line.find(IdTag) == 0) {
			questionText = line.substr(IdTag.size());

			std::getline(ReadFile, answerLine);

			break;
		}
	}

	// Parse line of answer options and put them into list
	std::string answerOption = "";
	for (int i = 0; i < answerLine.size(); i++) {
		if (answerLine[i] != '_') {
			answerOption += answerLine[i];
		}
		else {
			partsOfAnswerLine.push_back(answerOption);
			answerOption = "";
		}
	}
	partsOfAnswerLine.push_back(answerOption);

	// Put data into the object
	result.question = questionText;
	for (int i = 0; i < partsOfAnswerLine.size() - 1; i++) {
		result.answerOptions.push_back(partsOfAnswerLine[i]);
	}
	result.correctIndex = std::stoi(partsOfAnswerLine[partsOfAnswerLine.size() - 1].substr(2));

	return result;
}