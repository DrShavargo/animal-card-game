#include <iostream>
#include "Player.h"
#include "Hand.h"

using namespace std;

Player::Player(string name, string animal){
	_name = name;
	_animal = animal;
}

string Player::swapSecretAnimal(string& animal){
	_animal = animal;
	return _animal;
}

string Player::getSecretAnimal(){
	return _animal;
}

string Player::getName(){
	return _name;
}

void Player::setName(string name){
	_name = name;
}

Hand* Player::getHand(){
	return &_hand;
}

void Player::setHand(Hand hand){
	_hand = hand;
}

void Player::print(){
	cout << _name << " has " << _hand.noCards() << " cards and a " << _animal << " as his secret animal." << endl;
}