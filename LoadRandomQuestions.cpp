#include "Question.h"
#include <random>

std::vector<Question> LoadRandomQuestions(int amountOfQuestions)
{
	std::uniform_int_distribution<> distr(1, amountOfQuestions);

	std::vector<int> randomNumbers;
	for (int i = 0; i < 20; i++) {
		randomNumbers.push_back(i + 1);
	}

	std::random_device rd;
	std::mt19937 gen(rd());

	std::shuffle(randomNumbers.begin(), randomNumbers.end(), gen);

	randomNumbers.resize(amountOfQuestions);

	// Get random questions into a list
	std::vector<Question> Questions;
	std::vector<std::string> randomIDs;
	for (int i = 0; i < amountOfQuestions; i++) {
		randomIDs.push_back("###" + std::to_string(randomNumbers[i]));
	}
	for (int i = 0; i < amountOfQuestions; i++) {
		Question question = GetQuestionById("Database\\questionDB.txt", randomIDs[i]);
		Questions.push_back(question);
	}

	return Questions;
}