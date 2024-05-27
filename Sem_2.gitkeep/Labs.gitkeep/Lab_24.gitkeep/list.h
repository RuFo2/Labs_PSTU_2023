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