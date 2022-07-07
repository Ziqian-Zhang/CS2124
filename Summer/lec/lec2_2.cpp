//
//  lec2.cpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/5/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void helloFunc(){
    cout << "Hello World";
}

int countFunc(){
    return 10;
}

int addone(int a , int b = 1){
    return a + b;
}

void valueExample(int& x){
    cout << x << endl;
    x += 1;
}

void printVec(const vector<int>& v){
//    v[0] = 100;
    for (size_t i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

const double MATH_PI = 3.1415926;


int main() {
    helloFunc();
    countFunc();
    int val;
    val = countFunc();
    val = addone(100);
    val = addone(100, 200);
//    val = addone(b = 200, a = 100);
    
    val = 10;
    valueExample(val);
    cout << "value after value example: " << val << endl;
    
    
    int numLoops = 0;
    cout << "How many?";
    cin >> numLoops;
    int count = 0;
    vector<int> v;
    while (count < numLoops){
        int hiddenVar;
        cout << "Hello World" << endl;
        count++;
        v.push_back(count);
        hiddenVar = count;
    }
//    cout << hiddenVar;
    
    for (int i = 0; i < v.size() ; i++){
        cout << v[i] << endl;
    }
    
    for (int count = 0, j = 100; count < numLoops; count++, j *= 10){
        cout << "Hello World" << j << endl;
    }
//    cout << j << endl;
     

void printHello(ostream& output){
    output << "hello world" << endl;
}

void openInputFile(ifstream& inFile){
    string filename;
    cout << "What input filename?";
    cin >> filename;
    inFile.clear();
    inFile.open(filename);
}

int main(){
    ifstream inFile;
    openInputFile(inFile);
    int num;
    int sum = 0;
    while (inFile >> num){
        sum += num;
        cout << "The sum iof the numbers in the file is: " << sum;
    }
    cout << "What is the file name?";
    string filename;
    cin >> filename;
    
    ofstream outfile;
    outfile.open(filename);
    
    printHello(outfile);
    cout << "Done" << endl;
}

