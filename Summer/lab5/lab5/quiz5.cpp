//
//  quiz5.cpp
//  lab5
//
//  Created by Ziqian Zhang on 2022/6/15.
//

#include <iostream>

using namespace std;

class Measurement{
private:
    int feet;
    int inches;
    void normalize();
public:
    Measurement(){
        feet = 0;
        inches = 0;
    }
    Measurement(int totalInches): inches(totalInches) {
        feet = 0;
        normalize();
    }
    
    int getTotalInches() const{ return feet * 12 + inches;}
    
    Measurement operator+(const Measurement& rhs) const;
    Measurement operator-(const Measurement& rhs) const;
    Measurement& operator++();
    Measurement operator++(int);
    bool operator==(const Measurement& rhs);
    bool operator!=(const Measurement& rhs);
    bool operator<(const Measurement& rhs);
    bool operator>(const Measurement& rhs);
    bool operator<=(const Measurement& rhs);
    bool operator>=(const Measurement& rhs);
    
    friend ostream& operator<<(ostream& os, const Measurement& m){
        os << m.feet << "'" << m.inches << "''" << endl;
        return os;
    }
};

Measurement Measurement::operator+(const Measurement& rhs) const {
    Measurement temp;
    temp.inches = getTotalInches() + rhs.getTotalInches();
    temp.normalize();
    return temp;
}

Measurement Measurement::operator-(const Measurement& rhs) const {
    Measurement temp;
    temp.inches = getTotalInches() - rhs.getTotalInches();
    temp.normalize();
    return temp;
}

Measurement& Measurement::operator++(){
    inches++;
    normalize();
    return *this;
}

Measurement Measurement::operator++(int num){
    Measurement temp(*this);
    inches++;
    normalize();
    return temp;
}

bool Measurement::operator==(const Measurement& rhs){
    return getTotalInches() == rhs.getTotalInches();
}

bool Measurement::operator!=(const Measurement& rhs){
    return !(getTotalInches() == rhs.getTotalInches());
}

bool Measurement::operator<(const Measurement& rhs){
    return getTotalInches() < rhs.getTotalInches();
}
bool Measurement::operator>(const Measurement& rhs){
    return getTotalInches() > rhs.getTotalInches();
}
bool Measurement::operator<=(const Measurement& rhs){
    return getTotalInches() <= rhs.getTotalInches();
}
bool Measurement::operator>=(const Measurement& rhs){
    return getTotalInches() >= rhs.getTotalInches();
}

void Measurement::normalize(){
    if (inches >= 12){
        feet += inches/12;
        inches %= 12;
    }
    while (inches < 0){
        feet --;
        inches += 12;
    }
}

int main(){
    Measurement m1;
    Measurement m2(24);
    Measurement m3(-12);
    
    cout << "m1: " << m1;
    cout << "m2: " << m2;
    cout << "m3: " << m3;
    
    cout << endl;
    
    cout << "m1++: " << m1++;
    cout << "m1: " << m1;
    cout << "++m1: " << ++m1;
    cout << "m1: " << m1;
    
    
    cout << endl;
    
    cout << "m1: " << m1;
    cout << "m2: " << m2;
    cout << "m3: " << m3;
    
    cout << endl;
    
    cout << "m1 + m2: " << (m1 + m2);
    cout << "m2 + m3: " << (m2 + m3);
    cout << "m2 - m1: " << (m2 - m1);
    cout << "m1 - m2: " << (m1 - m2);
    cout << "m1 - m3: " << (m1 - m3);
    
    cout << endl;
    
    cout << "m1 == m2: " << boolalpha << (m1 == m2) << endl;
    cout << "m1 != m2: " << boolalpha << (m1 != m2)<< endl;
    
    cout << endl;
    
    cout << "m2 == m2: " << boolalpha << (m2 == m2) << endl;
    cout << "m2 != m2: " << boolalpha << (m2 != m2) << endl;
}

