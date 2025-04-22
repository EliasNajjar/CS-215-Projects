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
    for (int i = str.length() - 1;i >= 0;i--) {
        rev += str[i];
    }
    return rev;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string SuperString::rev_recursion() const {
    if (str.length() < 2) {
        return str;
    }
    SuperString middle(str.substr(1, str.length() - 2));
    return str[str.length() - 1] + middle.rev_recursion() + str[0];
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string SuperString::rev_stack() const {
    stack<char> letters;
    for (char i : str) {
        letters.push(i);
    }
    string rev;
    while (!letters.empty()) {
        rev += letters.top();
        letters.pop();
    }
    return rev;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool SuperString::isPalindrome() const {
    for (int i = 0;i < str.length() / 2;i++) {
        if (str[i] != str[str.length() - i - 1]) {
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
    // base case
    if (str.length() <= 1)
        return true;
    else // recursive case
    {
        SuperString shorter(str.substr(1, str.length() - 2));
        if (str[0] == str[str.length() - 1]) {
            return shorter.isPalindrome_recursion();
        }
        return false;
    }
}

// displays str, followed by a new line marker, 
// to the standard output
void SuperString::print() const {
    cout << str << endl;
}