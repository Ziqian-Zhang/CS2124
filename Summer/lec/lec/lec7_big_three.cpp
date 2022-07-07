//
//  lec7.cpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/6/16.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class IndexOutOfBounds {}; // Only used for the Exception

template <class T>
class DynArray{
    int currentCapacity; // maximum number of items we could store
    int currentSize; // number of items we are storing
    T* data; // pointer to our data array
    
    void resize(int newCapacity); // theta(N)
public:
    DynArray();
    void push_back(int value); // amortized theta(1)
    T pop_back(); // theta(1)
    int size() const { return currentSize; } // theta(1)
    int capacity() const { return currentCapacity; } // theta(1)
    T getAt(int position) const; // theta(1)
    void setAt(int position, int value); // theta(1); fail if position > current capacity
    void clear(); // theta(1)
    bool isEmpty() const{ return size() == 0; }
    
//    void destroy(){ delete[] data; }, not a good idea, destructor instead
    ~DynArray(){ delete [] data; }
    DynArray<T>& operator=(const DynArray<T>& rhs);
    DynArray(const DynArray& rhs): data(nullptr) {*this = rhs;}
    
    T operator[](int index) const {return data[index]; }
    T& operator[](int index) { return data[index]; }
};

template <class T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& rhs){
    if (this != &rhs){
        delete [] data;
        currentSize  = rhs.currentSize;
        currentCapacity = rhs.currentCapacity;
        data = new int[currentCapacity];
        for (int i = 0; i < currentSize; i++){
            data[i] = rhs.data[i];
        }
    }
    return *this;
}

template <class T>
void DynArray<T>::resize(int newCapacity){
    T* temp = new int[newCapacity];
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

template <class T>
T DynArray<T>::getAt(int position) const {
    if (position >= currentSize || position < 0){
        throw IndexOutOfBounds();
    }
    return data[position];
}

template <class T>
void DynArray<T>::setAt(int position , int value) {
    if (position >= currentCapacity || position < 0){
        throw IndexOutOfBounds();
    } else if (position >= currentSize){
        push_back(value);
        return;
    }
    data[position] = value;
}

template <class T>
DynArray<T>::DynArray(){
    currentCapacity = 5;
    currentSize = 0;
    data = new T[currentCapacity];
}

template <class T>
void DynArray<T>::clear(){
    delete[] data;
    currentCapacity = 5;
    currentSize = 0;
    data = new T[currentCapacity];
}

template <class T>
void DynArray<T>::push_back(int value){
    if (currentSize == currentCapacity){
        resize(currentCapacity * 2);
    }
    data[currentSize++] = value;
}

template <class T>
T DynArray<T>::pop_back(){
    if (currentSize == 0){
        throw IndexOutOfBounds(); // create a new IndexOutOfBounds object and throw it to indicate a problem
    }
    return data[--currentSize];
    /*
    int temp = data[currentSize - 1];
    currentSize -= 1;
    return temp;
     */
}

class HeapMem{
    int* data;
public:
    HeapMem(int newVal = 0): data(new int(newVal)){cout << "constructing a HeapMem object" << endl;}
    
    ~HeapMem(); // Destructor
    HeapMem& operator=(const HeapMem& rhs);
    HeapMem(const HeapMem& rhs);
    
    int getVal() const {return *data;}
    void setVal(int newval) { *data = newval;}
    
    HeapMem(HeapMem& rhs); // move constructor
    HeapMem& operator=(HeapMem& rhs);// move operator
    
};

// destructor
HeapMem::~HeapMem(){
    delete data;
    cout << "destructing a HeapMem object" << endl;
}

// assignment operator
HeapMem& HeapMem::operator=(const HeapMem& rhs){
    if (this != &rhs){
        delete data;
        data = new int(*rhs.data);
    }
    return *this; // 当执行m3 = m2 = m1时, m3 =  (m2 = m1的return value)
}

// copy constructor
HeapMem::HeapMem(const HeapMem& rhs){
    
//    data = new int(*rhs.data);
//    cout << "copy constructing a HeapMem object" << endl;
    
    data = nullptr;
    *this = rhs; // call assignment operator (delete nullptr is SAFE)
}

int main(){
    HeapMem m1(10);
    HeapMem m2 = 10;
    HeapMem m3;
    m3 = m2;
    HeapMem m4(m1);// call  to copy constructor
    
}

// Big three

// Problems:
// 1. memory allocated is never freed -> destructor
// 2. Copying from one object to another causes memory leak and 2 pointers pointing to the same object, causes double delete -> assignment operator
//  a = b, a is a value, b is a value
// 3. Constructing an object "based on" another object results in two pointers pointing to the same thing -> copy constructor


// move operator
// a = b, a exist after, b is empty

HeapMem& HeapMem::operator=(HeapMem& rhs){
    if (this != &rhs){
        data = rhs.data;
        rhs.data = nullptr;
    }
    return *this;
}

// move constructor
HeapMem::HeapMem(HeapMem& rhs){
    data = rhs.data;
    rhs.data = nullptr;
}

