#pragma once

//じゃんけんの手を表す　勝ち負け判定とかもする　デザインパターンとは無関係
//微妙な仕様の違いとかでところどころ違う実装に

#include <string>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;

enum class HAND {
    guu = 0,
    cho,
    paa,
};

class Hand
{
public:
    static Hand* getHand(HAND handvalue)
    {
        return hands[handvalue];
    }

    bool isStrongerThan(Hand* h)
    {
        return fight(h) == 1;
    }

    bool isWeakerThan(Hand* h)
    {
        return fight(h) == -1;
    }

    string toString()
    {
        return name[(int)handvalue];
    }

private:
    static vector<string> name;
    HAND handvalue;
    static map<HAND, Hand*> hands;

    Hand(HAND handvalue)
    {
        this->handvalue = handvalue;
    }

    int fight(Hand* h)
    {
        if (this->handvalue == h->handvalue)
        {
            return 0;
        }
        else if (((int)this->handvalue + 1) % 3 == (int)h->handvalue)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};

vector<string> Hand::name = { "グー", "チョキ", "パー" };
map<HAND, Hand*> Hand::hands = { {HAND::guu, new Hand(HAND::guu)}, {HAND::cho, new Hand(HAND::cho)}, {HAND::paa, new Hand(HAND::paa)} };
