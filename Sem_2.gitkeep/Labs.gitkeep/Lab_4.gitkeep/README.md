# Лабораторная работа №4
>[!NOTE]
>Тема : "Работа с одномерными массивами"
>Цель : Получение новых навыков обработки одномерных массивов.
# Вариант № 21
1) Реализовать с использованием массива двунаправленное
кольцо (просмотр возможен в обе стороны, от последнего
элемента можно перейти к первому).
2) Распечатать полученный массив, начиная с К-ого элемента
и до К-1 ( по кольцу влево).
3) Добавить в кольцо первый и 3 последних элемента.
4) Распечатать полученный массив, начиная с К-ого элемента
(и до К+1 по кольцу вправо)
# Блок-схема
-
# Код программы

```cpp
#include <iostream>
#include <ctime>
using namespace std;

void create(int* arr, int n) {
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % (100 - 20 + 1)) + 20;
    }
}
void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
void printArrRight(int* arr, int n, int k) {
    for (int i = k; i < n + 4 + k; i++)
    {
        cout << arr[ i % n ] << ' ';
    }
    cout << endl;
}
void printArrLeft(int* arr, int n, int k) {
    for (int i = (k + n); i > k; i--)
    {
        cout << arr[ i % n ] << ' ';
    }
    cout << endl;
}

void plusElement(int* arr, int& n) {
    arr[n] = arr[0];
    arr[n + 1] = arr[n - 3];
    arr[n + 2] = arr[n - 2];
    arr[n + 3] = arr[n - 1];
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    int arr[n+4];
    create(arr, n);
    printArr(arr, n);
    printArrLeft(arr, n, k);
    plusElement(arr, n);
    printArr(arr, n+4);
    printArrRight(arr, n, m);
    return 0;
}
```
