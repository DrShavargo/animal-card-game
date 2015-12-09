/*
Author: Georges-Antoine Assi
Repo: https://github.com/DrShavargo/animal-card-game
*/

#include <iostream>
#include "Player.h"
#include "Hand.h"

using namespace std;

Player::Player(string name, string animal){
	_name = name;
	_animal = animal;
}

string Player::swapSecretAnimal(string& animal){
	string currAnimal = _animal;
	_animal = animal;
	return currAnimal;
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

Hand Player::getHand(){
	return _hand;
}

void Player::setHand(Hand hand){
	_hand = hand;
}

void Player::print(){
	cout << _name << " has " << _hand.noCards() << " cards and a " << _animal << " as their secret animal." << endl;
}

PlayerList* PlayerList::_list = new PlayerList();

void PlayerList::addPlayer(Player player){
	_players.push_back(player);
}