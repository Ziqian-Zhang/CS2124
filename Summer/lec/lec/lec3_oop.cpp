//
//  lec3.cpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/5/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;


/*
 Class: A structure on which an object will be built
        components: data & functions
 Object: An instance of the class
        values
*/


class Date{
private: // item that only accessible from within the class; not necessary bc its the default
    int day;
    int month;
    int year;
public: // items that are accessible to everyone
    // Constructor, like __init__
    // Date(); // default constructor
    Date(int unixTime = 0);
    Date(int newDay, int newMonth, int newYear): day(newDay), month(newMonth), year(newYear){}
    
    // Accessor function (getter)
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    
    // Mutator function (setter)
    void setYear(int newYear){ year = newYear; }
    void setMonth(int newMonth); // decoration; defined outside of the class
    void setDay(int newDay);
    void printUSDate()const { cout << month << '/' << day << '/' << year << endl; }
};

Date::Date(int unixTime){
    if (unixTime == 0){
        day = month = 1;
        year = 1970;
    }
    
    tm* timeinfo;
    time_t val = (time_t)unixTime;
    timeinfo = localtime(&val);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon+1;
    year = timeinfo->tm_year;
    
}

//Date::Date(){
//    day = month = 1;
//    year = 1970;
//}

// definition (body)
void Date::setMonth(int newMonth){
    if (newMonth > 0 && newMonth <= 12){
        month = newMonth;
    }
}

void Date::setDay(int newDay){
    if (newDay > 0 && newDay <= 31){
        day = newDay;
    }
}

class Person{
private:
    Date doB;
public:
    int getAge(){ return 2022 - doB.getYear(); }
};

class Student {
    Date dob;
public:
    Student(Date newDob); // dob is required to create a student
};

Student::Student(Date newDob){
    dob = newDob;
}

void printMonth(const Date& d){
    cout << d.getMonth() << endl;
}

int main(){
    Date myDate; // default constructor invoked here
    myDate.printUSDate();
    myDate.setYear(2022);
    
    Date anotherDate(31, 5, 2022); // three argument constructor
    
    //Date currentDate(time(nullptr));
    
    Student a(anotherDate); // parameter must be provided, no
}

