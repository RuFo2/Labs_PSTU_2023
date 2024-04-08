# Лабораторная работа №14
>[!NOTE]
>Тема : "Быстрая сортировка по Хоару"
# Вариант № 21
Реализация быстрой сортировки по Хоару
# Блок-схема
-
# Код программы
```cpp
#include <iostream>
using namespace std;

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int num = 0;

    for (int i = left + 1; i <= right; i++)
    {
        if (arr[i] < pivot)
            num++;
    }

    int posIndx = left + num;

    swap(arr[posIndx], arr[left]);

    int i = left, j = right;
    while (i < posIndx && j > posIndx)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < posIndx && j > posIndx)
            swap(arr[i++], arr[j--]);
    }
    return posIndx;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;
    int pI = partition(arr, low, high);
    quickSort(arr, low, pI - 1);
    quickSort(arr, pI + 1, high);
}

void showArr(int* arr, int size) {
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' ';
    }
}

int main() {
    int arr[6] = { 3, 8, 5, 1, 7, 9 };
    showArr(arr, 6);
    cout << endl;
    quickSort(arr, 0, 5);
    showArr(arr, 6);

    return 0;
}
```
