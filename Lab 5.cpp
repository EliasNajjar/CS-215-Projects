/*
Course: CS215 - 09
Project: Lab Assignment 5
Date: 2/14/2025
Purpose: First, it converts a sequence of numbers to its corresponding Roman Numerals
Second, it repeatedly asks the user to input a triangle size until the user enters "Q" or "q" to quit the program
then displays a triangles using stars (asterisk symbol) and the total rows of stars is equal to the user input size, say n.
(The triangle contains one star at the first line, three little stars at the second line, and so on till 2*n-1 stars at the nth line, and it is symmetric.)
it displays the original triangle then roates the triangle 90-degree clockwise
Author: Elias Najjar
*/

#include <iostream>
#include <iomanip>
#include <limits>       // define numeric_limits
#include <cmath>        // define pow function

using namespace std;

// The compiler needs to see at least function prototype before the function can be called

// It turns a digit into a Roman numeral
string roman_digit(int digit, string one, string five, string ten);

// It returns a string form of a Roman Numeral.
// (n must be between 1 and 3999)
string roman_numeral(int n);

// It prints a triangle of n rows of asterisk, center alignment
// starting with one asterisk at the first row, three at the second row...
void printTri(int n);

// It prints a triangle of asterisk
// It rotates the pattern from printTri function, 90-degree clockwise
void printTriR90(int n);

int main()
{
    const int START = 0;      // The minimum exponent
    const int END = 12;       // The maximum exponent
    const int BASE = 2;       // The base for the power function
    const int WIDTH = 10;     // formatted layout purpose: as WIDTH wide

    cout << "\tWelcome to CS215 Roman Numeral Converter!" << endl;
    cout << "\tDecimal\t\tRoman Numerals" << endl << endl;
    // for the base to each exponent between start and end
    for (int exponent = START;exponent <= END;exponent++)
    {
        int num = pow(BASE, exponent); // BASE^exponent
        cout << setw(WIDTH) << num << setw(WIDTH) << "-->" << setw(WIDTH + 4) << roman_numeral(num) << endl; // convert to roman numerals and print
    }
    cout << endl << endl;

    // complete the following block of code
    // to display the sequence of numbers in the range: (BASE to the power of START, BASE to the power of END)
    // at each line: one number      -->     its Roman Numeral
    // your code starts here...

    const int MINSIZE = 1;
    const int MAXSIZE = 50;
    int triangle_size = 0;
    cout << "Enter the size of your triangle (an integer in [" << MINSIZE << ", " << MAXSIZE << "])" << endl;
    cout << "Type Q (or q) to quit the program: ";
    cin >> triangle_size;

    while (true)
    {
        if (cin.fail())  // the user input is not an integer
        {
            cin.clear();
            string usrOption;   // initialize to empty string
            cin >> usrOption;
            if (usrOption == "Q" || usrOption == "q")  // it satisfies the condition to quit the loop immediately
                break;
            else
                cout << "Invalid size! Expecting an integer in [" << MINSIZE << ", " << MAXSIZE << "]" << endl;
        }
        else  // the user input is an integer
        {
            if (triangle_size >= MINSIZE && triangle_size <= MAXSIZE) // the user input is in the correct range
            {
                cout << "The triangle with size " << triangle_size << " (ROMAN NUMBER: " << roman_numeral(triangle_size) << " ) is:" << endl;
                printTri(triangle_size);
                cout << "The rotation for 90 degrees clockwise: " << endl;
                printTriR90(triangle_size);
            }
            else  // the user input is NOT in the correct range
                cout << "The size is not in the correct range! Expecting the size in [" << MINSIZE << ", " << MAXSIZE << "]" << endl;
        }

        cin.ignore(numeric_limits<int>::max(), '\n'); //extra and ignore any bad input from input stream

        cout << "Enter the size of your triangle (an integer in [" << MINSIZE << ", " << MAXSIZE << "])" << endl;
        cout << "Type Q (or q) to quit the program: ";
        cin >> triangle_size;
    }

    cout << "Thank you, have a great day!" << endl;
    return 0;
}

/*
   Turns a digit into a Roman numeral.
   @param digit the digit to convert into Roman
   @param one string representing the Roman numeral for ones
   @param five string representing the Roman numeral for fives
   @param ten string representing the Roman numeral for tens
   @return string representing the Roman number for digit
*/
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
   Converts a number to its equivalent Roman numeral.
   @param n the number to convert into Roman
   @return string representing the full Roman numeral for digit
*/
string roman_numeral(int n)
{
    const int MIN = 1;
    const int MAX = 3999;
    string numeral = "";
    if (n < MIN || n > MAX) // if not in range, tell the user that
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

/*
   Prints a triangle with n number of rows, getting longer as it goes down. The bottom row has 2*n-1 asterisks
   @param n the number of rows the triangle will have
   @return void
*/
void printTri(int n)
{
    for (int i = 1;i <= n;i++) // for n number of rows
    {
        cout << setw(n - i + 1); // width is n - i + 1 because it needs to be n, then n-1, then n-2...
        for (int j = 0;j < 2 * i - 1;j++) // 2 * rowNumber - 1 is the number of asterisks to print
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
   Prints a rotated triangle with n number of columns, getting shorter as it goes across. The left column has 2*n-1 asterisks
   @param n the number of columns the triangle will have
   @return void
*/
void printTriR90(int n)
{
    for (int i = 1;i <= n;i++) // print n lines
    {
        for (int j = 0;j < i;j++) // print i asterisks on that line
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1;i > 0;i--) // print the remaining n-1 lines
    {
        for (int j = 0;j < i;j++) // print i asterisks, decreasing
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}