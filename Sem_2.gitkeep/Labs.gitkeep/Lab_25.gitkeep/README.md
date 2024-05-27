# Лабораторная работа №25
>[!NOTE]
>Тема : "Шаблоны классов"
>Цель: Реализация шаблона класса-контейнера.
# Вариант №15
1.	Определить шаблон класса-контейнера (см. лабораторную работу №6).
2.	Реализовать конструкторы, деструктор, операции ввода-вывода, операцию присваивания.
3.	Перегрузить операции, указанные в варианте.
4.	Инстанцировать шаблон для стандартных типов данных (int, float, double).
5.	Написать тестирующую программу, иллюстрирующую выполнение операций для контейнера, содержащего элементы стандартных типов данных.
6.	Реализовать пользовательский класс (см. лабораторную работу №3).
7.	Перегрузить для пользовательского класса операции ввода-вывода.
8.	Перегрузить операции необходимые для выполнения операций контейнерного класса.
9.	Инстанцировать шаблон для пользовательского класса.
10.	Написать тестирующую программу, иллюстрирующую выполнение операций для контейнера, содержащего элементы пользовательского класса
Класс- контейнер СПИСОК с ключевыми значениями типа int. Реализовать операции:
[] – доступа по индексу;
int() – определение размера списка;
* вектор – умножение элементов списков a[i]*b[i];
Пользовательский класс Pair (пара чисел). Пара должна быть представлено двумя полями: типа int для первого числа и типа double для второго. Первое число при выводе на экран должно быть отделено от второго числа двоеточием.

# UML-диаграмма
![](https://sun9-55.userapi.com/impg/MlDcM9YZUeBSR4yDh9JhmIkyvKkPRZM7866pqw/OfwenJIdcSQ.jpg?size=684x456&quality=96&sign=61f254788d66f7638ae3c01e879a4321&type=album)

# Код программы
## main
```cpp
#include <iostream>
#include "list.h"
#include "Pair.h"
using namespace std;

int main() {
	system("chcp 1251");
	int size;
	vector<int> a = { 2,1 };
	cout << "Введите размер списка: " << endl;
	cin >> size;
	List<int> A(size);
	cout << "Список A: "; A.show();
	int k;
	cout << "Введите индекс: " << endl;
	cin >> k;
	cout << "A[k] элемент: " << A[k] << endl;
	cout << "Размер списка A: " << A() << endl;
	cout << endl;
	cout << "Введите размер списка: " << endl;
	cin >> size;
	List<int> B(size);
	cout << "Список B: "; B.show();
	cout << "Размер списка B: " << B() << endl;
	cout << endl;
	A* a;
	List<int> C(size);
	C = A + B;
	cout << "Список C = A + B: "; C.show();
	cout << "Размер списка C: " << C() << endl;
	cout << endl;

	cout << "Тестирование класса Money:" << endl;

	Pair t1;
	cin >> t1;
	cout << "Первый экземпляр класса Money:" << endl;
	cout << t1; cout << endl;

	Pair t2;
	cin >> t2;
	cout << "Второй экзепляр класса Money: " << endl;
	cout << t2; cout << endl;

	return 0;
}
```
##list.h
```cpp
#include <iostream>
#include <vector>
#pragma once

using namespace std;

template <class T>
class List {
private:
	T size;
	T* array;
public:
	List(T size);
	virtual void show();
	~List();
	int& operator ()();
	List operator +(const List& other);
	T& operator [](int index);
	void operator*(vector<int> a) {
		for (int i = 0; i < a.size(); i++)
		{
			data[i] *= a[i];
		}
	}
};

template<class T>
List<T>::List(T size) {
	this->size = size;
	array = new T[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100 + 1;
	}
}
template<class T>
void List<T>::show() {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template<class T>
List<T>::~List() {}

template<class T>
int& List<T>::operator()() {
	return size;
}

template<class T>
List<T> List<T>::operator+(const List& other) {
	List<T> tmp(size);
	for (int i = 0; i < size; i++) {
		tmp[i] = array[i] + other.array[i];
	}
	delete[]array;
	return tmp;
}

template<class T>
T& List<T>::operator [](int index) {
	if (index >= 0 && index < size) {
		return array[index];
	}
	else {
		cout << "error" << endl;
	}
}
```
##Pair.h
```cpp

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
```
