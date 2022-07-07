#include<iostream>
#include "Thing.h"
#include "SecondClass.h"

using namespace std;

class Base {
private:
	int baseThing;
protected: //allows derived classes access but, otherwise, acts like private
	int thingWhichDerivedCanAccess;
public:
	Base(int newthing = 0) :baseThing(newthing) {}
	int getThing() const { return baseThing; }
	void setThing(int newthing) { baseThing = newthing; }
};

class Derived : public Base {
private:
	double derivedThing;
public:
	Derived(double newval = 0) :Base(100), derivedThing(newval) { thingWhichDerivedCanAccess = 100; }
	Derived(int baseVal, double doubleVal) :Base(baseVal), derivedThing(doubleVal) {}
	void setDerivedThing(double newthing) { derivedThing = newthing; }
	double getDerivedThing() const { return derivedThing; }
	void setThing(int newthing); //Override
	void setThing(int newInt, double newDouble); //Not an override, this didn't exist in Base
};
/*class MoreDerived : public Derived, public Base {

};*/
void Derived::setThing(int newthing) {
	derivedThing -= 1;
	//setThing(newthing); //infinite recursion!
	Base::setThing(newthing); //call to base's version of this same function!
}


void Derived::setThing(int newInt, double newDouble) {
	derivedThing = newDouble;
	setThing(newInt); //call to derived version of setThing
}

class A {
public:
	int val;
	A() { cout << "inside A's constructor" << endl; }
};

class C {
public:
	C() { cout << "inside C's constructor" << endl; }

};
class B:public A {
public:
	C c;
	B() { cout << "inside B's constructor" << endl; }
};


int main() {
	B b;
	cout << "*****************************************" << endl;
	Derived d1(5.5);
	d1.setThing(10);
	Base b1(10);
	b1.setThing(100);
	d1.setThing(200);
	Derived d2(6.7);
	cout << d2.getThing() << " " << d2.getDerivedThing() << endl;
	//d2.thingWhichDerivedCanAccess = 100; //not allowed, protected!
}