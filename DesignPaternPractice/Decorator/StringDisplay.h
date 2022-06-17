#pragma once

#include "Display.h"

class StringDisplay : public Display
{
public:
    StringDisplay(string text)
    {
        this->text = text;
    }

    int getColumns() override
    {
        return text.length();
    }

    int getRows() override
    {
        return 1;
    }

    string getRowText(int row)
    {
        if (row == 0)
        {
            return text;
        }
        else
        {
            return "";
        }
    }

private:
    string text;
};