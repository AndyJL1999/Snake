// ConsoleSnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <thread>
#include "Game.h"

void gameLoop(Game game, Snake snake)
{
	using namespace std::literals::chrono_literals;
	while (game.playing)
	{
		system("cls");

		std::cout << "\ta: Left | d: Right | w: Up | s: Down | x: Quit\n";
		game.play(snake);

		std::this_thread::sleep_for(0.1s);
	}
}
int main()
{
	srand(time(NULL));

	char choice;
	bool tryAgain = true;

	while (tryAgain)
	{
		std::cout << "\t\t\t\t\tDo you want to play Snake?(Y/N)\n";
		try {
			std::cin >> choice;
			if (choice != 'y' && choice != 'n')
			{
				throw choice;
			}
			else if(choice == 'n')
			{
				std::cout << "Good bye!\n";
				return 0;
			}
			tryAgain = false;
		}
		catch(char invalid){
			std::cout << invalid << " is not acceptable input Y or N only. Try Agan.\n";
		}
	}

	Game game;
	Snake snake;

	std::thread partner(gameLoop, std::ref(game), std::ref(snake));

	while (game.playing)
	{
		game.move();
	}

	partner.join();

	std::cout << "Bye! Bye!";

	return 0;
}