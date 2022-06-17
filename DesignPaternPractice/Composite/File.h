#pragma once

#include "Entry.h"
#include <iostream>
using std::cout;
using std::endl;

class File : public Entry
{
public:
    File(string name, int size)
    {
        this->name = name;
        this->size = size;
    }

    string getName() override
    {
        return name;
    }

    int getSize() override
    {
        return size;
    }

    void printList(string prefix)
    {
        cout << prefix + "/" + this->toString();
    }

private:
    string name;
    int size;
};