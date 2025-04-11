#include "player.h"

// default constructor
Player::Player() {
	numCards = 0;
	cards = {};
}

// alternative constructor
Player::Player(vector<Card> ini_cards) {
	numCards = ini_cards.size();
	for (int i = 0; i < numCards; i++) {
		cards.push_back(ini_cards[i]);
	}
}

// return how many cards player holds currently
int Player::getNumCards() const {
	return numCards;
}

// player plays one card from the front of cards at hand
Card Player::play_a_card() {
	Card toReturn = cards.front(); // get the first card
	cards.pop_front(); // remove the first card
	numCards--;
	return toReturn; // print the card
}

// when the player wins the round, this function will be called
// player adds winning cards to the end of the cards at hand 
void Player::addCards(vector<Card> winningCards) {
	for (int i = 0; i < winningCards.size(); i++) { // for each card to add
		cards.push_back(winningCards[i]); // add card
		numCards++; // you gained a card
	}
}

// when there is a tie, this function will be called
// player drops THREE cards from the front of cards at hand
vector<Card> Player::dropCards() {
	vector<Card> dropCards; // vector to store dropped cards
	for (int i = 0; i < 3 && cards.size() > 0; i++) { // drop three cards
		dropCards.push_back(cards.front()); // add card to vector
		cards.pop_front(); // remove card
		numCards--; // you lost a card
	}
	return dropCards;
}

// display cards at player's hand
void Player::print() const {
	for (Card c : cards) { // for each card
		c.print();
		cout << "\t";
	}
	cout << endl;
}