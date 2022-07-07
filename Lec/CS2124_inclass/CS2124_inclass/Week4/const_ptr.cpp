//
//  const_ptr.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/2/14.
//
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Thing{ int val;};

void foo(const Thing& aThing){
    // What kind of pointer can point to aThing?
    const Thing* p = &aThing;
}

int main(){
    int x = 17, y = 42;
    
    // a point that cannot modify what it points at
    const int* p = &x;
    
    // a pointer that can only ever point at one item it started with
    int* const q = &x;
    
    // a pointer can point at a constant item
    const int z =100;
    const int* r = &z;
    // *r = 100;
}
*/
