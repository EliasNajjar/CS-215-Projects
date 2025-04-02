#include "card.h"
#include <string>
#include <iomanip>

Card::Card()
{
	suit = 'I';
	point = 0;
}

Card::Card(char s, int p)
{
	suit = s;
	point = p;
}

int Card::getPoint() const
{
	return point;
}

char Card::getSuit() const
{
	return suit;
}

int Card::compareTo(Card other) const
{
	if (point < other.point) { return -1; }
	if (point > other.point) { return 1; }
	return 0;
}

void Card::print() const
{
	string value;
	switch (point) {
	case 11: value = "J"; break;
	case 12: value = "Q"; break;
	case 13: value = "K"; break;
	case 14: value = "A"; break;
	default: value = to_string(point);
	}
	switch (suit) {
	case 'C': cout << CLUB << setw(2) << value << CLUB; break;
	case 'D': cout << DIAMOND << setw(2) << value << DIAMOND; break;
	case 'H': cout << HEART << setw(2) << value << HEART; break;
	default: cout << SPADE << setw(2) << value << SPADE;
	}
}
