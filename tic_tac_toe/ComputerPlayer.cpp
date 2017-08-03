#include <cmath>
#include "ComputerPlayer.h"
#include "Main.h"

ComputerPlayer::ComputerPlayer(){}

ComputerPlayer::~ComputerPlayer(){}

void ComputerPlayer::move(Board* board)
{
	Board* board_copy = new Board(board);

	int ruch, m;
	int mmx = -1 - pow(board->get_size(), 2);

	for (int i = 0; i < board->get_size(); i++)
	{
		for (int j = 0; j < board->get_size(); j++)
		{
			if (board_copy->get_field(i ,j) != 'X' && board_copy->get_field(i, j) != 'O')
			{
				board_copy->set_field(i ,j, 'O');
				m = minimax(board_copy, 'O');
				board_copy->set_field(i, j, ' ');
				if (m > mmx)
				{
					mmx = m;
					ruch = i * board->get_size() + j;
				}
			}
		}
	}
	delete board_copy;

	int row = ruch;
	board->set_field(ruch / board->get_size(), ruch % board->get_size(), 'O');
}