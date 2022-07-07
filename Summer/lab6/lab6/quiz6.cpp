//
//  quiz6.cpp
//  lab6
//
//  Created by Ziqian Zhang on 2022/6/17.
//

#include <iostream>
using namespace std;

class IndexOutOfBounds {};

template <class T>
class Stack{
    int currentSize;
    int currentCapacity;
    T* data;
    void resize(int newCapacity){
        T* temp = new int[newCapacity];
        int copyLimit;
        if (newCapacity <= currentSize) {
            copyLimit = newCapacity;
            currentSize = newCapacity;
        }
        else
            copyLimit = currentSize;
        for (int i = 0; i < copyLimit; i++)
            temp[i] = data[i];
        delete[] data;
        data = temp;
        currentCapacity = newCapacity;
    }
public:
    // constructor
    Stack(){
        currentSize = 0;
        currentCapacity = 5;
        data = new T[currentCapacity];
    }
    
    // copy constructor
    Stack(const Stack& rhs) : data(nullptr) { *this = rhs; }
    
    // assignment operator
    Stack& operator=(const Stack& rhs){
        if (this != &rhs) {
            delete[] data;
            currentSize = rhs.currentSize;
            currentCapacity = rhs.currentCapacity;
            data = new int[currentCapacity];
            for (int i = 0; i < currentSize; i++)
                data[i] = rhs.data[i];
        }
        return *this;
    }
    
    // destructor
    ~Stack(){ delete[] data; }
    
    void push_back(T value){
        if (currentSize == currentCapacity)
            resize(currentCapacity * 2);
        data[currentSize++] = value;
    }
    T pop_back(){
        if (currentSize == 0)
            throw IndexOutOfBounds();
        return data[--currentSize];
    }
    T top() const{
        return data[currentSize];
    }
    void clear(){
        delete[] data;
        currentCapacity = 5;
        currentSize = 0;
        data = new T[currentCapacity];
    }
    bool isEmpty() {return currentSize == 0;}
};
