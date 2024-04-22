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