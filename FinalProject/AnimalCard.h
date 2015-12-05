#pragma once

#include <vector>

enum Orientation {UP, DOWN};
enum EvenOdd {EVEN, ODD};
enum Split {VERTICAL, HORIZONTAL};

class AnimalCard {
protected:
	Orientation _orientation = UP;
	EvenOdd _evenOdd;
	char _tl;
	char _tr;
	char _bl;
	char _br;
public:
	AnimalCard(char, char, char, char);
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual void printRow(EvenOdd);
	char* getAnimals();
};

class NoSplit : public AnimalCard { 
public:
	NoSplit(char);
};

class SplitTwo : public AnimalCard {
public:
	SplitTwo(char, char, Split);
};

class SplitThree : public AnimalCard {
public:
	SplitThree(char, char, char, Split);
};

class SplitFour : public AnimalCard {
public:
	SplitFour(char, char, char, char);
};

class Joker : public NoSplit {
public:
	Joker(char);
};

class StartCard : public NoSplit {
public:
	StartCard();
};