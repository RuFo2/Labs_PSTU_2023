# Лабораторная работа №17
>[!NOTE]
>Тема : "Методы поиска"
# Вариант № 21
Работа с алгоритмами Кнут-Моррис-Пратта и Бойер-Мура, разбор алгоритмов и их реализация.
# Блок-схема
-
# Код программы
##main
```cpp
#include "boyerSearch.h"
#include "knuthSearch.h"


int main() {
    setlocale(LC_ALL, "RU");
    cout << "Выберите способ сортировки:\n"
        << "1 - boyerSearch\n"
        << "2 - knuthSearch\n";
    int number;
    cin >> number;
    switch (number) {
    case 1: {
        boyerSearch("vzglyanivokrugoglyanisnazadduhi", "oglyanis");
        break;
    }
    case 2: {
        knuthSearch("vzglyanivokrugognyanisnazadduhi", "vokrug");
        break;
    }
    default: {
        cout << "1 or 2" << endl;
        break;
    }
    }
    return 0;
}
```
##boyerSearch.h
```cpp
#pragma once

#include <iostream>
#include <string>

using namespace std;

const int CHAR_NUM = 256;

void calcCharTable(string str, int size, int charTable[CHAR_NUM])
{
    for (int i = 0; i < CHAR_NUM; i++)
        charTable[i] = -1;

    for (int i = 0; i < size; i++)
        charTable[(int)str[i]] = i;
}

void boyerSearch(string str, string pat)
{
    int strSize = (int)str.size();
    int patSize = (int)pat.size();

    int shiftTable[CHAR_NUM];

    calcCharTable(pat, patSize, shiftTable);

    int shift = 0;

    while (shift <= (strSize - patSize))
    {
        int j = patSize - 1;
        while (j >= 0 && pat[j] == str[shift + j]) j--;

        if (j < 0)
        {
            cout << "Паттерн найден по индексу " << shift << endl;
            if (shift + patSize < strSize)
                shift += patSize - shiftTable[str[shift + patSize]];
            else shift++;
        }
        else shift += max(1, j - shiftTable[str[shift + j]]);
    }
}
```
##knuthSearch.h
```cpp
#pragma once

#include <iostream>
#include <string>

using namespace std;

int* calcPrefixFunc(string pat, int size)
{
    int* lps = new int[size];
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < size)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = len;
            len++;
            i++;
        }
        else
        {
            if (len != 0) { len = lps[len - 1]; }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void knuthSearch(string str, string pat)
{
    int strSize = (int)str.size();
    int patSize = (int)pat.size();

    int* lps = calcPrefixFunc(pat, patSize);
    int strIndx = 0;
    int patIndx = 0;

    while ((strSize - strIndx) >= (patSize - patIndx))
    {
        if (pat[patIndx] == str[strIndx])
        {
            patIndx++;
            strIndx++;
        }

        if (patIndx == patSize)
        {
            cout << "Паттерн найден по индексу " << strIndx - patIndx << endl;
            patIndx = lps[patIndx - 1];
        }
        else if (strIndx < strSize && pat[patIndx] != str[strIndx])
        {
            if (patIndx != 0) { patIndx = lps[patIndx - 1]; }
            else { strIndx++; }
        }
    }

}
```
