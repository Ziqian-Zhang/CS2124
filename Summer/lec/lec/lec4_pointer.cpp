//
//  lec4.cpp
//  lec: pointer 1
//
//  Created by Z.Q. Zhang on 2022/6/2.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

void func(){
    int* ptr = new int(10);
    delete ptr;
    ptr = nullptr;
}

class Thing {
public:
    int x;
};

class ThingWithPtr{
public:
    int* x;
};

int main(){
    
    int x = 5;
    cout << x << endl;
    cout << &x << endl;
    int* ptr = &x;
    cout << ptr << endl;
    cout << &ptr << endl;
    int** intPtrPtr = &ptr;
    
    cout << "Dereference ptr: " << *ptr << endl;
    cout << "Dereference intPtrPtr: " << **intPtrPtr << endl;
    cout << "X: " << x << endl;
    
    ptr = new int; // a new variable is created on the heap and referenced by ptr
    *ptr = 10;
    cout << *ptr << endl;
    delete ptr; // prevent Garbage on the heap (Memory leak):
                // inaccessible memory, no error produced untill memory is exhausted
     
    
//    for (int i = 0; i < 1000000; i++){
//        func();
//    }
    
    int* ptr = new int(10);
    int* otherptr = ptr;
    cout << "Ptr: " << ptr << endl;
    cout << "OtherPtr: " << otherptr << endl;
    delete ptr;
    // delete otherptr; // double delete: deleting the same memory location twice
    cout << "deleted ptr" << endl;
    cout << "ptr: " << ptr << endl;
    // cout << "ptr's value: " << *ptr << endl;
    cout << "otherptr: " << otherptr << endl; // dangling pointer: a pointer left pointing to memory we shoud no longer access
    cout << "otherptr's value: " << *otherptr << endl;
    ptr = otherptr = nullptr;
    cout << "ptr: " << ptr << endl;
    cout << "otherptr: " << otherptr << endl;
    // cout << "otherptr's value: " << *otherptr << endl;// possibly deref null: attemting to access the value NULL.
    
    int capacity = 100;
    int* arr = new int[capacity]; // An array of 100 integers on the heap
    arr[0] = 100;
    cout << *arr << endl;
    int* second = (arr + 1);// pointer arithmetic, c++ worries about the size of an int
    *second = 200;
    cout << arr[1] << endl;
    int num_item = 1;
    for (int i =0; i < 100; i++){
        int* ptr = arr + 1;
        *ptr = 100;
    }
    
    Thing one;
    one.x = 100;
    Thing* thingPtr = new Thing;
    (*thingPtr).x = 100;
    thingPtr->x = 100; // whatever  is to the left of -> MUST be a pointer
    
    ThingWithPtr twp;
    // twp->x = new int(100); // incorrect
    twp.x = new int(100);
    cout << *twp.x << endl;
    delete thingPtr;
    
    ThingWithPtr* twpPtr = new ThingWithPtr;
    twpPtr->x = new int(200);
    delete twpPtr->x;
    delete twpPtr;
}

