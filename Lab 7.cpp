/*
Course: CS215 - 09
Project: Lab Assignment 7
Date: 2/28/2025
Purpose: Takes 6 scores from the user, removes the highest and lowest, and finds the average, the final score
Author: Elias Najjar
*/

#include <iostream>
#include <iomanip>
using namespace std;


/*
Removes the highest and lowest values in an array by shifting all other values to replace them,
the last 2 values in the array will be bad data and size will be decreased by 2
@param double scores[] the array with the scores
@param int& size the size of the array
@return void
*/
void dropTWO(double scores[], int& size)
{
	// initialize the min and max positions to the start of the array
	int minPos = 0;
	int maxPos = 0;
	for (int i = 1;i < size;i++) // for each element except the first, the first is the initial position
	{
		if (scores[i] < scores[minPos]) // new min
		{
			minPos = i;
		}
		else if (scores[i] > scores[maxPos]) // new max
		{
			maxPos = i;
		}
	}

	for (int i = minPos;i < size - 1;i++) // for every element at and after the minPos index
	{
		scores[i] = scores[i + 1]; // move it to 1 index less
	}
	if (maxPos > minPos) // if maxPos was greater than minPos, its position has shifted to 1 less
	{
		maxPos--;
	}
	for (int i = maxPos;i < size - 2;i++) // for every element at and after the minPos index
	{
		scores[i] = scores[i + 1]; // move it to 1 index less, now the elements to be used are in the first 4 indexes
	}
	size -= 2; // 2 elements were removed
}


/*
Calculates the average of a given number of elements in an array
@param double scores[] the array with the scores
@param int& size the size of the array
@return sum/size, the average
*/
double final_score(double scores[], int size)
{
	double sum = 0;
	for (int i = 0;i < size;i++) // for each element
	{
		sum += scores[i]; // add the element
	}
	return sum / size; // return average
}

void main()
{
	const int NUMBER_OF_SCORES = 6;
	const double MIN_SCORE = 0;
	const double MAX_SCORE = 10;
	double score;
	double scores[NUMBER_OF_SCORES];

	for (int i = 0;i < NUMBER_OF_SCORES; i++) // for each score to be input
	{
		cout << "Please enter your score for the gymnast:" << endl;
		cin >> score;
		if (cin.fail())
		{
			cin.clear();
			cout << fixed << setprecision(2) << "Invalid score! Expecting a score in the range [" << MIN_SCORE << ", " << MAX_SCORE << "]" << endl;
			i--; // decrement i so that the loop will not end early
		}
		else if (score < MIN_SCORE || score > MAX_SCORE)
		{
			cout << "Score is NOT in the correct range!" << endl;
			i--; // decrement i so that the loop will not end early
		}
		else
		{
			scores[i] = score; // add the input to the array
		}
		cin.ignore(numeric_limits<int>::max(), '\n');
	}

	cout << "The scores from the judges are:" << endl;
	for (int i = 0;i < NUMBER_OF_SCORES;i++)
	{
		cout << scores[i] << "    "; // print each element
	}
	cout << endl << "The scores after dropping the highest and lowest scores:" << endl;
	int newNumScores = NUMBER_OF_SCORES; // new size after removal
	dropTWO(scores, newNumScores); // remove the highest and lowest scores
	for (int i = 0;i < newNumScores;i++)
	{
		cout << scores[i] << "    "; // print the elements used for the final score
	}
	cout << endl << "Final Execution Score is: " << final_score(scores, newNumScores) << endl; // print final score
}