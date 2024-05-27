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