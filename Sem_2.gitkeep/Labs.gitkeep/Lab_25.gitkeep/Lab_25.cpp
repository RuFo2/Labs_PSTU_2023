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