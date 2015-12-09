/*
Author: Georges-Antoine Assi
Repo: https://github.com/DrShavargo/animal-card-game
*/

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
	Hand getHand();
	void setHand(Hand);
	void print();
};

class PlayerList {
	static PlayerList *_list;
	vector<Player> _players;
	PlayerList(){};
public:
	static PlayerList* getList(){
		if (!_list){
			_list = new PlayerList();
		}
		return _list;
	};
	void addPlayer(Player);
	vector<Player> getPlayers(){ return _players; };
};