#pragma once

#include "Border.h"

class SideBorder : public Border
{
public:
    SideBorder(Display* display, string border)
        :Border(display)
    {
        this->border = border;
    }

    int getColumns() override
    {
        return 1 + display->getColumns() + 1;
    }

    int getRows() override
    {
        return display->getRows();
    }

    string getRowText(int row) override
    {
        return border + display->getRowText(row) + border;
    }

private:
    string border;
};