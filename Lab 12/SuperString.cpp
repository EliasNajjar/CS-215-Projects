#include "SuperString.h"
#include <iostream>
#include <stack>

// constructor: initialize str with ini_str passing as a parameter
SuperString::SuperString(string ini_str) {
    str = ini_str;
}

// return the current value of the private data member: str
string SuperString::getString() const {
    return str;
}

// set the value of str to be the passed in parameter input_str
void SuperString::setString(string input_str) {
    str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string SuperString::rev_loop() const {
    string rev;
    for (int i = str.length() - 1;i >= 0;i--) { // for each element end to beginning
        rev += str[i]; // add to string
    }
    return rev;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string SuperString::rev_recursion() const {
    if (str.length() <= 1) { // if length is 1 or 0, no reversing needed
        return str;
    }
    SuperString middle(str.substr(1, str.length() - 2)); // assign SuperString with middle portion, to be reversed recursively
    return str[str.length() - 1] + middle.rev_recursion() + str[0]; // return last, reversed middle, first
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string SuperString::rev_stack() const {
    stack<char> letters;
    for (char i : str) { // push each letter to the stack so that the last letter is on top
        letters.push(i);
    }
    string rev;
    while (!letters.empty()) { // while there are letters in the stack
        rev += letters.top(); // put the letter in rev
        letters.pop(); // remove from stack
    }
    return rev;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool SuperString::isPalindrome() const {
    //return str == rev_loop(); // simple solution
    for (int i = 0;i < str.length() / 2;i++) { // we need to run through length / 2 iterations, for odd number length we do not need to check the middle
        if (str[i] != str[str.length() - i - 1]) { // if earlier element does not equal later element, getting closer each iteration
            return false;
        }
    }
    return true;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool SuperString::isPalindrome_recursion() const
{
    //return str == rev_recursion(); // simple solution
    // base case
    if (str.length() <= 1) // if length is less than 2, it is a palindrome
        return true;
    SuperString shorter(str.substr(1, str.length() - 2)); // assign SuperString with middle of string
    return str[0] == str[str.length() - 1] && shorter.isPalindrome_recursion(); // return the first equals the last and if the middle is a palindrome
}

// displays str, followed by a new line marker, 
// to the standard output
void SuperString::print() const {
    cout << str << endl;
}