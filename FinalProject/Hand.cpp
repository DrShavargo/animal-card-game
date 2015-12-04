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
		int pos = find(_hand.begin(), _hand.end(), ptr) - _hand.begin();
		if (pos == _hand.end() - _hand.begin()){ throw  MissingCard(); }
		_hand.erase(_hand.begin() + pos);
	}
	catch (MissingCard e){
		cout << e.what() << endl;
	}
	return *this;
}

shared_ptr<AnimalCard> Hand::operator[](int pos){
	return _hand[pos];
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