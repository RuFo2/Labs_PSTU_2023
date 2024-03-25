#include <iostream>

using namespace std;

int cntEl(string str)
{
    int cnt = 0;
    char j = str[0];
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ' && str[i + 1] == ' ') {
            if (str[i] == j) {
                cnt++;
            }
            i++;
            j = str[i + 1];
        }

    }
    return cnt;
}

int cntEl(int arr[], int size)
{
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int arr[5] = { -1, 3 ,-4 , 4, 0 };
    string str = "asda tuit oo ie ";
    cout << cntEl(str) << ' ' << cntEl(arr, 5);
}
