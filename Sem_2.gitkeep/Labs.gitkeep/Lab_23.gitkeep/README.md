# Лабораторная работа №23
>[!NOTE]
>Тема : "Наследование. Виртуальные функции. Полиморфизм."
>Цель: Создание иеархии классов с использованием простого наследования. 3)	Изучение полиморфизма и виртуальных методов.

# Вариант №15
1.	Определить абстрактный класс.
2.	Определить иерархию классов, в основе которой будет находиться абстрактный класс (см. лабораторную работу №4).
3.	Определить класс Вектор, элементами которого будут указатели на объекты иерархии классов.
4.	Перегрузить для класса Вектор операцию вывода объектов с помощью потоков.
5.	В основной функции продемонстрировать перегруженные операции и полиморфизм Вектора.
Базовый класс:
ЧЕЛОВЕК (PERSON)
Имя (name) – string Возраст (age) – int
Определить методы изменения полей.
Создать производный класс STUDENT, имеющий поля Предмет – string и Оценка – int. Определить методы изменения полей и метод, выдающий сообщение о
неудовлетворительной оценке.

# UML-диаграмма
![](https://sun9-4.userapi.com/impg/98eXHf-ASpord-X0toQyTYpt4vt-w0qwFjAKOQ/zQtURLUoqos.jpg?size=564x410&quality=96&sign=767b7ed73fd3323ff53b4ab2a679f0c7&type=album)

# Код программы
## main
```cpp
#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;
int main()
{
	Person One("pupa", 56);
	Student Two("lupa", 32, "Math", 2);

	cin >> One;
	cout << One;

	cin >> Two;
	cout << Two;
	return 0;
}
```
##Person.h
```cpp
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
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
```
##Student.h
```cpp
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
```
