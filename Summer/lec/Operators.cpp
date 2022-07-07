#include <iostream>

using namespace std;

class Measurement; //Pre-definition of Measurement to allow for parameter in Demo
class Demo {
public:
	void changeMeasurement(Measurement& m);
};


class Measurement {
	int feet;
	int inches;
	void normalize();
public:
	/*explicit*/ Measurement(int totalInches = 0) :inches(totalInches) { normalize(); }
	int getInches() const { return inches; }
	int getFeet() const { return feet; }
	void setFeet(int newFeet) { feet = newFeet; }
	void setInches(int newInches);
	int getTotalInches() const { return feet * 12 + inches; }
	Measurement operator+(const Measurement& rhs) const;//Member of the class
	Measurement& operator-=(const Measurement& rhs);
	Measurement& operator++(); //Pre-increment
	Measurement operator++(int); //pos-incremement (due to the int)


	friend istream& operator>>(istream& ins, Measurement& rhs); //NOT A MEMBER!
	friend class Demo; //all of those member functions have access to our private stuff;
};
void Demo::changeMeasurement(Measurement& m) { m.inches++; }

bool operator<(const Measurement& lhs, const Measurement& rhs) {
	return lhs.getTotalInches() < rhs.getTotalInches();
}

bool operator>(const Measurement& lhs, const Measurement& rhs) {
	return rhs < lhs;
}
bool operator<=(const Measurement& lhs, const Measurement& rhs) {
	return !(rhs < lhs);
}
bool operator>=(const Measurement& lhs, const Measurement& rhs) {
	return !(lhs < rhs);
}
bool operator==(const Measurement& lhs, const Measurement& rhs) {
	return !(lhs < rhs || rhs < lhs);
}
bool operator!=(const Measurement& lhs, const Measurement& rhs) {
	return lhs < rhs || rhs < lhs;
}

Measurement& Measurement::operator++() {
	inches++;
	normalize();
	return *this;
}
Measurement Measurement::operator++(int) {
	Measurement temp=*this; //copy this object first
	inches++;
	normalize();
	return temp;
}

Measurement& Measurement::operator-=(const Measurement& rhs) {
	feet -= rhs.feet;
	inches -= rhs.inches;
	normalize();
	return *this;
}

Measurement Measurement::operator+(const Measurement& rhs) const {
	Measurement temp;
	temp.inches = getTotalInches() + rhs.getTotalInches();
	temp.normalize();
	return temp;
}

Measurement operator-(const Measurement& lhs, const Measurement& rhs) { //Non-member of the class
	return Measurement(lhs.getTotalInches() - rhs.getTotalInches());
}

void Measurement::setInches(int newInches) {
	inches = newInches;
	normalize();

}

void Measurement::normalize() {
	if (inches >= 12) {
		feet += inches / 12;
		inches %= 12;
	}
	while (inches < 0) {
		feet--;
		inches += 12;
	}

}

ostream& operator<<(ostream& outs, const Measurement& rhs) {
	outs << rhs.getFeet() << "\' " << rhs.getInches() << "\"";
	return outs;
}
istream& operator>>(istream& ins, Measurement& rhs) { //still a NON MEMBER, just a friend
	ins >> rhs.feet >> rhs.inches;
	return ins;
}

int main() {
	Measurement m1(100);
	Measurement m2(25);
	Measurement m3;

	m3 = m1 + m2;
	m3 = m1 - m2;

	m3 = m1 + 10;
	m3 = m1 - 10;

	m3 = 10 - m1;
	//m3 = 10 + m1;

	m3 = m1++; //post-incrememnt m1.operator(0)
	m3 = ++m1; //pre-incremement m1.operator()
	cout << m1;
	cout << "m1: "<< m1 << endl;
	if (m1 < m2)
		cout << "yup!" << endl;
}