//
//  lec9_10_linked_list.cpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/6/23.
//

#include <iostream>
#include <list>
using namespace std;

template <class T>
class LList;
template <class T>
class LListItr;
template <class T>
class LListNode {
private:
    LListNode<T>* next;
    LListNode<T>* prev;
    T data;
public:
    LListNode(T newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) : data(newdata), next(newnext), prev(newprev){}
    friend class LList<T>;
    friend class LListItr<T>;
};

template <class T>
class LListItr{
private:
    LListNode<T>* ptr;
public:
    LListItr(LListNode<T>* newptr = nullptr): ptr(newptr){}
    T operator*() const { return ptr->data; }
    T& operator*() {return ptr->data; }
    LListItr<T>& operator++();
    LListItr<T> operator++(int);
    LListItr<T>& operator--();
    LListItr<T> operator--(int);
    
    friend class LList<T>;
};

template <class T>
class LList{
private:
    LListNode<T>* head;
    LListNode<T>* tail;
public:
    LList();
    virtual ~LList();
    LList(const LList& rhs);
    LList& operator=(const LList& rhs);
    
    LListItr<T> begin() const { return head->next; }
    LListItr<T> end() const { return tail; }
    
    void push_front(const T& item){ insertAfter(item, head); }
    void push_back(const T& item){ insertAfter(item, tail->prev);}
    void pop_back(){ return isEmpty()? T(): remove(tail->prev);}
    void pop_front(){ return isEmpty()? T(): remove(begin());}
    void insertAfter(const T& item, LListItr<T>& location){
        LListNode<T> node = location.ptr;
        node->next = new LListNode<T>(item, node->next, node);
        node->next->next->prev = node->next;
    }
    T remove(LListItr<T>& location){
        LListNode<T>* node = location.ptr;
        T temp = node->data;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        location.ptr = nullptr;
        return temp;
    }
    void clear(){
        while (!isEmpty()){
            pop_front();
        }
    }
    
    bool isEmpty() const { return head->next == tail;}
};

template <class T>
LList<T>::LList(){
    head = new LListNode<T>;
    tail = new LListNode<T>(T(), nullptr, head);
    head->next = tail;
}
