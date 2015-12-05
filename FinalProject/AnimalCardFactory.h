#pragma once

#include "AnimalCard.h"
#include "ActionCard.h"
#include <vector>
#include <memory>
#include <typeinfo>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

template <class T>
class Deck : public vector<T>{
	vector<T> _deck;
public:
	shared_ptr<T> draw(){
		return _deck.pop_back();
	}
};

template <class T>
class AnimalCardFactory {
	static AnimalCardFactory *_factory;
	Deck<T> _deck;
	AnimalCardFactory(){
		char animals[5] = { b, d, h, m, w };
		int needle = 0;
		for (int i = 0; i < 5; i++){
			_deck.push_back(NoSplit(animals[needle % 5]));
			needle++;
		}
		for (int i = 0; i < 10; i++){
			_deck.push_back(SplitTwo(animals[needle % 5], animals[(needle+1) % 5], HORIZONTAL));
			needle += 2;
		}
		for (int i = 0; i < 20; i++){
			_deck.push_back(SplitThree(animals[needle % 5], animals[(needle + 1) % 5], animals[(needle + 2) % 5], VERTICAL));
			needle += 3;
		}
		for (int i = 0; i < 15; i++){
			_deck.push_back(SplitFour(animals[needle % 5], animals[(needle + 1) % 5], animals[(needle + 2) % 5], animals[(needle + 3) % 5]));
			needle += 4;
		}
		for (int i = 0; i < 15; i++){
			//Add action cards
		}
		_deck.push_back(Joker());
	}
public:
	static AnimalCardFactory* getfactory(){
		if (!_factory){
			_factory = new AnimalCardFactory();
		}
		return _factory;
	};
	Deck<shared_ptr<AnimalCard>> getdeck(){
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		shuffle(_deck.begin(), _deck.end(), default_random_engine(seed));
		return _deck;
	}
};