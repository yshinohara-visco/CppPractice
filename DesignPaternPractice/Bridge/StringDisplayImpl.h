#pragma once
//実際に実装を行っているクラス

#include "DisplayImpl.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class StringDisplayImpl : public DisplayImpl
{
public:
    StringDisplayImpl(string text)
    {
        this->text = text;
        this->width = text.length();
    }

    void rawOpen() override
    {
        printLine();
    }

    void rawPrint() override
    {
        cout << "|" + text + "|" << endl;
    }

    void rawClose() override
    {
        printLine();
    }

private:
    string text;
    int width;

    void printLine()
    {
        cout << "+";
        for (int i = 0; i < width; i++)
        {
            cout << "-";
        }
        cout << "+" << endl;
    }
};