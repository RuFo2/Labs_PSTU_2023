# Лабораторная работа №7.1
>[!NOTE]
>Тема : "Перегрузка функций в С++"
>Цель : Знакомство с организацией перегруженных функций в Си++
# Вариант № 21
Написать перегруженные функции и основную программу, которая их вызывает.
а) для массива целых чисел находит количество отрицательных элементов;
б) для строки находит количество слов, заканчивающихся и начинающихся на одну и ту же букву.
# Блок-схема
-
# Код программы
```cpp
#include <iostream>

using namespace std;

int cntEl(string str){
    int cnt = 0;
    char j = str[0];
    for (int i = 0; i <  str.size(); i++) {
        if (str[i] != ' ' && str[i+1] == ' ') {
            if (str[i] == j) {
                cnt++;
            }
            i++;
            j = str[i+1];
        }
        
    }
    return cnt;
}

int cntEl(int arr[], int size){
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int arr[5] = {-1, 3 ,-4 , 4, 0};
    string str = "asda tuit oo ie ";
    cout << cntEl(str)<< ' ' << cntEl(arr, 5);
}

```
