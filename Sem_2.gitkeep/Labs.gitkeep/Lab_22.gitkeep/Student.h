#pragma once
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;
class Student : public Person {
protected:
    string subject;
    int mark;
public:
    Student() : Person() {};
    Student(string a, int b, string c, int d) : Person(a, b) {
        subject = c;
        mark = d;
    };
    Student(const Student& a) {
        name = a.name;
        age = a.age;
        subject = a.subject;
        mark = a.mark;
    };

    string getSubject() { return subject; }
    int getMark() { return mark; }
    void setSubject(string a) {
        subject = a;
    }
    void setMark(int b) {
        mark = b;
    }


    void Show() { cout << "Name: " << name << ' ' << "Age: " << age << ' ' << "Subject: " << subject << "Mark:" << mark << endl; };
    void Input() {
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
        cout << "Subject: "; cin >> subject;
        cout << "Mark: "; cin >> mark;
    };

    friend ostream& operator << (ostream& os, const Student& a);
    friend istream& operator >> (istream& in, Student& a);

    ~Student() {};
};
ostream& operator << (ostream& os, const Student& a) {
    os << "Name: " << a.name << endl;
    os << "Age: " << a.age << endl;
    os << "Subject:" << a.subject << endl;
    os << "Mark:" << a.mark << endl;
    return  os;
}
istream& operator >> (istream& in, Student& a) {
    cout << "Name: "; in >> a.name;
    cout << "Age: "; in >> a.age;
    cout << "Subject: "; in >> a.subject;
    cout << "Mark: "; in >> a.mark;
    return in;
}
