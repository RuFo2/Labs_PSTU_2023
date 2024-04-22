# Лабораторная работа №18
>[!NOTE]
>Тема : "Hash-таблицы"
# Вариант № 21
Работа с hash-таблицами, разбор алгоритмов разрешение коллизий и их реализация.
# Блок-схема
-
# Код программы
##main
```cpp
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
```
##hashGen.h
```cpp
#pragma once

#include <iostream>
#include <string>

using namespace std;

int hashGen(int size, string str) {
    unsigned int key = 0;
    for (int i(0); i < str.size(); key += str[i], i++);
    return  static_cast<int>(key * 0.2) % size;
}
```
##openAdressing.h
```cpp
#pragma once

#include "hashGen.h"

#include <iostream>
#include <string>

using namespace std;

struct nodeTableOpAdr {
    string fullName{ " " };
    string numPasp{ " " };
    string birthDay{ " " };
};

struct hashOpAdr {
    const int sizeTable = 75;
    nodeTableOpAdr* table = new nodeTableOpAdr[sizeTable];
    void setTable(string fullName, string numPasp, string birthDay) {
        int hash = hashGen(sizeTable, birthDay);
        while (table[hash % (sizeTable)].birthDay != " ")
            if (++hash - sizeTable == sizeTable)
                break;
        if (hash - sizeTable < sizeTable) {
            table[hash % sizeTable].fullName = fullName;
            table[hash % sizeTable].numPasp = numPasp;
            table[hash % sizeTable].birthDay = birthDay;
        }

    }
    void showTable() {
        for (int i = 0; i < sizeTable; i++) {
            cout << '[' << table[i].fullName << ']'
                << '[' << table[i].numPasp << ']'
                << '{' << table[i].birthDay << '}';
            cout << endl;
        }
    }


    void setHashTable(int cnt) {
        auto randStr = []() {
            string str;
            static const char absd[] = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i < rand() % 8 + 3; i++) str += absd[rand() % 26];
            return str;
            };

        auto randNumber = []() {
            string numPh = "7";
            for (int i = 0; i < 10; i++) numPh += rand() % 10 + 0x30;
            return numPh; };
        auto randDayNumber = []() {
            string numPh = "";
            for (int i = 0; i < 2; i++) numPh += rand() % 10 + 0x30;
            numPh += '.';
            for (int i = 0; i < 2; i++) numPh += rand() % 10 + 0x30;
            numPh += '.';
            for (int i = 0; i < 4; i++) numPh += rand() % 10 + 0x30;
            return numPh; };

        for (int i = 0; i < cnt; i++)
            setTable(randStr(), randNumber(), randDayNumber());


    }
};
```
##chainMethod.h
```cpp
#pragma once

#include "hashGen.h"

#include <iostream>
#include <string>

using namespace std;



struct nodeChain {
    string fullName{ ' ' };
    string numPasp{ ' ' };
    string birthDay{ ' ' };
    nodeChain* next = 0;
    nodeChain* prev = 0;
    int size = 0;
};

struct hashChain {
    const int sizeTable = 75;
    nodeChain* table = new nodeChain[sizeTable];
    void setTable(string fullName, string numPasp, string birthDay) {
        int hash = hashGen(sizeTable, birthDay);
        if (table[hash].birthDay != " ") {
            nodeChain* newNode = new nodeChain;
            newNode->fullName = fullName;
            newNode->numPasp = numPasp;
            newNode->birthDay = birthDay;
            nodeChain* tmp = &table[hash];
            for (int i(0); i < table[hash].size - 1; i++) tmp = tmp->next;
            tmp->next = newNode;
            newNode->prev = tmp;
            table[hash].size++;
        }
        else {
            table[hash].fullName = fullName;
            table[hash].numPasp = numPasp;
            table[hash].birthDay = birthDay;
            table[hash].size++;
        }

    }

    void showTable() {
        for (int i(0); i < sizeTable; i++) {
            if (table[i].size == 0) continue;
            else {
                nodeChain* tmp = &table[i];
                for (int j = 0; j <= table[i].size && tmp != nullptr; j++) {
                    cout << '[' << tmp->fullName << ']'
                        << '[' << tmp->numPasp << ']'
                        << '{' << tmp->birthDay << '}';
                    tmp = tmp->next;
                }
                cout << endl;
            }
        }
    }
    void setHashTable(int cnt) {
        auto randStr = []() {
            string str;
            static const char absd[] = "abcdefghijklmnopqrstuvwxyz";
            for (int i(0); i < rand() % 8 + 3; i++) str += absd[rand() % 26];
            return str;
            };

        auto randNumber = []() {
            string numPh = "7";
            for (int i = 0; i < 10; i++) numPh += rand() % 10 + 0x30;
            return numPh; };

        auto randDayNumber = []() {
            string numPh = "";
            for (int i = 0; i < 2; i++) numPh += rand() % 10 + 0x30;
            numPh += '.';
            for (int i = 0; i < 2; i++) numPh += rand() % 10 + 0x30;
            numPh += '.';
            for (int i = 0; i < 4; i++) numPh += rand() % 10 + 0x30;
            return numPh; };

        for (int i(0); i < cnt; i++)
            setTable(randStr(), randNumber(), randDayNumber());


    }
};
```
