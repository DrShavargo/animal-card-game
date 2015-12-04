//#pragma once
//
//#include "AnimalCard.h"
//#include <vector>
//#include <memory>
//
//using namespace std;
//
//template <typename T>
//class Deck<T> : public vector<T>{
//public:
//	shared_ptr<T> draw();
//};
//
//template <typename T>
//class AnimalCardFactory {
//	static AnimalCardFactory *_factory;
//	Deck<T> _deck;
//	AnimalCardFactory(){
//		_deck.push_back();
//	}
//public:
//	static AnimalCardFactory* getFactory(){
//		if (!_factory){
//			_factory = new AnimalCardFactory;
//		}
//		return _factory;
//	};
//	Deck<shared_ptr<AnimalCard>> getDeck();
//};