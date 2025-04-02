/* File: Lab8.cpp
 * Course: CS215-9
 * Project: Lab 8
 * Purpose: Provide the delcaration of the class named Clock
 *			Note that it represents a 24-hour clock (or you can call it military time)
 * Author: Elias Najjar
 */

#include "Clock.h"

int main()
{
	//write each statement for each operation below in ()
	Clock C1; // (create Clock object C1)
	C1.setClock(3, -5, 16); // (set C1 with h : m:s = 3 : -5 : 16)
	C1.setClock(0, 0, 5); // (set C1 with h : m:s = 0 : 0 : 5)
	Clock C2(12, 35, 59); // (create second Clock object C2 with h : m:s = 12 : 35 : 59)
	cout << "Clock C1 -- ";
	C1.printTime(); // (print C1)
	cout << "Clock C2 -- ";
	C2.printTime(); // (print C2)
	int comparison = C1.compareTime(C2); // (compare C1 with C2)
	if (comparison < 0) {
		cout << "C1 is earlier than C2" << endl;
	}
	else if (comparison > 0) {
		cout << "C1 is later than C2" << endl;
	}
	else {
		cout << "C1 is the same as C2" << endl;
	}
	C1.addTime(C2); // (add C2 into C1)
	cout << "Clock C1 -- ";
	C1.printTime(); // (print C1)
	cout << "Clock C2 -- ";
	C2.printTime(); // (print C2)
	comparison = C1.compareTime(C2); // (compare C1 with C2)
	if (comparison < 0) {
		cout << "C1 is earlier than C2" << endl;
	}
	else if (comparison > 0) {
		cout << "C1 is later than C2" << endl;
	}
	else {
		cout << "C1 is the same as C2" << endl;
	}
	C1.incrementSeconds(55); // (increase clock C1 by 55 seconds)
	cout << "Clock C1 -- ";
	C1.printTime(); // (print C1)
	C1.incrementMinutes(119); // (increase clock C1 by 119 minutes)
	cout << "Clock C1 -- ";
	C1.printTime(); // (print C1)
	C1.incrementHours(22); // (increase clock C1 by 22 hours)
	cout << "Clock C1 -- ";
	C1.printTime(); // (print C1)
	cout << "Clock C2 -- ";
	C2.printTime(); // (print C2)
	comparison = C1.compareTime(C2); // (compare C1 with C2)
	if (comparison < 0) {
		cout << "C1 is earlier than C2" << endl;
	}
	else if (comparison > 0) {
		cout << "C1 is later than C2" << endl;
	}
	else {
		cout << "C1 is the same as C2" << endl;
	}
	return 0;
}