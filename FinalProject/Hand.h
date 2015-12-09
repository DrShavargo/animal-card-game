/*
Author: Georges-Antoine Assi
Repo: https://github.com/DrShavargo/animal-card-game
*/

#pragma once

#include "AnimalCard.h"
#include <memory>
#include <exception>
#include <stdexcept>
#include <list>

using namespace std;

class Hand {
	list<shared_ptr<AnimalCard>> _hand;
public:
	~Hand();
	Hand& operator+=(shared_ptr<AnimalCard>);
	Hand& operator-=(shared_ptr<AnimalCard>);
	shared_ptr<AnimalCard> operator[](int);
	int noCards() { return _hand.size(); };
	void print();
};

class MissingCard : public runtime_error {
public:
	MissingCard(void) : runtime_error("missing card"){};
	virtual const char* what() { return "Card is missing."; }
};