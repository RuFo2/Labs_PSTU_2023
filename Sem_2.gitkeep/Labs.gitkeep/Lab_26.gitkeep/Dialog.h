#pragma once
#include "Header.h"
#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmQuit = 101;

struct TEvent {
    int what;
    union {
        int command;
        struct {
            int message;
            int parametr;
        };
    };
};

class Dialog : public Tree {
protected:
    int EndState;
public:
    Dialog() { EndState = 0; };
    virtual ~Dialog() {};
    virtual void getEvent(TEvent& event) {
        string opInt = "m+-szq";
        string s;
        string param;

        char code;
        cout << '>'; cin >> s;  code = s[0];
        if (opInt.find(code) >= 0) {
            event.what = evMessage;
            switch (code) {
            case 'm': event.command = cmMake; break;
            case '+': event.command = cmAdd; break;
            case '-': event.command = cmDel; break;
            case 's': event.command = cmShow; break;
            case 'z': event.command = cmGet; break;
            case 'q': event.command = cmQuit; break;
            }
            if (s.length() > 1) {
                param = s.substr(1, s.length() - 1);
                int A = atoi(param.c_str());
                event.parametr = A;
            }
        }
        else event.message = evNothing;
    };
    virtual int execute() {
        TEvent event;
        do {
            EndState = 0;
            getEvent(event);
            handleEvent(event);
        } while (!valid());
        return EndState;
    };

    virtual void handleEvent(TEvent& event) {
        if (event.what == evMessage) {
            switch (event.command) {
            case cmAdd: {
                Magazin* data = new Magazin;
                data->Input();
                Add(data);
                clearEvent(event);
                break;
            }
            case cmDel: Del(event.parametr); size--; break;
            case cmGet: Find(event.parametr); clearEvent(event); break;
            case cmShow: Show(); clearEvent(event); break;
            case cmQuit: endExec(); clearEvent(event); break;
            }
        }
    };
    virtual void clearEvent(TEvent& event) {
        event.what = evNothing;
    };
    int valid() {
        if (EndState == 0) return 0;
        else return 1;
    };
    void endExec() { EndState = 1; }
};
