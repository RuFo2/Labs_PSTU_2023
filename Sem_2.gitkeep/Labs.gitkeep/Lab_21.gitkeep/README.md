# Лабораторная работа №21
>[!IMPORTANT]
>Тема : "Перегрузка операций"
>Цель: Использование перегруженных операций в классах.

# Вариант №15

1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Перегрузить операции указанные в варианте.
8. Написать программу, в которой продемонстрировать создание объектов и работу всех перегруженных операций.
9.Создать класс Pair (пара чисел). Пара должна быть представлено двумя полями: типа int
для первого числа и типа double для второго. Первое число при выводе на экран должно
быть отделено от второго числа двоеточием. Реализовать:
  - вычитание пар чисел
  - добавление константы к паре (увеличивается первое число, если константа
    целая, второе, если константа вещественная).


# UML-диаграмма
-

# Код программы
```cpp
#include <iostream>
using namespace std;

class Pair {
	int first;
	double second;
public:
	Pair(int n,double q){
		first = n;
		second = q;
	}
	Pair() {
		first = 20;
		second = 4;
	}
	Pair(const Pair& tmp){
		first = tmp.first;
		second = tmp.second;
	}

	void setFirst(int n) { first = n; }
	void setSecond(double q) { second = q; }

	int getFirst() { return first; }
	double getSecond() { return second; }

	Pair& operator-(const Pair& tmp){
		Pair* k = new Pair;
		k->setFirst(first);
		k->setSecond(second);
		k->first -= tmp.first;
		k->second -= tmp.second;
		return *k;
	}

	void operator+(int n) { first += n; }
	void operator+(double q) { second += q; }

	void Show() {
		cout << first << ' ' << second << endl;
	}
	~Pair(){}
};

int main()
{
	Pair pairOne(30, 8);
	Pair pairTwo;
	Pair pairThree = pairOne - pairTwo;
	pairThree.Show();
	pairThree + 87;
	pairThree + 34.5;
	pairThree.Show();
}
```
