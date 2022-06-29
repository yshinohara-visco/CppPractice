#include "AccessTime.h"

#include <vector>
#include <memory>

namespace AccessTime
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


	void Test()
	{
		int loopCount = 10000000; //1000–œ‰ñ
		int averageCount = 50; //50‰ñ
		double  rawTime, shareTime, uniqueTime; //•½‹ÏŽžŠÔ
		//std::vector<double> 
	}
}