/*
Author: Georges-Antoine Assi
Repo: https://github.com/DrShavargo/animal-card-game
*/

#include <iostream>
#include "AnimalCard.h"
#include "Hand.h"

using namespace std;

Hand::~Hand(){
	_hand.clear();
}

Hand& Hand::operator+=(shared_ptr<AnimalCard> ptr){
	_hand.push_back(ptr);
	return *this;
}

Hand& Hand::operator-=(shared_ptr<AnimalCard> ptr){
	try {
		list<shared_ptr<AnimalCard>>::iterator it = find(_hand.begin(), _hand.end(), ptr);
		if (it == _hand.end()){ throw  MissingCard(); }
		_hand.erase(it);
	}
	catch (MissingCard e){
		cout << e.what() << endl;
	}
	return *this;
}

shared_ptr<AnimalCard> Hand::operator[](int pos){
	list<shared_ptr<AnimalCard>>::iterator it = _hand.begin();
	advance(it, pos);
	return *it;
}

void Hand::print(){
	for (int i = 0; i < _hand.size(); i++){
		cout << i << "  ";
	}
	cout << endl;
	
	for (shared_ptr<AnimalCard> ptr : _hand){
		AnimalCard* card = ptr.get();
		card->printRow(ODD);
	}
	cout << endl;

	for (shared_ptr<AnimalCard> ptr : _hand){
		AnimalCard* card = ptr.get();
		card->printRow(EVEN);
	}
	cout << endl;
}