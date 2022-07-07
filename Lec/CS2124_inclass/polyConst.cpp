//
//  polyConst.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/4/11.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Base{
public:
    Base(){
//        foo();
        this->foo();
    }
    virtual void foo()const {cout << "Base\n";}
    void display(){
//        this->foo();
        foo();
    }
};

class Derived : public Base{
public:
    Derived(int n): Base(), x(n){}
    void foo() const override{cout << "Derived: x == " << x << endl;}
private:
    int x;
};

int main(){
    Derived der(17);
    der.display();
}
