/*
Author: Georges-Antoine Assi
Repo: https://github.com/DrShavargo/animal-card-game
*/

#pragma once

#include <vector>

enum Orientation {UP, DOWN};
enum EvenOdd {EVEN, ODD};
enum Split {VERTICAL, HORIZONTAL};

class AnimalCard {
protected:
	Orientation _orientation = UP;
	EvenOdd _evenOdd;
public:
	char _tl;
	char _tr;
	char _bl;
	char _br;
	AnimalCard(char, char, char, char);
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual void printRow(EvenOdd);
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