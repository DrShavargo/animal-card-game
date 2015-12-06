#include <iostream>
#include "Player.h"
#include "ActionCard.h"

using namespace std;

ActionCard::ActionCard(char c) : NoSplit(c){}

QueryResult BearAction::query(){
	QueryResult result;
	while (1){
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
					break;
				}
			}
		}
	}
	return result;
}

void BearAction::perfom(Table& table, Player* player, QueryResult result){
	Player *other = result.targetPlayer;
	Hand *tempHand = player->getHand();
	player->setHand(*(other->getHand()));
	other->setHand(*tempHand);
	cout << "Hands swapped successfully." << endl;
}