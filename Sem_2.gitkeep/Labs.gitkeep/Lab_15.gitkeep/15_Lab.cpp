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