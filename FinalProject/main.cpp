#include <iostream>
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
		// Start the round
		for (Player p : pList->getPlayers()){
			table.print();
			Hand h = p.getHand();
			h += deck.back();
			deck.pop_back();
			p.setHand(h);
			p.print();
			h.print();

			badCardNum:
			int cardNumber = 0;
			cout << "Please pick a card, from 0 to " << h.noCards() - 1 << ": " << endl;
			cin >> cardNumber;
			if (cin.fail()) {
				cout << "Enter a valid number" << endl;
				goto badCardNum;
			}

			shared_ptr<AnimalCard> chosenCard = h[cardNumber];
			char type = chosenCard->_tl;
			// AnimalCard or Joker
			if (islower(type)){
				string passOrGo;
				cout << "Would you like to pass? (yes/no)";
				cin >> passOrGo;
				if (passOrGo == "no"){
					badPos:
					int chosenRow, chosenColumn;
					
					cout << "Select a row: ";
					cin >> chosenRow;
					if (cin.fail()) {
						cout << "Enter numbers only" << endl;
						goto badPos;
					}
					
					cout << "Select a column: ";
					cin >> chosenColumn;
					if (cin.fail()) {
						cout << "Enter numbers only" << endl;
						goto badPos;
					}

					int cardsToPick = table.addAt(chosenCard, chosenRow, chosenColumn);
					if (cardsToPick > 0){
						for (int i = 0; i < cardsToPick; i++){
							h += deck.back();
							deck.pop_back();
						}
						p.setHand(h);
					}
					else{
						cout << "You can't place this card at that location!" << endl;
						goto badCardNum;
					}
				}

			}
			// ActionCard
			else{
				
			}
		}

		// Check if we have a winner
		for (Player p : pList->getPlayers()){
			if (table.win(p.getSecretAnimal())){ goto winner; }
		}
	}

	winner:
	cout << "We have a winner!" << endl;
};