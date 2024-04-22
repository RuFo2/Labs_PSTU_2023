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
