#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Food.h"

class Snake : public Food
{
protected:
	int sX = 9;//starting X position
	int sY = 19;//starting Y position
	static int tLen;//tail counter

	char head = 'O';//head representation

	std::vector<int> tailX;//container for tail X positions
	std::vector<int> tailY;//container for tail Y positions
};

#endif