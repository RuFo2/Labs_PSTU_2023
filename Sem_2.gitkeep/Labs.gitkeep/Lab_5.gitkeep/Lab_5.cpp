#include <iostream>
#include <ctime>
int n = 5;
using namespace std;

void create(int arr[5][5]) {
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = (rand() % (100 - 20 + 1)) + 20;
        }
    }
}

void printArr(int arr[5][5]) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
int check(int arr[5][5])
{
    int max = arr[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}
int main() {

    int array[5][5];
    create(array);
    printArr(array);
    cout << check(array) << endl;
    return 0;
}