/*
Author: Georges-Antoine Assi
Repo: https://github.com/DrShavargo/animal-card-game
*/

#pragma once

#include "Table.h"
#include "Player.h"

using namespace std;

class QueryResult{
public:
	bool _valid;
	Player* targetPlayer;
	int oldRow;
	int oldCol;
	int newRow;
	int newCol;
	QueryResult(bool);
};

class ActionCard : public NoSplit{
public:
	ActionCard(char);
	virtual QueryResult query() = 0;
	virtual void perfom(Table&, Player*, QueryResult) = 0;
};

class BearAction : public ActionCard{
public:
	BearAction() : ActionCard('B'){};
	QueryResult query();
	void perfom(Table&, Player*, QueryResult);
};

class DeerAction : public ActionCard{
public:
	DeerAction() : ActionCard('D'){};
	QueryResult query();
	void perfom(Table&, Player*, QueryResult);
};

class HareAction : public ActionCard{
public:
	HareAction() : ActionCard('H'){};
	QueryResult query();
	void perfom(Table&, Player*, QueryResult);
};

class MooseAction : public ActionCard{
public:
	MooseAction() : ActionCard('M'){};
	QueryResult query();
	void perfom(Table&, Player*, QueryResult);
};

class WolfAction : public ActionCard{
public:
	WolfAction() : ActionCard('W'){};
	QueryResult query();
	void perfom(Table&, Player*, QueryResult);
};