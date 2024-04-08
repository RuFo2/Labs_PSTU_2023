# Лабораторная работа №10
>[!NOTE]
>Тема : "Динамический массив"
>Цель : Организация динамических массивов
# Вариант № 21
Сформировать массив строк. Удалить из него строку с заданным номером.
# Блок-схема
-
# Код программы
```cpp
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

char** createArr(const int size) {
	char** tmpArr = new char* [size];
	for (int i = 0; i < size; i++)
	{
		tmpArr[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			tmpArr[i][j] = rand() % 200;
		}
	}
	return tmpArr;
}

void showArr(char** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void deleteElem(char** arr, int index, int size)
{
	delete arr[index];
	for (int i = index; i < size-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = nullptr;
	delete arr[size - 1];
}

int main() {
	int index;
	cin >> index;
	srand(time(0));
	char **arr = createArr(5);
	showArr(arr, 5);
	cout << endl;
	deleteElem(arr, index, 5);
	showArr(arr, 5 - 1);
	return 0;
}
```
