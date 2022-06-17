#pragma once

//アルゴリズムその1

#include "Strategy.h"
#include <random>
using std::random_device;

class WinningStrategy : public Strategy
{
public:
    WinningStrategy(int seed)
    {
        // random_device は seed が要らない　けど形だけ合わせとく
        int hoge = random(); //関数として実行するだけで毎回違う乱数が得られるはず
    }

    Hand* nextHand() override
    {
        if (!won)
        {
            prevHand = Hand::getHand((HAND)(random() % 3));
        }
        return prevHand;
    }

    void study(bool win)
    {
        won = win;
    }

private:
    random_device random;
    bool won = false;
    Hand* prevHand;
};