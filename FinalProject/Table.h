/*
Author: Georges-Antoine Assi
Repo: https://github.com/DrShavargo/animal-card-game
*/

#pragma once

#include <memory>
#include <string>
#include "AnimalCard.h"

using namespace std;

class Table {
	shared_ptr<AnimalCard> _table[103][103];
public:
	Table();
	int addAt(shared_ptr<AnimalCard>, int, int);
	shared_ptr<AnimalCard> pickAt(int, int);
	shared_ptr<AnimalCard> get(int, int);
	bool win(string&);
	void print();
};

class IllegalPlacement : public runtime_error {
public:
	IllegalPlacement(void) : runtime_error("illegal placement"){};
	virtual const char* what() { return "Card cannot be placed in this locaton."; }
};