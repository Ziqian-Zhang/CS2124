//
//  Rational.cpp
//  rec08
//
//  Created by Ziqian Zhang on 2022/3/25.
//

#include "Rational.h"
using namespace std;

namespace CS2124{
    int greatestCommonDivisor(int x, int y){
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }

    istream& operator>>(std::istream& input, Rational& aNum){
        char slash;
        input >> aNum.numerator >> slash >> aNum.denominator;
        aNum.normalize();
        return input;
    }

    ostream& operator<<(std::ostream& output, const Rational& aNum){
        if (aNum.denominator == 1){
            output << aNum.numerator;
        }else{
            output << aNum.numerator << '/' << aNum.denominator;
        }
        return output;
    }

    bool operator==(const Rational& lhs, const Rational& rhs){
        return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
    }

    bool operator<(const Rational& lhs, const Rational& rhs){
        if (lhs.denominator == rhs.denominator){
            if (lhs.numerator >= rhs.numerator){
                return false;
            }
        }else{
            int left, right;
            left = lhs.numerator * rhs.denominator;
            right = rhs.numerator * lhs.denominator;
            if (left >= right){
                return false;
            }
        }
        return true;
    }

    Rational::Rational(int nmrt, int dnmnt): numerator(nmrt), denominator(dnmnt){
        normalize();
    }

    Rational& Rational::operator+=(const Rational& rhs){
        numerator = numerator * rhs.denominator + rhs.numerator * denominator;
        denominator *= rhs.denominator;
        normalize();
        return *this;
    }

    Rational& Rational::operator++(){
        numerator += denominator;
        return *this;
    }

    Rational Rational::operator++(int num){
        Rational original(*this);
        numerator += denominator;
        return original;
    }

    Rational::operator bool() const{
        return numerator != 0;
    }

    void Rational::normalize(){
        if (denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }
        int gcd = greatestCommonDivisor(numerator, denominator);
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

    Rational operator+(const Rational& lhs, const Rational& rhs){
        Rational result(lhs);
        result += rhs;
        return result;
    }

    Rational& operator--(Rational& rhs){
        rhs += -1;
        return rhs;
    }
    Rational operator--(Rational& rhs, int num){
        Rational original(rhs);
        rhs += -1;
        return original;
    }
    bool operator!=(const Rational& lhs, const Rational& rhs){
        return !(lhs == rhs);
    }
    bool operator<=(const Rational& lhs, const Rational& rhs){
        return lhs < rhs || lhs == rhs;
    }
    bool operator>(const Rational& lhs, const Rational& rhs){
        return !(lhs <= rhs);
    }
    bool operator>=(const Rational& lhs, const Rational& rhs){
        return !(lhs < rhs);
    }
}
