#pragma once
#include <iostream>

using namespace std;

template <typename xyz>
struct QueueElem {
    xyz data;
    QueueElem<xyz>* next;
};

template <typename v>
struct Queue {
    QueueElem<v>* front = nullptr;
    QueueElem<v>* back = front;
    int size = 0;

    void pushBack(int data)
    {
        QueueElem<v>* newNode = new QueueElem<v>;
        newNode->data = data;
        newNode->next = nullptr;
        if (size == 0)
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }
    int pop()
    {
        int value = front->data;
        QueueElem<v>* tmp = front;
        if (size == 1) { back = nullptr; }
        front = front->next;
        size--;
        delete tmp;
        return value;
    }
    void popSpecifiedEl(int specifIndex) {
        Queue<v>* partQueue = new Queue<int>;
        for (int i = 0; i < specifIndex; i++) {
            partQueue->pushBack(pop());
        }
        pop();
        for (int i = 0; i < size; i++) {
            partQueue->pushBack(pop());
        }
        for (int i = 0; i <= partQueue->size; i++) {
            pushBack(partQueue->pop());
        }

        delete partQueue;

    }
    void newFirstEl() {
        Queue<v>* partQueue = new Queue<int>;
        for (int i = 0; i <= size; i++) {
            partQueue->pushBack(pop());
        }
        pushBack(rand() % 8);
        for (int i = 0; i <= partQueue->size; i++) {
            pushBack(partQueue->pop());
        }

        delete partQueue;

    }
    void showQueue() {
        QueueElem<int>* curPtr = front;
        for (int i = 0; i < size; i++) {
            printf("%i ", curPtr->data);
            curPtr = curPtr->next;
        }
        cout << endl;
    }

};

