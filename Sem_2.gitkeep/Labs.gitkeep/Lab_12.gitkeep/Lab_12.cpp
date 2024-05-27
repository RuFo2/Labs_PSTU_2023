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