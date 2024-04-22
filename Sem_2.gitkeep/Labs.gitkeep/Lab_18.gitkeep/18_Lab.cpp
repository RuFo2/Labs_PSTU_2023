#include "chainMethod.h"
#include "openAddressing.h"

#include <iostream>
#include <string>

using namespace std;


int main() {
    setlocale(LC_ALL, "RU");
    cout << "Выберите способ сортировки:\n"
        << "1 - open addressing\n"
        << "2 - the chain method\n";
    int number;
    cin >> number;
    switch (number) {
    case 1: {
        hashOpAdr* people = new hashOpAdr;
        people->setHashTable(100);
        people->showTable();
        break;
    }
    case 2: {
        hashChain* people = new hashChain;
        people->setHashTable(100);
        people->showTable();
        break;
    }
    default: {
        cout << "1 or 2" << endl;
        break;
    }
    }

}