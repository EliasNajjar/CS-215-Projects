/*
 * Course: CS215-09
 * Project: Lab 10 (as the second part of Project 2)
 * Purpose: Testing the definition of Player class.
 *          First, it creates 52 cards on deck (no shuffle)
 *          Second, it deals 26 cards for one player: testPlayer (another 26 cards are put on the pile at table)
 *          Third, testPlayer plays one card from hand, then drop THREE cards from hand
 *          Fourth, testPlayer plays one more card from hand
 *          Then "pretend" testPlayer wins and get FIVE cards on the pile (at the table) and  it displays the cards in testPlayer's hand
 *          Last, display simulation: testPlayer repeatedly plays ONE card, then drops THREE cards,until no more card in hand.
 *
 */
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main()
{
    // Avoid magic numbers
    const int HANDS = 26; // each player holds 52/2 = 26 cards to begin the game
    bool quitOption = false; // prompt quit between turns

    // create an object of Deck class to represent standard 52-card deck
    // create a 52-card deck first
    // for testing purpose:  DO NOT shuffle the cards
    Deck testDeck;
    testDeck.createDeck();
    testDeck.shuffleDeck();

    vector<Card> player1cards;
    vector<Card> player2cards;
    vector<Card> pile;

    for (int i = 0; i < HANDS; i++)
    {
        player1cards.push_back(testDeck.deal_a_card());
        player2cards.push_back(testDeck.deal_a_card());
    }

    Player player1(player1cards);
    Player player2(player2cards);

    while (true) {
        cout << "Player 1 plays: ";
        Card player1played = player1.play_a_card(); // get top card from player 1
        pile.push_back(player1played); // add to pile
        player1played.print();
        cout << endl << "Player 2 plays: ";
        Card player2played = player2.play_a_card(); // get card from player 2
        pile.push_back(player2played);
        player2played.print();

        cout << endl << "----------------------------------------------" << endl << endl;
        cout << "There are " << pile.size() << " cards on the pile!" << endl << endl; // show number of cards in pile
        cout << "----------------------------------------------" << endl;

        if (player1played.compareTo(player2played) == 1) { // if player 1 has the higher card
            cout << "Player 1 wins...get all cards from the pile!" << endl;
            player1.addCards(pile); // pile goes to bottom of player 1
            pile.clear(); // clear pile
        }
        else if (player1played.compareTo(player2played) == -1) {
            cout << "Player 2 wins...get all cards from the pile!" << endl;
            player2.addCards(pile);
            pile.clear();
        }
        else { // they had the same card
            cout << "It is a tie...for this round!" << endl;
            cout << "Each player drops three cards (face down) on the pile, then play one more card (face up)" << endl;
            if (player1.getNumCards() < 4 || player2.getNumCards() < 4) { break; } // if either of them have 3 or less, they will have 0 after the drop, end the game

            for (Card i : player1.dropCards()) { // take cards from player and add to pile
                pile.push_back(i);
            }
            for (Card i : player2.dropCards()) {
                pile.push_back(i);
            }

            cout << "----------------------------------------------" << endl << endl;
            cout << "There are " << pile.size() << " cards on the pile!" << endl << endl;
            cout << "----------------------------------------------" << endl;
        }

        cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl; // show number of cards
        cout << "Player 2 has " << player2.getNumCards() << " cards in hand!" << endl << endl;

        if (player1.getNumCards() == 0 || player2.getNumCards() == 0) { break; } // if they ran out of cards, end the game

        if (quitOption) {
            string input;
            cout << "Do you want to continue...for the next round? (N or n to quit) ";
            getline(cin, input);
            if (input == "N" || input == "n") {
                cout << "You choose to quit the game!" << endl;
                cout << "Player 1 has " << player1.getNumCards() << " cards left!" << endl;
                cout << "Player 2 has " << player2.getNumCards() << " cards left!" << endl;
                return 0;
            }
        }
    }

    cout << "Game is over!" << endl;
    if (player1.getNumCards() == player2.getNumCards()) { // if they both have the same number of cards, it's a tie
        cout << "It is a tie game!" << endl;
        cout << "Player 1 has " << player1.getNumCards() << " cards in hand!" << endl;
        cout << "Player 2 has " << player2.getNumCards() << " cards in hand!" << endl << endl;
    }
    else if (player1.getNumCards() < player2.getNumCards()) { // player 1 has less
        cout << "Player 2 wins the game!" << endl;
    }
    else {
        cout << "Player 1 wins the game!" << endl; // player 1 has more
    }

    return 0;
}
