#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

#include "GameScreens.h"
#include "GameState.h"
#include "Question.h"

int GameLoop(GameState& State)
{
	State.isActive = true;

	while (State.currentIndex < State.Questions.size()) {		
		int answer;

		State.Questions[State.currentIndex].Print();
		std::cout << "Your answer (0 to pause): ";
		std::cin >> answer;
		std::cout << std::endl;

		if (answer == 0) {
			std::cout << "Game paused\n";

			return 0; // Return to the main menu
		}

		if (State.Questions[State.currentIndex].CheckAnswer(answer)) {
			State.score += 10;
			std::cout << "It's correct!" << std::endl;
		}
		else {
			std::cout << "Sorry, it's wrong!" << std::endl;
		}

		State.currentIndex++;
	}

	std::cout << "Your score is: " << State.score << std::endl;
	State.isActive = false;

	return 1;
}