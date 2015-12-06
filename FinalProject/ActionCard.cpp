#include <iostream>
#include "Player.h"
#include "ActionCard.h"

using namespace std;

ActionCard::ActionCard(char c) : NoSplit(c){}

QueryResult::QueryResult(bool valid){
	_valid = valid;
}

QueryResult BearAction::query(){
	QueryResult result(false);
	bool legit = true;
	while (legit){
		string target = "";
		cout << "Enter the player you'd like to swap hands with, or type 'list' to list players: ";
		cin >> target;
		PlayerList* pList = PlayerList::getList();
		vector<Player> players = pList->getPlayers();
		if (target == "list"){
			for (Player p : players){
				cout << p.getName() << " ";
			}
		}
		else{
			for (Player p : players){
				if (p.getName() == target){
					result.targetPlayer = &p;
					legit = false;
				}
			}
		}
	}
	return result;
}

void BearAction::perfom(Table& table, Player* player, QueryResult result){
	Player *other = result.targetPlayer;
	Hand tempHand = player->getHand();
	player->setHand(other->getHand());
	other->setHand(tempHand);
	cout << "Hands swapped successfully." << endl;
}

// TODO: fill out the actions

QueryResult DeerAction::query(){
	QueryResult result(false);
	return result;
}

void DeerAction::perfom(Table& table, Player* player, QueryResult result){}

QueryResult HareAction::query(){
	QueryResult result(false);
	return result;
}

void HareAction::perfom(Table& table, Player* player, QueryResult result){}

QueryResult MooseAction::query(){
	QueryResult result(false);
	return result;
}

void MooseAction::perfom(Table& table, Player* player, QueryResult result){}

QueryResult WolfAction::query(){
	QueryResult result(false);
	return result;
}

void WolfAction::perfom(Table& table, Player* player, QueryResult result){}