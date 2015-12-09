/*
Author: Georges-Antoine Assi
Repo: https://github.com/DrShavargo/animal-card-game
*/

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "AnimalCard.h"
#include "Table.h"

using namespace std;

Table::Table(){
	_table[103][103] = { { NULL } };
	shared_ptr<AnimalCard> pnt(new StartCard());
	_table[52][52] = pnt;
}

int Table::addAt(shared_ptr<AnimalCard> card, int row, int col){
	try{
		if (row < 0 || col < 0 || row > 102 || col > 102){ throw IllegalPlacement(); }
		if (_table[row][col] != NULL){ throw IllegalPlacement(); }
		int matches = 0;
		AnimalCard animal = *card.get();

		// Check the top
		if (row > 0){
			shared_ptr<AnimalCard> topCard = _table[row - 1][col];
			if (topCard != NULL){
				if (animal._tl == (*topCard)._bl || animal._tr == (*topCard)._br || (*topCard)._bl == 'c' || (*topCard)._bl == 'j'){
					matches++;
				}
			}
		}

		// Check the bottom
		if (row < 102){
			shared_ptr<AnimalCard> bottomCard = _table[row + 1][col];
			if (bottomCard != NULL){
				if (animal._bl == (*bottomCard)._tl || animal._br == (*bottomCard)._tr || (*bottomCard)._bl == 'c' || (*bottomCard)._bl == 'j'){
					matches++;
				}
			}
		}

		// Check the left
		if (col > 0){
			shared_ptr<AnimalCard> leftCard = _table[row][col - 1];
			if (leftCard != NULL){
				if (animal._tl == (*leftCard)._tr || animal._bl == (*leftCard)._br || (*leftCard)._bl == 'c' || (*leftCard)._bl == 'j'){
					matches++;
				}
			}
		}

		// Check the right
		if (col < 102){
			shared_ptr<AnimalCard> rightCard = _table[row][col + 1];
			if (rightCard != NULL){
				if (animal._tr == (*rightCard)._tl || animal._br == (*rightCard)._bl || (*rightCard)._bl == 'c' || (*rightCard)._bl == 'j'){
					matches++;
				}
			}
		}

		if (matches < 1){ throw IllegalPlacement(); }
		_table[row][col] = card;
		return matches;
	}
	catch (IllegalPlacement e){
		cout << e.what() << endl;
		return 0;
	}
}

shared_ptr<AnimalCard> Table::pickAt(int row, int col){
	shared_ptr<AnimalCard> picked = _table[row][col];
	_table[row][col] = NULL;
	return picked;
}

shared_ptr<AnimalCard> Table::get(int row, int col){
	return _table[row][col];
}

bool Table::win(string& animal){
	char searched = animal.at(0);
	int count = 0;
	for (int i = 0; i < 103; i++){
		for (int j = 0; j < 103; j++){
			if (_table[i][j] != NULL){
				shared_ptr<AnimalCard> ptr = _table[i][j];
				AnimalCard* card = ptr.get();
				vector<char> w = { card->_tl, card->_tr, card->_br, card->_bl };
				for (char a : w){
					if (a == searched){ count++; }
				}
			}
		}
	}
	return (count >= 12);
}

void Table::print(){
	for (int i = 0; i < 103; i++){
		cout << setfill('0') << setw(3) << i;
		if (i % 10 == 0){
			for (int m = 0; m < 103; m++){
				cout << "|" << setfill('0') << setw(2) << (m % 100);
			}
		}
		else{
			for (int l = 0; l < 103; l++){
				cout << "|--";
			}
		}
		cout << endl;
		cout << "   ";
		for (int j = 0; j < 103; j++){
			if (_table[i][j] != NULL){
				shared_ptr<AnimalCard> card = _table[i][j];
				card->printRow(ODD);
			}
			else{
				cout << "   ";
			}
		}
		cout << endl;
		cout << "   ";
		for (int k = 0; k < 103; k++){
			if (_table[i][k] != NULL){
				shared_ptr<AnimalCard> card = _table[i][k];
				card->printRow(EVEN);
			}
			else{
				cout << "   ";
			}
		}
		cout <<endl;
	}
}