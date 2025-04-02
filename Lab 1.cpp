#include <iostream>

using namespace std;


int main()
{
	cout << "Hi Cameron," << endl
		 << "I am glad you are my TA." << endl
		 << "My name is Elias. Nice to meet you!" << endl;

	cout << "  Let it snow!" << endl
		 << "    *  *  *" << endl
		 << "   *   *   *" << endl
		 << "  *    *    *" << endl
		 << " *           *" << endl
		 << "   *  *  *  *" << endl;

	cout << "   _" << endl
		 << "  /_\\" << endl
		 << " (o o)" << endl
		 << " ( : )" << endl
		 << " ( : )" << endl
		 << "  ___" << endl;

	double numCourses;
	string coursePlural = "s";
	cout << "It is a snow day!" << endl
		 << "How many courses do you have today?" << endl;
	cin >> numCourses;
	numCourses = floor(numCourses);
	if (numCourses == 1)
	{
		coursePlural = "";
	}
	cout << "Enjoy your " << numCourses << " course" << coursePlural << "!" << endl;
	cout << "Have a beautiful snow day." << endl << endl;

	double hours = 0.0; // declare a variable to store how many hours
	cout << "How many hours are you going to spend on CS215 every week?" << endl;
	cin >> hours;
	const int HOUR_TO_MIN = 60; //declare a constant: 1 hour = 60 minutes
	const int MIN_TO_SEC = 60; //declare a constant: 1 minute = 60 seconds
	double seconds = hours * HOUR_TO_MIN * MIN_TO_SEC;
	cout << "Good Luck! You will spend " << seconds << " seconds each week on CS215." << endl;
}