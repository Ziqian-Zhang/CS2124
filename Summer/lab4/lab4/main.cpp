//
//  main.cpp
//  lab4
//
//  Created by Z.Q. Zhang on 2022/6/10.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Person{
private:
    string name;
    int phoneNum;
public:
    
};

class PhoneNumber{
private:
    
};

class PhoneBook{
private:
    vector<Person> pp;
};

struct SomeStruct {
         int data;
};

int main() {
//    ifstream file;
//    string fileName;
//    cout << "Enter a file name: " << endl;
//    cin >> fileName;
//    file.open(fileName);
//    if (!file){
//        cerr << "Failed to open the file" << endl;
//    }
//    double gpa;
//    string name;
//    vector<double> gpas;
//    vector<string> names;
//    while (file >> gpa >> name){
//        gpas.push_back(gpa);
//        names.push_back(name);
//    }
//    int highest_index = 0;
//    for (int i = 0; i < gpas.size(); i++){
//        if (gpas[i] > gpas[highest_index]){
//            highest_index = i;
//        }
//    }
//    cout << "The valedictorian is: " << names[highest_index] << endl;
    
    SomeStruct* ptr;
    
    int x = 2;
     int y = 4;
     int arr[] = {1, 2, 3, 5, 8, 13, 21, 34, 55};
     int* p = arr + 3;
     int* q = p + x;
     cout << "A: " << *q << endl;
     p = &y;
     *q = *p + x;
     *p = q[3];
     cout  << "B: " << *q++ << endl;
     cout  << "C: " << *q << endl;
     cout  << "D: " << y << endl;
}
