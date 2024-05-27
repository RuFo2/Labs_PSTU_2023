#pragma once
#include <iostream>

using namespace std;

struct ListElemB
{
    int data;
    ListElemB* next;
    ListElemB* prev;
};


ListElemB* createListB(int size)
{
    ListElemB* p, * r;
    ListElemB* start = new ListElemB;
    cin >> start->data;
    start->next = nullptr;
    start->prev = nullptr;
    p = start;
    for (int i = 0; i < size - 1; i++) {
        r = new ListElemB;
        cin >> r->data;
        r->prev = p;
        p->next = r;
        p = r;
    }
    return start;
}

void delElementListB(ListElemB* ptr, int delIndex) {
    for (int i = 0; i < delIndex - 1; i++) {
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    delete ptr->next->prev;
    ptr->next->prev = ptr;


}

void newNodeB(ListElemB* ptr, int size) {
    ListElemB* curNode = ptr;
    ListElemB* newNode = new ListElemB;
    for (int i = 0; i < size; i++) {
        curNode = curNode->next;
    }
    if (curNode->prev == nullptr) {
        newNode->prev = curNode->prev;
        newNode->next = curNode;
        curNode->prev = newNode;
        cin >> newNode->data;
        ptr = newNode;
    }
    else {
        newNode->prev = curNode->prev;
        newNode->next = curNode;
        curNode->prev->next = newNode;
        curNode->prev = newNode;
        cin >> newNode->data;
    }


}
void newFirstNodeB(ListElemB*& ptr) {
    ListElemB* newNode = new ListElemB;
    newNode->data = 0;
    newNode->prev = nullptr;
    newNode->next = ptr;
    ptr = newNode;
}
void showListB(ListElemB* ptr, int size) {
    cout << ptr->data;
    for (int i = 1; i < size; i++) {
        ptr = ptr->next;
        cout << ' ' << ptr->data;
    }
    cout << endl;
}


