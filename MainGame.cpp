#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "GameScreens.h"
#include "Question.h"

int main()
{
	GameState State; // Tooks the game state info

	// Main Menu
	bool running = true;
	while (running)
	{
		int choice;
		std::cout << "Welcome to the Quiz Game!\n";
		std::cout << "1. Sart Game\n";
		std::cout << "2. Resume Game\n";
		std::cout << "3. Help\n";
		std::cout << "4. Exit\n";
		std::cout << "Enter your choice\n";
		std::cin >> choice;

		switch (choice) {
		case 1:
			State = GameState(); // Reset the state

			int amountOfQuestions;
			std::cout << "How many questions you want to answer? ";
			std::cin >> amountOfQuestions;
			State.Questions = LoadRandomQuestions(amountOfQuestions);

			GameLoop(State);

			break;
		case 2:
			if (State.isActive) {
				GameLoop(State);
			}
			else {
				std::cout << "No paused game to resume. \n";
			}

			break;
		case 3:
			std::cout << "This is a quiz game. Choose the correct option to score points";

			break;
		case 4:
			std::cout << "Exiting. Goodbye!";
			running = false;
			
			break;
		default:
			std::cout << "Invalid choice";

			break;
		}
	}

	return 0;
}