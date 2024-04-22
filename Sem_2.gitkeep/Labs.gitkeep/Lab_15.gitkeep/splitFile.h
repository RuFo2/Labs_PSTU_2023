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
