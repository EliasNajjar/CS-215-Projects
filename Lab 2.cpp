// Course: CS215-09
// Project: Lab Assignment 2
// Date: 01/31/2025
// Purpose: Convert CAD to USD and calculate how many of each coin is needed
// Author: Elias Najjar

#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	double CADtoUSD = .69;
	double amountCAD;

	cout << "Convert CAD to USD service." << endl;
	cout << "Please enter the amount of Canadian Dollars you want to exchange: C$ ";
	cin >> amountCAD;
	int amountUSD = round(amountCAD * CADtoUSD * 100);
	cout << "The exchange for C$" << fixed << setprecision(2) << amountCAD << " --> $ " << static_cast<double>(amountUSD) / 100 << " :" << endl;

	// initial amount of USD to be lowered as coins are calculated
	int total = amountUSD;

	// find number of dollars/coins by using integer division
	int dollars = int(total / 100);
	// take what is leftover using modulus
	total %= 100;
	int quarters = int(total / 25);
	total %= 25;
	int dimes = int(total / 10);
	total %= 10;
	int nickels = int(total / 5);
	total %= 5;
	int pennies = int(total);

	cout << "Dollars: " << setw(13) << dollars << endl;
	cout << "Quarters: " << setw(12) << quarters << endl;
	cout << "Dimes: " << setw(15) << dimes << endl;
	cout << "Nickels: " << setw(13) << nickels << endl;
	cout << "Pennies: " << setw(13) << pennies << endl;
}