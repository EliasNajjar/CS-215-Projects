#include "deck.h"
#include <random>

// create a standard 52-card deck
	// Avoid duplicate cards, follow the dictionary order of chars for suit: C->D->H->S
	//                        and the increasing order of point for point: 2->3->…->14
void Deck::createDeck() {
	for (int i = CARD_START;i < CPOINTS + CARD_START;i++) { // for numbers 2-14
		for (char j : {'C', 'D', 'H', 'S'}) { // for suits D, S, C, H
			Card toAdd(j, i); // initialize card
			deck.push_back(toAdd); // add card to deck
		}
	}
}

// shuffle the cards in 52-card deck
void Deck::shuffleDeck() {
	srand(time(0)); // set seed
	random_shuffle(deck.begin(), deck.end()); // shuffle deck
}

// return a card from the tail of the deck
Card Deck::deal_a_card() {
	Card toReturn = deck.back(); // get last card
	deck.pop_back(); // remove last card
	return toReturn; // return card that was removed
}