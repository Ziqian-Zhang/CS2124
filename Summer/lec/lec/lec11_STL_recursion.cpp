//
//  lec11_STL_recursion.cpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/6/30.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <ctime>
#include <map>


using namespace std;

double sumArray(int* arr, int size) { //arr is an array!
    if (size == 0)
        return 0;
    double smaller = sumArray(arr, size - 1);
    double retval = smaller + arr[size-1];
    return retval;
}
double sumArray2(int* arr, int size) { //arr is an array!
    if (size == 0)
        return 0;
    double smaller = sumArray2(arr+1, size - 1);
    double retval = smaller + (* arr);
    return retval;
}
double power(int base, int exp) {
    if (exp == 0)
        return 1;
    else if (exp > 0) {
        //return base * power(base, exp - 1);
        double smaller = power(base, exp - 1);
        double retval = base * smaller;
        return retval;
    }
    else { //exp<0
        return 1 / power(base, -exp);
    }
}

void countUp(int n) {
    if (n <= 0) //Base Case
        return;
    countUp(n - 1); //Reduction of the set by the single case
    cout << n << endl; //Single Case
}

void countDown(int n) {
    if (n <= 0) //Base Case
        return;
    cout << n << endl; //Single Case
    countDown(n - 1); //Reduction of the set by the single case

}
void printAB(int n) {
    if (n <= 0)
        return;
    cout << 'A';
    printAB(n - 1);
    cout << 'B';
}
bool isPalindrome(const char* str, int size) {
    if (size <= 0)
        return true;
    if (str[0] < 'A' || str[0] > 'Z')
        return isPalindrome(str + 1, size - 1);
    else if (str[size - 1] < 'A' || str[size - 1] > 'Z')
        return isPalindrome(str, size - 1);
    else if (str[0] != str[size - 1])
        return false;
    return isPalindrome(str + 1, size - 2);
}
void printList(const list<int>& l) {
    for (list<int>::const_iterator i = l.begin(); i != l.end(); i++) {
        cout << *i << endl;
    }
}
class Thing {
    int x;
    int y;
public:
    Thing(int newx=0,int newy=0) :x(newx),y(newy) {}
    int getX() const { return x; }
    void setX(int newx) { x = newx; }
    int getY() const { return y; }
    void setY(int newy) { y = newy; }
};

bool lessThanOnX(const Thing& lhs, const Thing& rhs) {
    return lhs.getX() < rhs.getX();
}

class ThingLessThanOnXFunctor {
public:
    bool operator() (const Thing& lhs, const Thing& rhs)const { return lhs.getX() < rhs.getX(); }
};
class ThingLessThanOnYFunctor {
public:
    bool operator() (const Thing& lhs, const Thing& rhs)const { return lhs.getY() < rhs.getY(); }
};

int main() {
    /*pair<string, int> p1;
    p1.first = "Daniel";
    p1.second = 100;
    */
    map<string, int> m;
    m["Daniel"] = 90; // m.operator[]("Daniel", 90)
    if (m.find("John")!=m.end())
        cout << m["John"] << endl;

    for (map<string, int>::iterator i = m.begin(); i != m.end(); i++)
        cout << i->first<<"="<<i->second << endl;
    /*
    srand(time(NULL)); //seeding the random number generator with the current time
    set<Thing, ThingLessThanOnXFunctor> s;
    for (int i = 0; i < 100; i++)
        s.insert(Thing(rand() % 1000));

    for (set<Thing>::iterator i = s.begin(); i != s.end(); i++)
        cout << i->getX() << endl;

    cout << "Size of set: " << s.size() << endl;
    *//*
    list<Thing> l;
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        l.push_back(Thing(i * 10, 100-i*10));
        v.push_back(i * 10);
    }
    ThingLessThanOnXFunctor t1;
    ThingLessThanOnYFunctor t2;
    l.sort(t1); //sort the entire item.
    l.sort(t2); //sort the entire item.
    l.sort(lessThanOnX); //Passing in a function pointer!!!
    for (list<Thing>::iterator i = l.begin(); i != l.end(); i++)
        cout << i->getX() << endl; //operator*

    */
    /*Thing a(10);
    Thing b(20);
    ThingLessThanFunctor t1;
    if (t1(a, b))
        cout << "Yes";
    */
    
    //sort(v.begin(), v.end()); //Sort a subset
    //sort(l.begin(), l.end());
        /*
    const char* cstr = "A MAN, A PLAN, A CANAL, PANAMA!"; //Pointer can change, characters cannot
    *//*char* const cptr; //characters can change, pointer cannot
    char* cptr2; //Characters AND pointer can change
    const char * const cptr3; //Characters cannot change, pointer cannot change!
    */
    /*if (isPalindrome(cstr, strlen(cstr)))
        cout << "That is a palindrome!" << endl;
    else
        cout << "That is NOT a palindrome!" << endl;
    *///printAB(3); //AAABBB
    /*int* arr = new int[3];
    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    sumArray2(arr,3);
    delete[] arr;
    arr = nullptr;*/
}
