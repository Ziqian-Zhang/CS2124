//
//  copy_control.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/2/23.
//
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Thing{
    friend ostream& operator<<(ostream& os, const Thing& rhs);
public:
    Thing(int x, const string& foo): foo(foo){ p=new int(x); }
    void setValue(int val){*p = val;}
    int getValue() const { return *p;}
    
    // destructor
    ~Thing(){ delete p;}
    
    // copy constructor
    Thing(const Thing& rhs): foo(rhs.foo){
        p = new int(*rhs.p);
    }
    
    // assignment operator
    // aThing = anotherThing;
    // aThing.operator=(anotherThing);
    Thing operator = (const Thing& rhs) {
        // self assignment test
        if (this != &rhs ){
            // 1. Free up resources
            delete p;
            
            // 2. Allocate and copy
            p = new int(*rhs.p);
            
            foo = rhs.foo;
        }
        // 3. return something or other
        return *this;
    }
    
private:
    int* p;
    string foo;
};

void doNothing(Thing something){}

void simpleFunc(){
    Thing aThing(17);
    cout << aThing << endl;
    doNothing(aThing);
    
    Thing anotherThing(6);
    
//    aThing = anotherThing;
//    aThing.operator=(anotherThing);
}
ostream& operator<<(ostream& os, const Thing& rhs){
    os << *rhs.p;
    return os;
}

int main(){
    simpleFunc();
    Thing* thingPtr = new Thing(42);
    
    int x = 6;
    int y = 28;
    
    x = y;
}
*/
