#include <iostream>
#include "AnimalCard.h"
#include "AnimalCardFactory.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

void main(){
	SplitThree* three = new SplitThree('g', 'f', 'r', VERTICAL);
	SplitTwo* two = new SplitTwo('k', 'r', HORIZONTAL);
	Hand hand;
	shared_ptr<AnimalCard> card = make_shared<AnimalCard>(*three);
	hand+=(card);
	Player player("Joe", "dragon");
	player.setHand(hand);
	Hand *player_hand = player.getHand();
	shared_ptr<AnimalCard> card_two = make_shared<AnimalCard>(*two);
	*player_hand+=(card_two);
	player_hand->print();
};