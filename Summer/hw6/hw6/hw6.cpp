//
//  main.cpp
//  hw6
//
//  Created by Ziqian Zhang on 2022/6/24.
//

#include <iostream>
#include <string>
using namespace std;

class IndexOutOfBounds {};

class StringSet{
private:
    string* data;
    int setSize;
    int capacity;
    
    void resize(int newCapacity){
        string* temp = new string[newCapacity];
        int copyLimit;
        if (newCapacity <= setSize){
            copyLimit = newCapacity;
        } else{
            copyLimit = setSize;
        }
        for (int i = 0; i < copyLimit; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCapacity;
    }
public:
    StringSet(){
        setSize = 0;
        capacity = 100;
        data = new string[capacity];
    }
    
    StringSet(string initial[], int initialSize){
        setSize = 0;
        capacity = 100;
        data = new string[capacity];
        for (int i = 0; i < initialSize; i++){
            data[i] = initial[i];
            setSize++;
        }
    }
    void addString(const string& s){
        if (setSize == capacity){
            resize(capacity * 2);
        }
        setSize++;
        data[setSize - 1] = s;
        for (int i = 0; i < setSize - 1; i++){
            if (data[i] == s) {
                data[setSize - 1] = "";
                setSize--;
            }
        }
    }
    void removeString(const string& s){
        if(setSize == 0){
            throw IndexOutOfBounds();
        }
        for (int i = 0; i < setSize; i++){
            if(data[i] == s){
                for(int j = i; j < setSize; j++){
                    data[j] = data[j + 1];
                }
                data[setSize - 1] = "";
                setSize--;
            }
        }
    }
    void clear(){
        delete[] data;
        setSize = 0;
        capacity = 100;
        data = new string[capacity];
    }
    int size(){ return setSize; }
    friend ostream& operator<<(ostream& os, const StringSet& s);
    friend StringSet operator+(const StringSet& s1, const StringSet& s2);
    friend StringSet operator*(const StringSet& s1, const StringSet& s2);
};

ostream& operator<<(ostream& os, const StringSet& s){
    for (int i = 0; i < s.setSize; i++){
        os << s.data[i] << ' ';
    }
    return os;
}

StringSet operator+(const StringSet& s1, const StringSet& s2){
    StringSet result;
    for (int i = 0; i < s1.setSize; i++){
        result.addString(s1.data[i]);
    }
    for (int i = 0; i < s2.setSize; i++){
        for(int j = 0; j < s1.setSize; j++){
            if(result.data[j] == s2.data[i]){
                break;
            }
            result.addString(s2.data[i]);
        }
    }
    return result;
}

StringSet operator*(const StringSet& s1, const StringSet& s2){
    StringSet result;
    for (int i = 0; i < s1.setSize; i++){
        for(int j = 0; j < s2.setSize; j++){
            if(s1.data[i] == s2.data[j]){
                result.addString(s1.data[i]);
            }
        }
    }
    return result;
}

int main() {
    string s1[3] = {"a", "b", "c"};
    StringSet set1(s1, 3);
    cout << "String set 1: " << set1 << endl;
    cout << "Size of set 1: " << set1.size() << endl;
    set1.addString("d");
    cout << "Add a string (d) to set 1: " << set1 << endl;
    set1.removeString("d");
    cout << "Remove a string (d) from set 1: " << set1 << endl;
    set1.clear();
    cout << "Clear set 1: " << set1 << " Size of set 1: " << set1.size() << endl;
    
    cout << "***************************************\nTest for overloaded operators:\n";
    string s2[2] = {"a", "d"};
    StringSet test1(s1, 3);
    StringSet test2(s2, 2);
    cout << "test set 1: " << test1 << endl;
    cout << "test set 2: " << test2 << endl;
    cout << "Union of two test sets: " << test1 + test2 << endl;
    cout << "Intersection of two test sets: " << test1 * test2 << endl;
}
