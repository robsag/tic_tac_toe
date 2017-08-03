#pragma once
class Board
{
private: 
	int size;
	int in_a_row;
	char** fields;

public:
	Board(int, int);
	Board(Board*);
	~Board();
	void draw(void);
	int get_size(void);
	int get_in_a_row(void);
	char get_field(int, int);
	void set_field(int, int, char);
};

