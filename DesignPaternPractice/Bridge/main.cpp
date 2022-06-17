#include "CountDisplay.h"
#include "StringDisplayImpl.h"

int main()
{
    Display* d1 = new Display(new StringDisplayImpl("Hello, Japan"));
    Display* d2 = new CountDisplay(new StringDisplayImpl("Hello World")); // 動くがmultiDisplay()は呼び出せない
    CountDisplay* d3 = new CountDisplay(new StringDisplayImpl("Hello , Universe")); //multiDisplay()を呼び出せる

    d1->display();
    d2->display();
    d3->display();
    d3->multiDisplay(5);

    return 0;
}