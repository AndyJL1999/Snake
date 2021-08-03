#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <conio.h>
#include "Snake.h"
enum Direction { Stop = 0, Left, Right, Up, Down };
static Direction dir = Stop;

const int x = 15, y = 30;

class Game : public Snake
{	
public:
	static bool playing;
	void play(Snake&);
	void move();
private:
	std::vector <Food> meals;//container for <Food> objects

	struct map
	{
		char m[x][y];
	};
	map fillMap()//fill and return <map> object
	{
		map fill;

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				fill.m[i][j] = '*';
				if (i != 0 && i != (x - 1))
				{
					fill.m[i][j] = ' ';
				}
				if (j == 0 || j == (y - 1))
				{
					fill.m[i][j] = '*';
				}
			}
		}

		return fill;
	}
	void render(Snake&);
	void checkForEvents(std::vector<Food>&);
	void update();
};

#endif