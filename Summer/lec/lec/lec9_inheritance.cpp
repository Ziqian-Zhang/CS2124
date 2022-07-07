//
//  lec9_inheritance.cpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/6/23.
//

#include <iostream>
using namespace std;

class Pet{// abstract  because of speak
    string name;
public:
    Pet(string newname = ""): name(newname){}
    string getName() const { return name;}
    virtual void changeName(string newname) { name = newname; speak();}
    // eat
    // speak
    virtual void speak() const = 0; // pure virtual function, note the absence of {}
};

class Dog : public Pet{
    int usualWalkingTime;
public:
    Dog(string newname, int newusualWalkingTime = 240):
    usualWalkingTime(newusualWalkingTime), Pet(newname) {}
    int getUsualWalkingTime()const { return usualWalkingTime;}
    void changeTime(int newWalkingTime){ usualWalkingTime = newWalkingTime;}
    void changeName(string newname){
        usualWalkingTime = 240;
        Pet::changeName(newname);
    }
    void changeName(string newname, int newusualWalkingTime){
        usualWalkingTime = newusualWalkingTime;
        Pet::changeName(newname);
    }
    Dog& operator=(const Pet& p){
//        changeName(p.getName());
        usualWalkingTime = 240;
        Pet::operator=(p);// same as *this = p but with base class operator =
        return *this;
    }
    virtual void speak() const{ cout << " Woof! Woof!" << endl;}
};

ostream& operator<<(ostream& os, const Dog& d){
    os << "Name: " << d.getName() << "\tTime: " << d.getUsualWalkingTime() << endl;
    return os;
}

class HeapMemInt{
    int* i;
public:
    HeapMemInt(int newi = 0): i(new int(newi)){}
    HeapMemInt(const HeapMemInt& rhs): i(new int(*rhs.i)){}
    HeapMemInt& operator=(const HeapMemInt& rhs){*i = *rhs.i; return *this;}
    virtual ~HeapMemInt(){delete i;}
};

class HeapMemTwo: public HeapMemInt{
public:
    double* d;
    HeapMemTwo(int newi = 0, double newd = 0): HeapMemInt(newi), d(new double(newd)){}
    HeapMemTwo(const HeapMemTwo& rhs) : d(new double(*rhs.d)), HeapMemInt(rhs){}
    virtual ~HeapMemTwo(){delete d; d = nullptr;}
    HeapMemTwo& operator=(const HeapMemTwo& rhs){
        *d = *rhs.d;
        HeapMemInt::operator=(rhs);
        return *this;
    }
};

int main(){
//    Pet p1;
    /* Pure virtual
     • If the base class should contain a function, but doesn't know what the
     function should actually do, the function can be marked as pure
     virtual "=0"
     • If a class contains ANY pure virtual functions, it will be an abstract
     class
     • You cannot create an instance (object) of an abstract class
     • You can create pointers and have them point to derived class objects
     • You can call the pure virtual function in the derived class via the base pointer
     */
    
    Dog fido("fido");
    Dog fluffy("fluffy");
    /*
    fido = fluffy;
    
    p1 = fido; // default slicing; return name : fluffy
    
    fido = p1; // not by default; copy base class into a derived class
                // assignment operator, change the name, make the time to the default
    */
    
    Pet* pptr;
    Dog* dptr;
    dptr = &fido;
    dptr->changeTime(1080);
    dptr->changeName("fluffy"); // Name: fluffy Time: 240
    
    // base class pointer CAN point to a derived class pointer
    // only access the base class stuff
    pptr = &fido;
    pptr->changeName("fluffy");// 只改变名字; changeName改成virtual, time change to default
    
//    dptr = &p1; // this can NEVER be done
}

// every destructor should be virtual
