#pragma once
//機能を拡張したクラス

#include "Display.h"

class CountDisplay : public Display
{
public:
    CountDisplay(DisplayImpl* impl)
        :Display(impl) {}

    //新機能としての関数を追加している
    void multiDisplay(int times)
    {
        open();
        for (int i = 0; i < times; i++)
        {
            print();
        }
        close();
    }
};