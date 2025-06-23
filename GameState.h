#pragma once

#include <vector>
#include "Question.h"

struct GameState {
	std::vector<Question> Questions;
	int currentIndex = 0;
	int score = 0;
	bool isActive = false;
};