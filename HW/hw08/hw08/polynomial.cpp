//
//  polynomial.cpp
//  hw08
//
//  Created by Ziqian Zhang on 2022/4/30.
//

#include <iostream>
#include <vector>
#include "polynomial.h"

using namespace std;

Polynomial::Polynomial(const vector <int>& coes){
    head = new Node();
    if (coes.size() == 0){
        deg = 0;
        return;
    }
    size_t zeroIdx = 0;
    while (coes[zeroIdx] == 0){
        zeroIdx++;
    }
    for (size_t index = zeroIdx; index < coes.size(); index++){
        Node* newNode = new Node(coes[index], head->next);
        head->next = newNode;
    }
    deg = degree();
}

// output operator
ostream& operator<< (ostream& op, const Polynomial& ap){
    if (ap.head->next == nullptr){
        op << '0';
    }else{
        Polynomial::Node* leading = ap.head->next;
        printPoly(op, leading, 0);
    }
    return op;
}

// copy control
Polynomial::Polynomial(const Polynomial& another) : deg(another.deg){
    head = new Node();
    Node* curr = another.head->next;
    Node* tCurr = head;
    while (curr != nullptr){
        tCurr->next = new Node(curr->data);
        curr = curr->next;
        tCurr = tCurr->next;
    }
}

Polynomial& Polynomial::operator=(const Polynomial& rhs){
    if (*this != rhs){
        Node* curr = head;
        while (curr != nullptr){
            Node* victim = curr;
            curr = curr->next;
            delete victim;
        }
        head = new Node();
        deg = rhs.deg;
        Node* rCurr = rhs.head->next;
        Node* lCurr = head;
        while (rCurr != nullptr){
            lCurr->next = new Node(rCurr->data);
            lCurr = lCurr->next;
            rCurr = rCurr->next;
        }
    }
    return *this;
}

Polynomial::~Polynomial(){
    Node* curr = head;
    while (curr != nullptr){
        Node* victim = curr;
        curr = curr->next;
        delete victim;
    }
}

// operators
Polynomial& Polynomial::operator+=(const Polynomial& rhs){
    Node* curr = rhs.head->next;
    Node* tCurr = head->next;
    if (deg >= rhs.deg){
        while (curr != nullptr){
            tCurr->data += curr->data;
            curr = curr->next;
            tCurr = tCurr->next;
        }
    }else{
        while (tCurr->next != nullptr){
            tCurr->data += curr->data;
            curr = curr->next;
            tCurr = tCurr->next;
        }
        // ask
        tCurr->data += curr->data;
        curr = curr->next;
        while (curr != nullptr){
            Node* newNode = new Node(curr->data);
            tCurr->next = newNode;
            curr = curr->next;
            tCurr = tCurr->next;
        }
    }
    cutZeros(head);
    deg = degree();
    return *this;
}
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
    Polynomial ans(lhs);
    ans += rhs;
    return ans;
}

// comparison
bool operator==(const Polynomial& lhs, const Polynomial& rhs){
    if (lhs.deg == rhs.deg){
        Polynomial::Node* lHead = lhs.head;
        Polynomial::Node* rHead = rhs.head;
        while (lHead != nullptr){
            if (lHead->data != rHead->data){
                return false;
            }
            lHead = lHead->next;
            rHead = rHead->next;
        }
        return true;
    }
    return false;
}

bool operator!= (const Polynomial& lhs, const Polynomial& rhs){
    return !(lhs == rhs);
}

// evaluate
int Polynomial::evaluate(int num){
    Node* curr = head->next;
    int ans = 0;
    int degree = 0;
    while (curr != nullptr){
        ans += curr->data * power(num, degree);
        degree++;
        curr = curr->next;
    }
    return ans;
}

// helper & recursive methods
int Polynomial::degree() const {
    Node* temp = head->next;
    int degree = 0;
    while (temp->next != nullptr){
        degree++;
        temp = temp->next;
    }
    return degree;
}
int Polynomial::power(int base, int exp){
    if (exp == 0){
        return 1;
    }else if (exp == 1){
        return base;
    }
    int count = 1;
    int ans = base;
    while (count < exp){
        ans = ans * base;
        count++;
    }
    return ans;
}

void printPoly(ostream& op, Polynomial::Node* head, int currD){
    if (head == nullptr){
        return;
    }
    printPoly(op, head->next, currD + 1);
    if (head->data == 1){
        if (currD == 1){
            op << "x+";
        }else if(currD == 0){
            op << head->data;
        }else{
            op << "x^" << currD << '+';
        }
    }else if (head->data != 0){
        if (currD == 1){
            op << head->data << "x+";
        }else if (currD == 0){
            op << head->data;
        }else{
            op << head->data << "x^" << currD << '+';
        }
    }
}

void Polynomial::cutZeros(Node* headptr){
    if (headptr->next == nullptr){
        return;
    }
    cutZeros(headptr->next);
    if (headptr->next->data == 0 && headptr->next->next == nullptr){
        delete headptr->next;
        headptr->next = nullptr;
    }
    return;
}
