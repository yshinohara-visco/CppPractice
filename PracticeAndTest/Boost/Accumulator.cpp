#include "Accumlator.h"

#include <iostream>
#include <random>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

namespace ac = boost::accumulators;

namespace Accumulator
{

void VarianceSample()
{
    ac::accumulator_set<int, ac::stats<ac::tag::variance> > acc;

    acc(1);
    acc(2);
    acc(3);
    acc(4);
    acc(5);

    std::cout << "count=" << ac::count(acc) << std::endl
        << "mean=" << ac::mean(acc) << std::endl
        << "variance=" << ac::variance(acc) << std::endl;
}

void VarianceTestImmediate(int num)
{
    ac::accumulator_set<int, ac::stats<ac::tag::count, ac::tag::min, ac::tag::max, ac::tag::mean, ac::tag::median,
        ac::tag::variance> > acc;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    
    for (size_t i = 0; i < num; i++)
    {
        acc(distribution(gen));
    }

    auto variance = ac::variance(acc);
    std::cout << "num=" << num << " variance=" << variance << std::endl;
}

void VarianceTestLazy(int num)
{
    ac::accumulator_set<int, ac::stats<ac::tag::count, ac::tag::min, ac::tag::max, ac::tag::mean, ac::tag::median,
        ac::tag::lazy_variance>> acc;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);

    for (size_t i = 0; i < num; i++)
    {
        acc(distribution(gen));
    }

    auto variance = ac::variance(acc);
    std::cout << "num=" << num << " variance=" << variance << std::endl;
}


}