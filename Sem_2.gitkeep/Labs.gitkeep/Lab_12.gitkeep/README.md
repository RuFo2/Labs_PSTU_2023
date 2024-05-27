# Лабораторная работа №12
>[!NOTE]
>Тема : "Сложные сортировк"
>Цель: Работа со сложными сортировками, разбор алгоритмов и их реализация.

# Вариант №21
1. BucketSort
2. CountSort
3. MergeSort
4. QuickSortLomyto

# Блок-схема
-
# Код программы
## main
```cpp
#include "lomutoSort.h"
#include "mergeSort.h"
#include "countSort.h"
#include "bucketSort.h"
#include <iostream>

using namespace std;

int main() {
    system("chcp 1251");
    cout << "Выберите способ сортировки:\n"
        << "1 - bucketSort\n"
        << "2 - countSort\n"
        << "3 - mergeSort\n"
        << "4 - lomutoSort\n";
    int number;
    cin >> number;
    switch (number) {
    case 1: {
        int arr[6]{ 35, 7, 15, 22, 1, 13 };
        printArray(arr, 6);
        bucketSort(arr, 6);
        printArray(arr, 6);
        break;
    }
    case 2: {
        int arr[6]{ 35, 7, 15, 22, 1, 13 };
        printArray(arr, 6);
        countSort(arr, 6);
        printArray(arr, 6);
        break;
    }
    case 3: {
        int arr[] = { 12, 11, 13, 5, 6, 7 };
        printArray(arr, 6);
        mergeSort(arr, 0, 6);
        printArray(arr, 6);
        break;
    }
    case 4: {
        int arr[5]{ 1,0,3,2,6 };
        printArray(arr, 5);
        quickSort(arr, 0, 4);
        printArray(arr, 5);
        break;
    }

    default: {
        cout << "1 or 2 or 3 or 4" << endl;
        break;
    }
    }
    return 0;
}
```
##bucketSort
```cpp
#pragma once
#include <iostream>

using namespace std;

int* bucketSort(int arr[], int n) {
    const int BUCKET_NUM = 6;
    const int BUCKET_SIZE = 6;

    int buckets[BUCKET_NUM][BUCKET_SIZE];
    int bucketSizes[BUCKET_NUM] = {};
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / 6;
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }

    for (int i = 0; i < BUCKET_NUM; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            int tmp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > tmp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;

            }
            buckets[i][k + 1] = tmp;

        }
    }
    int idx = 0;
    for (int i = 0; i < BUCKET_NUM; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }

    return arr;
}
```
##countSort.h
```cpp
#pragma once
#include <iostream>

using namespace std;

int* countSort(int arr[], int size)
{
    int* output = new int[size];
    int* countArr;

    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max) { max = arr[i]; }
    }

    countArr = new int[max + 1] {};

    for (int i = 0; i < size; i++)
    {
        countArr[arr[i]]++;
    }

    for (int i = 0; i <= max; ++i)
    {
        countArr[i] += countArr[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }

    for (int i = 0; i < size; i++) arr[i] = output[i];

    delete[] countArr;
    delete[] output;

    return arr;
}
```
##mergeSort.h
```cppp
#pragma once
#include <iostream>
using namespace std;

void merge(int arr[], int leftIndx,
    int midIndx, int rightIndx)
{
    auto const subArrOne = midIndx - leftIndx + 1;
    auto const subArrTwo = rightIndx - midIndx;


    int* leftArr = new int[subArrOne],
        * rightArr = new int[subArrTwo];


    for (int i = 0; i < subArrOne; i++) {
        leftArr[i] = arr[leftIndx + i];
    }
    for (int j = 0; j < subArrTwo; j++) {
        rightArr[j] = arr[midIndx + 1 + j];
    }

    int indxSubArrOne = 0,
        indxSubArrTwo = 0;

    int indxMergedArr = leftIndx;


    while (indxSubArrOne < subArrOne &&
        indxSubArrTwo < subArrTwo)
    {
        if (leftArr[indxSubArrOne] <= rightArr[indxSubArrTwo])
            arr[indxMergedArr] = leftArr[indxSubArrOne++];
        else
        {
            arr[indxMergedArr] =
                rightArr[indxSubArrTwo++];
        }
        indxMergedArr++;
    }


    while (indxSubArrOne < subArrOne)
    {
        arr[indxMergedArr++] =
            leftArr[indxSubArrOne++];
    }


    while (indxSubArrTwo < subArrTwo)
    {
        arr[indxMergedArr++] =
            rightArr[indxSubArrTwo++];
    }
}


void mergeSort(int array[], int leftIndx, int rightIndx)
{

    if (leftIndx >= rightIndx) return;
    int midIndx = leftIndx + (rightIndx - leftIndx) / 2;
    mergeSort(array, leftIndx, midIndx);
    mergeSort(array, midIndx + 1, rightIndx);
    merge(array, leftIndx, midIndx, rightIndx);
}


void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
```
##lomutoSort.h
```cpp
#pragma once
#include <iostream>
using namespace std;

int partition(int arr[], int lowIndex, int highIndex)
{
    int pivot = arr[highIndex];
    int wall = lowIndex - 1;

    for (int curIndex(lowIndex); curIndex <= highIndex - 1; curIndex++)
        if (arr[curIndex] <= pivot)
            swap(arr[++wall], arr[curIndex]);

    swap(arr[++wall], arr[highIndex]);
    return wall;
}


void quickSort(int arr[], int lowIndex, int highIndex)
{
    if (lowIndex < highIndex)
    {
        int pI(partition(arr, lowIndex, highIndex));
        quickSort(arr, lowIndex, pI - 1);
        quickSort(arr, pI + 1, highIndex);
    }
}
```
