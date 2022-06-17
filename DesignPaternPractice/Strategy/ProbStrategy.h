#pragma once

//アルゴリズムその2
//enum class 使いにくすぎ

#include "Strategy.h"
#include <random>
using std::random_device;

class ProbStrategy : public Strategy
{
public:
    ProbStrategy(int seed)
    {
    }

    Hand* nextHand() override
    {
        int bet = random() % getSum(currentHandValue);
        int handvalue = 0;
        if (bet < history[currentHandValue][0])
        {
            handvalue = 0;
        }
        else if (bet < history[currentHandValue][0] + history[currentHandValue][1])
        {
            handvalue = 1;
        }
        else
        {
            handvalue = 2;
        }
        prevHandvalue = currentHandValue;
        currentHandValue = handvalue;
        return Hand::getHand((HAND)handvalue);
    }

    void study(bool win) override
    {
        if (win)
        {
            history[prevHandvalue][currentHandValue]++;
        }
        else
        {
            history[prevHandvalue][(currentHandValue + 1) % 3]++;
            history[prevHandvalue][(currentHandValue + 2) % 3]++;
        }
    }

private:
    random_device random;
    int prevHandvalue = 0;
    int currentHandValue = 0;
    int history[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    int getSum(int hv)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += history[hv][i];
        }
        return sum;
    }
};