#include "Accumlator.h"

#include "../TimeLib/Timer.h"

#include <iostream>
#include <random>

int main()
{
    Accumulator::VarianceSample();

    Time::Timer timer;

    const int num = 10000000;
    auto immediate = []() {
        Accumulator::VarianceTestImmediate(num);
        };
    auto lazy = []() {
        Accumulator::VarianceTestLazy(num);
        };

    auto timeI = Time::MeasureTime(immediate);
    auto timeL = Time::MeasureTime(lazy);

    /*
    lazyでもimmidiateでもメモリ使用量は増えない
    分散のみの場合、lazyの方が早い
    tag::medianを追加すると逆転する場合もあった。
    ac::tag::medianを追加すると結構処理時間が伸びる。メモリは増えなかった。
    */
    std::cout << "timeI=" << timeI << " timeL=" << timeL << std::endl;

}