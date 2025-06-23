#include "Question.h"

Question::Question() // Definition of default constructor
	: question(""), answerOptions({}), correctIndex(0) {};

Question::Question(std::string question, const std::vector<std::string> answerOptions, const int correctIndex) // Definition of parameterized constructor
	: question(question), answerOptions(answerOptions), correctIndex(correctIndex) {};


int Question::CheckAnswer(const int answerIndex) const
{
	if (answerIndex == correctIndex + 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void Question::Print() const
{
	std::cout << question << std::endl;

	int answerSize = static_cast<int>(answerOptions.size());
	std::cout << "0.Pause the game  ";
	for (int i = 0; i < answerSize; i++) {
		std::cout << i + 1 << "." << answerOptions[i];
		std::cout << (i != answerSize - 1 ? "  " : "\n");
	}
}