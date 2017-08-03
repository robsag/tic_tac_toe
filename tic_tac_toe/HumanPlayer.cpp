#include <iostream>
#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(){}

HumanPlayer::~HumanPlayer(){}

void HumanPlayer::move(Board* board)
{
	int row, column;
	char current_value;
	do
	{
		cout << endl << endl << "Podaj wspolrzedne ruchu." << endl;
		cout << "wiersz:";
		cin >> row; 
		row--;
		cout << "kolumna:";
		cin >> column; 
		column--;
		current_value = board->get_field(row, column);
		if (current_value != ' ') cout << "To pole jest juz zajete. Wybierz inne puste pole.";
		else board->set_field(row, column, 'X');
	} while (current_value != ' ');
}
