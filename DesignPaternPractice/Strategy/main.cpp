#include "Player.h"
#include "WinningStrategy.h"
#include "ProbStrategy.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int hogeseed = 0;
    int piyoseed = 1;
    //形だけ

    Player* player1 = new Player("Taro", new WinningStrategy(hogeseed));
    Player* player2 = new Player("Hana", new ProbStrategy(piyoseed));

    for (int i = 0; i < 10000; i++)
    {
        Hand* nextHand1 = player1->nextHand();
        Hand* nextHand2 = player2->nextHand();
        if (nextHand1->isStrongerThan(nextHand2))
        {
            //表示
            player1->win();
            player2->lose();
        }
        else if (nextHand2->isStrongerThan(nextHand1))
        {
            //hyouzi
            player1->lose();
            player2->win();
        }
        else
        {
            //hyouzi
            player1->even();
            player2->even();
        }
    }

    cout << "Total result" << endl;
    cout << player1->toString() << endl;
    cout << player2->toString() << endl;
}