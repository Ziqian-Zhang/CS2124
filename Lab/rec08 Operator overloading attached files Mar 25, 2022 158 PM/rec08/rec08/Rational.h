//
//  Rational.hpp
//  rec08
//
//  Created by Ziqian Zhang on 2022/3/25.
//

#ifndef Rational_hpp
#define Rational_hpp

#include <stdio.h>
#include <iostream>
#

namespace CS2124{
    int greatestCommonDivisor(int x, int y);

    class Rational {
        friend std::istream& operator>>(std::istream& input, Rational& aNum);
        friend std::ostream& operator<<(std::ostream& output, const Rational& aNum);
        friend bool operator==(const Rational& lhs, const Rational& rhs);
        friend bool operator<(const Rational& lhs, const Rational& rhs);
    public:
        Rational(int nmrt = 0, int dnmnt = 1);
        Rational& operator+=(const Rational& rhs);
        Rational& operator++();
        Rational operator++(int num);
        explicit operator bool() const;
        void normalize();
        
    private:
        int numerator;
        int denominator;
    };

    Rational operator+(const Rational& rhs, const Rational& lhs);
    Rational& operator--(Rational& rhs);
    Rational operator--(Rational& rhs, int num);
    bool operator!=(const Rational& lhs, const Rational& rhs);
    bool operator<=(const Rational& lhs, const Rational& rhs);
    bool operator>(const Rational& lhs, const Rational& rhs);
    bool operator>=(const Rational& lhs, const Rational& rhs);

}

#endif /* Rational_hpp */
