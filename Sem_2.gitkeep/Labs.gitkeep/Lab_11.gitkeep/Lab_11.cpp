#include "linkedList.h"
#include "doubleLinked.h"
#include "stack.h"
#include "queue.h"
#include <iostream>
#include <ctime>

using namespace std;


int main() {
    srand((unsigned int)time(0));
    int sizeList, delElIndex;
    cin >> sizeList;
    ListElemO* ptr = createListO(sizeList);
    showListO(ptr, sizeList);
    cin >> delElIndex;
    delElementListO(ptr, delElIndex);
    showListO(ptr, --sizeList);
    newFirstNodeO(ptr);
    showListO(ptr, ++sizeList);


    cin >> sizeList;
    ListElemB* ptrB = createListB(sizeList);
    showListB(ptrB, sizeList);
    cin >> delElIndex;
    delElementListB(ptrB, delElIndex);
    showListB(ptrB, --sizeList);
    newFirstNodeB(ptrB);
    showListB(ptrB, ++sizeList);


    stack<int>* x = new stack<int>;
    printf("Количество: ");
    cin >> sizeList;
    for (int i = 0; i < sizeList; i++) {
        x->pushTop(rand() % 8);
    }
    x->showStack();
    cout << '\n';
    x->popSpecifiedEl(2);
    x->showStack();

    Queue<int>* y = new Queue<int>;
    printf("Количество: ");

    cin >> sizeList;

    for (int i(0); i < sizeList; i++) {
        y->pushBack(rand() % 8);
    }
    cin >> delElIndex;
    y->showQueue();
    y->popSpecifiedEl(delElIndex);
    y->showQueue();
    y->newFirstEl();
    y->showQueue();

    return 0;
}