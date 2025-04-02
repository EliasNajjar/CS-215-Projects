/*
Course: CS215 - 09
Project: Lab Assignment 4
Date: 2/14/2025
Purpose: Take an 8 digit credit card number and check if it is valid
Author: Elias Najjar
*/

#include <iostream>
using namespace std;

int main()
{
	long long input = 0;

	// loop takes input at least once, then ends when user enter -1
	while (true)
	{
		cout << "Please enter the 8-digit credit card number (enter -1 to quit): ";
		cin >> input;

		// if input is -1, end loop
		if (input == -1)
		{
			break;
		}

		bool doubleDigit = false; // don't double the digit the first time, but it will switch every time
		int sum = 0;
		long long number = input; // copy input variable

		// while number > 0 runs until the last digit has been added then number /= 10 = 0, or the first digit is 0 and it doesn't need to be added
		while (number > 0)
		{
			// take lsat digit
			int currentDigit = number % 10;

			// if we're supposed to double that digit, double it and add those digits
			if (doubleDigit)
			{
				// 2 * currentDigit % 10 gets last digit, currentDigit / 5 adds 1 if 2 * currentDigit >= 10
				sum += 2 * currentDigit % 10 + currentDigit / 5;
			}
			// if we're supposed to just add the digit
			else
			{
				sum += currentDigit;
			}
			// switch doubleDigit
			doubleDigit = !doubleDigit;
			// remove lsat digit
			number /= 10;
		}

		// if the last digit of the sum is 0, its valid
		if (sum % 10 == 0)
		{
			cout << "Number is valid.";
		}
		// if the last digit is not 0, the digit should have been 10 - (the last digit of (sum - the last digit of the input))
		// this is essentially finding the sum without the last digit and, seeing what we need to add for the sum to be 0
		else
		{
			cout << "Number is invalid." << endl;
			cout << "Check digit should have been " << 10 - (sum - input % 10) % 10;
		}
		// go down 2 lines
		cout << endl << endl;
	}

	cout << "Thank you for using Credit Card Number Validation!" << endl;
	return 0;
}