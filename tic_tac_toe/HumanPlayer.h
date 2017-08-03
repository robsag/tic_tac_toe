#pragma once
#include "Player.h"
#include "Board.h"

class HumanPlayer :
	public Player
{
public:
	HumanPlayer();
	~HumanPlayer();
	void move(Board*);
};

