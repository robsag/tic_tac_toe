#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <windows.h>
#include "Board.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

using namespace std;

void loading(void);
void new_game(void);
bool check_win(Board*, char);
bool check_draw(Board*);
int minimax(Board*);

int main() {
	system("color 70");
	loading();

	string again;
	do
	{
		system("cls");
		new_game();
		cout << "Koniec gry." << endl << "Aby zagrac ponownie wpisz 'gram'.";
		cin >> again;
		transform(again.begin(), again.end(), again.begin(), tolower);
	} while (again == "gram");

	return 0;
}

void loading() 
{
	char c[] = { 219, 186, 187, 188, 200, 201, 205 };

	cout << "\n\n\n\n\n\n";
	cout << " " << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << c[0] << c[0] << c[2] << " " << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << "   " << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << " " << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << "  " << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << "   " << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << " " << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << " " << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << endl;
	cout << " " << c[4] << c[6] << c[6] << c[0] << c[0] << c[5] << c[6] << c[6] << c[3] << c[0] << c[0] << c[1] << c[0] << c[0] << c[5] << c[6] << c[6] << c[6] << c[6] << c[3] << "   " << c[4] << c[6] << c[6] << c[0] << c[0] << c[5] << c[6] << c[6] << c[3] << c[0] << c[0] << c[5] << c[6] << c[6] << c[0] << c[0] << c[2] << c[0] << c[0] << c[5] << c[6] << c[6] << c[6] << c[6] << c[3] << "   " << c[4] << c[6] << c[6] << c[0] << c[0] << c[5] << c[6] << c[6] << c[3] << c[0] << c[0] << c[5] << c[6] << c[6] << c[6] << c[0] << c[0] << c[2] << c[0] << c[0] << c[5] << c[6] << c[6] << c[6] << c[6] << c[3] << endl;
	cout << "    " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[1] << c[0] << c[0] << c[1] << "           " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[1] << c[0] << c[0] << c[1] << "           " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[1] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << endl;
	cout << "    " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[1] << c[0] << c[0] << c[1] << "           " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[5] << c[6] << c[6] << c[0] << c[0] << c[1] << c[0] << c[0] << c[1] << "           " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[1] << c[0] << c[0] << c[5] << c[6] << c[6] << c[3] << endl;
	cout << "    " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[1] << c[4] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << "      " << c[0] << c[0] << c[1] << "   " << c[0] << c[0] << c[1] << "  " << c[0] << c[0] << c[1] << c[4] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << "      " << c[0] << c[0] << c[1] << "   " << c[4] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[5] << c[3] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[0] << c[2] << endl;
	cout << "    " << c[4] << c[6] << c[3] << "   " << c[4] << c[6] << c[3] << " " << c[4] << c[6] << c[6] << c[6] << c[6] << c[6] << c[3] << "      " << c[4] << c[6] << c[3] << "   " << c[4] << c[6] << c[3] << "  " << c[4] << c[6] << c[3] << " " << c[4] << c[6] << c[6] << c[6] << c[6] << c[6] << c[3] << "      " << c[4] << c[6] << c[3] << "    " << c[4] << c[6] << c[6] << c[6] << c[6] << c[6] << c[3] << " " << c[4] << c[6] << c[6] << c[6] << c[6] << c[6] << c[6] << c[3] << endl;

	cout << "\n\n" << "                                 Loading..." << endl;
	cout << "                             [               ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	for (int i = 0; i < 15; i++)
	{
		cout << c[0];
		Sleep(250);
	}
}

