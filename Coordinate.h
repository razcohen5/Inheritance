#pragma once
class Coordinate{
public:
    int row,col;

    Coordinate(int a,int b);

	Coordinate(const Coordinate& other)
	{
		row = other.row;
		col = other.col;
	}
};