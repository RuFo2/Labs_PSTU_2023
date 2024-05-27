#pragma once
#include <string>
#include <iostream>
using namespace std;
class BasicError {
public:
    BasicError() {}
    virtual ~BasicError() {}
    void PrintError() {
        cout << msg << endl;
    }

protected:
    string msg;
};

class WrongSizeError : public BasicError {
public:
    WrongSizeError() { msg = "SizeError: "; }
    virtual ~WrongSizeError() {}
};

class EmptyColletionError : public WrongSizeError {
public:
    EmptyColletionError() { msg += "ColletionError"; }
};

class OverflowError : public WrongSizeError {
public:
    OverflowError() { msg += "OverflowError"; }
};

class WrongIndexError : public BasicError {
public:
    WrongIndexError() { msg = "IndexError: "; }
    virtual ~WrongIndexError() {}
};

class IndexOutOfRangeError : public WrongIndexError {
public:
    IndexOutOfRangeError() { msg += "IndexOutOfRangeError"; }
    ~IndexOutOfRangeError() {}
};

class NegativeIndexError : public WrongIndexError {
public:
    NegativeIndexError() { msg += "IndexError"; }
    ~NegativeIndexError() {}
};