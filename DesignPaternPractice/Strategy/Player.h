#pragma once

#include "Strategy.h"
#include <string>
using std::string;

class Player
{
public:
    Player(string name, Strategy* strategy) //名前と戦略を授けられる
    {
        this->name = name;
        this->strategy = strategy;
    }

    Hand* nextHand()
    {
        return strategy->nextHand();
    }

    void win()
    {
        strategy->study(true);
        wincount++;
        gamecount++;
    }

    void lose()
    {
        strategy->study(false);
        losecount++;
        gamecount++;
    }

    void even()
    {
        gamecount++;
    }

    string toString()
    {
        return "{" + name + ":" + std::to_string(gamecount) + "games, " + std::to_string(wincount) + " win, " + std::to_string(losecount) + "lose" + "}";
    }

private:
    string name;
    Strategy* strategy;
    int wincount;
    int losecount;
    int gamecount;
};