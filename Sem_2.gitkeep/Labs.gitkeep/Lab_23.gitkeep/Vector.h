#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Vector {
    Object** head;
    int size;
    int curIndx;

public:
    Vector() { head = 0; size = 0; curIndx = 0; };
    Vector(int n) { head = new Object * [n]; curIndx = 0; size = n; };

    void add(Object* p) { if (curIndx < size) head[curIndx++] = p; };

    friend ostream& operator <<(ostream& out, const Vector&);

    ~Vector() { if (head != 0) delete[] head; head = 0; };

};

ostream& operator <<(ostream& out, const Vector& v) {
    if (v.size == 0) out << "Empty" << endl;
    Object** p = v.head;
    for (int i(0); i < v.curIndx; i++) (*p++)->Show();
    return out;
};
