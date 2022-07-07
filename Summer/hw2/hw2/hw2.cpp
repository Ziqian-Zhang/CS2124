//
//  hw2.cpp
//  hw2
//
//  Created by Ziqian Zhang on 2022/6/3.
//

#include <iostream>
using namespace std;

class Measurement{
public:
    Measurement(){
        feet = 0;
        inch = 0;
    };
    Measurement(int input){
        if (input < 0){
            // adjust feet to be a nagetive number
            feet = input / 12;
            inch = - input % 12;
            if (feet == 0){
                inch = input % 12; // not sure if it is contradict with the range of inch (0 ~ 11)
            }
        } else if (input > 11){
            feet = input / 12;
            inch = input % 12;
        } else {
            inch = input;
            feet = 0;
        }
    }
    
    int inch;
    int feet;
};

int main() {
    Measurement m;
    cout << m.feet << " feet " << m.inch << " inches" << endl;
    Measurement num1(8);
    cout << num1.feet << " feet " << num1.inch << " inches" << endl;
    Measurement num2(13);
    cout << num2.feet << " feet " << num2.inch << " inches" << endl;
    Measurement num3(-3);
    cout << num3.feet << " feet " << num3.inch << " inches" << endl;
    Measurement num4(-13);
    cout << num4.feet << " feet " << num4.inch << " inches" << endl;
}
