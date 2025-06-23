#pragma once

#include <iostream>
#include <string>
#include <vector>

class Question
{
public:
	std::string question;
	std::vector<std::string> answerOptions;
	int correctIndex;

	Question(); // Default constructor
	Question(const std::string question, const std::vector<std::string> answerOptions, const int correctIndex); // Parameterized constructor

	int CheckAnswer(const int answerIndex) const;
	void Print() const;
};

Question GetQuestionById(const std::string& filename, const std::string& idTag);
std::vector<Question> LoadRandomQuestions(int amountOfQuestions);