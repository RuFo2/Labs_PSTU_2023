# Лабораторная работа №28
>[!NOTE]
>Тема : "Простое наследование. Принципы подстановки"
>Цель: Разработка программы, в которой данные сохраняются в файле, корректируются и выводятся из файла на печать. Работа с файлом осуществляется с использованием потоковых классов.

# Вариант №15
1.	Создать пользовательский класс с минимальной функциональностью.
2.	Написать функцию для создания объектов пользовательского класса (ввод исходной информации с клавиатуры) и сохранения их в потоке (файле).
3.	Написать функцию для чтения и просмотра объектов из потока.
4.	Написать функцию для удаления объектов из потока в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
5.	Написать функцию для добавления объектов в поток в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
6.	Написать функцию для изменения объектов в потоке в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
7.	Для вызова функций в основной программе предусмотреть меню.
представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
-	операции сравнения (<, >).
-	добавление копеек (++) (постфиксная и префиксная формы)
Задание:
•	Удалить все записи большие заданного значения.
•	Уменьшить все записи с заданным значением в два раза.
•	Добавить K записей после элемента с заданным номером.


# UML-диаграмма
![](https://sun9-3.userapi.com/impg/lZ5PC0N_0Cy7WeMasOKIDv-P_6IdUrXaq3pL0Q/gjUk-oA67T4.jpg?size=264x372&quality=96&sign=1fdf1e0ca5cabcbf44fd8c6412567526&type=album)

# Код программы
## main
```cpp
#include<iostream>
#include <fstream>
#include"Money.h"
#include"file.h"
using namespace std;
int main() {
	system("chcp 1251 > Null");
	srand(time(0));
	int n;
	do {
		cout << "Введите количество элементов: ";
		cin >> n;
	} while (n < 1);

	cout << endl;
	error(write(n));
	bool flag = true;
	while (flag) {
		int current_action = choosing();
		int tmp_1;
		double tmp_2;

		Money p_2;
		switch (current_action) {
		case 1:
			cout << "Текущее содержимое файла: " << endl;
			error(print_file());
			cout << endl;
			break;
		case 2:
			do {
				cout << "Введите количество элементов: ";
				cin >> tmp_1;
			} while (tmp_1 < 1);
			error(write(tmp_1));
			break;
		case 3:
			cout << "Введите значение, значения больше которого будут удалены: " << endl;
			cin >> p_2;
			error(remove(p_2));
			break;
		case 4:
			cout << "Уменьшим все записи в 2 раза: " << endl;
			error(decrease(2));
			cout << endl;
			break;

		case 5:
			int N;
			do {
				cout << "Введите номер, после которого необходимо ввести K элементов" << endl;
				cin >> N;
			} while (N < 1);

			do {
				cout << "Введите количество элементов, которые необходимо добавить: " << endl;
				cin >> tmp_1;
			} while (tmp_1 < 1);
			error(add_el(N, tmp_1));
			break;
		default:
			flag = false;
			break;
		}
	}
	return 0;
}
```
##Money.h
```cpp
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Money {
	int rub;
	long kop;
public:
	Money() {
		this->rub = 0;
		this->kop = 0;
	}
	Money(int rub, long kop) {
		this->rub = rub;
		this->kop = kop;
	}
	Money(const Money& other) {
		this->rub = other.rub;
		this->kop = other.kop;
	}
	~Money() { }
	Money operator/(const int& x) {
		return (Money(this->rub / x, this->kop));
	}

	Money& operator++() {
		Money x(this->rub++, this->kop);
		return x;
	}
	Money operator ++(int) {
		Money x(this->rub, this->kop++);
		return x;
	}
	bool operator<(const Money& para) { 
		if (this->rub < para.rub) return true;
		else if (this->rub == para.rub) {
			if (this->kop < para.kop) return true;
			else return false;
		}
		else return false;
	}
	bool operator>(const Money& para) {
		if (this->rub < para.rub) return false;
		else if (this->rub == para.rub) {
			if (this->kop < para.kop) return false;
			else return true;
		}
		else return true;
	}
	void operator=(const Money& para) {
		this->rub = para.rub;
		this->kop = para.kop;
	}
	friend ostream& operator <<(ostream& stream, const Money& p) {
		stream << p.rub << " , " << p.kop;
		return stream;
	}
	friend istream& operator >>(istream& stream, Money& p) {
		cout << "enter rub and kop: ";
		stream >> p.rub >> p.kop;
		return stream;
	}
	friend fstream& operator<<(fstream& stream, Money& para) {
		stream << para.rub << endl << para.kop << endl;
		return stream;
	}
	friend fstream& operator>>(fstream& stream, Money& para) {
		stream >> para.rub;
		stream >> para.kop;
		return stream;
	}
};
```
##file.h
```cpp
#pragma once
#include <iostream>
#include <fstream>
#include"Money.h"

using namespace std;

void randomize(Money& p) {
	int x = rand() % 100;
	long y = (rand() % 10000) * 0.01;
	p = Money(x, y);
}
bool write(int N) {
	fstream F1("file.txt", ios::out | ios::trunc);
	if (!F1) {
		cout << "error open!" << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		Money p_1;
		randomize(p_1);
		F1 << p_1 << endl;
	}
	F1.close();
	return 1;
}
bool print_file() {
	fstream F1("file.txt", ios::in);

	if (!F1) {
		cout << "error open!" << endl;
		return 0;
	}

	Money p_1;

	while (F1 >> p_1) {
		cout << p_1 << endl;
	}
	return 1;
}
void error(bool N) {
	if (!N) {
		cout << "error" << endl;
	}
}
bool remove(Money& para) {
	fstream F1("file.txt", ios::in);
	if (!F1) {
		cout << "error open!" << endl;
		return 0;
	}

	fstream tmp("temp.txt", ios::out | ios::trunc);

	Money p_3;

	while (F1 >> p_3) {
		if (p_3 < para) {
			tmp << p_3 << endl;
		}
	}
	F1.close();
	tmp.close();
	remove("file.txt");
	rename("temp.txt", "file.txt");
	return 1;
}
template<typename T>
bool decrease(T) {
	fstream F1("file.txt", ios::in);

	if (!F1) {
		cout << "error open!" << endl;
		return 0;
	}

	fstream tmp("temp.txt", ios::out | ios::trunc);
	Money p_4;

	while (F1 >> p_4) {
		p_4 = p_4 / 2;
		tmp << p_4 << endl;
	}

	F1.close();
	tmp.close();

	remove("file.txt");
	rename("temp.txt", "file.txt");
	return 1;
}
bool add_el(int number, int quantity) {
	fstream F1("file.txt", ios::in);

	if (!F1) {
		cout << "error open!" << endl;
		return 0;
	}

	fstream tmp("temp.txt", ios::out | ios::trunc);

	Money p_4;

	int counter = 0;

	while (F1 >> p_4) {
		counter++;
		tmp << p_4 << endl;

		if (counter == number) {
			for (int i = 0; i < quantity; i++) {
				Money new_money;
				randomize(new_money);
				tmp << new_money << endl;
			}
		}
	}

	if (counter < number)
		cout << "number: " << number << endl;

	F1.close();
	tmp.close();

	remove("file.txt");
	rename("temp.txt", "file.txt");
	return 1;
}
int choosing() {
	cout << "Choice" << endl;
	cout << "1 - make file" << endl;
	cout << "2 - print file" << endl;
	cout << "3 - delete record from file" << endl;
	cout << "4 - add record to file" << endl;
	cout << "5 - change record in file" << endl;
	cout << "0 - exit" << endl;
	int choice;
	do {
		cout << ">  ";
		cin >> choice;
	} while (choice < 0 || choice > 6);
	cout << endl;
	return choice;
}
```
