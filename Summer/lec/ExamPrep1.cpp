#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
	string name;
	Person* spouse;
public:
	Person(string newname = "") :name(newname), spouse(nullptr) {}
	string getName() const { return name; }
	void setName(string newname) { name = newname; }
	bool isMarried()const { return spouse != nullptr; }
	bool marry(Person& other);
	string getSpouseName() const { return isMarried() ? spouse->name : "(NOT MARRIED)"; }
};
bool Person::marry(Person& other) {
	if (isMarried() || other.isMarried())
		return false;
	spouse = &other;
	other.spouse = this; //"this" is a pointer to the calling object (myself)
	return true;
}


void func1(int var) {
	cout << "inside func1" << endl;
	var = 100;
}
void func2(int& var) {
	cout << "inside func2" << endl;
	var = 100;
}

void func3(int* var) {
	cout << "inside func3" << endl;
	var = new int(200); //Incidental memory leak
}
void func4(int*& var) {
	cout << "inside func4" << endl;
	var = new int(200);
}

int main() {
	Person d("Daniel");
	Person g("Gloria");
	g.marry(d); //"this" in the marry function points to the "g" object.
	d.marry(g); //"this" in the marry function points to the "d" object.
	cout << g.getName() << " is married to " << g.getSpouseName() << endl;



	int x = 5;
	cout << "X=" << x << endl;
	func1(x);
	cout << "X=" << x << endl;
	func2(x);
	cout << "X=" << x << endl;

	int* ptr = nullptr;
	x = 5;
	cout << "X=" << x << endl;
	func3(ptr);
	cout << "X=" << x << endl;
	cout << "*ptr=" << *ptr << endl;

	func4(ptr);
	cout << "X=" << x << endl;
	x = 5;
	cout << "X=" << x << endl;
	cout << "*ptr=" << *ptr << endl;
	delete ptr; //to prevent a memory leak from func4's allocation
}