#include "Clock.h"

//default constructor
Clock::Clock() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

//alternative constructor
Clock::Clock(int hh, int mm, int ss) {
	if (hh < 0 || mm < 0 || ss < 0) { // negative means invalid time
		cout << "Invalid time!" << endl;
	}
	hours = hh; // set data members
	minutes = mm;
	seconds = ss;
}

//Helper function to validate the data members
//it only serves the member functions of this class, hence private
void Clock::adjustClock() {
	if(seconds >= HOUR_MIN_SEC) { // if seconds are above 60
		minutes += seconds / HOUR_MIN_SEC; // increase minutes by: 60->1, 120->2...
		seconds %= HOUR_MIN_SEC; // seconds must be below 60
	}
	if (minutes >= HOUR_MIN_SEC) { // do the same for minutes
		hours += minutes / HOUR_MIN_SEC;
		minutes %= HOUR_MIN_SEC;
	}
	if (hours >= HOURS_TO_WRAP) { // if hours is above 24
		hours %= HOURS_TO_WRAP; // reset to be below 24
	}
}

//set time to hh:mm:ss
void Clock::setClock(int hh, int mm, int ss) { // same as constructor
	if (hh < 0 || mm < 0 || ss < 0) {
		cout << "Invalid time!" << endl;
	}
	hours = hh;
	minutes = mm;
	seconds = ss;
}
//increase time by sec seconds
void Clock::incrementSeconds(int sec) {
	seconds += sec;
	adjustClock();
}

//increase time by min minutes
void Clock::incrementMinutes(int min) {
	minutes += min;
	adjustClock();
}

//increase time by hh hours, 
//if hours reach 24, simply wrap around to 0.
void Clock::incrementHours(int hh) {
	hours += hh;
	adjustClock();
}

//add C into the current clock time
void Clock::addTime(Clock C) {
	hours += C.hours; // add data members from C object to this
	minutes += C.minutes;
	seconds += C.seconds;
	adjustClock();
}

//print time in hours:minutes:seconds in 24-hour format
void Clock::printTime() const {
	cout << setfill('0') << setw(2) << hours << " : " << setw(2) << minutes << " : " << setw(2) << seconds << endl; // print in format hours : minutes : seconds
}

//compare with C, if it is earlier than C, return -1;
// if it is the same time as C, return 0;
// if it is later than C, return 1.
int Clock::compareTime(Clock C) const {
	if (hours < C.hours) { return -1; } // check hours first
	if (hours > C.hours) { return 1; }
	if (minutes < C.minutes) { return -1; } // then minutes
	if (minutes > C.minutes) { return 1; }
	if (seconds < C.seconds) { return -1; } // then seconds
	if (seconds > C.seconds) { return 1; }
	return 0; // if none of the previous were true, they are the same time
}