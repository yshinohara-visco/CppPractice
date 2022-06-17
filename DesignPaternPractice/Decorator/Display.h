#pragma once

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Display
{
public:
    virtual int getColumns() = 0;
    virtual int getRows() = 0;
    virtual string getRowText(int row) = 0;

    void show()
    {
        for (int i = 0; i < getRows(); i++)
        {
            cout << getRowText(i) << endl;
        }
    }
};