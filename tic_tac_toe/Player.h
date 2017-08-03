#pragma once
#include "Board.h"

class Player
{
public:
	Player();
	~Player();
	virtual void move(Board*) = 0;
};

