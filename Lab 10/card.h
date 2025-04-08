/* File: card.h
 * Course: CS215-00x
 * Project: Project 2
 * Purpose: the declaration for the Card class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <Windows.h>

using namespace std;

//Windows 11 Terminal Does Not natively support setting the terminal mode to VT100 in the traditional sense
//Because it is a modern terminal emulator designed to support various shells (like PowerShell, Command Prompt, WSL, etc.) with extended ANSI/VT sequences
//To print the playing card suits in Windows 11 terminal, you need to include <Windows.h>
//   and set UTF-8 output: SetConsoleOutputCP(CP_UTF8);
//   cout << u8"\u2663 for Club";
//   cout << u8"\u2666 for Diamond";
//   cout << u8"\u2665 for Heart";
//   cout << u8"\u2660 for Spade";


// the following directly works for the Unix system, including Mac OS
//const char SPADE[] = "\u2660";
//const char CLUB[] = "\u2663";
//const char HEART[] = "\u2665";
//const char DIAMOND[] = "\u2666";

class Card
{
public:
    // Default constructor.
    // We allow uninitialized Cards to be created.
    // This allows arrays of Cards.
    // Uninitialized cards should have Invalid for its suit
    // and 0 for its points.
    Card();

    // Alternate constructor
    // Create a Card with specified suit and points.
    Card(char s, int p);

    // access the card point value
    int getPoint() const;

    // access the card suit value
    char getSuit() const;

    // compare with another Card object passed in as parameter: other
    // if the object your are working on has higher point than other, return 1;
    // if the object your are working on has lower point than other, return -1;
    // otherwise, return 0
    int compareTo(Card other) const;

    // Display a description of the Card object to standard output.
    // The output should look like:
    //   the sign of suit, followed by the point, then followed by the sign of suit again
    //   for example, the card of point 12 and the suit of diamond should display as: ♦ Q♦
    //                the card of point 10 and the suit of heart should display as:   ♥10♥
    void print() const;

private:
    char suit;    // suit of the card: I--Invalid, S--Spade, C--Club, H--Heart, D--Diamond
    int point;    // point value of the card, in the range of [2, 14]  J--11; Q--12; k--13 and A--14
    // For the suit of a playing card:
    // I means Invalid, which represents the Card object has not been initialized.
    // S represents Spade; C represents Club; H represents Heart and D represents Diamond

    // For the point value of a playing card:
    // A point value of 0 means the Card object has not been initialized.
    // J = 11, Q = 12, K = 13, A = 14.
    // A point value of 1 is not used.
};
#endif  /* CARD_H */

