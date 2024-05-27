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