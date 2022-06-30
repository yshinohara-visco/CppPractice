#include "pch.h"
#include "Timer.h"

#include <vector>
#include <functional>
#include <iostream>

namespace Time
{
	void Timer::Start()
	{
		m_start = std::chrono::system_clock::now();
	}

	double Timer::Get()
	{
		auto end = std::chrono::system_clock::now();
		auto diff = end - m_start;
		auto micro = std::chrono::duration_cast<std::chrono::microseconds>(diff);
		double ms = micro.count() / 1000.0;
		return ms;
	}

	void MeasureTime( std::function<void()> func, int countAverage, int countLoop, double& average, std::vector<double>& vecTime )
	{
		Timer timer;
		for (int i = 0; i < countAverage; i++)
		{
			timer.Start();
			for (int j = 0; j < countLoop; j++)
			{
				func();
			}
			double time = timer.Get();
			average += time;
			vecTime.push_back( time );
		}
		average = average / vecTime.size();
	}

	double MeasureTime( std::function<void()> func, int countAverage, int countLoop )
	{
		double time;
		std::vector<double> vecTime;
		MeasureTime( func, countAverage, countLoop, time, vecTime );
		return time;
	}

}