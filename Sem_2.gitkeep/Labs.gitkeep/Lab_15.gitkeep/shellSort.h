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