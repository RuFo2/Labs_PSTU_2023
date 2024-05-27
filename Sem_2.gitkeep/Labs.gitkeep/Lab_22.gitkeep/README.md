# Лабораторная работа №22
>[!NOTE]
>Тема : "Простое наследование. Принципы подстановки"
>Цель: Создание иеархии классов с использованием простого наследования. Изучение принципа подстановки.

# Вариант №15
1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Определить производный класс. Написать программу, в которой продемонстрировать создание объектов и работу всех перегруженных операций.
9. Реализовать функции, получающие и возвращающие объект базового класса. Продемонстрировать принцип подстановки.
10. Базовый класс:
ЧЕЛОВЕК (PERSON)
Имя (name) – string
Возраст (age) – int
Определить методы изменения полей.
Создать производный класс STUDENT, имеющий поля Предмет – string и Оценка – int. Определить методы изменения полей и метод, выдающий сообщение о
неудовлетворительной оценке.

# UML-диаграмма
![](https://sun9-54.userapi.com/impg/32DqZun0PqZckprukJlXujeqhah-XxdEIFrHzQ/sODnmAL0KL0.jpg?size=744x410&quality=96&sign=602adc12c230d2effe5a6c7b6038bf10&type=album)

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
