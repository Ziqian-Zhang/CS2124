//
//  oop.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/2/2.
//
//  encapsulation; data hiding

//#include <iostream>
//#include <string>
//using namespace std;
//
//
//// struct is public by default
//// class is private by default
//// struct Person{
//class Person{
//    friend ostream& operator << (ostream& os, const Person& aPerson);
//    // mark a function as a friend: access private field in Person
//    
//public:
////    Person(const string& aName){
////        name = aName;
////    }
//
//// uninitialized primitive
//// default constructor
//    Person(const string& name) : name(name){
//        
//    }
//    
//    void eating() const {
//        cout << name << " eating\n";
//    }
//    
//    void setName(const string& theName){
//        name = theName;
//    }
//    
//    const string& getName() const{
//        return name; // return a copy
//    }
//    
//private:
//    string name; // can be only accessed by the methods in the type
//};
//
//void personEating(const Person& aPerson){
//    cout << aPerson.getName() << " eating\n";
//}
//
//ostream& operator << (ostream& os, const Person& aPerson){
//    // os << "Person: " << aPerson.getName();
//    os << "Person: " << aPerson.name;
//    return os;
//}
//
//int main(){
//    // Person john;
//    Person john("John");
//    john.setName("John");
//    personEating(john);
//    john.eating();
//    
//    Person mary("Mary");
//    cout << mary; // c++不能直接转化为string输出，converge to the below funcion call
//    operator << (cout, mary); // output operator
//    // mary.operator<<(cout); // if operator is a method instead of a function, the order could not be this
//    
//    cout << mary << endl;
//}
