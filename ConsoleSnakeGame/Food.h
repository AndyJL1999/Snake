#pragma once
#ifndef FOOD_H
#define	FOOD_H

#include <stdlib.h>
#include <iostream>

class Food
{
protected: 
	char food = '@';//food representation
	static int food_count;//food counter
public:
	int fX = rand() % 13 + 1; //random position generator for food's X position
	int fY = rand() % 27 + 1; //random position generator for food's Y position
};

#endif