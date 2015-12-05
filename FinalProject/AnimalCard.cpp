#include <string>
#include <iostream>
#include <vector>
#include "AnimalCard.h"
using namespace std;

AnimalCard::AnimalCard(char tl, char tr, char br, char bl){
	_tl = tl;
	_tr = tr;
	_br = br;
	_bl = bl;
}

void AnimalCard::setOrientation(Orientation orientation){
	_orientation = orientation;
}

void AnimalCard::setRow(EvenOdd evenOdd){
	_evenOdd = evenOdd;
}

void AnimalCard::printRow(EvenOdd evenOdd){
	if (evenOdd == ODD){
		cout << _tl << _tr << " ";
	}
	else{
		cout << _bl << _br << " ";
	}
}

char* AnimalCard::getAnimals(){
	char v[4] = { _tl, _tr, _br, _bl };
	return v;
}

NoSplit::NoSplit(char c) : AnimalCard(c, c, c, c){}

SplitTwo::SplitTwo(char t, char b, Split split = HORIZONTAL) : AnimalCard(t, t, b, b){
	if (split == VERTICAL){
		_tr = b;
		_bl = t;
	}
}

SplitThree::SplitThree(char t, char l, char r, Split split = HORIZONTAL) : AnimalCard(t, t, r, l){
	if (split == VERTICAL){
		_tr = l;
		_bl = t;
	}
}

SplitFour::SplitFour(char a, char b, char c, char d) : AnimalCard(a, b, c, d){}

Joker::Joker(char type) : NoSplit(type){}

StartCard::StartCard() : NoSplit('c'){};