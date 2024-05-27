#pragma once
#include <iostream>

using namespace std;

struct ListElemO
{
    int data;
    ListElemO* next;
    ListElemO* prev;
};


ListElemO* createListO(int size)
{
    ListElemO* p, * r;
    ListElemO* start = new ListElemO;
    cin >> start->data;
    start->next = nullptr;
    start->prev = nullptr;
    p = start;
    for (int i = 0; i < size - 1; i++) {
        r = new ListElemO;
        cin >> r->data;
        r->prev = p;
        p->next = r;
        p = r;
    }
    return start;
}

void delElementListO(ListElemO* ptr, int delIndex) {
    for (int i = 0; i < delIndex - 1; i++) {
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    delete ptr->next->prev;
    ptr->next->prev = ptr;


}

void newNodeO(ListElemO* ptr, int size) {
    ListElemO* curNode = ptr;
    ListElemO* newNode = new ListElemO;
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
void newFirstNodeO(ListElemO*& ptr) {
    ListElemO* newNode = new ListElemO;
    newNode->data = 0;
    newNode->prev = nullptr;
    newNode->next = ptr;
    ptr = newNode;
}
void showListO(ListElemO* ptr, int size) {
    cout << ptr->data;
    for (int i = 1; i < size; i++) {
        ptr = ptr->next;
        cout << ' ' << ptr->data;
    }
    cout << endl;
}


