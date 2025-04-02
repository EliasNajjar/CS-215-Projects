/*
Course: CS215 - 09
Project: Lab Assignment 3
Date: 2/7/2025
Purpose: Take either A or D and three numbers from a user and sort them in ascending or descending order based on first input
Author: Elias Najjar
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Your wish is my command!\nI will sort three numbers under your wish:\nEnter A for ascending order, D for descending order (A or D): ";
	string AorD; cin >> AorD;
	
	// vars to print later, ascending or descending and <= or >=
	string AorDoutput;
	string comparisonOutput;

	// set vars and check if input is valid, if it's not A or D, terminate
	if (AorD == "A" || AorD == "a")
	{
		AorDoutput = "ascending";
		comparisonOutput = "<=";
	}
	else if (AorD == "D" || AorD == "d")
	{
		AorDoutput = "descending";
		comparisonOutput = ">=";
	}
	else
	{
		cout << "Invalid choice, quitting the program..." << endl;
		return 0;
	}

	cout << "Please enter three integer numbers: ";
	int num1; cin >> num1;
	int num2; cin >> num2;
	int num3; cin >> num3;

	// temp variable used for switching
	int temp;

	// var to print later, strictly or leniently sorted
	string lenientORstrict = "strictly";
	if (num1 == num2 || num1 == num3 || num2 == num3)
	{
		lenientORstrict = "leniently";
	}

	// if A and num2 is less than num1 or D and num2 is greater than num1, switch them
	if (((AorD == "A" || AorD == "a") && num2 < num1) || ((AorD == "D" || AorD == "d") && num2 > num1))
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	// if A and num3 is less or D and num3 is greater, switch it to its spot
	if (((AorD == "A" || AorD == "a") && num3 < num2) || ((AorD == "D" || AorD == "d") && num3 > num2))
	{
		temp = num2;
		num2 = num3;
		num3 = temp;
		// check num1 and num2 again
		if (((AorD == "A" || AorD == "a") && num2 < num1) || ((AorD == "D" || AorD == "d") && num2 > num1))
		{
			temp = num1;
			num1 = num2;
			num2 = temp;
		}
	}

	cout << "Numbers are sorted in " << AorDoutput << " order: " << endl;
	cout << to_string(num1) << " " << comparisonOutput << " " << to_string(num2) << " " << comparisonOutput << " " << to_string(num3) << endl;
	cout << "Numbers are in " << lenientORstrict << " " << AorDoutput << " order!" << endl;
}