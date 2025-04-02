/*
Course: CS215 - 09
Project: Project 1
Date: 2/21/2025
Purpose: Takes a year as input from the user and prints the Super Bowl number in Roman Numerals as long as
the year is between 1967 (the first Super Bowl) and 5965 (Super Bowl 3999, the max amount possible in Roman Numerals)
Author: Elias Najjar
*/

#include <iostream>
#include <iomanip>

using namespace std;

string roman_numeral(int n);

// define the correct range for Roman Numerals: [MIN_ROMAN, MAX_ROMAN]
const int MIN_ROMAN = 1;
const int MAX_ROMAN = 3999;

void main()
{
    while (true)
    {
        // The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum)
        const int START_SUPERBOWL = 1967;
        // the largest year possible is 5965 because that is super bowl 3999, the largest number in roman numerals
        const int FINAL_YEAR = START_SUPERBOWL + MAX_ROMAN - MIN_ROMAN;
        // The roman numeral function must be called with the year-offset because 1967 corresponds to 1 and so on
        const int offset = START_SUPERBOWL - 1;

        // print information
        cout << "*************************************************************" << endl;
        cout << "*      The Super Bowl is the annual final playoff game      *" << endl;
        cout << "*          of the NFL to determine the league champion.     *" << endl;
        cout << "*  The first Super Bowl took place on January 15, " << START_SUPERBOWL << ".     *" << endl;
        cout << "*  Super Bowl " << roman_numeral(START_SUPERBOWL - offset) << " (Los Angeles Memorial Coliseum) -- > " << START_SUPERBOWL << "   *" << endl;
        cout << "*                                                           *" << endl;
        cout << "*  Super Bowl " << roman_numeral(2025-offset) << " was played on February 9, 2025            *" << endl;
        cout << "*                 at Caesars Superdome in New Orleans.      *" << endl;
        cout << "*      Philadelphia Eagles 40 -- Kansas City Chiefs 22      *" << endl;
        cout << "*                                                           *" << endl;
        cout << "* This Roman Numerals Convertor is written by Elias Najjar. *" << endl;
        cout << "* If you had a time machine, which year of Super Bowl       *" << endl;
        cout << "* would you want to attend (" << START_SUPERBOWL << " - " << FINAL_YEAR << ") ?                  *" << endl;
        cout << "*************************************************************" << endl;

        // get year from user
        cout << "Please enter the year you want to attend (click Q or q to quit):" << endl;
        int year; cin >> year;

        // check for q to end
        if (cin.fail())
        {
            cin.clear();
            string usrOption;   // initialize to empty string
            cin >> usrOption;
            if (usrOption == "Q" || usrOption == "q")  // it satisfies the condition to quit the loop immediately
            {
                break;
            }
            else // not q so invalid input
            {
                cout << "Please use four-digit number to represent a year (" << START_SUPERBOWL << " - " << START_SUPERBOWL + MAX_ROMAN - MIN_ROMAN << ")!" << endl;
            }
        }
        else // valid input
        {
            cout << "The time machine will bring you to the year of " << year << ":" << endl;
            if (year < START_SUPERBOWL) // if too early
            {
                cout << "Wait!!! The year you enter is TOO EARLIER than the first Super Bowl!" << endl;
            }
            else if (year > FINAL_YEAR) // if too late
            {
                cout << "Hold on!!! The year you enter is TOO BIG for Roman Numerals!" << endl;
            }
            else // valid input
            {
                cout << "It is Super Bowl " << roman_numeral(year - offset) << endl; // year-offset is the super bowl number
                cout << "We will help you find out the result and other interesting" << endl;
                cout << "information...next time:)" << endl;
            }
        }
        cout << endl << endl;
        cin.ignore(numeric_limits<int>::max(), '\n'); //extra and ignore any bad input from input stream
    }
    cout << "Back to 2025, and have a great day!" << endl;
}

string roman_digit(int digit, string one, string five, string ten)
{
    //using switch statement
    string roman;
    switch (digit)
    {
    case 1: roman = one;
        break;
    case 2: roman = one + one;
        break;
    case 3: roman = one + one + one;
        break;
    case 4: roman = one + five;
        break;
    case 5: roman = five;
        break;
    case 6: roman = five + one;
        break;
    case 7: roman = five + one + one;
        break;
    case 8: roman = five + one + one + one;
        break;
    case 9: roman = one + ten;
        break;
    default: break;
    }
    return roman;
}

/*
Purpose: convert the integer n to its corresponding Roman Numeral
n must be between 1 and 3999
it returns string form of the Roman Numeral
@param n int: representing the number to convert into Roman Numeral
@return string: representing the corresponding Roman Numeral for n
*/
string roman_numeral(int n)
{
    string numeral;
    if (n < MIN_ROMAN || n > MAX_ROMAN) // if not in range, tell the user that
    {
        return "\tError: NOT in the correct range!";
    }
    numeral += roman_digit(n / 1000, "M", "", ""); // print an M for each of the thousands because it can only be 1, 2, or 3
    n %= 1000; // remove thousands place
    numeral += roman_digit(n / 100, "C", "D", "M"); // print the roman numeral corresponding to the hundereds place
    n %= 100; // remove hundreds place
    numeral += roman_digit(n / 10, "X", "L", "C"); // print the roman numeral corresponding to the tens place
    n %= 10; // remove tens place
    numeral += roman_digit(n, "I", "V", "X"); // print the roman numeral corresponding to the ones place
    return numeral;
}