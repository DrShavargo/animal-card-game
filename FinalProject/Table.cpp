#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "AnimalCard.h"
#include "Table.h"

using namespace std;

Table::Table(){
	_table[103][103] = { { NULL } };
	shared_ptr<AnimalCard> pnt(new StartCard);
	_table[52][52] = pnt;
}

int Table::addAt(shared_ptr<AnimalCard> card, int row, int col){
	try{
		if (_table[row][col] != NULL){ throw IllegalPlacement(); }
		if (row < 0 || col < 0 || row > 102 || col > 102){ throw IllegalPlacement(); }
		// DO ALL THE FREAKY CALCS TO GET THIS WORKING
		_table[row][col] = card;
	}
	catch (IllegalPlacement e){
		cout << e.what() << endl;
		return 0;
	}
	return 0;
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
			shared_ptr<AnimalCard> ptr = _table[i][j];
			AnimalCard* card = ptr.get();
			char* v = card->getAnimals();
			vector<char> w(v, v + sizeof(v) / sizeof(v[0]));
			for (char a : w){
				if (a == searched){ count++; }
			}
		}
	}
	return true;
}