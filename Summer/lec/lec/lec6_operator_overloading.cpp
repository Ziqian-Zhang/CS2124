//
//  lec6.cpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/6/9.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Person{
//    string name;
//    Person* spouse;
//public:
//    Person(string newName = ""): name(newName), spouse(nullptr){}
//    string getName() const {return name;}
//    void setName(string newname){ name = newname;}
//    bool isMarried() const {return spouse != nullptr;}
//    bool marry(Person& other);
//    string getSpouseName() const { return isMarried() ? spouse->name : "(Not Married)";}
//    // conditional operator:
//    // (condition) ? (value if true) : (value if false);
//};
//
//bool Person::marry(Person& other){
//    if (isMarried()|| other.isMarried()){
//        return false;
//    }
//    spouse = &other;
//    other.spouse = this; // "this" is a pointer to the calling object (myself)
//    return true;
//}
//
//int main(){
//    Person d("Daniel");
//    Person g("Gloria");
//    d.marry(g);
//    g.marry(d);
//    cout << g.getName() << " is married to " << g.getSpouseName() << endl;
//}
//
//void func1(int var){
//    cout << "inside func1" << endl;
//    var = 100;
//}
//
//void func2(int& var){
//    cout << "inside func2" << endl;
//    var = 100;
//}
//
//void func3(int* var){
//    cout << "inside func3" << endl;
////    *var = 100;
//    var = new int(100);// incidental memory leak
//}
//
//void func4(int*& var){
//    cout << "inside func4" << endl;
////    *var = 200;
//    var = new int(200);
//}

//int main(){
//    int x = 5;
//    cout << "x = " << x << endl;
//    func1(x);
//    cout << "x = " << x << endl;
//    func2(x);
//    cout << "x = " << x << endl;
//
//    int* ptr = &x;
//    x = 9;
//    func3(ptr);
//    cout << "x = " << x << endl;
//    cout << "*ptr = " << *ptr << endl;
//
//    func4(ptr);
//    cout << "x = " << x << endl;
//    x = 5;
//    cout << "x = " << x << endl;
//    cout << "*ptr = " << *ptr << endl; // *ptr != x ???
//
//    delete ptr; // prevent a memory leak from func4's allocation; set to nullptr???
//}

class Measurement;

class Demo{
public:
    void changeMeasurement(Measurement& m);
};

class Measurement{
    int feet;
    int inches;
    void normalize();
public:
    /*explicit*/ Measurement(int totalInches = 0): inches(totalInches) {normalize();}
    int getInches() const { return inches;}
    int getFeet() const { return feet;}
    void setFeet(int newFeet){ feet = newFeet;}
    void setInches(int newInches);
    int getTotalInches() const{ return feet * 12 + inches;}
    Measurement operator+(const Measurement& rhs) const; // operator overloading
    Measurement& operator-=(const Measurement& rhs);
    Measurement& operator++(); // pre-increment
    Measurement operator++(int); // post-increment (due to the int)
    
    friend istream& operator>>(istream& ins, Measurement& rhs); // NOT A MEMBER
    friend class Demo;
};

void Demo::changeMeasurement(Measurement& m){ m.inches++; }

bool operator<(const Measurement& lhs, const Measurement& rhs){
    return lhs.getTotalInches() < rhs.getTotalInches();
}

bool operator>(const Measurement& lhs, const Measurement& rhs){
    return rhs < lhs;
}

bool operator<=(const Measurement& lhs, const Measurement& rhs){
    return !(rhs < lhs);
}

bool operator>=(const Measurement& lhs, const Measurement& rhs){
    return !(lhs < rhs);
}

bool operator==(const Measurement& lhs, const Measurement& rhs){
    return !(lhs < rhs || rhs < lhs);
}

bool operator!=(const Measurement& lhs, const Measurement& rhs){
    return lhs < rhs || rhs < lhs;
}

Measurement& Measurement::operator++(){
    inches++;
    normalize();
    return *this;
}

Measurement Measurement::operator++(int){
    Measurement temp(*this); // copy this object first
    inches++;
    normalize();
    return temp;
}

Measurement& Measurement::operator-=(const Measurement& rhs){
    feet -= rhs.feet;
    inches -= rhs.inches;
    normalize();
    return *this;
}

Measurement Measurement::operator+(const Measurement& rhs) const { // member
    Measurement temp;
    temp.inches = getTotalInches() + rhs.getTotalInches();
    temp.normalize();
    return temp;
}

Measurement operator-(const Measurement& lhs, const Measurement& rhs){ // Non-member
    return Measurement(lhs.getTotalInches() - rhs.getTotalInches());
}

void Measurement::normalize(){
    if (inches >= 12){
        feet +=inches/12;
        inches %= 12;
    }
    while (inches < 0){
        feet --;
        inches += 12;
    }
}

ostream& operator<<(ostream& outs, const Measurement& rhs){
    outs << rhs.getFeet() << "\'" << rhs.getInches() << "\"" << endl;
    return outs;
}

istream& operator>>(istream& ins, Measurement& rhs){
    ins >> rhs.feet >> rhs.inches;
    return ins;
}

int main(){
    Measurement m1(100);
    Measurement m2(25);
    Measurement m3;
    
    m3 = m1 + m2;
    m3 = m1 - m2;
    
    m3 = m1 + 10;
    m3 = m1 - 10;
    
    m3 = 10 - m1;
//    m3 = 10 + m1;
    
    m1++; // post-increment m1.operator(0)
    ++m1; // pre-increment  m1.operator()
}

// code -> equivalent function call;
// a + b -> (member)     a.operator+(b)
//       -> (non-member) operator+(a,b)

// unary operator:
// ! () ++ --
// + - *(deref) &(address of)
// bool
// new delete

// binary operator:
// + - * / %
// . ->
// = == != > < >= <=
// << >>
// && || & |
// []

// ternary operator:
// ?:


// Operator that cannot be overload:
// ?: . *. size of ::

// Operator that can only be overloaded as a member of the class:
// [] =

// Operator that make no sense as members:
// << >>


