#pragma once
//機能の最上位クラス

#include "DisplayImpl.h"

class Display
{
public:
    Display(DisplayImpl* impl)
    {
        this->impl = impl;
    }

    void open()
    {
        impl->rawOpen();
    }

    void print()
    {
        impl->rawPrint();
    }

    void close()
    {
        impl->rawClose();
    }

    void display()
    {
        open();
        print();
        close();
    }

private:
    DisplayImpl* impl;
};