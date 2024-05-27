#pragma once
#include <string>
#include <iostream>

using namespace std;

class Object {
public:
    Object() {};
    virtual void Show() = 0;
    virtual void Input() = 0;

    ~Object() {};
};

class Print : public Object {
protected:
    string name;
    string author;

public:
    Print() { name = ""; author = ""; }
    Print(string a, string b) { name = a; author = b; }
    Print(Print& a) { name = a.name; author = a.author; }

    string getName() { return name; };
    string getAuthor() { return author; };
    void setName(string a) { name = a; };
    void setAuthor(int a) { author = a; };

    Print& operator= (Print& a) {
        if (&a == this) return *this;
        name = a.name;
        author = a.author;
        return *this;
    };


    void Show() { cout << name << ' ' << author << endl; };
    void Input() {
        cout << "Name: "; cin >> name;
        cout << "Author: "; cin >> author;
    };
    virtual ~Print() {};
};


class Magazin : public Print {
protected:
    int size = 0;
public:
    Magazin() : Print() {};
    Magazin(string a, string b, int c) :Print(a, b) { size = c; };
    Magazin(const Magazin& a) { name = a.name; author = a.author; size = a.size; };

    int getSize() { return size; };
    void setSize(int a) { size = a; };


    void Show() { cout << "Name: " << name << ' ' << "Author: " << author << ' ' << "size: " << size << endl; };
    void Input() {
        cout << "Name: "; cin >> name;
        cout << "Author: "; cin >> author;
        cout << "Size: "; cin >> size;
    };

    ~Magazin() {};
};