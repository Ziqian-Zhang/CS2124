//
//  main.cpp
//  hw5
//
//  Created by Ziqian Zhang on 2022/6/16.
//

#include <iostream>
using namespace std;

class Date{
public:
    Date(int d = 0, int h = 0, int m = 0): day(d), hour(h), minute(m){ adjust(); }
    
    // constraints
    void adjust();
    
    // getter and setter
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    void setDay(int d);
    void setHour(int h);
    void setMinute(int m);
    
    // output operator overloading
    friend ostream& operator<<(ostream& os, const Date& date);
    
    // pre-increment
    Date& operator++();
    
    // post-increment
    Date operator++(int num);
    
    // pre-decrement
    Date& operator--();
    
    // post-decrement
    Date operator--(int num);
private:
    int day;
    int hour;
    int minute;
};

void Date::adjust(){
    while (minute > 59){
        hour += 1;
        minute -= 60;
    }
    while (minute < 0){
        hour -= 1;
        minute += 60;
    }
    while (hour > 23){
        day += 1;
        hour -= 24;
    }
    while (hour < 0){
        day -= 1;
        hour += 24;
    }
}

int Date::getDay() const { return day; }
int Date::getHour() const { return hour; }
int Date::getMinute() const { return minute; }
void Date::setDay(int d) { day = d; }
void Date::setHour(int h) {
    hour = h;
    adjust();
}
void Date::setMinute(int m) {
    minute = m;
    adjust();
}

ostream& operator<<(ostream& os, const Date& date){
    os << date.hour << ":" ;
    if(date.minute < 10){
        os << "0" << date.minute;
    } else {
        os << date.minute;
    }
    os << " (" << date.day << ")" << endl;
    return os;
}

Date& Date::operator++(){
    minute++;
    adjust();
    return *this;
}

Date Date::operator++(int num){
    Date result(*this);
    minute++;
    adjust();
    return result;
}

Date& Date::operator--(){
    minute--;
    adjust();
    return *this;
}

Date Date::operator--(int num){
    Date result(*this);
    minute--;
    adjust();
    return result;
}

Date operator+(const Date& lhs, const Date& rhs){
    Date result;
    result.setDay(lhs.getDay() + rhs.getDay());
    result.setHour(lhs.getHour() + rhs.getHour());
    result.setMinute(lhs.getMinute() + rhs.getMinute());
    result.adjust();
    return result;
}

Date operator-(const Date& lhs, const Date& rhs){
    Date result;
    result.setDay(lhs.getDay() - rhs.getDay());
    result.setHour(lhs.getHour() - rhs.getHour());
    result.setMinute(lhs.getMinute() - rhs.getMinute());
    result.adjust();
    return result;
}

int main() {
    Date d1(1,2,10);
    Date d2(0,2,5);
    cout << d1 + d2;
    cout << d1 - d2;
    cout << d2 - d1;
    d1++;
    cout << d1;
    cout << ++d1;
    d1--;
    cout << d1;
    cout << --d1;
}
