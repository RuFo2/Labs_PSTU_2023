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