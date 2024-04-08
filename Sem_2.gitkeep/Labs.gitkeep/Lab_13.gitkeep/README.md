# Лабораторная работа №13
>[!NOTE]
>Тема : "Сортировка Шелла"
# Вариант № 21
Реализация сортировки Шелла
# Блок-схема
-
# Код программы
```cpp
#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    for (int h = n / 2; h > 0; h /= 2)
    {
        for (int i = h; i < n; i++)
        {
            int tmp = arr[i];
            int j = 0;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h)
            {
                arr[j] = arr[j - h];
            }
            arr[j] = tmp;
        }
    }
}

void showArr(int* arr, int size) {
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    int arr[6] = { 7, 8, 9, 5, 4, 2 };
    showArr(arr, 6);
    cout << endl;
    shellSort(arr, 6);
    showArr(arr, 6);

    return 0;
}
```
