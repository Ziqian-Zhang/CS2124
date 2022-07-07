//
//  oop2.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/2/7.
//


#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Date{
//    friend ostream& operator << (ostream& os, const Date& theDate);
//public:
//    // constructor
//    Date(int m, int d, int y) : month(m), day(d), year(y){}
//private:
//    int month, day, year;
//};

//ostream& operator << (ostream& os, const Date& theDate){
//    os << theDate.month << '/' << theDate.day << '/' << theDate.year;
//    return os;
//}

class Person{
    friend ostream& operator << (ostream& os, const Person& aPerson);
    // mark a function as a friend: access private field in Person
    
public:
    class Date{
        friend ostream& operator << (ostream& os, const Date& theDate);
    public:
        // constructor
        Date(int m, int d, int y) : month(m), day(d), year(y){}
    private:
        int month, day, year;
    };
    
    Person(const string& name, int m, int d, int y) : name(name), bday(m, d, y){}
    
    friend ostream& operator << (ostream& os, const Person::Date& theDate);
    
private:
    string name;
    Date bday;
};

ostream& operator << (ostream& os, const Person& aPerson){
    // os << "Person: " << aPerson.getName();
    os << "Person: " << aPerson.name;
    return os;
}

ostream& operator << (ostream& os, const Person::Date& theDate){
    os << theDate.month << '/' << theDate.day << '/' << theDate.year;
    return os;
}


int main(){
    Person john("John", 2, 7, 2000);
    cout << john << endl;
}

