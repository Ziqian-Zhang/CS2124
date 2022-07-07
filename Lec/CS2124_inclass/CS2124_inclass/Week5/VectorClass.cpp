//
//  VectorClass.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/2/23.
//
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vector{
public:
    Vector(){
        theSize = 0;
        theCapacity = 0;
        data = nullptr;
    }
    Vector(size_t size,int value = 0){}
    
    // *** copy control ***
    
    // Destructor
    ~Vector(){
        delete [] data;
    }
    // copy constructor
    Vector(const Vector& rhs){
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];
        for (size_t i = 0; i < theSize; ++i){
            data[i] = rhs.data[i];
        }
    }
    
    // assignment operator
    // v3 = v
    Vector& operator = (const Vector& rhs){
        // self assignment
        if (this != &rhs){
            // free up
            delete [] data;
            
            // allocate and copy
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            data = new int[theCapacity];
            for (size_t i = 0; i < theSize; ++i){
                data[i] = rhs.data[i];
            }
        }
        // return self
        return *this;
    }
    
    void push_back(int val){
        // make sure we have enough space
        if (theSize == theCapacity){
            if (theCapacity == 0){
                delete data;
                data = new int[1];
                theCapacity = 1;
            } else {
                int* old = data;
                // create a new array
                data = new int[2*theCapacity];
                // move the data over
                for (size_t i = 0; i < theSize; ++i){
                    data[i] = old[i];
                }
                // double the capacity
                theCapacity *= 2;
                // free up the memory
                // delete old; No!
                delete [] old;
            }
        }
        // add the value to the array
        // *(data + theSize) = val;
        data[theSize] = val;
        ++theSize;
    }
    size_t size() const{
        return theSize;
    }
    void clear(){
        theSize = 0;
    }
    void pop_back(){
        --theSize;
    }
    
    // Square brackets;
    // v[i]
    // v.operator[i]
    int operator[](size_t index) const {
        return data[index];
    }
    
    // v.begin()
    const int* begin() const{ // 前一个const使返回的data指针不可改变
                                // 后一个const 避免compile error
        return data;
    }
    
    // v.end()
    const int* end() const{
        return data + theSize;
    }
private:
    size_t theSize;
    size_t theCapacity;
    int* data;
};

int main(){
    Vector v; // No templated.Our vector class can only hold ints
    v.push_back(17);
    
    Vector v2(v);
    
    Vector v3;
    v3 = v;
    for (size_t i = 0; i < v.size();++i){
        cout << v[i] << endl;
        v[i];
        v.operator[](i);
        // operator[](v,i); // illegal
    }
}
*/
