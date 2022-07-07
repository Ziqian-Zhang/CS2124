//
//  main.cpp
//  lab7
//
//  Created by Z.Q. Zhang on 2022/6/24.
//
/*
#include <iostream>
using namespace std;

class myLocation{
protected:
    int x;
    int y;
public:
    myLocation(){cout << "no argument constructor of myLocation" << endl;}
    myLocation(int x, int y): x(x), y(y){ cout << "two argument constructor of myLocation" << endl;}
    //friend ostream& operator<<(ostream& os, const myLocation& l);
    virtual void display() const {
        cout << "display function of myLocation" << endl;
    }
};

//ostream& operator<<(ostream& os, const myLocation& l){
//    os << "display function of myLocation" << endl;
//    return os;
//}

class myPoint: public myLocation{
    char color;
public:
    myPoint(){cout << "no argument constructor of myPoint" << endl;}
    myPoint(int x, int y, char c): myLocation(x,y), color(c){
        cout << "three argument constructor of myPoint" << endl;
    }
    //friend ostream& operator<<(ostream& os, const myPoint& p);
    void display() const {
        cout << "display function of myPoint" << endl;
    }
};

//ostream& operator<<(ostream& os, const myPoint& p){
//    os << "display function of myPoint" << endl;
//    return os;
//}

int main() {
    myPoint p1;
    myPoint p2(1,2,3);
    p1.display();
    p2.display();
    myLocation* loc;
    loc = &p1;
    (*loc).display();
    loc = &p2;
    (*loc).display();
}
*/
