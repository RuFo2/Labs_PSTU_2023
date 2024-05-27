#pragma once
#include <iostream>
#include <string>
using namespace std;

class Object {
public:
    Object() {};
    ~Object() {};
    virtual void Show() = 0;
};

class Person : public Object {
protected:
    string name;
    int age;
public:
    Person() {
        name = "Borya";
        age = 0;
    };
    Person(string a, int b) {
        name = a;
        age = b;
    };
    Person(Person& a) {
        name = a.name;
        age = a.age;
    };

    string getName() { return name; }
    int getAge() { return age; }
    void setName(string a) { name = a; }
    void setAge(int a) { age = a; }

    void Show() { cout << name << ' ' << age << endl; };
    void Input() {
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
    };

    friend ostream& operator << (ostream& os, const Person& a);
    friend istream& operator >> (istream& in, Person& a);

    virtual ~Person() {};
};
ostream& operator << (ostream& os, const Person& a) {
    os << "Name: " << a.name << endl;
    os << "Age: " << a.age << endl;
    return  os;
}
istream& operator >> (istream& in, Person& a) {
    cout << "Name: "; in >> a.name;
    cout << "Age: "; in >> a.age;
    return in;
}
