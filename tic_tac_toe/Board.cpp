#include <iostream>
#include "Board.h"

using namespace std;

Board::Board(int size, int in_a_row)
{
	this->size = size;
	this->in_a_row = in_a_row;
	fields = new char*[size];
	for (int i = 0; i < size; i++)
	{
		fields[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			fields[i][j] = ' ';
		}
	}
}

Board::Board(Board* board) 
{
	this->size = board->get_size();
	this->in_a_row = board->get_in_a_row();
	fields = new char*[size];
	for (int i = 0; i < size; i++)
	{
		fields[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			fields[i][j] = board->get_field(i, j);
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < size; i++)
	{
		delete fields[i];
	}
	delete fields;
}

void Board::draw(void) 
{
	system("cls");
	cout << " ";
	for (int i = 0; i < size; i++)
	{
		cout << "   " << i + 1;
	}
	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "  ";
		for (int j = 0; j < size; j++)
		{
			cout << " " << fields[i][j];
			if (j != size - 1) cout << " |";
		}
		cout << endl << "   ";
		if (i != size - 1)
		{
			for (int j = 0; j < size - 1; j++)
			{
				cout << "---+";
			}
			cout << "---" << endl;
		}
		
	}
}

int Board::get_size(void) { return size; }

int Board::get_in_a_row(void) { return in_a_row; }

char Board::get_field(int x, int y)
{
	return fields[x][y];
}

void Board::set_field(int x, int y, char value)
{
	fields[x][y] = value;
}