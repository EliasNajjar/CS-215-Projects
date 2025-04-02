#include "deck.h"
#include <random>

void Deck::createDeck()
{
	for (int i = 0;i < POINTS;i++) {
		for (char j : {'H', 'C', 'S', 'D'}) {
			Card toAdd(j,i+CARD_START);
			deck.push_back(toAdd);
		}
	}
}

void Deck::shuffleDeck()
{
	srand(time(0));
	random_shuffle(deck.begin(), deck.end());
}

Card Deck::deal_a_card()
{
	Card toReturn = *(deck.end()-1);
	deck.pop_back();
	return toReturn;
}
