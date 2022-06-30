#pragma once

#include <chrono>
#include <vector>
#include <functional>

namespace Time
{
	class Timer
	{
	public:
		void Start();
		double Get();

	private:
		std::chrono::system_clock::time_point m_start;
	};

	void MeasureTime( std::function<void()> func, int countAverage, int countLoop, double& average, std::vector<double>& vecTime );
	double MeasureTime( std::function<void()> func, int countAverage, int countLoop );

}