void new_game()
{
	int size;
	int in_a_row;
	string who_begins;
	char move;

	cout << "Rozmiar planszy:";
	cin >> size;

	do {
		cout << "Liczba znakow w rzedzie aby wygrac:";
		cin >> in_a_row;
		if (in_a_row > size)
		{
			cout << "Liczba znakow w rzedzie nie moze byc wieksza od rozmiaru." << endl;
		}
	} while (in_a_row > size);

	cout << "Kto zaczyna ('ja' jezeli chcesz zaczynac)? ";
	cin >> who_begins;
	transform(who_begins.begin(), who_begins.end(), who_begins.begin(), tolower);
	if (who_begins == "ja") move = 'X';
	else move = 'O';

	Board* board = new Board(size, in_a_row);
	HumanPlayer* human_player = new HumanPlayer();
	ComputerPlayer* computer_player = new ComputerPlayer();
	board->draw();

	do
	{
		if (move == 'X') { human_player->move(board); move = 'O'; }
		else { computer_player->move(board); move = 'X'; }
		board->draw();
	} while (!check_win(board, 'X') && !check_win(board, 'O') && !check_draw(board));

	cout << endl << endl;
	if (check_win(board, 'X')) cout << "Gratulacje, wygrywasz!" << endl;
	else if (check_win(board, 'O')) cout << "Niestety wygral komputer." << endl;
	else cout << "Remis." << endl;

	delete human_player;
	delete computer_player;
	delete board;
}

bool check_win(Board* board, char player) 
{
	int in_a_row;

	for (int i = 0; i < board->get_size(); i++)
	{
		in_a_row = 0;
		for (int j = 0; j < board->get_size(); j++)
		{
			if (board->get_field(i, j) == player) in_a_row++;
			else in_a_row = 0;
			if (in_a_row == board->get_in_a_row())
			{
				return true;
			}
		}
	}

	for (int i = 0; i < board->get_size(); i++)
	{
		in_a_row = 0;
		for (int j = 0; j < board->get_size(); j++)
		{
			if (board->get_field(j, i) == player) in_a_row++;
			else in_a_row = 0;
			if (in_a_row == board->get_in_a_row())
			{
				return true;
			}
		}
	}

	in_a_row = 0;
	for (int i = 0; i < board->get_size(); i++)
	{
		if (board->get_field(i, i) == player) in_a_row++;
		else in_a_row = 0;
		if (in_a_row == board->get_in_a_row())
		{
			return true;
		}
	}

	in_a_row = 0;
	for (int i = 0; i < board->get_size(); i++)
	{
		if (board->get_field(board->get_size() - 1 - i, i) == player) in_a_row++;
		else in_a_row = 0;
		if (in_a_row == board->get_in_a_row())
		{
			return true;
		}
	}

	for (int i = 0; i < board->get_size() - board->get_in_a_row(); i++)
	{
		int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
		for (int j = 0; j < board->get_size() - 1 - i; j++)
		{
			if (board->get_field(j, board->get_size() - 2 - i - j) == player) tmp1++;
			else tmp1 = 0;

			if (board->get_field(j, 1 + i + j) == player) tmp2++;
			else tmp2 = 0;

			if (board->get_field(1 + i + j, j) == player) tmp3++;
			else tmp3 = 0;

			if (board->get_field(1 + i + j, board->get_size() - 1 - j) == player) tmp4++;
			else tmp4 = 0;

			if (tmp1 == board->get_in_a_row() ||
				tmp2 == board->get_in_a_row() ||
				tmp3 == board->get_in_a_row() ||
				tmp4 == board->get_in_a_row())
			{
				return true;
			}
		}
	}
	
	return false;
}

bool check_draw(Board* board)
{
	for (int i = 0; i < board->get_size(); i++)
	{
		for (int j = 0; j < board->get_size(); j++)
		{
			if (board->get_field(i, j) == ' ') return false;
		}
	}
	return true;
}

int minimax(Board* board, char _player)
{
	if (check_win(board, _player))
	{
		return (_player == 'O') ? 1 : -1;
	}

	if (check_draw(board))
	{
		return 0;
	}

	int m, mmx;
	char player = _player;
	Board* board_copy = new Board(board);

	player = (player == 'O') ? 'X' : 'O';

	mmx = (player == 'X') ? pow(board_copy->get_size(), 2) + 1 : -1 - pow(board_copy->get_size(), 2);

	for (int i = 0; i < board_copy->get_size(); i++)
	{
		for (int j = 0; j < board_copy->get_size(); j++)
		{
			if (board_copy->get_field(i, j) != 'X' && board_copy->get_field(i, j) != 'O')
			{
				board_copy->set_field(i, j, player);
				m = minimax(board_copy, player);
				board_copy->set_field(i, j, ' ');
				if (((player == 'X') && (m < mmx)) || ((player == 'O') && (m > mmx)))
				{
					mmx = m;
				}
			}
		}
	}
	delete board_copy;

	return mmx;
}