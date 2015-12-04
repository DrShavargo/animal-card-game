#include <iostream>
#include "AnimalCard.h"
#include "Hand.h"

using namespace std;

void main(){
	SplitThree* three = new SplitThree('g', 'f', 'r', VERTICAL);
	SplitTwo* two = new SplitTwo('k', 'r', HORIZONTAL);
	Hand hand;
	shared_ptr<AnimalCard> card = make_shared<AnimalCard>(*three);
	hand+=(card);
	shared_ptr<AnimalCard> card_two = make_shared<AnimalCard>(*two);
	hand += (card_two);
	hand.print();
};