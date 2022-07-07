//
//  main.cpp
//  rec14
//
//  Created by Ziqian Zhang on 2022/5/6.
//

#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    friend ostream& operator<<(ostream& os, const Node* head){
        const Node* holder = head;
        while(holder != nullptr){
            os << holder->data << ", ";
            holder = holder->next;
        }
        return os;
    }
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

//int max(TNode* root) {
//  // Provide this code
//}

// Task 1
bool checkEvenOnes(int val){
    if (val == 0){
        return true;
    }
    if (val % 2 == 0){
        return checkEvenOnes(val / 2);
    }
    return !checkEvenOnes(val / 2);
}

// Task 2
Node* sumList(const Node* list1, const Node* list2){
    if (list1 == nullptr && list2 == nullptr){
        return nullptr;
    }
    else if (list1 == nullptr){
        return new Node(list2->data, sumList(list1, list2->next));
    }
    else if (list2 == nullptr){
        return new Node(list1->data, sumList(list1->next, list2));
    }
    else {
        return new Node(list1->data + list2->data, sumList(list1->next, list2->next));
    }
}

// Task 3
int maxTree(TNode* root) {
  // Provide this code
    if (root == nullptr){
        throw invalid_argument("No meaningful maximum for an empty tree");
    }
    else if (root->left == nullptr && root->right == nullptr){
        return root->data;
    }
    else if (root->left == nullptr){
        return max(root->data, maxTree(root->right));
    }
    else if (root->right == nullptr){
        return max(root->data, maxTree(root->left));
    }
    else {
        return max(root->data, max(maxTree(root->left), maxTree(root->right)));
    }
}

// Task 4
bool palindrome(char* start, int length){
    if(length < 2){
        return true;
    }
    if (*start != *(start + length - 1)){
        return false;
    }
    return palindrome(start + 1, length - 2);
}

// Task 5
int towers(int disk, char start, char spare, char target){
    if (disk == 0){
        return 0;
    }
    if (disk == 1){
        return 1;
    }
    return 2 * towers(disk - 1, start, spare, target) + 1;
}

// Task 6
void mystery(int n) {
   if (n > 1) {
      cout << 'a';
      mystery(n/2);
      cout << 'b';
      mystery(n/2);
   }
   cout << 'c';
}

int main() {
    cout << checkEvenOnes(7) << endl;
    cout << checkEvenOnes(4) << endl;
    
    Node a1(1), b1(2,&a1), c1(4,&b1), d1(8, &c1), e1(16, &d1), f1(32, &e1);
    Node g1(3), h1(-6,&g1), i1(10,&h1), j1(-100, &i1);
    cout << &f1 << '\n' << &j1 << '\n' << sumList(&f1,&j1) << endl;

    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    cout << maxTree(&f) << endl;
    
    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "Yes!\n"; }
    
    cout << towers(1, 'a', 'b', 'c') << endl;
    cout << towers(2, 'a', 'b', 'c') << endl;
    cout << towers(3, 'a', 'b', 'c') << endl;
    cout << towers(4, 'a', 'b', 'c') << endl;
    cout << towers(5, 'a', 'b', 'c') << endl;
    cout << towers(6, 'a', 'b', 'c') << endl;
    cout << towers(7, 'a', 'b', 'c') << endl;
    cout << towers(8, 'a', 'b', 'c') << endl;
    cout << towers(9, 'a', 'b', 'c') << endl;
    cout << towers(10, 'a', 'b', 'c') << endl;

    mystery(0);
    cout << endl;
    mystery(1);
    cout << endl;
    mystery(2);
    cout << endl;
    mystery(3);
    cout << endl;
    mystery(4);
    cout << endl;
    mystery(5);
    cout << endl;
    mystery(6);
    cout << endl;
    mystery(7);
    cout << endl;
    mystery(8);
    cout << endl;
    mystery(9);
    cout << endl;
    mystery(10);
    cout << endl;
}
