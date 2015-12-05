#pragma once
#include <string>
#include "Hand.h"

using namespace std;

class Player {
	string _name;
	string _animal;
	Hand _hand;
public:
	Player(string, string);
	string swapSecretAnimal(string&);
	string getSecretAnimal();
	string getName();
	void setName(string);
	Hand* getHand();
	void setHand(Hand);
	void print();
};