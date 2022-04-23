#pragma once
#include "Node.h"
#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
class List
{
public:
    Node<T>* head;
    Node<T>* tail;
    int length;
        List() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        };
     ~List();
    void AddToHead(T elem);
    void AddToTail(T elem);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show();
    void InsertByPos(int idx, T elem);
    void DelByPos(int idx);
    void Reverse();
    int SearchEL(T el);
    int SearchAndRepl(T elRep, const T elNew);
    List& operator =(const List& l);
};

template<typename T>
inline List<T>::~List()
{
    DeleteAll();
}

template<typename T>
inline void List<T>::AddToHead(T elem)
{
    Node<T>* node_elem = new Node<T>(elem);
    if (head==nullptr&&tail==nullptr) {
        head = tail = node_elem;
    }
    else {
        head->prev = node_elem;
        node_elem->next = head;
        head= node_elem ;
    }
    length++;
}

template<typename T>
inline void List<T>::AddToTail(T elem)
{
    Node<T>* node_elem = new Node<T>(elem);
    if (tail == nullptr&&head==nullptr) {
       head= tail = node_elem;
    }
    else {
        tail->next = node_elem;
        node_elem->prev = tail;
        tail= node_elem;
    }
    length++;
}

template<typename T>
inline void List<T>::DeleteFromHead()
{
    Node<T>* node_elem = new Node<T>();
    if (length == 0) {
        cout << "Length = 0!" << endl;
        return;
    }
    else if (length == 1) {
        node_elem = head;
    }
    else {
        node_elem = head;
        head = head->next;
        head->prev = nullptr;
    }
    delete  node_elem;
    length--;
}

template<typename T>
inline void List<T>::DeleteFromTail()
{
    Node<T>* node_elem = new Node<T>();
    if (length == 0) {
        cout << "Length = 0!" << endl;
        return;
    }
    else if (length == 1) {
        node_elem = tail;
    }
    else {
        node_elem = tail;
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete  node_elem;
    length--;
}

template<typename T>
inline void List<T>::DeleteAll()
{
    Node<T>* node_elem = new Node<T>();
    while (length >1) {
        node_elem = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete  node_elem;
        length--;
    }
    node_elem = tail;
    delete  node_elem;
}

template<typename T>
inline void List<T>::Show()
{
    uint32_t temp = length;
    Node<T>* node_elem = new Node<T>();
    node_elem = head;
    while (temp != 0) {
        cout <<node_elem->getValue()<<setw(4);
        node_elem = node_elem->next;
        temp--;
    }
    cout << endl;
}

template<typename T>
inline void List<T>::InsertByPos(int idx,T elem)
{
    Node<T>*temp1 = new Node<T>();
    Node<T>*temp2 = new Node<T>(elem);
    Node<T>* temp3 = new Node<T>(); 
    int i = 1;
    temp1 = head;
    if (idx == 1) {
        AddToHead(elem);
        return;
    }
    if (idx == length + 1) {
        AddToTail(elem);
        return;
    }
    while (i <idx) {
        i++;
        temp1=temp1->next;
    }
    temp3 = temp1->prev;
    if (temp3 != 0 && length != 1) {
        temp3->next = temp2;
        temp2->next = temp1;
        temp2->prev = temp3;
        temp1->prev = temp2;
        length++;
    }
}

template<typename T>
inline void List<T>::DelByPos(int idx){
    Node<T>* PosDel = new Node<T>();
    Node<T>* PrePosDel = new Node<T>();
    Node<T>* NextPosDel = new Node<T>();
    int i = 1;
    PosDel = head;
    if (idx == 1) {
        DeleteFromHead();
        return;
    }
    if (idx == length) {
        DeleteFromTail();
        return;
    }
    while (i < idx) {
        i++;
        PosDel = PosDel->next;
    }
    NextPosDel = PosDel->next;
    PrePosDel = PosDel->prev;
    if (NextPosDel != 0 && length != 1) {
        PrePosDel->next = NextPosDel;
    }
    if (PrePosDel != 0 && length != 1) {
        NextPosDel->prev = PrePosDel;
    }
    PosDel = nullptr;
    delete  PosDel;
    length--;
}

template<typename T>
inline void List<T>::Reverse()
{
    int k = length;
    Node<T>* temp = new Node<T>();
    temp = tail;
    for (size_t i = 1; i <k; i++) {
        InsertByPos(i, temp->getValue());
        temp = temp->prev;
        DeleteFromTail();
    }
}

template<typename T>
inline int List<T>::SearchEL(T el)
{
    int k = 0;
    Node<T>* temp = new Node<T>();
    temp =head ;
    for (size_t i = 1; i < length; i++) {
        if (temp->getValue() == el) {
            k++;
            return i;
        }
        temp = temp->next;
    }
    if (k == 0) {
        return NULL;
    }
}

template<typename T>
inline int List<T>::SearchAndRepl(T elRep,  const T elNew)
{
    int Qty_el = 0;T temp2;
    Node<T>* temp = new Node<T>();
    temp = head;
    for (size_t i = 1; i <=length; i++) {
        if (temp->getValue() == elRep) {
            temp->setValue(elNew);
            Qty_el++;
        }
        temp = temp->next;
    } 
    if (!Qty_el) {
        return -1;
    }
    else {
        return Qty_el;
    }
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T>& l)
{
    if (this == l) {
        return this;
    }
    delete this;
    this->head = l.head;
    this->length = l.length;
    this->tail = l.tail;
    return this;
}
