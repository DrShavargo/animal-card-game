#include <iostream>
#include "AnimalCard.h"
#include "AnimalCardFactory.h"
#include "Hand.h"
#include "Player.h"
#include "ActionCard.h"
#include "Table.h"

using namespace std;

void main(){
	/*SplitThree* three = new SplitThree('g', 'f', 'r', VERTICAL);
	SplitTwo* two = new SplitTwo('k', 'r', HORIZONTAL);
	Hand hand;
	shared_ptr<AnimalCard> card = make_shared<AnimalCard>(*three);
	hand+=(card);
	Player player("Joe", "dragon");
	player.setHand(hand);
	Hand *player_hand = player.getHand();
	shared_ptr<AnimalCard> card_two = make_shared<AnimalCard>(*two);
	*player_hand+=(card_two);
	player_hand->print();*/

	string animalList[5] = { "bear", "deer", "hare", "moose", "wolf" };
	PlayerList* pList = PlayerList::getList();
	AnimalCardFactory* factory = AnimalCardFactory::getfactory();
	Deck<shared_ptr<AnimalCard>> deck = factory->getdeck();

	// Initialize players and secret animals
	int playerCount = 0;
	while (playerCount < 5){
		string player = "";
		cout << "Enter Player " << playerCount + 1 << "'s name, or type 'done' if finished" << endl;
		cin >> player;
		if (player == "done"){
			if (playerCount > 1){ playerCount = 5; }
			else { cout << "This game requires a minimum of 2 players" << endl; }
		}
		Player newPlayer(player, animalList[playerCount]);
		Hand hand();
		pList->addPlayer(newPlayer);
		playerCount++;
	}


};