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
    lazy�ł�immidiate�ł��������g�p�ʂ͑����Ȃ�
    ���U�݂̂̏ꍇ�Alazy�̕�������
    tag::median��ǉ�����Ƌt�]����ꍇ���������B
    ac::tag::median��ǉ�����ƌ��\�������Ԃ��L�т�B�������͑����Ȃ������B
    */
    std::cout << "timeI=" << timeI << " timeL=" << timeL << std::endl;

}