# Лабораторная работа №20
>[!NOTE]
>Тема : "Классы и объекты. Использование конструкторов"
>Цель: Создание объектов с использованием конструкторов.

# Вариант №15
1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы).
5. Написать демонстрационную программу, в которой продемонстрировать все три случая вызова конструктора-копирования, вызов конструктора с параметрами и конструктора без параметров.
6. Пользовательский класс ЗАРПЛАТА:
- ФИО - string
- Оклад - double
- Премия (% от оклада) - int

# UML-диаграмма
-

# Код программы
```cpp
#include <iostream>
#include <string>
using namespace std;

class Salary {
    string fullName;
    double salary;
    int bonus;
public:
    Salary() {
        fullName = "Buch Yan";
        salary = 20000;
        bonus = 15;
    };
    Salary(string str, double cash, int prize) {
        fullName = str;
        salary = cash;
        bonus = prize;
    };
    Salary(const Salary& tmp) {
        fullName = tmp.fullName;
        salary = tmp.salary;
        bonus = tmp.bonus;
    };

    void Show() {
        cout << fullName << ' ' << salary << ' ' << bonus << endl;
    }

    string getName() { return fullName; }
    double getSalary() { return salary; }
    int getBonus() { return bonus; }
    
    void setName(string str) { fullName = str; }
    void setSalary(double cash) { salary = cash; }
    void setBonus(int prize) { bonus = prize; }

    ~Salary(){}
};
int main()
{
    Salary salWithoutPar;
    Salary salWithPar("Buch", 5000, 9);
    Salary salPointer(salWithPar);
    salWithoutPar.Show();
    salWithPar.Show();
    salPointer.Show();
    salPointer.setBonus(24);
    cout << salWithoutPar.getName() << endl;
    return 0;
}
```
