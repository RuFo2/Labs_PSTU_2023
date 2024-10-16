# Лабораторная работа №27
>[!NOTE]
>Тема : "Обработка исключительных ситуаций"
>Цель: Разработка программы, обрабатывающей исключительные ситуации.

# Вариант №15
1.	Реализовать класс, перегрузить для него операции, указанные в варианте.
2.	Определить исключительные ситуации.
3.	Предусмотреть генерацию исключительных ситуаций.
Класс- контейнер СПИСОК с ключевыми значениями типа int.
Реализовать операции:
[] – доступа по индексу;
int() – определение размера списка;
+ – объединение множеств;
++ - добавление элемента в множество .

# UML-диаграмма
![](https://sun9-28.userapi.com/impg/sgxE1UOkh0OXOTTkhW0kT8WM93QK0oaCEWU3RA/OSImIwAsFoM.jpg?size=1404x562&quality=96&sign=4ff481a50852e93abdf71281ee76d60a&type=album)

# Код программы
## main
```cpp
#include <iostream>
#include"list.h"
#include"error.h"

int main()
{
    system("chcp 1251");
    int a = 0;
    while (true) {
        try
        {
            list<int> list1;
            list<int> list2;

            cout << endl;
            cout << "Введите количество элементов первого списка: ";
            cin >> list1;
            cout << "Введите количество элементов второго списка: ";
            cin >> list2;

            cout << endl;

            list<int> result = list1 + list2;
            cout << "Сумма списков: " << result << endl;

            cout << endl;

        }
        catch (IndexOutOfRangeError e) {
            e.PrintError();
            continue;
        }
        catch (NegativeIndexError e) {
            e.PrintError();
            continue;
        }
        catch (BasicError& err)
        {
            err.PrintError();
            char c;
            cout << "Хотите начать заново? (1/0): ";
            cin >> c;
            if (c == '0') break;
        }
    }
}
```
##list.h
```cpp
#pragma once
#include "error.h"
#include <string>
#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

struct Node
{
    Node* next = nullptr;
    Node* prev = nullptr;
    int Data;
};

template<typename t>
class list
{
public:
    list() : elements(nullptr), num_elements(0) {}
    list(const list& other) : elements(new t[other.num_elements]), num_elements(other.num_elements)
    {
        for (int i = 0; i < num_elements; i++)
            elements[i] = other.elements[i];
    }
    list& operator=(const list& other)
    {
        if (this != &other)
        {
            delete[] elements;

            elements = new t[other.num_elements];
            num_elements = other.num_elements;

            for (int i = 0; i < num_elements; i++)
                elements[i] = other.elements[i];
        }

        return *this;
    }
    ~list() { delete[] elements; }
    t& operator[](int index)
    {
        if (index >= num_elements) throw IndexOutOfRangeError();
        if (index < 0) throw NegativeIndexError();
        return elements[index];
    }

    list& operator--()
    {
        num_elements--;
        return *this;
    }

    friend istream& operator>>(istream& in, list& list)
    {
        int num_elements;
        in >> num_elements;
        if (num_elements > MAX_SIZE) throw OverflowError();
        if (num_elements == 0) throw EmptyColletionError();

        list.elements = new t[num_elements];
        list.num_elements = num_elements;

        for (int i = 0; i < num_elements; i++)
            in >> list.elements[i];

        return in;
    }

    friend ostream& operator<<(ostream& out, const list& list)
    {
        for (int i = 0; i < list.num_elements; i++)
            out << list.elements[i] << " ";

        return out;
    }

    list<t> operator+(const list<t>& other) {
        list<t> res;
        res.num_elements = num_elements + other.num_elements;
        res.elements = new t[res.num_elements];
        for (int i = 0; i < num_elements; i++) {
            res.elements[i] = elements[i];
        }
        for (int i = 0; i < other.num_elements; i++) {
            res.elements[i + num_elements] = other.elements[i];
        }
        return res;
    }
private:
    t* elements;
    int num_elements;
};
```
##error.h
```cpp
#pragma once
#include <string>
#include <iostream>
using namespace std;
class BasicError {
public:
    BasicError() {}
    virtual ~BasicError() {}
    void PrintError() {
        cout << msg << endl;
    }

protected:
    string msg;
};

class WrongSizeError : public BasicError {
public:
    WrongSizeError() { msg = "SizeError: "; }
    virtual ~WrongSizeError() {}
};

class EmptyColletionError : public WrongSizeError {
public:
    EmptyColletionError() { msg += "ColletionError"; }
};

class OverflowError : public WrongSizeError {
public:
    OverflowError() { msg += "OverflowError"; }
};

class WrongIndexError : public BasicError {
public:
    WrongIndexError() { msg = "IndexError: "; }
    virtual ~WrongIndexError() {}
};

class IndexOutOfRangeError : public WrongIndexError {
public:
    IndexOutOfRangeError() { msg += "IndexOutOfRangeError"; }
    ~IndexOutOfRangeError() {}
};

class NegativeIndexError : public WrongIndexError {
public:
    NegativeIndexError() { msg += "IndexError"; }
    ~NegativeIndexError() {}
};
```
