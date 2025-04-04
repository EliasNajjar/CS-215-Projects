#include "card.h"
#include <string>
#include <iomanip>

// Default constructor.
// We allow uninitialized Cards to be created.
// This allows arrays of Cards.
// Uninitialized cards should have Invalid for its suit
// and 0 for its points.
Card::Card()
{
	suit = 'I';
	point = 0;
}

// Alternate constructor
// Create a Card with specified suit and points.
Card::Card(char s, int p)
{
	suit = s;
	point = p;
}

// access the card point value
int Card::getPoint() const
{
	return point;
}

// access the card suit value
char Card::getSuit() const
{
	return suit;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other) const
{
	if (point < other.point) { return -1; } // this card is less
	if (point > other.point) { return 1; } // this card is greater
	return 0; // cards have the same point the same
}

// Display a description of the Card object to standard output.
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again
//   for example, the card of point 12 and the suit of diamond should display as: ? Q?
//                the card of point 10 and the suit of heart should display as:   ?10?
void Card::print() const
{
	string value;
	switch (point) {
	case 11: value = "J"; break; // 11 is jack
	case 12: value = "Q"; break; // 12 is queen
	case 13: value = "K"; break; // 13 is king
	case 14: value = "A"; break; // 14 is ace
	default: value = to_string(point); // 2-10 are just numbers
	}
	switch (suit) {
	case 'D': cout << DIAMOND << setw(2) << value << DIAMOND; break;
	case 'S': cout << SPADE << setw(2) << value << SPADE; break;
	case 'C': cout << CLUB << setw(2) << value << CLUB; break;
	default: cout << HEART << setw(2) << value << HEART;
	}
}
