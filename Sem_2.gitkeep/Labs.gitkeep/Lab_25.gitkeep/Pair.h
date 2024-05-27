
#pragma once
#include <iostream>

using namespace std;

class Object {
public:
    Object() {};
    ~Object() {};
    virtual void Show() = 0;
};

class Pair : public Object {
protected:
    int first;
    int second;

public:
    Pair() {
        first = 0;
        second = 0;
    }
    Pair(int cnt, int ar) {
        first = cnt;
        second = ar;
    }
    Pair(const Pair& NoName) {
        first = NoName.first;
        second = NoName.second;
    }
    void showClass() {
        printf("Price: %i,%i\n", first, second);
    }

    int getFirst() { return first; }
    int getSecond() { return second; }
    void setFirst(int tmp) { first = tmp; }
    void setSecond(int tmp) { second = tmp; }
    void Show() { cout << '1' << endl; };

    Pair& operator+(const Pair& a) {
        Pair* tmp = new Pair;
        tmp->setFirst(this->first); tmp->setSecond(a.first);
        tmp->first += this->second;
        tmp->second += a.second;
        return  *tmp;
    }

    Pair& operator=(Pair& a) {
        this->first = a.first;
        this->second = a.second;
        return *this;
    }


    friend ostream& operator << (ostream& os, const Pair& a);
    friend istream& operator >> (istream& in, Pair& a);

    virtual ~Pair() {};

};

ostream& operator << (ostream& os, const Pair& a) {
    os << "First: " << a.first;
    os << "\nSecond: " << a.second;
    return  os;
}
istream& operator >> (istream& in, Pair& a) {
    cout << "First: "; in >> a.first;
    cout << "Second: "; in >> a.second;
    return in;
}
