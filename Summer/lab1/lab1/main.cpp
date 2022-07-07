//
//  main.cpp
//  lab1
//
//  Created by Ziqian Zhang on 2022/5/27.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
// Task 1
    cout << "Hello World!" << endl;
    
// Task 2
    int operand1;
    char op;
    int operand2;
    int result;
    cout << "Enter a mathematical expression: " << endl;
    cin >> operand1 >> op >> operand2;
    if (op == '+'){
        result = operand1 + operand2;
        cout << operand1 << ' ' << op << ' ' << operand2 << " = " << result << endl;
    } else if (op == '-'){
        result = operand1 - operand2;
        cout << operand1 << ' ' << op << ' ' << operand2 << " = " << result << endl;
    } else if (op == '*'){
        result = operand1 * operand2;
        cout << operand1 << ' ' << op << ' ' << operand2 << " = " << result << endl;
    } else if (op == '/'){
        result = operand1 / operand2;
        cout << operand1 << ' ' << op << ' ' << operand2 << " = " << result << endl;
    }
    
// Task 3
    srand(time(0));
    int place;
    cout << "Enter a number (A negative integer means prepend, positive means append and zero will mean choose (prepend or append) randomly) " << endl;
    cin >> place;
    ifstream inputFile("2124_Lab1_-_57pwordlist.txt");
    string line;
    vector<string> v;
    while (inputFile >> line){
        v.push_back(line);
    }
    int randomNum = rand() % 899 + 100;
    int randomLine = rand() % v.size() + 1;
    int pos = rand() % 4 - 1;
    for (int i = 0; i < v.size(); i++){
        if (i == randomLine){
            if (place > 0){
                cout  << v[i] << randomNum << endl;
            } else if (place < 0){
                cout << randomNum  << v[i] << endl;
            } else {
                if (pos > 0){
                    cout  << v[i] << randomNum << endl;
                } else {
                    cout << randomNum  << v[i] << endl;
                }
            }
        }
    }
     
    
// Task 4
    
    
}

