# Лабораторная работа №26
>[!NOTE]
>Тема : "Программа, управляемая событиями"
>Цель: 2)	Разработка программы, управляемой событиями.

# Вариант №15
1.	Определить иерархию пользовательских классов (см. лабораторную работу №5). Во главе иерархии должен стоять абстрактный класс с чисто виртуальными методами для ввода и вывода информации об атрибутах объектов.
2.	Реализовать конструкторы, деструктор, операцию присваивания, селекторы и модификаторы.
3.	Определить класс-группу на основе структуры, указанной в варианте.
4.	Для группы реализовать конструкторы, деструктор, методы для добавления и удаления элементов в группу, метод для просмотра группы, перегрузить операцию для получения информации о размере группы.
5.	Определить класс Диалог – наследника группы, в котором реализовать методы для обработки событий.
6.	Добавить методы для обработки событий группой и объектами пользовательских классов.
7.	Написать тестирующую программу.
8.	Нарисовать диаграмму классов и диаграмму объектов.
Базовый класс: ПЕЧАТНОЕ_ИЗДАНИЕ(PRINT)
Название– string Автор – string Производный класс
ЖУРНАЛ (MAGAZIN)
Количество страниц - int Группа – Дерево (Tree). Команды:
•	Создать группу (формат команды: m количество элементов группы).
•	Добавить элемент в группу (формат команды: +)
•	Удалить элемент из группы (формат команды -)
•	Вывести информацию об элементах группы (формат команды: s)
•	Вывести информацию о названиях всех элементов группы (формат команды : z) Конец работы (формат команды: q)

# UML-диаграмма
![](https://sun9-13.userapi.com/impg/wHADlbxpTqGRNpLDQ1_IU8w-tVFdzWTjOvcBVQ/j6s8yWpgK28.jpg?size=1494x433&quality=96&sign=ebd330c5f9ed47f4e4287e839e07596a&type=album)

# Код программы
## main
```cpp
#include <iostream>
#include "Dialog.h"
#include "tree.h"
using namespace std;

int main() {
	Print* p = new Print;
	p->Input();
	p->Show();

	Magazin* s = new Magazin;
	s->Input();
	s->Show();

	Tree t(10);
	Object* o = p;
	t.Add();
	o = s;
	t.Show();
	t.Del();
	cout << "\nTree: " << t() << endl;

	Dialog D;
	D.execute();
	return 0;
}
```
##Dialog.h
```cpp
#pragma once
#include "Header.h"
#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmQuit = 101;

struct TEvent {
    int what;
    union {
        int command;
        struct {
            int message;
            int parametr;
        };
    };
};

class Dialog : public Tree {
protected:
    int EndState;
public:
    Dialog() { EndState = 0; };
    virtual ~Dialog() {};
    virtual void getEvent(TEvent& event) {
        string opInt = "m+-szq";
        string s;
        string param;

        char code;
        cout << '>'; cin >> s;  code = s[0];
        if (opInt.find(code) >= 0) {
            event.what = evMessage;
            switch (code) {
            case 'm': event.command = cmMake; break;
            case '+': event.command = cmAdd; break;
            case '-': event.command = cmDel; break;
            case 's': event.command = cmShow; break;
            case 'z': event.command = cmGet; break;
            case 'q': event.command = cmQuit; break;
            }
            if (s.length() > 1) {
                param = s.substr(1, s.length() - 1);
                int A = atoi(param.c_str());
                event.parametr = A;
            }
        }
        else event.message = evNothing;
    };
    virtual int execute() {
        TEvent event;
        do {
            EndState = 0;
            getEvent(event);
            handleEvent(event);
        } while (!valid());
        return EndState;
    };

    virtual void handleEvent(TEvent& event) {
        if (event.what == evMessage) {
            switch (event.command) {
            case cmAdd: {
                Magazin* data = new Magazin;
                data->Input();
                Add(data);
                clearEvent(event);
                break;
            }
            case cmDel: Del(event.parametr); size--; break;
            case cmGet: Find(event.parametr); clearEvent(event); break;
            case cmShow: Show(); clearEvent(event); break;
            case cmQuit: endExec(); clearEvent(event); break;
            }
        }
    };
    virtual void clearEvent(TEvent& event) {
        event.what = evNothing;
    };
    int valid() {
        if (EndState == 0) return 0;
        else return 1;
    };
    void endExec() { EndState = 1; }
};
```
##tree.h
```cpp
#pragma once
#include <iostream>
#include "Dialog.h"

using namespace std;

class Tree {
protected:
	Object** beg;
	int size;
	int cur;
public:
	Tree(void);
	Tree(int);
	~Tree(void);
	void Add(void);
	void Del(void);
	void Show(void);
	void Find(int);
	int operator()();
	void HandleEvent(const TEvent& event);
};
```
##tree.cpp
```cpp
#include <iostream>
#include "tree.h"
#include "Header.h"


using namespace std;

Tree::Tree(void) {
	beg = nullptr;
	size = 0;
	cur = 0;
}
Tree::Tree(int n) {
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Tree::~Tree(void) {
	if (beg != 0) { delete[] beg; }
	beg = 0;
}
void Tree::Add() {
	Object* p;

	cout << "\n1.Person\n2.Student\nEnter variant >> ";
	int y;
	cin >> y; cout << "\n";

	if (y == 1) {
		Print* a = new (Print);
		a->Input();
		p = a;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else if (y == 2) {
		Magazin* b = new (Magazin);
		b->Input();
		p = b;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}
void Tree::Show()
{
	if (cur == 0) { cout << "\nEmpty" << endl; }
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->Show();
		p++;
	}
}
int Tree::operator()() { return cur; }
void Tree::Del(void) {
	if (cur == 0) { return; }
	cur--;
}
void Tree::Find(int tmp) {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		if (i == tmp - 1) { (*p)->Show(); }
		p++;
	}
}
void Tree::HandleEvent(const TEvent& event) {
	if (event.what == evMessage) {
		Object** p = beg;
		for (int i = 0; i < cur; i++) {
			(*p)->Show();
			++p;
		}
	}
}
```
##Header.h
```cpp
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
```
