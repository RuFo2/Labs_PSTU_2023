# Лабораторная работа №1
>[!NOTE]
>Тема : "Работа с двумерными массивами"
>Цель : Получение новых навыков обработки двумерных массивов.
# Вариант № -
Заполнить массив, если сумма номера строки и номера столбца - нечетное число, то такой элемент = 0. Все остальные элементы заполняются от 1-9 по порядку(последовательно, пропуская те элементы, которые заняты нулями)
# Блок-схема
-
# Код программы

```cpp
#include <iostream>
using namespace std;

int main()
{
	int num[9] = {1,2,3,4,5,6,7,8,9};
	int arr[8][8];
	for (int i = 0, k = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				arr[i][j] = num[k % 9];
				k++;
			}
			else arr[i][j] = 0;
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
  return 0;			
}
```
