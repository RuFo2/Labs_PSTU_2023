# Лабораторная работа №15
>[!NOTE]
>Тема : "Внешние сортировки"
# Вариант № 21
Работа с Многофазной и Естественной сортировками, разбор алгоритмов и их реализация.
# Блок-схема
-
# Код программы
##main
```cpp
#include "nuturalSort.h"
#include "splitFile.h"

#include <stdio.h>
#include <iostream>

using namespace std;

void showArr(int* arr, int size)
{
    for (int i = 0; i < 8; ++i) cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int arr[8] = { 5, 7, 1, -1, 28, -6, 2, 12 };
    int countArr[8]{};

    splitFile(arr, sizeof(arr) / sizeof(arr[0]), countArr);
    showArr(arr, 8);
    sortNutural(countArr, arr);
    showArr(arr, 8);

    return 0;
}
```
##splitFile.h
```cpp
#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

void splitFile(int arr[], int size, int* countArr)
{
    FILE* fp;
    fp = fopen("t.txt", "wb");
    if (fp == NULL) { fputs("fopen error", fp); fclose(fp); }
    int* subArr = new int[size] {};
    int mn = arr[0]; int subIndx = 1; int cntIndx = 0;
    subArr[0] = mn;

    for (int i(1); i < size; i++)
    {
        if (mn <= arr[i]) {
            subArr[subIndx++] = arr[i];
            mn = arr[i];
        }
        else {
            int trueSizeArr[subIndx];
            for (int j = 0; j < subIndx; j++) trueSizeArr[j] = subArr[j];
            countArr[cntIndx++] = (int)sizeof(trueSizeArr);
            fwrite(trueSizeArr, sizeof(trueSizeArr), 1, fp);
            mn = arr[i];
            subArr[0] = mn;
            subIndx = 1;
        }
    }

    int trueSizeArr[subIndx];
    for (int j(0); j < subIndx; j++) trueSizeArr[j] = subArr[j];
    countArr[cntIndx++] = (int)sizeof(trueSizeArr);
    fwrite(trueSizeArr, sizeof(trueSizeArr), 1, fp);
    fclose(fp);
    delete[] subArr;
}
```
##shellSort.h
```cpp
#pragma once

void shellSort(int* arr, int n)
{
    for (int h = n / 2; h > 0; h /= 2)
    {
        for (int i = h; i < n; i++)
        {
            int tmp = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h)
            {
                arr[j] = arr[j - h];
            }
            arr[j] = tmp;
        }
    }
}
```
##naturalSort.h
```cpp
#pragma once

#include "shellSort.h"

#include <stdio.h>
#include <iostream>

using namespace std;

void sortNutural(int* countArr, int* arr)
{
    int size = 0;
    FILE* pFile;
    string str;
    pFile = fopen("t.txt", "rb");
    int* firstArr = new int[countArr[0] / 4];
    size += countArr[0] / 4;
    fread(firstArr, countArr[0], 1, pFile);
    for (int i = 1; countArr[i] != 0; ++i)
    {
        int sizeMX = size;
        int* secondArr = new int[countArr[i] / 4];
        sizeMX += countArr[i] / 4;
        fread(secondArr, countArr[i], 1, pFile);
        int* thirdArr = new int[sizeMX];
        for (int j = 0; j < size; j++) thirdArr[j] = firstArr[j];
        for (int j = 0; j < countArr[i] / 4; j++) thirdArr[j + size] = secondArr[j];
        delete[] firstArr;
        delete[] secondArr;
        firstArr = new int[sizeMX];
        shellSort(thirdArr, sizeMX);
        for (int j = 0; j < sizeMX; j++) firstArr[j] = thirdArr[j];
        size = sizeMX;
    }
    for (int i = 0; i < size; i++) arr[i] = firstArr[i];
    delete[] firstArr;
    fclose(pFile);
}
```
