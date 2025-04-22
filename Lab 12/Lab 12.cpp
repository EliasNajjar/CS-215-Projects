/*
 * Course: CS215-09
 * Project: Lab 12
 * Purpose: To reverse each text line, say original, from the user input
 *          Then decide if each of original,is a palindrome or not
 *          A palindrome is defined as a sequence of characters which
 *                       reads the same backward as forward
 ******PLEASE DO NOT CHANGE THIS FILE!******
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include "SuperString.h"

using namespace std;

int main()
{
    string original;
    cout << "Welcome to CS215 Super String operations! " << endl;
    cout << "Please input a string to watch its magic: " << endl;
    getline(cin, original);

    // Stop the loop when the user clicks enter/return key
    while (!original.empty())
    {
        // create s SuperString object
        SuperString magic(original);
        cout << "The original string you type is: ";
        magic.print();
        cout << "Reverse of the string (using a loop): " << magic.rev_loop() << endl;
        cout << "Reverse of the string (using recursion): " << magic.rev_recursion() << endl;
        cout << "Reverse of the string (using a stack): " << magic.rev_stack() << endl << endl;

        // when the boolalpha format flag is set, bool values are represented as true or false, instead of integral values
        // for standard streams, the boolalpha flag is not set on initialization
        cout << boolalpha;
        cout << "Is \" " << magic.getString() << " \" a palindrome? " << endl;
        // note that the following two answers should always be the same
        cout << "Calling member function to decide, the answer is: " << magic.isPalindrome() << endl;
        cout << "Using recursion to decide, the answer is: " << magic.isPalindrome_recursion() << endl;

        // asking for another input string...till the user clicks Ctrl-d
        cout << endl << endl;
        cout << "Please input a string to watch its magic: " << endl;
        getline(cin, original);
    }

    cout << "Quitting CS215 Super String operations. Thank you!" << endl;
    return 0;
}
