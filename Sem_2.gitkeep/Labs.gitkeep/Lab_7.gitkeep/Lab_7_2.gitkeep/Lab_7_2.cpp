﻿#include <iostream>
#include <stdarg.h>
using namespace std;

void octFunc(int* arr, int size, ...)
{
    va_list ptr;
    va_start(ptr, size);
    for (int i = 0; i < size; i++) {
        int a = va_arg(ptr, int);
        int b = a % 8;
        a /= 8;
        while (a != 0) {
            b += a % 8 * 10;
            a /= 8;
        }
        arr[i] = b;
    }
    va_end(ptr);
}

int main() {
    int arr0[3]{};
    octFunc(arr0, 3, 9, 2, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << arr0[i] << ' ';
    }
    cout << endl;

    int arr1[5]{};
    octFunc(arr1, 5, 9, 2, 3, 52, 89);
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << ' ';
    }
    cout << endl;

    int arr2[8]{};
    octFunc(arr2, 8, 9, 2, 3, 52, 89, 90, 34, 77);
    for (int i = 0; i < 8; i++)
    {
        cout << arr2[i] << ' ';
    }
    cout << endl;
}
