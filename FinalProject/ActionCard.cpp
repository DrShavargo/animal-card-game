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
	while (!result._valid){
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
					result._valid = true;
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
	while (!result._valid){
		string target = "";
		cout << "Enter the player you'd like to swap secret card with, or type 'list' to list players: ";
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
					result._valid = true;
				}
			}
		}
	}
	return result;
}

void DeerAction::perfom(Table& table, Player* player, QueryResult result){
	Player *other = result.targetPlayer;
	string otherAnimal = player->swapSecretAnimal(other->getSecretAnimal());
	other->swapSecretAnimal(otherAnimal);
	cout << "Secret animals swapped successfully." << endl;
}

QueryResult HareAction::query(){
	QueryResult result(false);
	while (!result._valid){
		result._valid = true;

		int uInput = NULL;

		cout << "Select a row to pick from: ";
		cin >> uInput;
		if (cin.fail()) {
			cout << "Enter numbers only" << endl;
			result._valid = false;
		}
		result.oldRow = uInput;

		cout << "Select a column to pick from: ";
		cin >> uInput;
		if (cin.fail()) {
			cout << "Enter numbers only" << endl;
			result._valid = false;
		}
		result.oldCol = uInput;

		cout << "Select a row to place at: ";
		cin >> uInput;
		if (cin.fail()) {
			cout << "Enter numbers only" << endl;
			result._valid = false;
		}
		result.newRow = uInput;

		cout << "Select a column to place at: ";
		cin >> uInput;
		if (cin.fail()) {
			cout << "Enter numbers only" << endl;
			result._valid = false;
		}
		result.newCol = uInput;
	}
	return result;
}

void HareAction::perfom(Table& table, Player* player, QueryResult result){
	shared_ptr<AnimalCard> card = table.pickAt(result.oldRow, result.oldCol);
	table.addAt(card, result.newRow, result.newCol);
}

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