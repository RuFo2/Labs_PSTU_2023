# Лабораторная работа №19
>[!NOTE]
>Тема : "Классы и объекты. Инкапсуляция."
>Цель : 
1) Создание консольного приложения, состоящего из нескольких файлов в системе программирования Visual Studio.
2) Использование классов и объектов в О программе.
# Вариант № 15
Элемент арифметической прогрессии aj вычисляется по формуле: aj=a0*r^j.Поле first -
дробное число, первый элемент прогрессии ао, поле second - положительное целое число,
постоянное отношение r. Реализовать метод element(int j) -вычисление j-го элемента
прогрессии.
# Блок-схема
-
# Код программы
```cpp
#include <iostream>
#include <cmath>
using namespace std;

class arProg {
    double first;
    unsigned int second;

public:
    void set(double a, unsigned int b)
    {
        first = a;
        second = b;
    }
    void element(int j)
    {
        cout << "a(j) = " << first * pow(second, j);
    }
};
int main()
{
    arProg el;
    el.set(1, 3);
    el.element(5);
    return 0;
}
```
