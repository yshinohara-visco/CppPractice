#pragma once

#include "Border.h"
#include <sstream>
using std::stringstream;

class FullBorder : public Border
{
public:
    FullBorder(Display* display)
        :Border(display) {}

    int getColumns() override
    {
        return 1 + display->getColumns() + 1;
    }

    int getRows() override
    {
        return 1 + display->getRows() + 1;
    }

    string getRowText(int row)
    {
        if (row == 0)
        {
            return "+" + makeLine("-", display->getColumns()) + "+";
        }
        else if (row == display->getRows() + 1)
        {
            return "+" + makeLine("-", display->getColumns()) + "+";
        }
        else
        {
            return "|" + display->getRowText(row - 1) + "|";
        }
    }


private:
    string makeLine(string s, int count)
    {
        stringstream ss;
        for (int i = 0; i < count; i++)
        {
            ss << s;
        }
        return ss.str();
    }
};