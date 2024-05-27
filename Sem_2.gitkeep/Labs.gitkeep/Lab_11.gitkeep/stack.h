#pragma once
#include <iostream>

using namespace std;

template <typename xyz>
struct node {
    xyz data;
    node<xyz>* next;
};

template <typename v>
struct stack {
    node<v>* head = nullptr;
    int size = 0;

    void pushTop(int data) {
        node<v>* newNode = new node<v>;
        newNode->next = head;
        newNode->data = data;
        head = newNode;
        size++;

    }
    int pop()
    {
        int value = head->data;
        node<v>* tmp = head;
        head = head->next;
        size--;
        delete tmp;
        return value;
    }
    void popSpecifiedEl(int specifIndex) {
        stack<v>* partStack = new stack<int>;
        for (int i = 0; i < specifIndex; i++) {
            partStack->pushTop(pop());
        }
        pop();
        for (int i = 0; i <= partStack->size; i++) {
            pushTop(partStack->pop());
        }
        delete partStack;

    }
    void showStack() {
        node<int>* curPtr = head;
        for (int i = 0; i < size; i++) {
            printf("%i ", curPtr->data);
            curPtr = curPtr->next;
        }
    }

};

