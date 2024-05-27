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