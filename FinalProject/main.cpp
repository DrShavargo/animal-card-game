#include <iostream>
#include <regex>
#include "AnimalCard.h"
#include "AnimalCardFactory.h"
#include "Hand.h"
#include "Player.h"
#include "ActionCard.h"
#include "Table.h"

using namespace std;

void main(){
	// Setup game
	string animalList[5] = { "bear", "deer", "hare", "moose", "wolf" };
	PlayerList* pList = PlayerList::getList();
	AnimalCardFactory* factory = AnimalCardFactory::getfactory();
	Deck<shared_ptr<AnimalCard>> deck = factory->getdeck();
	Table table;

	// TODO: Implement reading and saving to file

	// Initialize players and secret animals
	int playerCount = 0;
	while (playerCount < 5){
		needPlayers:
		string player = "";
		cout << "Enter Player " << playerCount + 1 << "'s name, or type 'done' if finished" << endl;
		cin >> player;
		if (player == "done"){
			if (playerCount > 1){ goto havePlayers; }
			else { 
				cout << "This game requires a minimum of 2 players" << endl;
				goto needPlayers;
			}
		}
		Hand hand;
		hand += deck.back();
		deck.pop_back();
		hand += deck.back();
		deck.pop_back();
		hand += deck.back();
		deck.pop_back();
		Player newPlayer(player, animalList[playerCount]);
		newPlayer.setHand(hand);
		pList->addPlayer(newPlayer);
		playerCount++;
	}

	havePlayers:
	while (1){
		// Check if we have a winner
		for (Player p : pList->getPlayers()){
			if (table.win(p.getSecretAnimal())){ goto winner; }
		}
		
		// No winner, start the round
		for (Player p : pList->getPlayers()){
			table.print();
			shared_ptr<AnimalCard> card(deck.back());
			deck.pop_back();
			Hand h = p.getHand();
			h += card;
			p.setHand(h);
			p.print();
			h.print();

			badCardNum:
			int cardNumber = 0;
			cout << "Please pick a card, from 0 to " << h.noCards() - 1 << ": " << endl;
			cin >> cardNumber;
			if (cin.fail()) {
				cout << "Enter a valid number." << endl;
				goto badCardNum;
			}

			shared_ptr<AnimalCard> chosenCard = h[cardNumber];
			char type = chosenCard->_tl;
			// Joker
			if (type == 'j'){

			}
			// AnimalCard
			else if (islower(type)){
				
			}
			// ActionCard
			else{
				
			}
		}
	}

	winner:
	cout << "We have a winner!" << endl;
};