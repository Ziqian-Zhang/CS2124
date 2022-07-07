//
//  main.cpp
//  lec2
//
//  Created by Z.Q. Zhang on 2022/5/26.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Hello World" << endl;
    cout << "What is your name?";
    string name;
    getline(cin, name);
    
    int age;
    cout << "What is your age?";
    cin >> age;
    
    string place;
    cout << "Where do you live?";
    cin.ignore(9999, '\n');
    getline(cin, place);
    
    int year = 100;
    cout << "How many years have you lived there?";
    cin >> year;
    
    cout << "Name: " << name << endl
        << "Age: " << age << endl
        << "Residence: " << place << endl
        << "Years: " << year << endl;
    cout << "First Initial: " << name[0] << endl;
    cout << "First three letters: " << name.substr(0,3) << endl;
    
    if (age > 21)
        cout << 'A';
    else if (age >18)
        cout << 'B';
    else
        cout << 'C';
    
    cout << endl;
    
    switch (age){
        case 21: cout << "Have a drink." << endl;
        case 18: cout << "Buy a lotto ticket." << endl;
            break;
        default: cout << "Happy Birthday!" << endl;
    }
    
    int grade;
    cout << "What is your numerical grade?";
    cin >> grade;
    char letterGrade;
//    switch (grade){
//        case 100:
//        case 99:
//        case 98:
//        case 97:
//        case 96:
//        case 95:
//        case 94:
//        case 93:
//        case 92:
//        case 91:
//        case 90: letterGrade = 'A';
//    }
}


