﻿#include <iostream>
#include <string>
using namespace std;
void reverseStr(string str) {
    string subStr = "";
    string newStr;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        count += 1;
        subStr += str[i];
        if (str[i + 1] == ' ')
        {
            string tmp = "";
            while (count != 0) {
                tmp += subStr[count - 1];
                count--;
            }
            newStr += tmp + ' ';
            i++;
            subStr = "";
        }
    }
    string tmp = "";
    while (count != 0) {
        tmp += subStr[count - 1];
        count--;
    }
    newStr += tmp + ' ';
    cout << newStr << endl;
}

int main()
{
    reverseStr("aaff ffaa jefnkj joi");
    return 0;
}
