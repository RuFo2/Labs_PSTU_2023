# Лабораторная работа №24
>[!NOTE]
>Тема : "АТД. Контейнеры"
>Цель: 2)	Реализация класса-контейнера.

# Вариант №15
1. 1.	Определить класс-контейнер.
2.	Реализовать конструкторы, деструктор, операции ввода-вывода, операцию присваивания.
3.	Перегрузить операции, указанные в варианте.
4.	Реализовать класс-итератор. Реализовать с его помощью операции последовательного доступа.
5.	Написать тестирующую программу, иллюстрирующую выполнение операций.
Класс- контейнер СПИСОК с ключевыми значениями типа int. Реализовать операции:
[] – доступа по индексу;
int() – определение размера списка;
* вектор – умножение элементов списков a[i]*b[i];
+n - переход вправо к элементу с номером n ( с помощью класса-итератора).

# UML-диаграмма
![](https://psv4.userapi.com/c909228/u172605325/docs/d51/f304a36f6346/ClassDiagram.png?extra=t2aLDZigZJJHAOEa56optwksTipXaHgwARfsiAIrlACuKz-0GlriiUwIn_B_yh9Xa46uIe-9hztbDnta9UdamWi1244-v2jcc9pEZEeSdOZdj6PtQk19ADQGLIfkmNHN_5DUbWeyQ7_8gilPd9wttmEb_5w)

# Код программы
## main
```cpp
#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	system("chcp 1251");
	vector<int> a = { 2,3 };
	List list1, list2;
	list1.input();
	list2.input();
	cout << "List1: " << list1 << endl;
	cout << "List2: " << list2 << endl;
	List list3 = list1 + list2;
	cout << "list1 + list2 : " << list3 << endl;
	cout << "Вывод размера list3: " << static_cast<int>(list3) << endl;
	cout << "Вывод элемента list3 с индексом 2 : " << list3[2] << endl;
	list3* a;
	cout << *(list3.first()) << endl;
	Iterator it = list3.first();
	++it;
	++it;
	cout << "*it: " << *it << endl;
	for (it = list3.first(); it != list3.last(); ++it) {
		cout << *it << "\t";
	}
	cout << endl;
	//cout << list3[3] << endl;
	cout << "Введите  индекс для сдвига: ";
	int n;
	cin >> n;
	it = list3.last();
	it + n;
	cout << *it << endl;

	return 0;
}
```
##list.h
```cpp
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Iterator
{
	friend class List;
private:
	int* elem;
public:
	Iterator() { elem = nullptr; }
	Iterator(const Iterator& it) { elem = it.elem; }
	int& operator *() const { return*elem; }
	bool operator==(const Iterator& it) const;
	bool operator!=(const Iterator& it);
	void operator++() { ++elem; }
	void operator--() { --elem; }
	void operator+(int n);
};

class List
{
private:
	int size;
	int* data;
	Iterator beg, end;
public:
	List();
	List(int size);
	List(const List& a);
	~List();
	List& operator=(const List& a);
	int& operator[](int index);
	List& operator+(const int a) {};
	List operator+ (const List& a);
	operator int() const { return size; }
	void input();
	friend ostream& operator<<(ostream& out, const List& a);
	friend istream& operator>>(istream& in, List& a);
	Iterator first() { return beg; }
	Iterator last() { return end; }

	void operator*(vector<int> a) {
		for (int i = 0; i < a.size(); i++)
		{
			data[i] *= a[i];
		}
	}
};
```
##maincpp.cpp
```cpp
#include <iostream>
#include "list.h"
using namespace std;

bool Iterator::operator==(const Iterator& it) const {
	return elem == it.elem;
}

bool Iterator::operator!=(const Iterator& it) {
	return elem != it.elem;
}

List::List() :data(nullptr), size(0) {}

List::List(int size) {
	this->size = size;
	data = new int[size];
	beg.elem = &data[0];
	end.elem = &data[size - 1];
}

List::List(const List& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = a.data[i];
	}
	beg = a.beg;
	end = a.end;
}

List::~List()
{
	delete[]data;
	data = 0;

}

List& List::operator=(const List& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
	return *this;
}

int& List::operator[](int index) {
	if (index >= 0 && index < size) {
		return data[index];
	}
	return data[index];
}

List List::operator+(const List& a) {
	List result(size + a.size);
	int i = 0;
	for (; i < size; i++) {
		result[i] = data[i];
	}
	for (int j = 0; j < a.size; j++, i++) {
		result[i] = data[i] + a.data[j];
	}
	return result;
}

void Iterator::operator+(int n) {
	for (int i = n; i > 0; i--) {
		++elem;
	}
}

void List::input() {
	cin >> size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> data[i];
	}
}

ostream& operator<<(ostream& fout, const List& other) {
	for (int i = 0; i < other.size; i++) {
		fout << other.data[i];
	}
	fout << endl;
	return fout;
}

istream& operator>>(istream& fin, List& other) {
	for (int i = 0; i < other.size; i++) {
		fin >> other.data[i];
	}
	return fin;
}
```
