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
	list<Card>::iterator pos = cards.begin(); // iterator to the first card
	vector<Card> dropCards; // vector to store dropped cards
	for (int i = 0; i < 3; i++) { // drop three cards
		dropCards.push_back(*pos); // add card to vector
		cards.erase(pos); // remove card
		pos = cards.begin(); // set to new first card
		numCards--; // you lost a card
		if (numCards == 0) { // if you have no more cards
			break;
		}
	}
	return dropCards;
}

// display cards at player's hand
void Player::print() const {
	for (list<Card>::const_iterator pos = cards.begin();pos != cards.end();pos++) { // for each card
		pos->print();
		cout << "\t";
	}
	cout << endl;
}