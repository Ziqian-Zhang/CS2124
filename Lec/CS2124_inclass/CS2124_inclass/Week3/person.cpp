//
//  person.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/2/9.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
    friend ostream& operator << (ostream& os, const Person& aPerson);
    
public:
    Person(const string& name) : name(name), spouse(nullptr){}
    
    // ?
    void marries(Person betrothed){
        spouse = &betrothed;
        betrothed.spouse = this; // this: pointer to itself, only inside methods
    }
    
private:
    string name;
    bool hasPartner;
    //Person spouse;
    Person* spouse;
};

int main(){
    Person john("John");
    Person mary("Mary");
    cout << john << endl
    << mary << endl;
    john.marries(mary);
    cout << john << endl
    << mary << endl;
    
    int x = 17;
    cout << &x << endl; // address of operator
    int* p = &x; // pointer // * define type
    cout << p << ' ' << x << endl;
    cout << *p << endl; // dereference operator *
    *p += 2;
    
    // ?
    int *r; // pointer
    int * q; // pointer
    cout << sizeof(p) << ' ' << sizeof(int*)<< ' ' << sizeof(Person*) << endl;
    // sizeof(variable, type)
}

ostream& operator << (ostream& os, const Person& rhs){
    // os << "Person: " << aPerson.getName();
    os << "Name: " << rhs.name;
    if (rhs.spouse != nullptr){
        // os << "; Married to:" << *rhs.spouse;
        // os << "; Married to:" << *rhs.spouse.name;
        os << "; Married to:" << rhs.spouse->name; // arrow operator
    } else {
        os << "; still single." ;
    }
    return os;
}
