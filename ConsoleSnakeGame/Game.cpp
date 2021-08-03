#include "Game.h"

bool Game::playing = true;

void Game::play(Snake& player)
{
	render(player);
	update();
	checkForEvents(meals);
}
void Game::move()
{
	if (_kbhit)
	{
		switch (_getch())
		{
			case'a':
			{
				dir = Left;
				break;
			}
			case'd':
			{
				dir = Right;
				break;
			}
			case'w':
			{
				dir = Up;
				break;
			}
			case's':
			{
				dir = Down;
				break;
			}
			case'x':
			{
				std::cout << "Good bye! Thanks for playing!\n";
				exit(0);
				break;
			}
		}
	}
}
void Game::render(Snake &s)
{
	map m = fillMap();
	static int frame = 0;//frame counter

	m.m[sX][sY] = head;//spawn snake

	if (frame % 6 == 0 && meals.size() != 8)
	{
		food_count++;
		meals.emplace_back();
	}

	if (!meals.empty())
	{
		for (int i = 0; i < meals.size(); i++)
		{
			m.m[meals[i].fX][meals[i].fY] = food;//spawn food
		}
	}

	std::cout << "\n\tFrame: " << frame << '\n';
	std::cout << "\tFood: " << food_count << '\n';
	std::cout << "\tTail-Length: " << tLen << '\n';
	std::cout << '\n';

	for (int i = 0; i < x; i++)
	{
		std::cout << '\t';
		for (int j = 0; j < y; j++)
		{
			std::cout << m.m[i][j];

			if (!tailX.empty())
			{
				for (int i = 0; i < tailX.size(); i++)
				{
					m.m[tailX[i]][tailY[i]] = '#';//spawn tail
				}
			}
		}
		std::cout << '\n';
	}

	frame++;
}
void Game::checkForEvents(std::vector<Food>& f)
{
	bool eating = false;

	if (sY == 0 || sY == 29 || sX == 0 || sX == 14)//check for out of bounds
	{
		std::cout << "Out of bounds! Game over!\n";
		playing = false;
	}

	if (!f.empty())//check if snake has eaten food
	{
		for (int i = 0; i < f.size(); i++)
		{
			if (sY == f[i].fY && sX == f[i].fX)
			{
				tailX.push_back(f[i].fX);
				tailY.push_back(f[i].fY);

				f.erase(f.begin() + i);
				food_count--;
				tLen++;
				eating = true;//represent eating
			}
		}
	}

	if (!tailX.empty())
	{
		for (int i = 0; i < tailX.size(); i++)
		{
			if (!eating)//If eating do nothing | Otherwise check for tail collision
			{
				if ((sX == tailX[i] && sY == tailY[i]))
				{
					std::cout << "You bit your own tail! Game Over!\n";
					playing = false;
				}
			}
		}
	}
}
void Game::update()
{
	switch (dir)
	{
		case Left:
		{
			sY--;

			if (!tailX.empty())//adds to the tail x and y vectors
			{
				tailY.push_back(sY + 1);
				tailX.push_back(sX);
			}
			if (tailX.size() > 1)//destroys old positions
			{
				tailX.erase(tailX.begin());
				tailY.erase(tailY.begin());
			}
			break;
		}
		case Right:
		{
			sY++;

			if (!tailX.empty())
			{
				tailY.push_back(sY - 1);
				tailX.push_back(sX);
			}
			if (tailX.size() > 1)
			{
				tailX.erase(tailX.begin());
				tailY.erase(tailY.begin());
			}
			break;
		}
		case Up:
		{
			sX--;

			if (!tailX.empty())
			{
				tailX.push_back(sX + 1);
				tailY.push_back(sY);
			}
			if (tailX.size() > 1)
			{
				tailX.erase(tailX.begin());
				tailY.erase(tailY.begin());
			}
			break;
		}
		case Down:
		{
			sX++;

			if (!tailX.empty())
			{
				tailX.push_back(sX - 1);
				tailY.push_back(sY);
			}
			if (tailX.size() > 1)
			{
				tailX.erase(tailX.begin());
				tailY.erase(tailY.begin());
			}
			break;
		}
	}
}
