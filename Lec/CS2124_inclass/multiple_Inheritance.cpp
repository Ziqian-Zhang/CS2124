//
//  animal.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/4/11.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class Flier{
public:
    virtual void fly() = 0;
};

void Flier::fly(){cout << "I can fly!!!\n";}

class Animal{
    virtual void display(){cout << "Animal\n";}
};

class Bat : public Animal, public Flier{
public:
    void fly(){cout << "flap...flap"; Flier::fly();}
};

class Insect : public Animal, public Flier{
public:
    void fly(){cout << "Bzzzz."; Flier::fly();}
};

class Plane : public Flier{
public:
    void fly(){
        cout << "vroooommmm!";
    }
};

class Student {
public:
    virtual void display() const {
        cout<< "Student\n";
    }
private:
    string name;
};

class Instructor {
public:
    virtual void display() const {
        cout<< "Instructor\n";
    }
private:
    string name;
};

class TA : public Student, public Instructor{
public:
//    void display() const {
//        Student::display();
//    }
    using Student::display;
};

int main(){
    TA rohit;
    // rohit.display() // ambiguous
}
