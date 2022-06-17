#pragma once

#include "FileTreatmentException.h"
#include <string>
using std::string;

class Entry
{
public:
    virtual string getName() = 0;
    virtual int getSize() = 0;

    Entry* add(Entry* entry) throw(FileTreatmentException)
    {
        int hoge = 111;
        throw FileTreatmentException("FileTreatmentExceptionやで", hoge);
    }

    void printList()
    {
        printList("");
    }

    string toString()
    {
        return getName() + " (" + std::to_string(getSize()) + ")\n";
    }

    //protected: だとDirectoryのprintList内から呼ぶことができなかった
    virtual void printList(string prefix) = 0;
};