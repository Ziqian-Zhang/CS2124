//
//  main.cpp
//  lab5
//
//  Created by Z.Q. Zhang on 2022/6/15.
//
/*
#include <iostream>
using namespace std;

class Angle{
    friend ostream& operator<<(ostream& os, const Angle& a){
        os << a.degree << " d " << a.minute << " m " << a.second << " s ";
        return os;
    }
    
    friend istream& operator>>(istream& is, Angle& a){
        is >> a.degree >> a.minute >> a.second;
        a.normalize();
        return is;
    }
    
public:
    Angle(){}
    Angle(int d, int m, int s): degree(d), minute(m), second(s){}
    
    void getDataKB(int d, int m, int s){
        degree = d;
        minute = m;
        second = s;
    }
    
    void normalize(){
        if (second > 60){
            minute += 1;
            second -= 60;
        }
        if (minute > 60){
            degree += 1;
            minute -= 60;
        }
        if (second < 0){
            minute -= 1;
            second += 60;
        }
        if (minute < 0){
            degree -= 1;
            minute += 60;
        }
    }
    
    int getDegree() const { return degree; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
    void setDegree(int d){ degree = d; }
    void setMinute(int m){ minute = m; }
    void setSecond(int s){ second = s; }
    
    Angle& operator++(){
        degree++;
        normalize();
        return *this;
    }
    
    Angle operator++(int a){
        Angle temp(*this);
        degree++;
        normalize();
        return temp;
    }
    
    bool operator==(const Angle& rhs){
        if (degree == rhs.degree && minute == rhs.minute && second == rhs.second){
            return true;
        }
        return false;
    }
    
    bool operator>(const Angle& rhs){
        int total1 = 3600 * degree + 60 * minute + second;
        int total2 = rhs.degree * 3600 + rhs.minute * 60 + rhs.second;
        if (total1 > total2){
            return true;
        } else {
            return false;
        }
    }
    
    bool operator<(const Angle& rhs){
        int total1 = 3600 * degree + 60 * minute + second;
        int total2 = rhs.degree * 3600 + rhs.minute * 60 + rhs.second;
        if (total1 < total2){
            return true;
        } else {
            return false;
        }
    }
private:
    int degree;
    int minute;
    int second;
};

Angle operator+(const Angle& lhs, const Angle& rhs){
    Angle result;
    result.setDegree(lhs.getDegree() + rhs.getDegree());
    result.setMinute(lhs.getMinute() + rhs.getMinute());
    result.setSecond(lhs.getSecond() + rhs.getSecond());
    result.normalize();
    return result;
}

Angle operator-(const Angle& lhs, const Angle& rhs){
    Angle result;
    result.setDegree(lhs.getDegree() - rhs.getDegree());
    result.setMinute(lhs.getMinute() - rhs.getMinute());
    result.setSecond(lhs.getSecond() - rhs.getSecond());
    result.normalize();
    return result;
}

int main() {
    Angle a1;
    a1.getDataKB(30, 30, 30);
    Angle a2(20, 40, 20);
    cout << a1 + a2 << endl;
    Angle a3(40,5,10);
    Angle a4(20,20,20);
    cout << a3 - a4 << endl;
    Angle a5(40,5,10);
    if (a3 == a5){
        cout << "True" << endl;
    } else {cout << "False" << endl;}
    if (a3 > a4){
        cout << "True" << endl;
    } else {cout << "False" << endl;}
    if (a4 < a3){
        cout << "True" << endl;
    } else {cout << "False" << endl;}
}
*/
