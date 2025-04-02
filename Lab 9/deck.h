/* File: deck.h
 * Course: CS215-09
 * Project: Project 2
 * Purpose: the declaration for the Deck class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */
#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

using namespace std;

// Avoid magic numbers
// define constants for a standard 52-card deck: 4 suits * 13 point values
const int CARD_START = 2;  // the card value starting at 2
const int POINTS = 13;   // standard 52-card deck includes 13 different point values in the range of [2, 14]

class Deck
{
public:
    // create a standard 52-card deck
    // Avoid duplicate cards, follow the dictionary order of chars for suit: C->D->H->S
    //                        and the increasing order of point for point: 2->3->…->14
    void createDeck();

    // shuffle the cards in 52-card deck
    void shuffleDeck();

    // return a card from the tail of the deck
    Card deal_a_card();

private:
    vector<Card> deck;  // store the Card objects in the vector to present current cards on the deck
                        // each Card object represents a valid card from standard 52-card game, no duplicate cards
};

#endif  /* DECK_H */
