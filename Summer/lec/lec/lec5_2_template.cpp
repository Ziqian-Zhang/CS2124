//
//  lec5_2.cpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/6/7.
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
    void destroy(){ delete[] data; }
    T operator[](int index) const {return data[index]; }
    T& operator[](int index) { return data[index]; }
};

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

