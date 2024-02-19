# Лабораторная работа №3.2
>[!NOTE]
>Тема : "Работа с рекурсиями"
# Вариант № -
Выполнить сумму ряда Фибоначчи.
# Блок-схема
-
# Код программы

```cpp
#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1) return n;
    else return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fib(i) << " ";
    }
    return 0;
}
```
