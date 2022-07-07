//
//  polynomial.hpp
//  hw08
//
//  Created by Ziqian Zhang on 2022/4/30.
//

#ifndef polynomial_hpp
#define polynomial_hpp

#include <iostream>
#include <vector>

class Polynomial{
    
private:
    struct Node {
        Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
        int data;
        Node* next;
    };
    Node* head;
    int deg;
    friend std::ostream& operator<<(std::ostream& op, const Polynomial& ap);
    friend void printPoly(std::ostream& op, Node* head, int currD);
    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
    Polynomial(const std::vector <int>& coes = {});
    Polynomial(const Polynomial& another);
    ~Polynomial();
    int degree() const;
    void cutZeros(Node* headptr);
    Polynomial& operator=(const Polynomial& rhs);
    Polynomial& operator+=(const Polynomial& rhs);
    int power(int base, int exp);
    int evaluate(int num);

};

bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

#endif /* polynomial_hpp */
