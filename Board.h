#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Coordinate.h"

using namespace std;
class Bridge;
class Board;
class IllegalCharException;
class IllegalCoordinateException;
class Board
{
public:
	int size;
	char **b;

	Board(int size);

	Board(const Board& other);


	const Bridge operator[](const Coordinate& c);
	const Bridge operator[](const Coordinate& c) const;
	void operator=(char c);

	void deleteBoard();


	Board& operator=(const Board& other);

	~Board();

};

class Bridge
{
public:

	const Board* bp;
	int i;
	int j;
	
	Bridge(Board* p,const int a,const int b);
	Bridge(const Board* p,const int a,const int b);
	Bridge(const Bridge& other);

	void operator=(char c) const;

	bool operator==(char c) const;

	bool operator!=(char c) const;

	bool operator==(const Bridge& other);

	bool operator!=(const Bridge& other);
};

class IllegalCoordinateException : public exception 
{
	public:	

	int i;
	int j;

	IllegalCoordinateException(int a, int b);


	string theCoordinate() const;
};

class IllegalCharException : public exception 
{
public:

	char c;

	IllegalCharException(char a);


	char theChar() const;

};

ostream& operator<< (ostream& os, const Board& b);