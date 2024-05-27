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

