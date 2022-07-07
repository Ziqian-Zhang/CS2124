#include <iostream>
#include <string>

using namespace std;

/*
Author: Daniel Katz
Class: CS-UY 2124
Semester: Summer 2022
Grade: A+
*/

int main() {
	int x = 100; //Create the variable x as an integer with a value of 100
	//x = "100";
	//cout << x; //Print the value of x to the screen with a return character
	cout << "The value of x is " << x << endl;
	cout << "5/2 is " << 5 / 2 << endl;

	int y;
	cout << "X before incrementation: " << x << endl;
	y = x++;
	cout << "X after incrementation: " << x << endl;
	cout << "Y's value is " << y << endl;

	if (x<10000) //no curly braces needed
		if (x < 1000)
			cout << "It is less than 1000" << endl;
		else
			cout << "It is more than 1000" << endl;

	if (x < 10) {
		if (x < 0)
			cout << "X is negative" << endl;
	}
	else
		cout << "X is greater than 10!" << endl;

	cout << "What is your name? :";
	string name;
	cin >> name;

	int age;
	cout << "What is your age? ";
	cin >> age;

	double ws;
	cout << "What is the average flight speed of an african swallow? ";
	cin >> ws;

}