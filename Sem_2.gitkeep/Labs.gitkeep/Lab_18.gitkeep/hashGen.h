#pragma once

#include <iostream>
#include <string>

using namespace std;

int hashGen(int size, string str) {
    unsigned int key = 0;
    for (int i(0); i < str.size(); key += str[i], i++);
    return  static_cast<int>(key * 0.2) % size;
}