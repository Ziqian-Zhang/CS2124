//
//  main.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/1/31.
//

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addOne(int someInt); // function prototype

void addOne(int someInt){ //pass by value
    ++someInt;
}

int addOneV2(int someInt){
    ++someInt;
    return someInt;
}

void addOneRef(int& someInt){ // pass by reference; no copy; if we want to change the value
    ++someInt; //same effect as: someInt += 1
}

void printVec(const vector<int>& someVec){ // pass by constant reference; no change; no copy
    for(int val: someVec){
        cout << val << ' ';
    }
    cout << endl;
    //someVec[] = 42;
}

int main(){
    int x = 17;

    //addOneV2(x);
    x = addOneV2(x);
    cout << x << endl;

//    addOneRef(x);
//    cout << x << endl;
//
    vector<int> v{1, 2, 3, 5, 8, 13, 21};
//    for(int val: v){
//        cout << val << ' ';
//    }
    cout << endl;

    for(int&val:v){
        ++val;
    }

    printVec(v);
}


//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

*/
