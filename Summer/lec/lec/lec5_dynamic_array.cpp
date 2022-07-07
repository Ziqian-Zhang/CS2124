//
//  lec5.cpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/6/7.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

class IndexOutOfBounds {}; // Only used for the Exception

// template <class T>
class DynArray{
    int currentCapacity; // maximum number of items we could store
    int currentSize; // number of items we are storing
    int* data; // pointer to our data array
    
    void resize(int newCapacity); // theta(N)
public:
    DynArray();
    void push_back(int value); // amortized theta(1)
    int pop_back(); // theta(1)
    int size() const { return currentSize; } // theta(1)
    int capacity() const { return currentCapacity; } // theta(1)
    int  getAt(int position) const; // theta(1)
    void setAt(int position, int value); // theta(1); fail if position > current capacity
    void clear(); // theta(1)
    bool isEmpty() const{ return size() == 0; }
    void destroy(){ delete[] data; }
};

void DynArray::resize(int newCapacity){
    int* temp = new int[newCapacity];
    int copyLimit;
    if (newCapacity <= currentSize){
        copyLimit = newCapacity;
    } else{
        copyLimit = currentSize;
    }
    for (int i = 0; i < copyLimit; i++){
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    currentCapacity = newCapacity;
}

int DynArray::getAt(int position) const {
    if (position >= currentSize || position < 0){
        throw IndexOutOfBounds();
    }
    return data[position];
}

void DynArray::setAt(int position , int value) {
    if (position >= currentCapacity || position < 0){
        throw IndexOutOfBounds();
    } else if (position >= currentSize){
        push_back(value);
        return;
    }
    data[position] = value;
}

DynArray::DynArray(){
    currentCapacity = 5;
    currentSize = 0;
    data = new int[currentCapacity];
}

void DynArray::clear(){
    delete[] data;
    currentCapacity = 5;
    currentSize = 0;
    data = new int[currentCapacity];
}

void DynArray::push_back(int value){
    if (currentSize == currentCapacity){
        resize(currentCapacity * 2);
    }
    data[currentSize++] = value;
}
int DynArray::pop_back(){
    if (currentSize == 0){
        throw IndexOutOfBounds(); // create a new IndexOutOfBounds object and throw it to indicate a problem
    }
    return data[--currentSize];
    /*
    int temp = data[currentSize - 1];
    currentSize -= 1;
    return temp;
     
}

/*
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
void swap(string& a, string& b){
    string temp = a;
    a = b;
    b = temp;
 }
     */
/*
//template <class T> // could also be tamplate<typename T>; T could be anything you like
void mySwap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
class Thing{
public:
    Thing(T newVal = T()); // I don't know what a new value should be for this, so I'll use default
    T x;
};

template <class T>
Thing<T>::Thing(T newVal){
    x = newVal;
}
 */
    
void func(){
    DynArray d1;
    d1.destroy();
}

int main(){
    Thing<int> t1;
    Thing<string> t2;
    Thing<double> t3;
    
    vector<int> v;
    
    DynArray d1;
    for (int i = 0; i < 100; i++){
        d1.push_back(i * 10);
    }
    for (int i = 0; i < d1.size(); i++){
        cout << d1.getAt(i) << endl;
    }
    cout << "********************" << endl;
    while (!d1.isEmpty()){
        cout << d1.pop_back() << endl;
    }
    /*
    int size = 100;
    const int CONST_SIZE = 100;
    cout << "What size? ";
    cin >> size;
    // int arr[size]; // stack-dynamic array; size must be known at compile time
    int arr[CONST_SIZE];
    int* dynarr = new int[size]; // Heap-Dynamic array, size can be dynamic
     */
}

