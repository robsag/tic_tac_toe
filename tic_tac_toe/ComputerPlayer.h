#pragma once
#include "Player.h"
#include "Board.h"

class ComputerPlayer :
	public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();
	void move(Board*);
};

